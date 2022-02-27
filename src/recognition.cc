#include "recognition.h"


std::vector<Mat> Recognition::BoardValues(const Mat& sourceImg) {
  std::vector<Mat> blocks(81);// vector that contains all 81 blocks
  for (size_t i = 0; i < 450; i += 50)
  {
    for (size_t j = 0; j < 450; j += 50)
    {
      block = Mat(sourceImg, cv::Rect(j, i, 50, 50));
      blocks.push_back(block);
    }
    
  }
  std::vector<std::vector<cv::Point> > contours;

  for (size_t i = 0; i < blocks.size; i++)//populate a vector of the outer border of the individual blocks
  {//numbers are not centered
      Mat threshold = blocks[i];
      findContours(threshold, contours, CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE);
  
  Rect curr;
  double temp_area;
  double curr_area; 
  int temp;
  for (int j = 0; j < contours.size(); j++)
     {//resizing the rectabgle to center the numbers below
          Rect bound = boundingRect(contours[j]);
         curr_area = bound.height*bound.width;
           if (curr_area > temp_area)
          {
                   curr = bound;
                   temp_area = curr_area;
                   temp = j;
           }
       } 
   Rect rec = curr;
   regionOfInterest = blocks[i](rec);
   resize(regionOfInterest, blocks, Size(16,16),0,0,INTER_NEAREST);

  }
  return blocks;//a matrix with all values centered.
}
