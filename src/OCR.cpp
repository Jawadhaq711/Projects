#include "OCR.h"

OCR::OCR()
{
    api = new tesseract::TessBaseAPI();
}

OCR::OCR(cv::Mat image)
{
    _image = image;
    api = new tesseract::TessBaseAPI();
    if (api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY)) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    api -> SetImage((uchar*)_image.data, _image.size().width, _image.size().height, _image.channels(), _image.step1());
    api -> Recognize(0);
}

int OCR::getDigit()
{
    const char* out = api -> GetUTF8Text();
    if(!out) return 0;
    const char c = out[0];
    switch(c)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}