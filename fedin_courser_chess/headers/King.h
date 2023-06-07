#pragma once
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"


/**
* @detailed класс Короля
* Класс для реализации методов проверки Короля. В классе присутствует следующие методы:нахождения координат короля 
* на поле, определения легальности хода, установки и получения флагов для реализации рокировки.
*/
class King { 
public:
	/**
* @brief Метод проверяющий не делает ли белый король шах черному 
* @param ox oy позиция белого короля
* @param kingx kingy - позиция черного короля
* @param int(&board)[8][8] игровая доска
* @return 1 - если шах, 0 - в противном случае
*/
	int KingWSah(int ox, int oy, int kingx, int kingy, int(&board)[8][8]);
	/**
* @brief Метод проверки на шах белого короля
* @detailed Метод пробегается по всем фигурам соперника и проверяет не делают ли они шах королю в текущем местоположении на доске
* @param posKingX posKingY - позиции белого короля
* @param int(&board)[8][8] игровая доска
* @return 1 - если нет шаха, 0 - в противном случае
*/
	int KingWhiteSahCheck(int posKingX, int posKingY, int (&board)[8][8]);
	/**
* @brief Метод проверки хода белого короля на легальность + проверка возможности рокировки
* @param ox oy старые позиции короля
* @param nx ny новые позиции короля
* @param int(&board)[8][8] игровая доска
* @return 1 - если ход легален, 0 - в противном случае
*/
	int KingW(int ox, int oy, int nx, int ny, int(&board)[8][8]);
	/**
* @brief Метод нахождения короля на поле и установки его координат в переменные kingWX, kingWY
* @param int(&board)[8][8] игровая доска
* @return 1 - если ход легален, 0 - в противном случае
*/
	void pozKingWhite (int(&board)[8][8]);

	//int mateWhiteCheck(int posKingX, int posKingY, int(&board)[8][8]);

	/**
* @brief Метод проверяющий не делает ли черный король шах белому
* @param ox oy позиция черного короля
* @param kingx kingy - позиция белого короля
* @param int(&board)[8][8] игровая доска
* @return 1 - если шах, 0 - в противном случае
*/
	int KingBSah(int ox, int oy, int kingx, int kingy, int(&board)[8][8]);
	/**
* @brief Метод проверки на шах черного короля
* @detailed Метод пробегается по всем фигурам соперника и проверяет не делают ли они шах королю в текущем местоположении на доске
* @param posKingX posKingY - позиции черного короля
* @param int(&board)[8][8] игровая доска
* @return 1 - если нет шаха, 0 - в противном случае
*/
	int KingBlackSahCheck(int posKingX, int posKingY, int(&board)[8][8]);
	/**
* @brief Метод проверки хода черного короля на легальность + проверка возможности рокировки
* @param ox oy старые позиции короля
* @param nx ny новые позиции короля
* @param int(&board)[8][8] игровая доска
* @return 1 - если ход легален, 0 - в противном случае
*/
	int KingB(int ox, int oy, int nx, int ny, int(&board)[8][8]);
	/**
* @brief Метод нахождения короля на поле и установки его координат в переменные kingBX, kingBY
* @param int(&board)[8][8] игровая доска
* @return 1 - если ход легален, 0 - в противном случае
*/
	void pozKingBlack(int(&board)[8][8]);

	//int mateBlackCheck(int posKingX, int posKingY, int(&board)[8][8]);

	void SetWKFM(int value);

	int GetWKFM();

	void SetRWRM(int value);

	int GetRWRM();

	void SetLWRM(int value);

	int GetLWRM();

	void SetBKFM(int value);

	int GetBKFM();

	void SetRBRM(int value);

	int GetRBRM();

	void SetLBRM(int value);

	int GetLBRM();

