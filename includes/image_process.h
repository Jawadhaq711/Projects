#pragma once

#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace cv;

class ImageProcess
{
    private:
        std::string _filename;
        cv::Mat _image;


    public:

    ImageProcess() = default;
    explicit ImageProcess(std::string filename);
    void PreProcess(); // involved in the preprocessing of the image
    void testImage();
    std::vector<cv::Point> FindLargestContour();
    std::vector<cv::Point> FindIntersections();
    std::vector<std::pair<cv::Point, cv::Point>> FindHoughLines();
    void WarpTransform();
    Mat GetImage();
  

};
