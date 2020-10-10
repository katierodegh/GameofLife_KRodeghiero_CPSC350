// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include "Play.h"
#include "ClassicMode.h"
#include<iostream>
#include <fstream>

ClassicMode::ClassicMode() {} //constructor needs for object creation

int ClassicMode::CountOcc(int i, int j) { //takes in the i, j we're looking at
  arrayCopy; //grabs the arraycopy
  countFilled = 0;
  for(int k = i-1; k <= i+1; ++k) { //loops through the 8 (+self) surrounding spaces
    for(int r = j-1; r <= j+1; ++r) {
      if((k < 0) || (r < 0) || (k >= Rsize) || (r >=Csize)) {} //if it's out of bounds, do nothing
      else if ((k == i) & (r == j)) {} //if it's itself do nothing
      else if (arrayCopy[k][r] == 'X') { //if the position is equal to X add to the count filled
        countFilled++;
      }
    }
  }
  return countFilled; //returns number of filled spaces surrounding the i,j
}
