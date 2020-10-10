// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include <fstream>
#include<iostream>
using namespace std;

class ClassicMode:public Play{ //inherits from Play
  public:
    ClassicMode(); //default constructor

    int CountOcc(int i, int j); //counts number of 'X's surrounding the i,j
};
