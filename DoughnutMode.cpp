// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include "Play.h"
#include "DoughnutMode.h"
#include<iostream>
#include <fstream>

DoughnutMode::DoughnutMode() {} //constructor needed for object creation

int DoughnutMode::CountOcc(int i, int j) { //takes in each i,j and return number of filled cells that surround it
  arrayCopy; //grabs arraycopy;
  countFilled = 0;
  int c; //new variables so we don't mess with k and r in the loop
  int d;
  for(int k = i-1; k <= i+1; ++k) { //lets us look at the 8 (+self) surrounding spaces
    for(int r = j-1; r <= j+1; ++r) {
      if ((k == i) & (r == j)) {} //if space is self, do nothing
      else {
      c = k; //makes it so we don't mess us the loop
      d = r;
        //if c is out of bounds, make it in bounds by wraping around
        if (c < 0) {
          c = (Rsize - 1);
        }
        else if (c >= Rsize) {
          c = 0;
        }
        //if d is out of bounds, make it in bounds by wraping around
        if (d < 0) {
          d = (Csize - 1);
        }
        else if (d >= Csize) {
          d = 0;
        }
        if (arrayCopy[c][d] == 'X') { //if the new space we're checking is good, add to count filled
          countFilled++;
        }
      }
    }
  }
  return countFilled; //return number of filled surrounding spaces
}
