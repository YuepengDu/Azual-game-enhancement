#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "Player.h"
#include "Factory.h"
#include "Mosaic.h"
#include "Game.h"
#include "LinkedList.h"

using namespace std;
void displayMenu();

Player* player = new Player();
Factory* factories = new Factory();
Mosaic* mosaics = new Mosaic();
Game g;

//MAIN
int main(int argc, char** argv) {
	if (argc > 1) {
		if (0 == strcmp(argv[1], "-s")) {
			unsigned int seed = stoi(argv[2]);
			factories->setShuffle(true);
			factories->setRandomseed(seed);
		}
		if (0 == strcmp(argv[1], "--adv")) {
			mosaics->setAdvanceMode(true);
			player->setAdvanceMode(true);
			factories->setAdvanceMode(true);
			g.setAdvanceMode(true);
		}
	}
	displayMenu();

	system("pause");
}

//MENU
void displayMenu() {
	int choice;
	string name1;
	string name2;

	string factory[6][6];

	string mosaic[10][10];
	string mosaic2[10][10];

	string mosaic_square[10][10];
	string mosaic_square2[10][10];

	string fileName;

	bool gameOn = true;
	while (gameOn != false) {
		std::cout << "Welcome to Azul!" << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "Menu " << std::endl;
		std::cout << "----" << std::endl;
		std::cout << "1. New Game" << std::endl;
		std::cout << "2. Load Game" << std::endl;
		std::cout << "3. Credits (Show student information)" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << " " << std::endl;
		std::cout << ">" << " ";
		std::cin >> choice;

		switch (choice) {
		case 1:
		{
			std::cout << "Starting a New Game" << std::endl;
			std::cout << " " << std::endl;
			std::cout << "Enter a name for player 1" << std::endl;
			std::cout << ">" << " ";
			std::cin >> name1;
			player->setPlayer1(name1);

			std::cout << " " << std::endl;
			std::cout << "Enter a name for player 2" << std::endl;
			std::cout << ">" << " ";
			std::cin >> name2;
			player->setPlayer2(name2);

			std::cout << " " << std::endl;
			std::cout << "Let's Play!" << std::endl;

			mosaics->execute(mosaic, mosaic_square);
			mosaics->execute(mosaic2, mosaic_square2);

			g.getFactories(factories);
			g.getMosaics(mosaics);

			g.readRound(player, factory, mosaic, mosaic2, mosaic_square, mosaic_square2, 1, 0, 0);


		}
		break;
		case 2: {
			std::cout << "Enter the filename from which load a game" << std::endl;
			std::cout << ">" << " ";
			std::cin >> fileName;
			std::cout << " " << std::endl;
			std::cout << "Azul game successfully loaded" << std::endl;
			std::cout << "" << std::endl;

			ifstream ifile(fileName);
			string Line;
			string factory[6];
			string turn[100];

			int count = 0;
			int count2 = 0;
			int count3 = 0;
			if (ifile.is_open()) {
				while (getline(ifile, Line)) {
					if (Line.length() == 21) {
						factory[count] = Line;
						count++;
					}
					else
					{
						for (int i = 0; i < Line.length(); i++) {
							if ((i == 0) && (Line[i] == 't') && (Line[i + 1] == 'u') && (Line[i + 2] == 'r') && (Line[i + 3] == 'n') && (Line[i + 4] == ' ')) {
								turn[count2] = Line;
								count2++;
								break;
							}
							else
							{
								if (count3 == 0) {
									player->setPlayer1(Line);
									count3++;
									break;
								}
								else {
									player->setPlayer2(Line);
									break;
								}
							}
						}
					}
				}

			}

			g.getFactories(factories);
			g.getMosaics(mosaics);
			g.load(player, factory, turn);
			ifile.close();
		}
		break;
		case 3:
			std::cout << "-------------------------" << std::endl;
			std::cout << "Name: <Phan Gia Bao Le>" << std::endl;
			std::cout << "Student ID: <s3688102>" << std::endl;
			std::cout << "Email: <s3688102@student.rmit.edu.au>" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "Name: <Thong Nguyen>" << std::endl;
			std::cout << "Student ID: <s3769688>" << std::endl;
			std::cout << "Email: <s3769688@student.rmit.edu.au>" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "Name: <Yuepeng Du>" << std::endl;
			std::cout << "Student ID: <s3698728>" << std::endl;
			std::cout << "Email: <s3698728@student.rmit.edu.au>" << std::endl;
			std::cout << "" << std::endl;

			break;
		case 4:
			std::cout << "End of the Game !" << std::endl;
			gameOn = false;
			break;

		default:
			std::cout << "Not a Valid Choice!!!" << std::endl;
			std::cout << "Choose again, please!" << std::endl;
			std::cin >> choice;
			break;
		}
	}

}
