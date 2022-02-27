project(sudoku_solver)
cmake_minimum_required(VERSION 3.0)  # CMake version check
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(INCLUDES includes/)
set(SOURCE src/)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /root/tesseract /root/leptonica/build)
set(CMAKE_MODULE_PATH "/source/cmake-modules")
find_package( OpenCV REQUIRED )
include_directories(${INCLUDES})
include_directories(${OpenCV_INCLUDE_DIRS})
find_package( Tesseract REQUIRED ) # 3.05 is currently the latest version of the git repository.
include_directories(${Tesseract_INCLUDE_DIRS})

# Add main.cpp file of project root directory as source filei

add_executable(exec ${SOURCE}/solver.cpp ${SOURCE}/main.cpp ${SOURCE}/image_process.cc ${SOURCE}/OCR.cpp)
target_link_libraries( exec ${OpenCV_LIBS} ${Tesseract_LIBRARIES})
# target_link_libraries(exec -llept -ltesseract) # must add this line to link Tesseract and leptonica libs

add_executable(sudoku_tests tests/test.cc ${SOURCE}/solver.cpp)
target_include_directories(sudoku_tests PUBLIC tests/)



# Add executable target with source files listed in SOURCE_FILES variable
# target_link_libraries(sudoku_tests PRIVATE Catch2::Catch2WithMain)
