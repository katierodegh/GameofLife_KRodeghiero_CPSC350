// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include "Play.h"
#include "MirrorMode.h"
#include<iostream>
#include <fstream>

MirrorMode::MirrorMode() {} //constructor needed for object creation

int MirrorMode::CountOcc(int i, int j) {
  arrayCopy; //grabs array copy
  countFilled = 0;
  int c; //new variables so we don't alter k and r in the loop
  int d;
  for(int k = i-1; k <= i+1; ++k) { //lets us look at the 8 (+self) surrounding spaces on the grid
    for(int r = j-1; r <= j+1; ++r) { //d
      if ((k == i) & (r == j)) {} //if we're looking at self (i,j), do nothing
      else {
      c = k; //makes it so we don't screw up k and r
      d = r;
        //checking to sure everything is in bounds, if not, make it in bounds
        if (c < 0) { //if c is -1, make it 0
          c++;
        }
        else if (c >= Rsize) { // if c is Rsize, make it Rsize-1
          c--;
        }
        if (d < 0) { //if d is -1, make it 0
          d++;
        }
        else if (d >= Csize) { //is d is Csize, make it Csize-1
          d--;
        }
        if (arrayCopy[c][d] == 'X') { //if the spot is filled, add to the number of filled spaces
          countFilled++;
        }
      }
    }
  }
  return countFilled; //return the number of filled spaces surrounding the single i,j
}
