#include "Game.h"
using namespace std;

//Execute the Factories and Mosaic for PLAYER ONE once Factory_line, title_code and storage_row are inputed by user ONE
void Game::processFactory_Mosaic(Player* player, string factory[6][6], string mosaic[10][10], int factory_line, char title_code, int storage_row) {
	string lineFactory = "";
	string lineMosaic = "";
	string lineBroken = "";

	turn tmpp;
	tmpp.factory_line = factory_line;
	tmpp.storage_row = storage_row;
	tmpp.title_code = title_code;
	player->turn_player1.push_back(tmpp);

	int count = 0;
	int countTotal = 0;

	for (int i = 0; i <= 5 ; i++) {
		if (factory_line == 0) {
			lineBroken = factory[0][0];
			for (int j = 0; j < lineBroken.length(); j++) {
				if (lineBroken[j] == 'F') {
					// insert F into broken line
					player->l1.insertTail(lineBroken[j]);
					// remove F from line 0
					lineBroken.erase(j, 1);
					// refresh line 0
					factory[0][0] = lineBroken;
					break;
				}
			}
		}
		if (i == factory_line) {
			lineFactory = factory[i][i];
			factory[i][i] = "";
			if (storage_row != 0)
				lineMosaic = mosaic[storage_row][storage_row];
			// 3 B 0 => adding B to Broken line
			if (storage_row == 0)
				lineMosaic = "&";

			break;
			//
		}
	}
	for (int i = 0; i < lineFactory.length(); i++) {
		if (lineFactory[i] == title_code) {
			countTotal++;
		}
		if (lineFactory[i] != ' ') {
			for (int j = lineMosaic.length() - 1; j >= 0; j--) {
				if ((lineFactory[i] != title_code) && (lineFactory[i] != ' ')) {
					factory[0][0] = factory[0][0] + lineFactory[i] + " ";
					break;
				}
				// 3 B 0 => adding B to Broken line
				if ((lineFactory[i] == title_code) && (lineMosaic[j] == '&')) {
					player->l1.insertTail(title_code);
					lineFactory[i] = ' ';
				}
				//
				if ((lineFactory[i] == title_code) && (lineMosaic[j] == '.')) {
					lineMosaic[j] = title_code;
					lineFactory[i] = ' ';
					count++;
				}
			}
		}

	}
	//
	if (countTotal > count && storage_row != 0) {
		for (int i = 1; i <= (countTotal - count); i++) {
			player->l1.insertTail(title_code);
		}
	}

	if (storage_row != 0)
		mosaic[storage_row][storage_row] = lineMosaic;
}

//Execute the Factories and Mosaic for PLAYER TWO once Factory_line, title_code and storage_row are inputed by user TWO
void Game::processFactory_Mosaic2(Player* player, string factory[6][6], string mosaic[10][10], int factory_line, char title_code, int storage_row) {
	string lineFactory = "";
	string lineMosaic = "";
	string lineBroken = "";

	turn tmpp;
	tmpp.factory_line = factory_line;
	tmpp.storage_row = storage_row;
	tmpp.title_code = title_code;
	player->turn_player2.push_back(tmpp);

	int count = 0;
	int countTotal = 0;

	for (int i = 0; i <= 5; i++) {
		if (factory_line == 0) {
			lineBroken = factory[0][0];
			for (int j = 0; j < lineBroken.length(); j++) {
				if (lineBroken[j] == 'F') {
					player->l2.insertTail(lineBroken[j]);
					lineBroken.erase(j, 1);
					factory[0][0] = lineBroken;
					break;
				}
			}
		}
		if (i == factory_line) {
			lineFactory = factory[i][i];
			factory[i][i] = "";
			if (storage_row != 0)
				lineMosaic = mosaic[storage_row][storage_row];
			// 3 B 0 => adding B to Broken line
			if (storage_row == 0)
				lineMosaic = "&";
			break;
			//
		}
	}
	for (int i = 0; i < lineFactory.length(); i++) {
		if (lineFactory[i] == title_code) {
			countTotal++;
		}
		if (lineFactory[i] != ' ') {
			for (int j = lineMosaic.length() - 1; j >= 0; j--) {
				if ((lineFactory[i] != title_code) && (lineFactory[i] != ' ')) {
					factory[0][0] = factory[0][0] + lineFactory[i] + " ";
					break;
				}
				// 3 B 0 => adding B to Broken line
				if ((lineFactory[i] == title_code) && (lineMosaic[j] == '&')) {
					player->l2.insertTail(title_code);
					lineFactory[i] = ' ';
				}
				if ((lineFactory[i] == title_code) && (lineMosaic[j] == '.')) {
					lineMosaic[j] = title_code;
					lineFactory[i] = ' ';
					count++;
				}
			}
		}
	}
	if (countTotal > count && storage_row != 0) {
		for (int i = 1; i <= (countTotal - count); i++) {
			player->l2.insertTail(title_code);
		}
	}
	if (storage_row != 0)
		mosaic[storage_row][storage_row] = lineMosaic;
}

