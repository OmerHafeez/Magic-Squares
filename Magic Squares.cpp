#include<iostream>
using namespace std;

void display_board(char** board, int rows, int columns);
void fill_the_board (char** board, int rows, int columns);

int main ()
{
    int rows, columns;
    cout << "Enter the number of rows: " << endl;
    cin >> rows;
    columns=rows;
    
    // Allocating memory for the board
    char** board = new char*[rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new char[columns];
    }
    
    // Initializing the board with '_' characters
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = '_';
        }
    }
    
    fill_the_board(board, rows, columns);
   
    
    // Deallocating the memory
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;
    
    return 0;
}

void display_board(char** board, int rows, int columns)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << int(board[i][j]) << "  ";
        }
        cout << endl;
    }
}

void fill_the_board (char** board, int rows, int columns)
{
    char num = 1;
    int R = 0;
    int C = (columns / 2);
    
    int total = rows * columns;
    board[R][C] = num;
    
    for (int i = 0; i < total - 1; i++) 
	{
        R--;
        C++;
        if (R < 0) {
            R = rows - 1;
        }
        if (C == columns) {
            C = 0;
        }
        if (board[R][C] != '_')
		{
            R = (R + 1) % rows;
            C = (C - 1 + columns) % columns;
        }
        if (board[R][C] != '_')
        {
        	R++;
		}
        board[R][C] = ++num;
    }
    
     display_board(board, rows, columns);
}
