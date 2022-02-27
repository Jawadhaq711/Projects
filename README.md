# Running Docker Container
When you first clone the project, it is good practice to run the docker container in order to have the same environment from computer to computer. 
First, type chmod +rwx run_docker.sh to give the shell script permissions. Then, simply type the ./run_docker.sh to build and run the docker container. After
this is done, you will want to not run this file again. Simply type:

docker start cs128finalenv

to start the environment, or 

docker stop cs128finalenv 

to stop the container




# Proposal: Sudoku Solver With OpenCV

Author(s): Jawad Haq, Robert Azarcon, Matthew Jacobs, Rishabh Jois

Last updated: 11/9/21


## Executive Summary

For our final project, we will be implementing a Sudoku Solver using Open Source Computer Vision Library (OpenCV). OpenCv is a free open source library which is very useful for computer vision applications primarily in video and image analysis. We will be using OpenCV to populate a Sudoku board locally from a given Sudoku image (.png or .jpg). The output image should then contain numbers overlaid on the image to show the solution you want to use to solve. Finally, we will be implemeting this program primarily in C++ and python (python will be used for character recognition.)


## Features

The problem we are solving is we want to be able to quickly solve sudoku puzzles with very minimal effort. By taking a picture and having the program solve it we can easily get the solution for our puzzle without having to manually type in the puzzle which could be prone to human error. In terms of background we need some knowledge about OpenCV but it should be easy to pick up as long as we spend some time reading or watching tutorials. We also need to figure out an efficient algorithm to solve the sudoku puzzle and figure out a way to implement it in C++.


## Plan
We will start with configuring OpenCV to successfully extract a Sudoku board from the image we give it. Since the parsing aspect of our project is very important, this will be a major priority for our project. Once the image is successfully parsed into our program, we can implement a function to optimally solve the board. In terms of work, we plan to split it into the two sections mentioned. We will have half of us implement the OpenCV portion of the project while the other half works on writing the puzzle solver as well as aiding in the implementation of the OpenCV. Ideally, we should have the OpenCV portion finished before Thanksgiving week.


## Third Party Libraries
PyTessaract 
OpenCV


