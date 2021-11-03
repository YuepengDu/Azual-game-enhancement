#include "Mosaic.h"
#include <string>
using namespace std;

Mosaic::Mosaic() {

}

Mosaic::~Mosaic() {

}
void Mosaic::execute(string mosaic[10][10], string mosaic_square[10][10]) {
	string line = "";

	for (int i = 1; i <= 5 + offset; i++) {
		for (int j = 1; j <= 5 + offset - i; j++) {
			line = line + "  ";
		}
		for (int z = 1; z <= i; z++) {
			line = line + ". ";
		}
		mosaic[i][i] = line;
		line = "";
	}

	string line2 = "";
	for (int i = 1; i <= 5 + offset; i++) {
		for (int j = 1; j <= 5 + offset; j++) {
			line2 = line2 + ". ";
		}
		mosaic_square[i][i] = line2;
		line2 = "";
	}
}
void Mosaic::execute2(string mosaic[10][10]) {
	string line = "";

	for (int i = 1; i <= 5 + offset; i++) {
		for (int j = 1; j <= 5 - i; j++) {
			line = line + "  ";
		}
		for (int z = 1; z <= i + offset; z++) {
			line = line + ". ";
		}
		mosaic[i ][i] = line;
		line = "";
	}
}
