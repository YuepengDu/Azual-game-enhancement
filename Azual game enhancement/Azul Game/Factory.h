#ifndef COSC_ASSIGN_FACTORY
#define COSC_ASSIGN_FACTORY
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct storeFac {
	string fac[6][6];
};

class Factory {
public:
	Factory();
	~Factory();

	// init the factory with random card
	void execute();

	// print the factory
	void printFac();

	// get factory
	string factory[6][6];

	// store factories
	vector <storeFac> sFac;

	// copy factory
	void pushFac();

	void storingFac(string factory[6][6]);

	void setShuffle(bool s) { isShuffle = s; }
	void setRandomseed(unsigned int seed) { this->seed = seed; }

	void setPattern();
	void setPattern(const string& s);
	void setAdvanceMode(bool b) { isAdvance = b; colorNum = 6; }

	unsigned int getSeed() { return seed; }
private:
	bool isShuffle = false;
	unsigned int seed = 12345;
	string pattern = "";

	bool isAdvance = false;
	int colorNum = 5;

	char colors[6] = { 'R','Y','B','L','U', 'O'};
};
#endif