//A part of Executing from Rectangle to Square
void Game::checkSquare(Player* player, string lineSquare, int position, char color, string mosaic_square[10][10], int &score, int lineS) {
	int count = 0;
	int newPos = 0;
	for (int i = 0; i < lineSquare.length(); i++) {
		if (lineSquare[i] != ' ') count++;
		if (count == position && lineSquare[i] == '.') {
			lineSquare[i] = color;

			this->Cal_score(score, mosaic_square, i, lineS);

			player->setLineSquare(lineSquare);
			break;
		}
	}
}

//Executing from Rectangle to Square Mosaic
void Game::processRectagle_Square(Player* player, string mosaic[10][10], string mosaic_square[10][10], int &score) {
	string lineSquare = "";
	string lineMosaic = "";
	string mosaicClone[10][10];

	mosaics->execute2(mosaicClone);

	for (int i = 1; i <= 5 + offset; i++) {
		lineSquare = mosaic_square[i][i];
		int count = 0;
		for (int j = 1; j <= 5 + offset; j++) {
			lineMosaic = mosaic[j][j];
			if (i == j) {
				for (int z = 0; z < lineMosaic.length(); z++) {
					//Dark Blue
					if (lineMosaic[z] == 'B') {
						count++;
						if (count == j) {
							putTileToBoxlid("B", j - 1);
							int pos = i;
							checkSquare(player, lineSquare, pos, lineMosaic[z], mosaic_square, score, i);
							mosaic_square[i][i] = player->getLineSquare();
							mosaic[j][j] = mosaicClone[j][j];
							break;
						}
					}
					else
						//Yellow
						if (lineMosaic[z] == 'Y') {
							count++;
							if (count == j) {
								putTileToBoxlid("Y", j - 1);
								int pos;
								if ((i + 1) > 5 + offset) {
									pos = i - 4 - offset;
								}
								else
									pos = i + 1;

								checkSquare(player, lineSquare, pos, lineMosaic[z], mosaic_square, score, i);
								mosaic_square[i][i] = player->getLineSquare();
								mosaic[j][j] = mosaicClone[j][j];
								break;
							}
						}
						else
							//Red
							if (lineMosaic[z] == 'R') {
								count++;
								if (count == j) {
									putTileToBoxlid("R", j - 1);
									int pos;
									if ((i + 2) > 5 + offset) {
										pos = i - 3 - offset;
									}
									else
										pos = i + 2;
									checkSquare(player, lineSquare, pos, lineMosaic[z], mosaic_square, score, i);
									mosaic_square[i][i] = player->getLineSquare();
									mosaic[j][j] = mosaicClone[j][j];
									break;
								}
							}
							else
								//Black
								if (lineMosaic[z] == 'U') {
									count++;
									if (count == j) {
										putTileToBoxlid("U", j - 1);
										int pos;
										if ((i + 3) > 5 + offset) {
											pos = i - 2 - offset;
										}
										else
											pos = i + 3;
										checkSquare(player, lineSquare, pos, lineMosaic[z], mosaic_square, score, i);
										mosaic_square[i][i] = player->getLineSquare();
										mosaic[j][j] = mosaicClone[j][j];
										break;
									}
								}
								else
									//Light Blue
									if (lineMosaic[z] == 'L') {
										count++;
										if (count == j) {
											putTileToBoxlid("L", j - 1);
											int pos;
											if ((i + 4) > 5 + offset) {
												pos = i - 1 - offset;
											}
											else
												pos = i + 4;

											checkSquare(player, lineSquare, pos, lineMosaic[z], mosaic_square, score, i);
											mosaic_square[i][i] = player->getLineSquare();
											mosaic[j][j] = mosaicClone[j][j];
											break;
										}
									}
				}
			}
		}
	}
}

