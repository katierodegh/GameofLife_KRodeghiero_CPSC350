// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include <fstream>
#include<iostream>
#include <vector>
using namespace std;

class Play{
  public:
    Play(); //default constructor
    Play(int Rsize, int Csize); //constructor that takes in number of rows and columns
    ~Play(); // destrutor

    virtual int CountOcc(int i, int j) = 0; //the function all children classes need to implement

    void CreateGrid(int Rsize, int Csize); //creates a grid of Rsize, Csize filled with empty char '-'
    void CreateGridEmpty(int Rsize, int Csize); //creates a new empty grid of Rsize, Csize
    float generateGrid(); //gets the user imput needed for the user generated grid and returns popDen
    void genGridIn(float popDen); //uses both the population density and empty character filled 2D array to make generation 0

    void UpdateCopyArray(); //fills the arrayCopy with the gridArray information
    bool CheckGens(); //checks to see if the generations of the grids are the exact same

    string textRead(); //promts for the file to read from and checks to make sure it exists
    void copyFile(string fileName); //opens the file the user wants to read from and makes a grid with that file

    void PrintGrid();//prints each cell to the .out file
    void PrintToFile(ofstream& fileName); //passes writeFile by refernces to print to the open writeFile

    void showCursor(); //print s cursor (just an aesthetic thing)
    void RunMode(); //uses information from CountOcc to update the cells depending on surrounding cells

    float popDen; //population density
    int countFilled; //used in children classes for the number of surrounding cells that are filled
    int Rsize; //number of rows
    int Csize; //number of columns

    char** arrayGrid; //this is a pointer to my 2D array arrayGrid
    char** arrayCopy; //this is a pointer to my 2D array arrayCopy
};