	int kingWX, kingWY;
	int kingBX, kingBY;
private:
	int whiteKingFirstMove = 0, rightWhiteRookMove = 0, leftWhiteRookMove = 0;
	int blackKingFirstMove = 0, rightBlackRookMove = 0, leftBlackRookMove = 0;
	Pawn pawn;
	Rook rook;
	Bishop bishop;
	Knight knight;
	Queen queen;
};

int King::KingWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) {
	if (posx - 1 >= 0 && posy - 1 >= 0 && kingy == posy - 1 && kingx == posx - 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posy - 1 >= 0 && kingx == posx && kingy == posy - 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posy - 1 >= 0 && posx + 1 < LENGTH && kingx == posx + 1 && kingy == posy - 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posx + 1 < LENGTH && kingy == posy && kingx == posx + 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posx + 1 < LENGTH && posy + 1 < LENGTH && kingy == posy + 1 && kingx == posx + 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posy + 1 < LENGTH && kingy == posy + 1 && kingx == posx && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posx - 1 >= 0 && posy + 1 < LENGTH && kingx == posx - 1 && kingy == posy + 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	if (posx - 1 >= 0 && kingy == posy && kingx == posx - 1 && board[kingy][kingx] <= 0) {
		return 1;
	}
	return 0;
}

int King::KingWhiteSahCheck(int posKingX, int posKingY, int(&board)[8][8]) {
	int ok = 0;
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (board[i][j] > 0) {
				if (board[i][j] == PawnBlack) {
					ok = pawn.PawnBSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == RookBlack) {
					ok = rook.RookBSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == KnightBlack) {
					ok = knight.KnightBSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == BishopBlack) {
					ok = bishop.BishopBSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == QueenBlack) {
					ok = queen.QueenBSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == KingBlack) {
					ok = KingBSah(j, i, posKingX, posKingY, board);
				}
				if (ok == 1) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int King::KingW(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox - 1, oy - 1, board);
		if (ok == 1) {
			return 1;  // влево вверх
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox, oy - 1, board);
		if (ok == 1) {
			return 1; // вверх
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LENGTH && nx == ox + 1 && ny == oy - 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox + 1, oy - 1, board);
		if (ok == 1) {
			return 1; // вправо вверх
		}
	}
	if (ox + 1 < LENGTH && ny == oy && nx == ox + 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox + 1, oy, board);
		if (ok == 1) {
			return 1; // вправо
		}
	}
	if (ox + 1 < LENGTH && oy + 1 < LENGTH && ny == oy + 1 && nx == ox + 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox + 1, oy + 1, board);
		if (ok == 1){
			return 1; // вправо вниз
		}
	}
	if (oy + 1 < LENGTH && ny == oy + 1 && nx == ox && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox, oy + 1, board);
		if (ok == 1) {
			return 1; // вниз
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LENGTH && nx == ox - 1 && ny == oy + 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox - 1, oy + 1, board);
		if (ok == 1) {
			return 1; // влево вниз
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] >= 0) {
		int ok = KingWhiteSahCheck(ox - 1, oy, board);
		if (ok == 1) {
			return 1; // влево
		}
	}
	// рокировка правых
	if (whiteKingFirstMove == 0 && rightWhiteRookMove == 0 && board[7][5] == 0 && board[7][6] == 0 && ny == 7 && nx == 6) {
		int ok = 1;
		ok = KingWhiteSahCheck(4, 7, board);
		if (ok == 1) {
			ok = KingWhiteSahCheck(5, 7, board);
			if (ok == 1) {
				ok = KingWhiteSahCheck(6, 7, board);
				if (ok == 1) {
					board[7][7] = 0;
					board[7][5] = RookWhite;
					whiteKingFirstMove = 1;
					rightWhiteRookMove = 1;
					return 1;
				}
			}
		}
	}
	// рокировка левых
	if (whiteKingFirstMove == 0 && leftWhiteRookMove == 0 && board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && ny == 7 && nx == 2) {
		int ok = 1;
		ok = KingWhiteSahCheck(4, 7, board);
		if (ok == 1) {
			ok = KingWhiteSahCheck(3, 7, board);
			if (ok == 1) {
				ok = KingWhiteSahCheck(2, 7, board);
				if (ok == 1) {
					ok = KingWhiteSahCheck(1, 7, board);
					if (ok == 1) {
						board[7][0] = 0;
						board[7][3] = RookWhite;
						whiteKingFirstMove = 1;
						leftWhiteRookMove = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void King::pozKingWhite(int(&board)[8][8]) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (board[i][j] == KingWhite) {
				kingWX = j;
				kingWY = i;
				break;
			}
		}
	}
}

/*int King::mateWhiteCheck(int posKingX, int posKingY, int(&board)[8][8]) {
	int num_sah = 0, num_ok = 0;
	if (posKingX - 1 >= 0 && posKingY - 1 >= 0 && board[posKingY - 1][posKingX - 1] >= 0) { // влево вверх
		num_ok++;
		std::cout << "LeftUp" << std::endl;
		if (KingWhiteSahCheck(posKingX - 1, posKingY - 1, board) == 0) {
			num_sah++;
			std::cout << "LeftUp" << std::endl;
		}
	}
	if (posKingY - 1 >= 0 && board[posKingY - 1][posKingX] >= 0) { // вверх
		num_ok++;
		std::cout << "Up" << std::endl;
		if (KingWhiteSahCheck(posKingX - 1, posKingY, board) == 0) {
			num_sah++;
			std::cout << "Up" << std::endl;
		}
	}
	if (posKingX + 1 < LENGTH && posKingY - 1 >= 0 && board[posKingY - 1][posKingX + 1] >= 0) { // вправо вверх
		num_ok++;
		std::cout << "RUp" << std::endl;
		if (KingWhiteSahCheck(posKingX + 1, posKingY - 1, board) == 0) {
			num_sah++;
			std::cout << "RUp" << std::endl;
		}
	}
	if (posKingX + 1 < LENGTH && board[posKingY][posKingX + 1] >= 0) { // вправо
		num_ok++;
		std::cout << "R" << std::endl;
		if (KingWhiteSahCheck(posKingX + 1, posKingY, board) == 0) {
			num_sah++;
			std::cout << "R" << std::endl;
		}
	}
	if (posKingX + 1 < LENGTH && posKingY + 1 < LENGTH && board[posKingY + 1][posKingX + 1] >= 0) { // вправо вниз
		num_ok++;
		std::cout << "RD" << std::endl;
		if (KingWhiteSahCheck(posKingX + 1, posKingY + 1, board) == 0) {
			num_sah++;
			std::cout << "RD" << std::endl;
		}
	}
	if (posKingY + 1 < LENGTH && board[posKingY + 1][posKingX] >= 0) { // вниз
		num_ok++;
		std::cout << "D" << std::endl;
		if (KingWhiteSahCheck(posKingX, posKingY + 1, board) == 0) {
			num_sah++;
			std::cout << "D" << std::endl;
		}
	}
	if (posKingY + 1 < LENGTH && posKingX - 1 >= 0 && board[posKingY + 1][posKingX - 1] >= 0) { // влево вниз
		num_ok++;
		std::cout << "LD" << std::endl;
		if (KingWhiteSahCheck(posKingX - 1, posKingY + 1, board) == 0) {
			num_sah++;
			std::cout << "LD" << std::endl;
		}
	}
	if (posKingX - 1 >= 0 && board[posKingY][posKingX - 1] >= 0) { // влево
		num_ok++;
		std::cout << "L" << std::endl;
		if (KingWhiteSahCheck(posKingX - 1, posKingY, board) == 0) {
			num_sah++;
			std::cout << "L" << std::endl;
		}
	}
	if (num_sah == num_ok && num_sah != 0) {
		std::cout << "YES" << std::endl;
		return 1;
	}
	return 0;
}*/
/*
std::cout << "LeftUp" << std::endl;
std::cout << "Up" << std::endl;
std::cout << "RUp" << std::endl;
std::cout << "R" << std::endl;
std::cout << "RD" << std::endl;
std::cout << "D" << std::endl;
std::cout << "LD" << std::endl;
std::cout << "L" << std::endl;
*/

int King::KingBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) {
	if (posx - 1 >= 0 && posy - 1 >= 0 && kingy == posy - 1 && kingx == posx - 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posy - 1 >= 0 && kingx == posx && kingy == posy - 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posy - 1 >= 0 && posx + 1 < LENGTH && kingx == posx + 1 && kingy == posy - 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posx + 1 < LENGTH && kingy == posy && kingx == posx + 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posx + 1 < LENGTH && posy + 1 < LENGTH && kingy == posy + 1 && kingx == posx + 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posy + 1 < LENGTH && kingy == posy + 1 && kingx == posx && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posx - 1 >= 0 && posy + 1 < LENGTH && kingx == posx - 1 && kingy == posy + 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	if (posx - 1 >= 0 && kingy == posy && kingx == posx - 1 && board[kingy][kingx] >= 0) {
		return 1;
	}
	return 0;
}

int King::KingBlackSahCheck(int posKingX, int posKingY, int(&board)[8][8]) {
	int ok = 0;
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (board[i][j] < 0) {
				if (board[i][j] == PawnWhite) {
					ok = pawn.PawnWSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == RookWhite) {
					ok = rook.RookWSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == KnightWhite) {
					ok = knight.KnightWSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == BishopWhite) {
					ok = bishop.BishopWSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == QueenWhite) {
					ok = queen.QueenWSah(j, i, posKingX, posKingY, board);
				}
				if (board[i][j] == KingWhite) {
					ok = KingWSah(j, i, posKingX, posKingY, board);
				}
				if (ok == 1) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int King::KingB(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox - 1, oy - 1, board);
		if (ok == 1) {
			return 1;  // влево вверх
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox, oy - 1, board);
		if (ok == 1) {
			return 1; // вверх
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LENGTH && nx == ox + 1 && ny == oy - 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox + 1, oy - 1, board);
		if (ok == 1) {
			return 1; // вправо вверх
		}
	}
	if (ox + 1 < LENGTH && ny == oy && nx == ox + 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox + 1, oy, board);
		if (ok == 1) {
			return 1; // вправо
		}
	}
	if (ox + 1 < LENGTH && oy + 1 < LENGTH && ny == oy + 1 && nx == ox + 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox + 1, oy + 1, board);
		if (ok == 1) {
			return 1; // вправо вниз
		}
	}
	if (oy + 1 < LENGTH && ny == oy + 1 && nx == ox && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox, oy + 1, board);
		if (ok == 1) {
			return 1; // вниз
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LENGTH && nx == ox - 1 && ny == oy + 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox - 1, oy + 1, board);
		if (ok == 1) {
			return 1; // влево вниз
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] <= 0) {
		int ok = KingBlackSahCheck(ox - 1, oy, board);
		if (ok == 1) {
			return 1; // влево
		}
	}
	// рокировка правых
	if (rightBlackRookMove == 0 && blackKingFirstMove == 0 && board[0][5] == 0 && board[0][6] == 0 && ny == 0 && nx == 6) {
		int ok = KingBlackSahCheck(4, 0, board);
		if (ok == 1) {
			ok = KingBlackSahCheck(5, 0, board);
			if (ok == 1) {
				ok = KingBlackSahCheck(6, 0, board);
				if (ok == 1) {
					blackKingFirstMove = 1;
					rightBlackRookMove = 1;
					board[0][7] = 0;
					board[0][5] = RookBlack;
					return 1;
				}
			}
		}
	}
	// рокировка левых
	if (leftBlackRookMove == 0 && blackKingFirstMove == 0 && board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && ny == 0 && nx == 2) {
		int ok = KingBlackSahCheck(4, 0, board);
		if (ok == 1) {
			ok = KingBlackSahCheck(3, 0, board);
			if (ok == 1) {
				ok = KingBlackSahCheck(2, 0, board);
				if (ok == 1) {
					ok = KingBlackSahCheck(1, 0, board);
					if (ok == 1) {
						blackKingFirstMove = 1;
						leftBlackRookMove = 1;
						board[0][0] = 0;
						board[0][3] = RookBlack;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void King::pozKingBlack(int(&board)[8][8]){
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			if (board[i][j] == KingBlack) {
				kingBY = i;
				kingBX = j;
				break;
			}
		}
	}
}

/*int King::mateBlackCheck(int posKingX, int posKingY, int(&board)[8][8]) {
	int num_sah = 0, num_ok = 0;
	if (posKingX - 1 >= 0 && posKingY - 1 >= 0 && board[posKingY - 1][posKingX - 1] <= 0) { // влево вверх
		num_ok++;
		if (KingBlackSahCheck(posKingX - 1, posKingY - 1, board) == 0) {
			num_sah++;
		}
	}
	if (posKingY - 1 >= 0 && board[posKingY - 1][posKingX] >= 0) { // вверх
		num_ok++;
		if (KingBlackSahCheck(posKingX, posKingY - 1, board) == 0) {
			num_sah++;
		}
	}
	if (posKingX + 1 < LENGTH && posKingY - 1 >= 0 && board[posKingY - 1][posKingX + 1] <= 0) { // вправо вверх
		num_ok++;
		if (KingBlackSahCheck(posKingX - 1, posKingY + 1, board) == 0) {
			num_sah++;
		}
	}
	if (posKingX + 1 < LENGTH && board[posKingY][posKingX + 1] <= 0) { // вправо
		num_ok++;
		if (KingBlackSahCheck(posKingX + 1, posKingY, board) == 0) {
			num_sah++;
		}
	}
	if (posKingX + 1 < LENGTH && posKingY + 1 < LENGTH && board[posKingY + 1][posKingX + 1] <= 0) { // вправо вниз
		num_ok++;
		if (KingBlackSahCheck(posKingX + 1, posKingY + 1, board) == 0) {
			num_sah++;
		}
	}
	if (posKingY + 1 < LENGTH && board[posKingY + 1][posKingX] <= 0) { // вниз
		num_ok++;
		if (KingBlackSahCheck(posKingX, posKingY + 1, board) == 0) {
			num_sah++;
		}
	}
	if (posKingY + 1 < LENGTH && posKingX - 1 >= 0 && board[posKingY + 1][posKingX - 1] <= 0) { // влево вниз
		num_ok++;
		if (KingBlackSahCheck(posKingX - 1, posKingY + 1, board) == 0) {
			num_sah++;
		}
	}
	if (posKingX - 1 >= 0 && board[posKingY][posKingX - 1] <= 0) { // влево
		num_ok++;
		if (KingBlackSahCheck(posKingX - 1, posKingY, board) == 0) {
			num_sah++;
		}
	}
	if (num_sah == num_ok && num_sah != 0) {
		return 1;
	}
	return 0;
}*/


void King::SetWKFM(int value) {
	whiteKingFirstMove = value;
}

int King::GetWKFM() {
	return whiteKingFirstMove;
}

void King::SetRWRM(int value) {
	rightWhiteRookMove = value;
}

int King::GetRWRM() {
	return rightWhiteRookMove;
}

void King::SetLWRM(int value) {
	leftWhiteRookMove = value;
}

int King::GetLWRM() {
	return leftWhiteRookMove;
}

void King::SetBKFM(int value) {
	blackKingFirstMove = value;
}

int King::GetBKFM() {
	return blackKingFirstMove;
}

void King::SetRBRM(int value) {
	rightBlackRookMove = value;
}

int King::GetRBRM() {
	return rightBlackRookMove;
}

void King::SetLBRM(int value) {
	leftBlackRookMove = value;
}

int King::GetLBRM() {
	return leftBlackRookMove;
}
