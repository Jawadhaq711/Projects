#pragma once
#include <memory>
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
// #include <opencv2\highgui\highgui.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>


class OCR 
{
    private:
        cv::Mat _image;
        tesseract::TessBaseAPI *api = nullptr;
    public:
        OCR();
        OCR(cv::Mat image); // ASSUMING THE SIZE OF IMAGE IS 50x50
        int getDigit(); // returns the digit in the Mat _image

};