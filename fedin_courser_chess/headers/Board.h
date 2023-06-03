#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#define LENGTH 8
#define PawnBlack 1
#define PawnWhite -1
#define RookBlack 2
#define RookWhite -2
#define KnightWhite -3
#define KnightBlack 3
#define BishopBlack 4
#define BishopWhite -4
#define QueenWhite -5
#define QueenBlack 5
#define KingBlack 6
#define KingWhite -6

class Board {
public:
	Board();

	void Drawing(sf::RenderWindow& window);

	void ReSetSprite(int& enteringSt, std::string& temp);

	// array of sprites
	sf::Sprite	figures[15];
	// board
	int board[8][8] =
	{ 2, 3, 4, 5, 6, 4, 3, 2,
	  1, 1, 1, 1, 1, 1, 1, 1,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	 -1,-1,-1,-1,-1,-1,-1,-1,
	 -2,-3,-4,-5,-6,-4,-3,-2, };
private:
	sf::Texture texture[15];
	const int size = 100;
};

Board::Board() {
	texture[0].loadFromFile("images/figure1/board.png");
	texture[1].loadFromFile("images/figure1/BlackPawn.png");
	texture[2].loadFromFile("images/figure1/WhitePawn.png");
	texture[3].loadFromFile("images/figure1/BlackRook.png");
	texture[4].loadFromFile("images/figure1/WhiteRook.png");
	texture[5].loadFromFile("images/figure1/BlackKnight.png");
	texture[6].loadFromFile("images/figure1/WhiteKnight.png");
	texture[7].loadFromFile("images/figure1/BlackBishop.png");
	texture[8].loadFromFile("images/figure1/WhiteBishop.png");
	texture[9].loadFromFile("images/figure1/BlackQueen.png");
	texture[10].loadFromFile("images/figure1/WhiteQueen.png");
	texture[11].loadFromFile("images/figure1/BlackKing.png");
	texture[12].loadFromFile("images/figure1/WhiteKing.png");
	texture[13].loadFromFile("images/figure1/BlackTransformare.png");
	texture[14].loadFromFile("images/figure1/WhiteTransformare.png");
	for (int i = 0; i != 15; i++) {
		figures[i].setTexture(texture[i]);
	}
}

void Board::Drawing(sf::RenderWindow& window) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (board[i][j] != 0) {
				if (board[i][j] == PawnBlack) {
					figures[1].setPosition(j * size, i * size);
					window.draw(figures[1]);
				}
				if (board[i][j] == PawnWhite) {
					figures[2].setPosition(j * size, i * size);
					window.draw(figures[2]);
				}
				if (board[i][j] == RookBlack) {
					figures[3].setPosition(j * size, i * size);
					window.draw(figures[3]);

				}
				if (board[i][j] == RookWhite) {
					figures[4].setPosition(j * size, i * size);
					window.draw(figures[4]);

				}
				if (board[i][j] == KnightWhite) {
					figures[6].setPosition(j * size, i * size);
					window.draw(figures[6]);
				}
				if (board[i][j] == KnightBlack) {
					figures[5].setPosition(j * size, i * size);
					window.draw(figures[5]);
				}
				if (board[i][j] == BishopBlack) {
					figures[7].setPosition(j * size, i * size);
					window.draw(figures[7]);
				}
				if (board[i][j] == BishopWhite) {
					figures[8].setPosition(j * size, i * size);
					window.draw(figures[8]);
				}
				if (board[i][j] == QueenWhite) {
					figures[10].setPosition(j * size, i * size);
					window.draw(figures[10]);
				}
				if (board[i][j] == QueenBlack) {
					figures[9].setPosition(j * size, i * size);
					window.draw(figures[9]);
				}
				if (board[i][j] == KingBlack) {
					figures[11].setPosition(j * size, i * size);
					window.draw(figures[11]);
				}
				if (board[i][j] == KingWhite) {
					figures[12].setPosition(j * size, i * size);
					window.draw(figures[12]);
				}
			}
		}
	}
}

void Board::ReSetSprite(int& enteringSt, std::string& temp) {
	enteringSt = 0;
	std::string compare = "images/figure";
	if (temp != compare) {
		texture[0].loadFromFile(temp + "/board.png");
		texture[1].loadFromFile(temp + "/BlackPawn.png");
		texture[2].loadFromFile(temp + "/WhitePawn.png");
		texture[3].loadFromFile(temp + "/BlackRook.png");
		texture[4].loadFromFile(temp + "/WhiteRook.png");
		texture[5].loadFromFile(temp + "/BlackKnight.png");
		texture[6].loadFromFile(temp + "/WhiteKnight.png");
		texture[7].loadFromFile(temp + "/BlackBishop.png");
		texture[8].loadFromFile(temp + "/WhiteBishop.png");
		texture[9].loadFromFile(temp + "/BlackQueen.png");
		texture[10].loadFromFile(temp + "/WhiteQueen.png");
		texture[11].loadFromFile(temp + "/BlackKing.png");
		texture[12].loadFromFile(temp + "/WhiteKing.png");
	}
	for (int i = 0; i != 13; i++) {
		figures[i].setTexture(texture[i]);
	}
}
