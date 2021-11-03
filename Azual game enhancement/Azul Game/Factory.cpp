#include "Factory.h"
#include <string>
using namespace std;

Factory::Factory() {

}

Factory::~Factory() {

}

void Factory::execute() {

	this->factory[0][0] = "F ";

	if (pattern.empty())	setPattern();

	string line = ""; int cout = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {

			if (j < 3) {
				line = line + pattern[cout++] + " ";
			}
			else line = line + pattern[cout++];

		}
		this->factory[i][i] = line;
		line = "";
	}
}

void Factory::printFac() {
	std::cout << "Factories:" << std::endl;
	for (int i = 0; i <= 5; i++) {
		std::cout << i << ": " << this->factory[i][i] << endl;
	}

}

void Factory::pushFac() {
	storeFac tmpp;
	for (int i = 0; i < 6; i++) {
		tmpp.fac[i][i] = this->factory[i][i];
	}
	this->sFac.push_back(tmpp);
}

void Factory::storingFac(string factory[6][6]) {
	storeFac tmpp;
	for (int i = 0; i < 6; i++) {
		tmpp.fac[i][i] = factory[i][i];
	}
	this->sFac.push_back(tmpp);
}


void Factory::setPattern(const string& s)
{
	string temp = s;
	int size = temp.length();

	//
	if (size < 20) {
		int t = 20 - size;
		for (int i = 0; i < t; i++) {
			unsigned int r = (seed * i + i * i + t) / 3;
			temp += colors[r % colorNum];
		}
	}
	if (isShuffle)	seed = (seed + 7) * 3;

	pattern = temp;
}


void Factory::setPattern()
{
	string temp;
	int n = 20;

	//if (isShuffle)	srand(seed);
	for (int i = 0; i < n; i++) {
		unsigned int r = (seed * i + i * i + n) / 3;
		temp += colors[r % colorNum];
	}

	if (isShuffle)	seed = (seed + 7) * 3;
	pattern = temp;
}
