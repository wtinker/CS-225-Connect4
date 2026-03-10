#pragma once
#ifndef INSTRUCTIONS
#define INSTRUCTIONS
using namespace std;
// Instructions file

void printInstructions() {
    cout << "================ CONNECT 4 ================" << endl << endl;
    cout << "Welcome to Connect 4!" << endl;
    cout << "You will be playing against the computer." << endl << endl;
    cout << "YOUR GOAL:" << endl;
    cout << "Be the first player to connect 4 of your pieces in a row." << endl;
    cout << "You can connect pieces: Horizontally, Vertically, or Diagonally" << endl << endl;
    cout << "HOW TO PLAY:" << endl;
    cout << "1. The board has 7 columns and 6 rows." << endl;
    cout << "2. On your turn, enter the column number where you want to drop your piece and then," << endl
         << "   your piece will fall to the lowest available space in that column." << endl;
    cout << "3. The computer will then take its turn." << endl;
    cout << "4. The game ends when someone connects 4 pieces or the board is full." << endl << endl;
    cout << "RULES:" << endl;
    cout << "1. You cannot place a piece in a full column." << endl;
    cout << "2. If you enter an invalid column, you must choose again." << endl << endl;
    cout << "Good luck!!" << endl;
    cout << "===========================================" << endl;
}

#endif // !INSTRUCTIONS