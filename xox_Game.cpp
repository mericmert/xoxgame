#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<char>> infraOfBoard() {
	vector<vector<char>> board;
	vector<char> rows = { ' ', ' ',' ' };
	for (int i = 0; i < 3; i++)
	{
		board.push_back(rows);
	}
	
	return board;
}

void drawGameBoard(vector<vector<char>> board) {
	for (int i = 0; i < board.size(); i++) {
		cout << "-----------------" << endl;
		for (int k = 0; k < board.size(); k++) {
			cout << "| " << board[i][k] <<" | ";
		}
		cout << "\n";
	}
	cout << "-----------------" << endl;
}

string getInput(char start, vector<vector<char>> board) {
	string move, row, column;
	while (true) {  // CHECKING FORMAT
		row = "", column = "";
		if (start == 'X') cout << "Player X please enter your move in a {row-column} format: ";
		else { cout << "Player O please enter your move in a {row-column} format: "; }
		getline(cin, move);
		if (move.length() == 3) {
			row += move[0]; column += move[2];
			if (move.length() != 3 || (move[1] != '-' || stoi(row) <= 0) || stoi(row) > 3 || stoi(column) <= 0 || stoi(column) > 3 || board[stoi(row) - 1][stoi(column) - 1] != ' ') {
				cout << "Please enter correct format!" << endl;
			}
			else {
				cout << "You made a move!" << endl;
				break;
			}
		}
	}
	return row + "-" + column;
}

void makeAMove(vector<vector<char>>& board, string inp, char start) {
	
	int row = inp[0] - 48;
	int column = inp[2] - 48;
	if (start == 'X') {
		board[row - 1][column - 1] = 'X';
	}
	else
	{
		board[row - 1][column - 1] = 'O';
	}
}

void moveOfX(vector<vector<char>> & board) {
	string inp;
	drawGameBoard(board);
	inp = getInput('X',board);
	makeAMove(board,inp,'X');
}


void moveOfO(vector<vector<char>> & board) {
	string inp;
	drawGameBoard(board);
	inp = getInput('O',board);
	makeAMove(board, inp, 'O');
}



bool diaganolChecker(vector<vector<char>> board) {
	if (board[1][1] != ' ' && ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
		return true;
	}
	return false;
}
bool sameDirectionChecker(vector<vector<char>> board) {
	
	for (int i = 0; i < board.size(); i++) {
		if (board[i][1] != ' ' && (board[i][0] == board[i][1] && board[i][1] == board[i][2])) {
			return true;
		}
		else if (board[1][i] != ' ' && (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
			return true;
		}
	}
	return false;
}

bool winChecker(vector<vector<char>> board) {
	bool checker = false;
	if (diaganolChecker(board)) {
		checker = true;
	}
	if (sameDirectionChecker(board)) {
		checker = true;
	}

	return checker;
}

int main()
{
	vector<vector<char>> board = infraOfBoard();
	

	
	while (true){
		moveOfX(board);
		if (winChecker(board)) {
			drawGameBoard(board);
			cout << "Player X won!" << endl;
			break;
		}
		moveOfO(board);
		if (winChecker(board)) {
			drawGameBoard(board);
			cout << "Player O won!" << endl;
			break;
		}
	}
	


	return 0;
}


