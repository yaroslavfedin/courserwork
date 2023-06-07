#pragma once
#include "Board.h"

/**
 @brief Класс Пешки. Содержит методы проверки 
 * на легальность хода, так же методы проверки шаха
*/
class Pawn {
public:
	/**
	* @brief Функция проверки белой пешки на возможный ход
	* @param ox oy Старая позиция пешки
	* @param nx ny Новая позиция пешки
	* @param int(&board)[8][8] Доска
	* @return [int] 1 - если ход сделан в соответствии с правила, 0 - в другом случае
	*/
	int PawnW(int ox, int oy, int nx, int ny, int(&board)[8][8]);
	/**
	* @brief Функция проверки черной пешки на возможный ход
	* @param ox oy Старая позиция пешки
	* @param nx ny Новая позиция пешки
	* @param int(&board)[8][8] Доска
	* @return [int] 1 - если ход сделан в соответствии с правила, 0 - в другом случае
	*/
	int PawnB(int ox, int oy, int nx, int ny, int(&board)[8][8]);
	/**
	* @brief Функция проверки белой пешки на возможный шах черному королю
	* @param posx posy Текущая позиция пешки
	* @param kingx kingy Текущая позиция короля
	* @param int(&board)[8][8] Доска
	* @return [int] 1 - если шах, 0 - в другом случае
	*/
	int PawnWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);
	/**
	* @brief Функция проверки черной пешки на возможный шах белому королю
	* @param posx posy Текущая позиция пешки
	* @param kingx kingy Текущая позиция короля
	* @param int(&board)[8][8] Доска
	* @return [int] 1 - если шах, 0 - в другом случае
	*/
	int PawnBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);
};

int Pawn::PawnW(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	// old x,y ; new x, y
	
	if (oy == 6) {
		if ((ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0) || (ny == oy - 2 && nx == ox && board[oy - 1][ox] == 0 && board[oy - 2][ox] == 0)) {
			return 1;
		}
	}
	else if (ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0) {
		return 1;
	}
	if (board[oy - 1][ox - 1] > 0) {
		if (ny == oy - 1 && nx == ox - 1) {
			return 1;
		}
	}
	if (board[oy - 1][ox + 1] > 0) {
		if (ny == oy - 1 && nx == ox + 1) {
			return 1;
		}
	}
	return 0;
}

int Pawn::PawnB(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	// old x,y ; new x, y

	if (oy == 1) {
		if ((ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0) || (ny == oy + 2 && nx == ox && board[oy + 1][ox] == 0 && board[oy + 2][ox] == 0)) {
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0) {
		return 1;
	}
	if (board[oy + 1][ox - 1] < 0) {
		if (ny == oy + 1 && nx == ox - 1) {
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] < 0) {
		if (ny == oy + 1 && nx == ox + 1) {
			return 1;
		}
	}
	return 0;
}

int Pawn::PawnWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // если шах, то 1
	if (board[posy - 1][posx - 1] >= 0) {
		if (posy - 1 == kingy && posx - 1 == kingx) {
			return 1;
		}
	}
	if (board[posy - 1][posx + 1] >= 0) {
		if (posy - 1 == kingy && posx + 1 == kingx) {
			return 1;
		}
	}
	return 0;
}

int Pawn::PawnBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // если шах, то 1
	if (board[posy + 1][posx - 1] <= 0) {
		if (kingy == posy + 1 && kingx == posx - 1) {
			return 1;
		}
	}
	if (board[posy + 1][posy + 1] <= 0) {
		if (kingy == posy + 1 && kingx == posx + 1) {
			return 1;
		}
	}
	return 0;
}