//Execute 5 ROUNDS - EACH ROUND needs to finish all turns and all tiles are taken
void Game::readRound(Player* player, string factory_load[6][6], string mosaic[10][10], string mosaic2[10][10], string mosaic_square[10][10], string mosaic_square2[10][10], int round, int scoreForPlayer1, int scoreForPlayer2) {

	//int scoreForPlayer1 = 0;
	//int scoreForPlayer2 = 0;

	int factory_line, storage_row;
	char title_code;
	string row;
	int checkPl = 0;
	int count = 0;
	int count2 = 0;
	string cmd, fileName;


	while (round <= 5) {
		bool turn = true;
		if (count == -1) {
			count = 0;
			count2 = -1;
		}
		if (count2 == 0) {
			for (int i = 0; i <= 5; i++) {
				string line = factory_load[i][i];
				for (int j = 0; j < line.length(); j++) {
					if (line[j] != ' ') {
						count = -1;
						break;
					}
				}
				if (count == -1) break;
			}
		}

		if (count == 0) {
			this->factories->execute();
			this->factories->pushFac();
		}
		std::cout << "=== Start Round " << round << " ===" << endl;

		//Turns between 2 Players
		while (turn) {
			if (checkPl == 0) {
				std::cout << " " << std::endl;
				std::cout << "TURN FOR PLAYER: " << player->getPlayer1() << endl;
				if (count == 0) {
					this->factories->printFac();
				}
				else {
					std::cout << "Factories:" << std::endl;
					for (int i = 0; i <= 5; i++) {
						std::cout << i << ": " << factory_load[i][i] << endl;
					}
				}

				std::cout << " " << std::endl;
				std::cout << "Mosaic for " << player->getPlayer1() << ":" << endl;

				for (int i = 1; i <= 5 + offset; i++) {
					std::cout << i << ": " << mosaic[i][i] << "|| " << mosaic_square[i][i] << endl;
				}
				// broken line here
				std::cout << "broken: ";
				player->l1.printList();
				std::cout << endl;

				// Input command here
				cout << "> ";
				cin >> cmd;

				this->Check_cmd(cmd);

				if (cmd == "save") {
					cin >> fileName;
					this->save(fileName, player);
					cout << "> ";
					cin >> cmd;
					this->Check_cmd(cmd);
				}
				if (cmd == "turn") {
					std::cin >> factory_line >> title_code >> storage_row;

					if (count == 0) {
						// Check turn input here
						while (this->check_input_turn(factory_line, title_code, storage_row) == false || this->check_empty_line_F(factory_line) == false ||
							this->check_same_color(title_code, storage_row, mosaic) == false ||
							this->check_square_mosaic(factory_line, title_code, storage_row, mosaic_square) == false ||
							this->check_line_0(factory_line, title_code) == false ||
							this->check_color_in_factory(factory_line, title_code) == false)
						{
							std::cout << "Invalid input, please input again" << std::endl;
							std::cout << "> turn" << " ";
							std::cin >> factory_line >> title_code >> storage_row;
						}
						processFactory_Mosaic(player, this->factories->factory, mosaic, factory_line, title_code, storage_row);
					}
					else {
						// Check turn input here
						while (this->check_input_turn(factory_line, title_code, storage_row) == false || this->check_empty_line_F_Load(factory_load,factory_line) == false ||
							this->check_same_color(title_code, storage_row, mosaic) == false ||
							this->check_square_mosaic(factory_line, title_code, storage_row, mosaic_square) == false ||
							this->check_line_0_Load(factory_line, title_code, factory_load) == false ||
							this->check_color_in_factory_Load(factory_load, factory_line, title_code) == false)
						{
							std::cout << "Invalid input, please input again" << std::endl;
							std::cout << "> turn" << " ";
							std::cin >> factory_line >> title_code >> storage_row;
						}
						processFactory_Mosaic(player, factory_load, mosaic, factory_line, title_code, storage_row);
					}

					std::cout << "Turn successful." << endl;

					//Check when all titles are taken, GO TO NEXT ROUND
					string checkLine = ""; bool check = true;
					for (int i = 0; i <= 5; i++) {
						if (count == 0) {
							checkLine = this->factories->factory[i][i];
						} else checkLine = factory_load[i][i];

						for (int j = 0; j < checkLine.length(); j++) {
							if (checkLine[j] != ' ') {
								check = false;
								break;
							}
						}
						if (!check) break;
					}
					if (check) {
						checkPl = 1;
						break;
					}
				}

			}

			checkPl = 0;

			std::cout << " " << std::endl;
			//	std::cout << "================" << std::endl;
			std::cout << "TURN FOR PLAYER: " << player->getPlayer2() << endl;

			if (count == 0) {
				this->factories->printFac();
			}
			else {
				std::cout << "Factories:" << std::endl;
				for (int i = 0; i <= 5; i++) {
					std::cout << i << ": " << factory_load[i][i] << endl;
				}
			}

			std::cout << " " << std::endl;
			std::cout << "Mosaic for " << player->getPlayer2() << ":" << endl;
			for (int i = 1; i <= 5; i++) {
				std::cout << i << ": " << mosaic2[i][i] << "|| " << mosaic_square2[i][i] << endl;
			}
			// broken line here
			std::cout << "broken: ";
			player->l2.printList();
			std::cout << endl;

			// Input turn here
			cout << "> ";
			cin >> cmd;

			this->Check_cmd(cmd);

			if (cmd == "save") {
				cin >> fileName;
				this->save(fileName, player);
				cout << "> ";
				cin >> cmd;
				this->Check_cmd(cmd);
			}
			if (cmd == "turn") {
				std::cin >> factory_line >> title_code >> storage_row;

				if (count == 0) {
					// Check turn input here
					while (this->check_input_turn(factory_line, title_code, storage_row) == false || this->check_empty_line_F(factory_line) == false ||
						this->check_same_color(title_code, storage_row, mosaic2) == false ||
						this->check_square_mosaic(factory_line, title_code, storage_row, mosaic_square2) == false ||
						this->check_line_0(factory_line, title_code) == false ||
						this->check_color_in_factory(factory_line, title_code) == false)
					{
						std::cout << "Invalid input, please input again" << std::endl;
						std::cout << "> turn" << " ";
						std::cin >> factory_line >> title_code >> storage_row;
					}
					processFactory_Mosaic2(player, this->factories->factory, mosaic2, factory_line, title_code, storage_row);
				}
				else {
					// Check turn input here
					while (this->check_input_turn(factory_line, title_code, storage_row) == false || this->check_empty_line_F_Load(factory_load, factory_line) == false ||
						this->check_same_color(title_code, storage_row, mosaic2) == false ||
						this->check_square_mosaic(factory_line, title_code, storage_row, mosaic_square2) == false ||
						this->check_line_0_Load(factory_line, title_code, factory_load) == false ||
						this->check_color_in_factory_Load(factory_load, factory_line, title_code) == false)
					{
						std::cout << "Invalid input, please input again" << std::endl;
						std::cout << "> turn" << " ";
						std::cin >> factory_line >> title_code >> storage_row;
					}
					processFactory_Mosaic2(player, factory_load, mosaic2, factory_line, title_code, storage_row);
				}

				std::cout << "Turn successful." << endl;

				//Check when all titles are taken, GO TO NEXT ROUND
				string checkLine2 = ""; bool check2 = true;
				for (int i = 0; i <= 5; i++) {
					if (count == 0) {
						checkLine2 = this->factories->factory[i][i];
					} else checkLine2 = factory_load[i][i];

					for (int j = 0; j < checkLine2.length(); j++) {
						if (checkLine2[j] != ' ') {
							check2 = false;
							break;
						}
					}
					if (!check2) break;
				}
				if (check2) turn = false;
			}
			std::cout << " " << endl;
			// Input command here
			cout << "> save ";
			cin >> fileName;
			this->save(fileName, player);
		}
		std::cout << "=== END OF ROUND ===" << endl;

		//Process Score for 2 Players



		processRectagle_Square(player, mosaic, mosaic_square, scoreForPlayer1);
		processRectagle_Square(player, mosaic2, mosaic_square2, scoreForPlayer2);

		//put tiles from boxlid to bag, then set factory's pattern, update the factory in next step
		factories->setPattern(putToTileBag());
		factories->execute();
		factory_load = factories->factory;

		this->Cal_score_BL(player, scoreForPlayer1, scoreForPlayer2);
		player->setPlayer1Score(scoreForPlayer1);
		player->setPlayer2Score(scoreForPlayer2);

		std::cout << endl << "Player " << player->getPlayer1() << " score: " << player->getScore() << endl;
		std::cout << endl << "Player " << player->getPlayer2() << " score: " << player->getScore2() << endl;
		std::cout << " " << endl;
		round++;
	}



	//print scores
	std::cout << "=== GAME OVER ===" << endl;
	std::cout << endl;
	std::cout << "Final Scores: " << endl;
	std::cout << "Player " << player->getPlayer1() << ": " << player->getScore() << endl;
	std::cout << "Player " << player->getPlayer2() << ": " << player->getScore2() << endl;
	if (player->getScore() > player->getScore2()) {
		std::cout << "Player " << player->getPlayer1() << " wins" << endl;
	}
	else if (player->getScore2() > player->getScore()) {
		std::cout << "Player " << player->getPlayer2() << " wins" << endl;
	}
	else {
		std::cout << "Nobody wins, it's tie" << endl;
	}
	std::cout << " " << endl;
}


