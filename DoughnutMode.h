// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include <fstream>
#include<iostream>
using namespace std;

class DoughnutMode:public Play{
  public:
    DoughnutMode(); //default constructor

    int CountOcc(int i, int j); //taks in each i,j and returns the number of filled cells surrounding it
};
