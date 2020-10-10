// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include "Play.h"
#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;

Play::Play(){ //default constructer
  CreateGridEmpty(30, 30); //creates an empty grid
}

Play::Play(int Rsize, int Csize) { //overload constructor
  CreateGrid(Rsize, Csize); // create a grid of Rsize, Csize
}

Play::~Play(){ //destructor
  for (int i = 0; i < Rsize; ++i) { //gets rid of all the column arrays
    delete [] arrayGrid[i];
    delete [] arrayCopy[i];
  }
  delete [] arrayGrid; //deletes the rest of the array
  delete [] arrayCopy; // deletes the rest of the array
}

void Play::CreateGridEmpty(int Rsize, int Csize) { //creates a new empty grid of Rsize, Csize
  arrayGrid = new char*[Rsize]; //dynamically allocates arrayGrid
  arrayCopy = new char*[Rsize]; //dynamically allocates arrayCopy
  for(int i = 0; i < Rsize; ++i) { //for each spot in the array, store a pointer
      arrayGrid[i] = new char[Csize];
      arrayCopy[i] = new char[Csize];
  }
}

void Play::CreateGrid(int Rsize, int Csize) { //creates a grid of Rsize, Csize filled with empty char '-'
  CreateGridEmpty(Rsize, Csize); //create a new empty grid of size Rsize, Csize
  for(int i = 0; i < Rsize; ++i) { //fill both arrays with an empty char '-'
    for(int j = 0; j < Csize; ++j) {
      arrayGrid[i][j] = '-';
      arrayCopy[i][j] = '-';
    }
  }
}

float Play::generateGrid() { //gets the user imput needed for the user generated grid and returns popDen
  cout << "How many rows?" << endl;
  showCursor();
  cin >> Rsize; //Grabs number of rows
  cout << "How many columns?" << endl;
  showCursor();
  cin >> Csize; //grabs number of columns
  cout << "What is the population density? (greater than 0, less than or equal to 1)" << endl;
  showCursor();
  cin >> popDen; //grabs population density
  while((popDen <= 0) || (popDen > 1)) { //makes sure the population density is greater than 0 and less than or equal to 1, loops if its not
    cout << "Let's try that again" << endl;
    showCursor();
    cin >> popDen;
  }
  CreateGrid(Rsize, Csize); //greates a grid with empty character 'X' of Rsize, Csize
  return popDen;
}

void Play:: genGridIn(float popDen) { //uses both the population density and empty character filled 2D array to make generation 0
  int total = Rsize * Csize; //total number of spaces
  int numOcc = total*popDen; //total number of oxxupied spaces
  int xRand; //makes random variables for x and y
  int yRand;
  int i = 0;
  while(i < numOcc) {
     xRand = rand() % Rsize; //returns any number between 0 and Rsize-1
     yRand = rand() % Csize; //returns any number between 0 and Csize-1
     if (arrayGrid[xRand][yRand] == '-') //as long as the space isn't occupied
     {
       arrayGrid[xRand][yRand] = 'X'; //occupy that spot
       arrayCopy[xRand][yRand] = 'X'; //occupy that spot
       i++;
     }
   }
}

void Play::UpdateCopyArray(){ //fills the arrayCopy with the gridArray information
  arrayGrid; //grabs both arrayGrid and arrayCopy
  arrayCopy;
  for(int i = 0; i < Rsize; ++i) { //for each cell is arrayGrid
    for(int j = 0; j < Csize; ++j) {
      arrayCopy[i][j] = arrayGrid[i][j]; //copy that information into arrayCopy
    }
  }
}

bool Play::CheckGens() { //checks to see if the generations of the grids are the exact same
  arrayGrid;
  arrayCopy;
  int countSame = 0; //counts the number of times arrayGrid[i][j] == arrayCopy[i][j]
  for(int i = 0; i < Rsize; ++i) { //loops through all of arrayGrid/arrayCopy
    for(int j = 0; j < Csize; ++j) {
      if(arrayGrid[i][j] == arrayCopy[i][j]) {
        countSame++; //when they are equal, add to countSame
      }
    }
  }
  if(countSame == (Csize*Rsize)) { //if they grids are the exact same return true
    return true;
  }
  else { //if the grids are not the same return false and then make them the same
    UpdateCopyArray();
    return false;
  }
}

string Play::textRead() { //promts for the file to read from and checks to make sure it exists
  string fileName;
  //string myText;
  bool loop = true;
  cout << "Please enter the text file you want to use." << endl;
  while (loop) {
    showCursor();
    cin >> fileName;
    ifstream file(fileName);

    if (file.is_open()) { //makes sure the file exists
      file.close();
      loop = false; //takes us out of the loop
    }
    else {
      cout << "That file doesn't exist. Try again." << endl; //repromts for input
      loop = true; //keeps us in the loop
    }
  }
  return fileName; //returns the name of the file we want to read from
}

void Play::copyFile(string fileInput) { //opens the file the user wants to read from and makes a grid with that file
  int x;
  int y;
  int count = 0;
  char storedChar;
  string myText;
  int numLines = 0;

  ifstream myfile(fileInput); //opens the .txt file
  while (count < 2){ //loops through the first two lines
    getline(myfile, myText);
    if (count == 0) { //the first number in the file is the Rsize
      stringstream num(myText);
      num >> x;
      Rsize = x;
      count++;
    }
    else if (count == 1) { //the second line in the file is the Csize
      stringstream num(myText);
      num >> y;
      Csize = y;
      count++;
    }
  }

  CreateGridEmpty(Rsize, Csize); //creates an emp
  int iCount = -1;
  while(getline(myfile, myText)) {
    iCount++; //keeps track of the row it sould be on
      for(int k = 0; k <= (myText.length() - 1); ++k) { //for each char in the line, put in the array
          arrayGrid[iCount][k] = myText.at(k);
          arrayCopy[iCount][k] = myText.at(k);
          }
      }
  myfile.close(); //close the .txt file
}

void Play::PrintGrid() { //prints each cell to the .out file
  arrayGrid; //grabs arrayGrid
  for(int i = 0; i < Rsize; ++i) {
    for(int j = 0; j < Csize; ++j) {
      cout << arrayGrid[i][j]; //prints each cell to the .out file
    }
    cout << endl;
  }
}

void Play::PrintToFile(ofstream& writeFile) { //passes writeFile by refernces to print to the open writeFile
  arrayGrid;
  for(int i = 0; i < Rsize; ++i) {
    for(int j = 0; j < Csize; ++j) {
      writeFile << arrayGrid[i][j]; //writes each line to the output file
    }
    writeFile << endl;
  }
}

void Play::showCursor() { //print s cursor (just an aesthetic thing)
cout << "-> ";
}

void Play::RunMode() { //uses information from CountOcc to update the cells depending on surrounding cells
  int numFilled;
  arrayGrid;
  for(int i = 0; i < Rsize; ++i) { //looks at every i,j
    for(int j = 0; j < Csize; ++j) {
      numFilled = CountOcc(i, j); //counts the number of sounding spaces that are filled
      //depending on how many spaces are filled, update cell
      if(numFilled <= 1) {
        arrayGrid[i][j] = '-';
      }
      else if (numFilled == 2) {
        arrayGrid[i][j] = arrayGrid[i][j];
      }
      else if (numFilled == 3) {
        arrayGrid[i][j] = 'X';
      }
      else {
        arrayGrid[i][j] = '-';
      }
    }
  }
}