void Game::getFactories(Factory *f) {
	this->factories = f;
}

void Game::getMosaics(Mosaic *m) {
	this->mosaics = m;
}

void Game::putTileToBoxlid(const string& tile, int n)
{

	for (int j = 1; j <= n; j++) {
		int i = (factories->getSeed() + j) * (j + 1)  % 2;
		if (i)
			boxLid.push_front(tile);
		else
			boxLid.push_back(tile);
	}
}

string Game::getTileFormBoxlid()
{
	if (boxLid.empty())	return "";


	unsigned int i = (factories->getSeed() + 3) * 3 % 2;

	string t;
	if (i) {
		t = boxLid.front();
		boxLid.pop_front();
	}
	else {
		t = boxLid.back();
		boxLid.pop_back();
	}
	return t;
}


std::string Game::putToTileBag()
{
	string tileBag = "";

	while (!boxLid.empty()) {
		tileBag += getTileFormBoxlid();
	}
	return tileBag;
}



bool Game::check_input_turn(int factory_line, char title_code, int storage_row) {
	if (factory_line > 5 || factory_line < 0)
		return false;
	if (storage_row > 5 + offset || storage_row < 0)
		return false;
	if (title_code != 'R' && title_code != 'Y' && title_code != 'B' && title_code != 'L' && title_code != 'U')
		return false;
	return true;
}

