#include "image_process.h"

ImageProcess::ImageProcess(std::string filename)
{
    _filename = filename;
    _image = cv::imread(_filename, cv::IMREAD_GRAYSCALE); // read the image in grayscale
}

void ImageProcess::testImage()
{
    bool check = cv::imwrite("PostProcess.jpeg", _image);
	// cv::waitKey(0);
}

void ImageProcess::PreProcess()
{
// gaussian blur to reduce noise
  cv::Mat gaussBlur;
  cv::Size_<int> kernelBlur(5,5);
  cv::GaussianBlur(_image, gaussBlur,kernelBlur,1,1);

  // adaptive threshold to convert color scale and highlight things of interest
  cv::Mat adaptiveThresh;
  cv::adaptiveThreshold(gaussBlur, adaptiveThresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 13,6);

  // binary inversion to convert numbers and grid to white
  cv::Mat binary_inversion;
  cv::bitwise_not(adaptiveThresh,binary_inversion);

  // dilation to increase size of numbers and grid outlines
  cv::Mat dilation;
  cv::Mat kernelDilation(2,3,CV_8UC1);
  cv::dilate(binary_inversion, dilation, kernelDilation);

  cv::Mat binaryThresh;
  threshold(dilation, binaryThresh, 127, 255, cv::THRESH_BINARY);

  _image = binaryThresh;
}


std::vector<cv::Point> ImageProcess::FindLargestContour()
{
  std::vector<std::vector<cv::Point> > contours;
  findContours(_image, contours,  cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
  std::vector <cv::Point>max_contour = contours.at(0);
  size_t max_size = contours.at(0).size();
  for(const auto& contour_vec : contours)
  {
    if(max_size < contour_vec.size())
    {
      max_size = contour_vec.size();
      max_contour = contour_vec;
    }
  }
  return max_contour;
}

std::vector<cv::Point> ImageProcess::FindIntersections()
{
  int height = _image.rows;
  int width = _image.cols;

  std::vector<std::pair<cv::Point, cv::Point>> lines = FindHoughLines();

  std::vector<Point> intersections;
  for(unsigned int i = 0; i < lines.size();i++) {
    for (unsigned int j = 0; j < lines.size(); j++) {
      if (j != i) {
        // find intersections
        std::pair<Point,Point> lineA = lines.at(i); // corresponds to points a and b
        std::pair<Point,Point> lineB = lines.at(j); // corresponds to points c and d

        Point a = lineA.first;
        Point b = lineA.second;

        Point c = lineB.first;
        Point d = lineB.second;

        double a1 = b.y - a.y;
        double b1 = a.x - b.x;
        double c1 = a1*(a.x) + b1*(a.y);

        // Line CD represented as a2x + b2y = c2
        double a2 = d.y - c.y;
        double b2 = c.x - d.x;
        double c2 = a2*(c.x)+ b2*(c.y);

        double determinant = a1*b2 - a2*b1;
        if (determinant != 0) {
          double x = (b2*c1 - b1*c2)/determinant;
          double y = (a1*c2 - a2*c1)/determinant;

          bool x_out_of_bounds = x < 0.0 || x > (double) width;
          bool y_out_of_bounds = y < 0.0 || y > (double) height;
          bool duplicate = std::count(intersections.begin(), intersections.end(), Point(x,y));

          if (!x_out_of_bounds && !y_out_of_bounds && !duplicate) {
            intersections.emplace_back(x,y);
            std:: cout << "x: " << x << " y: " << y << std::endl;
          }
        }
      }
    }
  }

  return intersections;
}

std::vector<std::pair<cv::Point, cv::Point>> ImageProcess::FindHoughLines() {
  Scalar color( 255, 255, 255, 128 );
  std::vector<Point> largestContour = FindLargestContour();
  std::vector<std::vector<Point>> contours;
  contours.push_back(largestContour);

  Mat dst = Mat::zeros(_image.rows, _image.cols, CV_8UC1);
  drawContours(dst, contours, -1, color, 1, LINE_8);


  std::vector<Vec2f> linesP; // will hold the results of the detection
  HoughLines(dst, linesP, 1, CV_PI/180, 128, 0, 0, 0 ); // runs the actual detection
//  std::cout << "Lines: " << linesP.size() << std::endl;

//  for (int i = 0; i < linesP.size(); i++) {
//    std::cout << "Point: " << linesP.at(i) << std::endl;
//  }

  std::vector<std::pair<cv::Point,cv::Point>> hough_lines;
  for (auto & i : linesP)
  {
    float rho = i[0], theta = i[1];
    Point pt1, pt2;
    double a = cos(theta), b = sin(theta);
    double x0 = a*rho, y0 = b*rho;
    pt1.x = cvRound(x0 + _image.cols*(-b));
    pt1.y = cvRound(y0 + _image.cols*(a));
    pt2.x = cvRound(x0 - _image.rows*(-b));
    pt2.y = cvRound(y0 - _image.rows*(a));
//    line( dst, pt1, pt2, Scalar(255,255,255), 2, LINE_AA);
//    std::cout << "Line " << i << " " << pt1 << " ," << pt2 << std::endl;
    hough_lines.emplace_back(pt1,pt2);
  }


  return hough_lines;
}

void ImageProcess::WarpTransform() {
  std::vector<Point> corners = FindIntersections();

  std::vector<Point2f> inputs(4);
  std::vector<Point2f> outputs(4);

  inputs[0] = (Point2f) corners.at(0);
  inputs[1] = (Point2f) corners.at(1);
  inputs[2] = (Point2f) corners.at(2);
  inputs[3] = (Point2f) corners.at(3);

  outputs[0] = Point2f(450,450);
  outputs[1] = Point2f(450,0);
  outputs[2] = Point2f(0,450);
  outputs[3] = Point2f(0,0);

  Mat wrap;
  Mat mat = Mat::zeros(_image.size(), _image.type());

  wrap = getPerspectiveTransform(inputs,outputs);

  warpPerspective(_image, mat,wrap, Size(450,450));

  _image = mat;
}
Mat ImageProcess::GetImage() {
  return _image;
}
