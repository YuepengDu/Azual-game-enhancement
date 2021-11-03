#ifndef COSC_ASSIGN_TWO_PLAYER
#define COSC_ASSIGN_TWO_PLAYER
#include <string>
#include "LinkedList.h"
#include <vector>

using namespace std;

struct command
{

};

struct turn {
	int factory_line;
	char title_code;
	int storage_row;
};

class Player {
public:
	Player();
	~Player();

	void setPlayer1(string player1);
	void setPlayer2(string player2);

	void setLineSquare(string lineSquare);

	void setMosaic(const string mosaic[10][10]);
	void setMosaic2(const string mosaic[10][10]);

	void setMosaicSquare(const string mosaic_square[10][10]);
	void setMosaicSquare2(const string mosaic_square[10][10]);

	string getPlayer1();
	string getPlayer2();

	string getLineSquare();

	string getMosaic(int i);
	string getMosaic2(int i);

	string getMosaicSquare(int i);
	string getMosaicSquare2(int i);

	// Broken Line
	Linkedlist l1;
	Linkedlist l2;

	void setPlayer1Score(int score);
	void setPlayer2Score(int score);

	int getScore();
	int getScore2();

	// Turn array
	vector <turn> turn_player1;
	vector <turn> turn_player2;

	void setAdvanceMode(bool b) { isAdvance = b; offset = 1; }

private:
	string player1;
	string player2;

	string lineSquare;

	string mosaic[10][10];

	string mosaic_square[10][10];

	int score1;
	int score2;

	bool isAdvance = false;
	int offset = 0;
};
#endif // COSC_ASSIGN_TWO_PLAYER