bool Game::check_same_color(char title_code, int storage_row, string m[10][10]) {
	string st_tmp = m[storage_row][storage_row];
	int counter = 0;
	for (int i = 0; i < m[storage_row][storage_row].length(); i++) {
		if (st_tmp[i] != 'R' && st_tmp[i] != 'Y' &&
			st_tmp[i] != 'B' && st_tmp[i] != 'L' &&
			st_tmp[i] != 'U' ) {
			if (isAdvanceMode && st_tmp[i] == 'O')	continue;
			counter++;
		}

	}
	if (counter == m[storage_row][storage_row].length())
		return true;
	for (int i = 0; i < m[storage_row][storage_row].length(); i++) {
		if (title_code == st_tmp[i]) {
			return true;
		}
	}
	return false;
}

bool Game::check_empty_line_F(int factory_line) {
	if (this->factories->factory[factory_line][factory_line] == "")
		return false;
	return true;
}
bool Game::check_empty_line_F_Load(string factory[6][6], int factory_line) {
	if (factory[factory_line][factory_line] == "")
		return false;
	return true;
}

bool Game::check_square_mosaic(int factory_line, char title_code, int storage_row, string mosaic_square[10][10]) {
	for (int i = 1; i <= 5 + offset; i++) {
		for (int j = 0; j < mosaic_square[storage_row][i].length(); j++) {
			if (title_code == mosaic_square[storage_row][i][j]) {
				return false;
			}
		}

	}
	return true;
}

