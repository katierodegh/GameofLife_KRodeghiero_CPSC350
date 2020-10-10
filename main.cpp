// Katie Rodeghiero
// ID: 2345864
// rodeghiero@chapman.edu
// CPSC350 - 02
// Assignment 2: Game of Life

#include "Play.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

void showCursor(){ //just an aesthetic thing
cout << "-> ";
}

int main(int argc, char** argv){ //this is our main method

  //initializing variables
  char gridChoice;
  char gameMode;
  char genGap;
  bool goodChoice = false;
  string writeFileName;
  bool save = false;
  bool textSave = true;
  int genNumber = 0;

  //Desidew what map style the user wants
  cout << "Would you like to (G) generate a map or (T) input a text file? (enter G or T to choose)" << endl;
  while (!goodChoice) {
    showCursor();
    goodChoice = true;
    cin >> gridChoice; //grabs user input
    if((toupper(gridChoice) != 'G') & (toupper(gridChoice) != 'T')) { //if it's not a good input, try again
      goodChoice = false;
      cout << "Try again" << endl;
      continue;
    }
  }

  //Decides what game mode the user wants to play in
  cout << "What mode do you want to play in? (C) Classic, (M) Mirror, or (D) Doughnut. (enter C, M, or D to choose)" << endl;
  showCursor();
  cin >> gameMode; //grabs user input
  while((toupper(gameMode) != 'C')  & (toupper(gameMode) != 'M') & (toupper(gameMode) != 'D')) { //if input bad, retry
    cout << "That wasn't an option, try again" << endl;
    showCursor();
    cin >> gameMode;
  }

  Play *playGame; //creates an instance of the Play class

  //depending on game mode, create new object
  if(toupper(gameMode) == 'C') {
    playGame = new ClassicMode(); //creates ClassicMode object
  }
  else if(toupper(gameMode) == 'M') {
    playGame = new MirrorMode(); //Creates Mirror mode object
  }
  else if(toupper(gameMode) == 'D') {
    playGame = new DoughnutMode(); // creates doughnut mode object
  }

  //decides how the user wants things outputed
  cout << "How would you like to see generations? (E) Press 'Enter', (P) pause, or (W) write to output file? " << endl;
  showCursor();
  cin >> genGap; //gets user input
  while((toupper(genGap) != 'E')  & (toupper(genGap) != 'P') & (toupper(genGap) != 'W')) { //if it's bad... try again
    cout << "That wasn't an option, try again" << endl;
    showCursor();
    cin >> genGap;
  }

  if (toupper(genGap) == 'W') { //gets info for if the usr wants to write to a file
    cout << "What file would you like to write to?" << endl;
    showCursor(); //gets user input
    cin >> writeFileName;
    ofstream writeFile;
    writeFile.open(writeFileName , ofstream::trunc); // opens the file and makes sure it's empty
    save = true; //sets booleans for write/not write loops
    textSave = false;
    writeFile.close();
  }


  if (toupper(gridChoice) == 'G') { //generates a gird if that's want a user chooses
    playGame->genGridIn(playGame->generateGrid());
  }
  else if (toupper(gridChoice) == 'T') { //reads the grid if that's what a user chooses
    playGame->copyFile(playGame->textRead());
  }
  while(!(save)) { //while looping
    if(toupper(genGap) == 'P') { //if the user chose to pause, sleep
      sleep(3);
    }
    else if(toupper(genGap) == 'E') { //if the user choose to push enter wait for enter
      cin.get();
    }
    cout << "Generation Number: " << genNumber << endl; //prints the generation number
      genNumber++; //incremetns generaton number
      playGame->PrintGrid(); //prints the grid to .out
      playGame->RunMode(); //actually executes the modes
      if(playGame->CheckGens()) { //if the two generations are the same
        if (genNumber == 1) { //either the map is stabilized or it was a bad file
          cout << "If there is no printed grid, that was a bad .txt file." << endl;
          cout << "If there is a printed grid, the map was already stabilized." << endl;
        }
        else { //onces the map stabalizes or is empty goes here
          cout << "If there are 'X's, the map stabalized." << endl;
          cout << "If there are no 'X's, the map is empty." << endl;
        }
        cout << endl;
        cout << "Press 'enter to exit' program." << endl; //IDK why this doesn't work
        cin.get();
        save = true; //makes us stop looping
      }
    }

while(!textSave) { //loop for writing to a file
  if(toupper(genGap) == 'W') {
    ofstream writeFile;
    writeFile.open(writeFileName , ofstream::app); //allows user to append grids
    writeFile << "Generation Number: " << genNumber << endl; //prints the generation number to the file
    playGame->PrintToFile(writeFile); //appends grid to the file
    writeFile.close();
  }
  genNumber++;
  playGame->RunMode(); //actually runs the mode
  if(playGame->CheckGens()) { //if the two generations are the same
    if (genNumber == 1) { //either the map is stabilized or it was a bad file
      cout << "If there is no printed grid, that was a bad .txt file." << endl;
      cout << "If there is a printed grid, the map was already stabilized." << endl;
    }
    cout << endl;
    cout << "Press 'enter' to exit program." << endl; //IDK why this doesn't work
    cin.get();
    textSave = true; //makes us stop looping
  }
}
return 0;
}
