#include "File_Log.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void gameLog(string p1, string winner, int numMoves, Board boardFinal) {
    /*
    * Name: gameLog
    * Input(s): 
        - p1: Player Name
        - winner: Who won, player or computer
        - numMoves: How many moves back and forth made in the game. 
        - boardFinal: The final layout of the board at either win/loss/tie.
    * Return: void
    * Description: Takes all the game data and appends it to our gameRecord.txt file so that 
    * the player can go back and see how they improved overtime.
    */
    time_t current = time(NULL);
    char* date = ctime(&current);
    
    ofstream fileLog("gameRecord.txt", ios::app);
    if (!fileLog) {
        throw string("Error: could not open gameRecord.txt for appending.");
    }

    fileLog << "===== Connect4 Game Info =====" << endl;
    fileLog << "Date: " << date << endl;
    fileLog << "Player One: " << p1 << endl;
    fileLog << "Player Two: Computer" << endl;
    fileLog << "Winner: " << winner << endl;
    fileLog << "Total Moves: " << numMoves << endl;
    fileLog << "Final Board: " << endl << endl;
    for (int i = 0; i < ROWS; i++) {
        fileLog << i + 1 << " | ";

        for (int j = 0; j < COLUMNS; j++) {
            if (boardFinal.getId(i,j) == 0) {
                fileLog << "* ";
            }
            else if (boardFinal.getId(i,j) == 1) {
                fileLog << "O ";
            }
            else if (boardFinal.getId(i,j) == 2) {
                fileLog << "X ";
            }
        }

        fileLog << "|" << endl;
    }
    fileLog << "+-----------------+" << endl;
    fileLog << "    1 2 3 4 5 6 7 " << endl << endl;
    fileLog << "====== End of Game Info ======" << endl << endl;

    fileLog.close();
}