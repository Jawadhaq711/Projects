#include <iostream>

#include "solver.h"
#include "image_process.h"
#include "OCR.h"

int main()
{
  
  std::string path = "../ImageInputs/Sodoku1.jpg";
  ImageProcess image_processor = ImageProcess(path);

  image_processor.PreProcess();
  image_processor.WarpTransform();
  image_processor.testImage();
  auto img = image_processor.GetImage();
  OCR ocr(img);
  // cv::imshow("warped", image_processor.GetImage());
  // cv::waitKey(0);

    // std::vector< std::vector<int> > v{
    // {0, 0, 6, 5, 0, 8, 4, 0, 0},
    // {5, 2, 0, 0, 0, 1, 0, 0, 0},
    // {0, 7, 8, 0, 0, 0, 0, 0, 1},
    // {0, 0, 4, 0, 1, 0, 0, 8, 0},
    // {9, 0, 0, 8, 2, 3, 0, 0, 5},
    // {0, 5, 0, 0, 9, 0, 6, 0, 0},
    // {1, 3, 0, 0, 0, 0, 2, 5, 0},
    // {0, 0, 0, 0, 0, 0, 0, 7, 4},
    // {0, 0, 5, 2, 0, 6, 3, 0, 0}
    // };
    
    // Solver s(v);
    // std::cout << "DOES THIS USE TOO MUCH MEMORY?\n";
    // s.solver();
    // auto medium_test = std::vector<std::vector<int> >{ 
    //                        { 0, 8, 0, 0, 0, 0, 0, 0, 0 },
	// 					   { 0, 6, 0, 0, 0, 5, 3, 0, 0 },
	// 					   { 0, 0, 0, 0, 9, 0, 5, 6, 0 },
	// 					   { 0, 0, 0, 0, 0, 0, 8, 0, 2 },
	// 					   { 0, 0, 0, 0, 0, 0, 0, 4, 0 },
	// 					   { 3, 0, 7, 0, 2, 0, 0, 0, 0 },
	// 					   { 0, 0, 5, 0, 6, 0, 9, 8, 0 },
	// 					   { 7, 0, 0, 4, 0, 0, 0, 0, 3 },
	// 					   { 0, 4, 0, 0, 0, 1, 0, 0, 0 } };
    // auto empty_board = std::vector< std::vector<int> >(9,std::vector<int>(9,0));
    // Solver empty(empty_board);
    // empty.solver();
    // std::cout << "EMPTY BOARD\n" << empty << "\n";
    // Solver solve_medium(medium_test);
    // solve_medium.solver();
    // std::cout << solve_medium << "\n";
  //   std::cout << "NEW MAIN\n";
  //   std::cout << __cplusplus << std::endl;
  //   ImageProcess p("../test/testimage.jpg");
  // p.PreProcess();
  // p.testImage();
  //   std::cout << "END OF PROGRAM\n";
}
