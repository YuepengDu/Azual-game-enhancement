#include <string>
using namespace std;

class Mosaic {
public:
	Mosaic();
	~Mosaic();

	void execute(string mosaic[10][10], string mosaic_square[10][10]);
	void execute2(string mosaic[10][10]);
	void setAdvanceMode(bool t) { is6Tile = t; offset = 1; }
private:
	bool is6Tile = false;
	int offset = 0;
	//string mactory[6][6];
};

#pragma once