bool Game::check_line_0(int factory_line, char title_code) {
	if (factory_line == 0) {
		for (int i = 0; i < this->factories->factory[0][0].length(); i++) {
			if (title_code == this->factories->factory[0][0][i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

bool Game::check_line_0_Load(int factory_line, char title_code, string factory[6][6]) {
	if (factory_line == 0) {
		for (int i = 0; i < factory[0][0].length(); i++) {
			if (title_code == factory[0][0][i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

bool Game::check_color_in_factory(int factory_line, char title_code) {
	for (int i = 0; i < this->factories->factory[factory_line][factory_line].length(); i++) {
		if (title_code == this->factories->factory[factory_line][factory_line][i]) {
			return true;
		}
	}
	return false;
}

bool Game::check_color_in_factory_Load(string factory[6][6], int factory_line, char title_code) {
	for (int i = 0; i < factory[factory_line][factory_line].length(); i++) {
		if (title_code == factory[factory_line][factory_line][i]) {
			return true;
		}
	}
	return false;
}

void Game::save(string nameFile, Player* player) {
	ofstream myfile;
	myfile.open(nameFile);

	vector<storeFac>::iterator itF = this->factories->sFac.begin();
	while (itF!=this->factories->sFac.end()) {

		storeFac tmpp = *itF;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < tmpp.fac[i][i].length(); j++)
			{
				if (tmpp.fac[i][i][j] != ' ') {
					myfile << tmpp.fac[i][i][j];
				}
			}
		}
		myfile << "\n";
		itF++;
	}

	myfile << player->getPlayer1() << "\n";
	vector<turn>::iterator it1 = player->turn_player1.begin();

	myfile << player->getPlayer2() << "\n";
	vector<turn>::iterator it2 = player->turn_player2.begin();

	while (it1 != player->turn_player1.end() &&
		it2 != player->turn_player2.end()) {

		myfile << "turn ";
		turn tmpp1 = *it1;
		myfile << tmpp1.factory_line << " " << tmpp1.title_code << " " << tmpp1.storage_row << "\n";

		myfile << "turn ";
		turn tmpp2 = *it2;
		myfile << tmpp2.factory_line << " " << tmpp2.title_code << " " << tmpp2.storage_row << "\n";

		it1++;
		it2++;
	}
	if (player->turn_player1.size() > player->turn_player2.size()) {
		myfile << "turn ";
		turn tmpp1 = *it1;
		myfile << tmpp1.factory_line << " " << tmpp1.title_code << " " << tmpp1.storage_row << "\n";
	}
	cout << " " << endl;
	cout << "Game successfully saved to '" << nameFile << "'" << endl;
	myfile.close();
}

void Game::load(Player* player, string factories[6], string turns[100]) {
	string line = "";
	string line2 = "";
	string lineTurn = "";
	string clone = "";

	string mosaic[10][10];
	string mosaic_square[10][10];

	string mosaic2[10][10];
	string mosaic_square2[10][10];

	int count = 0;
	int count2 = 0;
	int count3 = 0;

	int factory_line, storage_row;
	char title_code;
	bool turn = true;
	string factory[6][6];

	int scoreForPlayer1 = 0;
	int scoreForPlayer2 = 0;

	mosaics->execute(mosaic, mosaic_square);
	mosaics->execute(mosaic2, mosaic_square2);

	for (int i = 0; i < 6; i++) {
		line = factories[i]; int position = 0; line2 = ""; bool turn = true;
		if (line == "") break;
		for (int j = 0; j < 6; j++) {
			for (int z = position; z < line.length(); z++) {
				if (line[z] == 'F') {
					factory[j][j] = factory[j][j] + line[z] + " ";
					position = z + 1;
					break;
				}
				else
				{
					line2 = line2 + line[z] + " ";
					count++;
					if (count == 4) {
						factory[j][j] = line2;
						line2 = "";
						count = 0;
						position = z + 1;
						break;
					}
				}
			}
		}
		this->factories->storingFac(factory);
		while (turn) {
			lineTurn = turns[count2];
			if (lineTurn == "") break;
			count3 = 0;
			for (int j = 0; j < lineTurn.length(); j++) {
				if (lineTurn[j] == ' ') {
					clone = clone + lineTurn[j + 1];
					if (count3 == 0) {
						factory_line = stoi(clone);
						clone = "";
						count3++;
					}
					else
						if (count3 == 1) {
							title_code = lineTurn[j + 1];
							clone = "";
							count3++;
						}
						else
							if (count3 == 2) {
								storage_row = stoi(clone);
								clone = "";
								count3++;
							}
				}
			}
			if ((count2 == 0) || (count2 % 2 == 0)) {
				processFactory_Mosaic(player, factory, mosaic, factory_line, title_code, storage_row);
			}
			else processFactory_Mosaic2(player, factory, mosaic2, factory_line, title_code, storage_row);
			//Check when all titles are taken, GO TO NEXT ROUND
			string checkLine = ""; bool check = true;
			for (int i = 0; i <= 5; i++) {
				checkLine = factory[i][i];
				for (int j = 0; j < checkLine.length(); j++) {
					if (checkLine[j] != ' ') {
						check = false;
						break;
					}
				}
				if (!check) break;
			}
			if (check) turn = false;
			count2++;
		}
		if (!turn) {
			processRectagle_Square(player, mosaic, mosaic_square, scoreForPlayer1);
			processRectagle_Square(player, mosaic2, mosaic_square2, scoreForPlayer2);

			this->Cal_score_BL(player, scoreForPlayer1, scoreForPlayer2);
			player->setPlayer1Score(scoreForPlayer1);
			player->setPlayer2Score(scoreForPlayer2);
		}
		else readRound(player, factory, mosaic, mosaic2, mosaic_square, mosaic_square2, i + 1, scoreForPlayer1, scoreForPlayer2);
	}
}
bool Game::Check_cmd(string &cmd) {
	while (cmd != "save" && cmd != "turn") {

		if (cmd == "place" && isAdvanceMode)	return true;

		if (cmd == "\x4") {
			cout << "Goodbye" << endl;
			exit(0);
		}
		else {
			cout << "Invalid Input" << endl;
			cout << "> ";
			cin >> cmd;
		}
	}
	return true;
}

void Game::Cal_score_BL(Player* player, int &score1, int &score2) {
	for (int i = 0; i < player->l1.GetSize(); i++) {
		if (i == 0 || i == 1) {
			score1 = score1 - 1;
		}
		if (i == 2 || i == 3 || i == 4) {
			score1 = score1 - 2;
		}
		if (i == 5 || i == 6) {
			score1 = score1 - 3;
		}
		if (i == 7) {
			score1 = score1 - 4;
		}
	}
	player->l1.Clear_List();
	for (int i = 0; i < player->l2.GetSize(); i++) {
		if (i == 0 || i == 1) {
			score2 = score2 - 1;
		}
		if (i == 2 || i == 3 || i == 4) {
			score2 = score2 - 2;
		}
		if (i == 5 || i == 6) {
			score2 = score2 - 3;
		}
		if (i == 7) {
			score2 = score2 - 4;
		}
	}
	player->l2.Clear_List();
}

void Game::Cal_score(int &score, string mosaic_square[10][10], int position, int lineS) {
	int point = 1;
	int counter = 0;
	int j = position;


	while (j <= mosaic_square[lineS][lineS].length()) {
		if (j == mosaic_square[lineS][lineS].length()) {
			j = j + 2;
		}
		else {
			if (mosaic_square[lineS][lineS][j + 2] == 'B' || mosaic_square[lineS][lineS][j + 2] == 'Y' ||
				mosaic_square[lineS][lineS][j + 2] == 'R' ||
				mosaic_square[lineS][lineS][j + 2] == 'U' || mosaic_square[lineS][lineS][j + 2] == 'L'
				|| mosaic_square[lineS][lineS][j + 2] == 'O') {
				if (counter == 0) {
					counter = 1;
				}
				else {
					if (counter >= 1) {
						counter++;
					}
				}
				point++;
			}
			else {
				counter = 0;
				break;
			}
			j = j + 2;
		}
	}
	j = position;
	counter = 0;
	while (j >= 0) {
		if (j == 0) {
			j = j - 2;
		}
		else {
			if (mosaic_square[lineS][lineS][j - 2] == 'B' || mosaic_square[lineS][lineS][j - 2] == 'Y' ||
				mosaic_square[lineS][lineS][j - 2] == 'R' ||
				mosaic_square[lineS][lineS][j - 2] == 'U' || mosaic_square[lineS][lineS][j - 2] == 'L'
				|| mosaic_square[lineS][lineS][j - 2] == 'O') {
				if (counter == 0) {
					counter = 1;
				}
				else {
					if (counter >= 1) {
						counter++;
					}
				}
				point++;
			}
			else {
				counter = 0;
				break;
			}
			j = j - 2;
		}
	}
	j = lineS;
	int i = position;
	counter = 0;
	while (j <= 5) {
		if (j == 5) {
			j = j + 1;
		}
		else {
			if (mosaic_square[j+1][j+1][i] == 'B' || mosaic_square[j+1][j+1][i] == 'Y' ||
				mosaic_square[j+1][j+1][i] == 'R' ||
				mosaic_square[j+1][j+1][i] == 'U' || mosaic_square[j+1][j+1][i] == 'L'
				|| mosaic_square[j + 1][j + 1][i] == 'O') {
				if (counter == 0) {
					counter = 1;
				}
				else {
					if (counter >= 1) {
						counter++;
					}
				}
				point++;
			}
			else {
				counter = 0;
				break;
			}
			j = j + 1;
		}
	}
	j = lineS;
	i = position;
	counter = 0;
	while (j >= 1) {
		if (j == 1) {
			j = j - 1;
		}
		else {
			if (mosaic_square[j - 1][j - 1][i] == 'B' || mosaic_square[j - 1][j - 1][i] == 'Y' ||
				mosaic_square[j - 1][j - 1][i] == 'R' ||
				mosaic_square[j - 1][j - 1][i] == 'U' || mosaic_square[j - 1][j - 1][i] == 'L'
				|| mosaic_square[j - 1][j - 1][i] == 'O') {
				if (counter == 0) {
					counter = 1;
				}
				else {
					if (counter >= 1) {
						counter++;
					}
				}
				point++;
			}
			else {
				counter = 0;
				break;
			}
			j = j - 1;
		}
	}

	score = score + point;
}
