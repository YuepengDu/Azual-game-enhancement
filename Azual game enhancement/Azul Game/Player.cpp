#include "Player.h"
#include <string>
using namespace std;

Player::Player() {
	this->score1 = 0;
	this->score2 = 0;
}

Player::~Player() {

}

void Player::setPlayer1(string player1) {
	this->player1 = player1;
}

void Player::setPlayer2(string player2) {
	this->player2 = player2;
}

void Player::setLineSquare(string lineSquare) {
	this->lineSquare = lineSquare;
}

void Player::setMosaic(const string mosaic[10][10]) {
	for (int i = 0; i < 6 + offset; i++)
		this->mosaic[i][i] = mosaic[i][i];
}

void Player::setMosaic2(const string mosaic[10][10]) {
	for (int i = 0; i < 6 + offset; i++)
		this->mosaic[i][i] = mosaic[i][i];
}

void Player::setMosaicSquare(const string mosaic_square[10][10]) {
	for (int i = 1; i <= 5 + offset; i++)
		this->mosaic_square[i][i] = mosaic_square[i][i];
}

void Player::setMosaicSquare2(const string mosaic_square[10][10]) {
	for (int i = 1; i <= 5 + offset; i++)
		this->mosaic_square[i][i] = mosaic_square[i][i];
}
string Player::getPlayer1() {
	return this->player1;
}

string Player::getPlayer2() {
	return this->player2;
}

string Player::getLineSquare() {
	return this->lineSquare;
}

string Player::getMosaic(int i) {
	return this->mosaic[i][i];
}

string Player::getMosaic2(int i) {
	return this->mosaic[i][i];
}

string Player::getMosaicSquare(int i) {
	return this->mosaic_square[i][i];
}

string Player::getMosaicSquare2(int i) {
	return this->mosaic_square[i][i];
}

void Player::setPlayer1Score(int score) {
	this->score1 = score;
}

void Player::setPlayer2Score(int score) {
	this->score2 = score;
}

int Player::getScore() {
	return this->score1;
}

int Player::getScore2() {
	return this->score2;
}
