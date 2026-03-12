#include "File_Log.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void gameLog(string p1, string winner, int num_moves, int board_final[ROWS][COLUMNS]) {
    time_t current = time(NULL);
    char* date = ctime(&current);
    
    ofstream fileLog("gameRecord.txt", ios::app);

    fileLog << "===== Connect4 Game Info =====" << endl;
    fileLog << "Date: " << date << endl;
    fileLog << "Player One: " << p1 << endl;
    fileLog << "Player Two: Computer" << endl;
    fileLog << "Winner: " << winner << endl;
    fileLog << "Total Moves: " << num_moves << endl;
    fileLog << "Final Board: " << endl << endl;
    for (int i = 0; i < ROWS; i++) {
        fileLog << i + 1 << " | ";

        for (int j = 0; j < COLUMNS; j++) {
            if (board_final[i][j] == 0) {
                fileLog << "* ";
            }
            else if (board_final[i][j] == 1) {
                fileLog << "O ";
            }
            else if (board_final[i][j] == 2) {
                fileLog << "X ";
            }
        }

        fileLog << "|" << endl;
    }
    fileLog << "-------------------" << endl;
    fileLog << "    1 2 3 4 5 6 7 " << endl << endl;
    fileLog << "====== End of Game Info ======" << endl << endl;

    fileLog.close();
}