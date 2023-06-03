#pragma once
#include "Board.h"


class Knight {
public:
	int KnightW(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int KnightB(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int KnightWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);

	int KnightBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);

};

int Knight::KnightW(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] >= 0) { // вверх влево
		return 1; 
	}
	if (oy - 2 >= 0 && ox + 1 < LENGTH && ny == oy - 2 && nx == ox + 1 && board[ny][nx] >= 0) { // вверх вправо
		return 1; 
	}
	if (oy - 1 >= 0 && ox + 2 < LENGTH && ny == oy - 1 && nx == ox + 2 && board[ny][nx] >= 0) { // вправо вверх
		return 1; 
	}
	if (oy + 1 >= 0 && ox + 2 < LENGTH && ny == oy + 1 && nx == ox + 2 && board[ny][nx] >= 0) { // вправо вниз
		return 1; 
	}
	if (oy + 2 < LENGTH && ox + 1 < LENGTH && ny == oy + 2 && nx == ox + 1 && board[ny][nx] >= 0) { // вниз вправо
		return 1;
	}
	if (oy + 2 < LENGTH && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] >= 0) { // вниз влево
		return 1; 
	}
	if (oy + 1 < LENGTH && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] >= 0) { //влево вверх
		return 1; 
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] >= 0) { // влево вниз
		return 1;
	}
	return 0;
}

int Knight::KnightB(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] <= 0) { // вверх влево
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < LENGTH && ny == oy - 2 && nx == ox + 1 && board[ny][nx] <= 0) { // вверх вправо
		return 1; 
	}
	if (oy - 1 >= 0 && ox + 2 < LENGTH && ny == oy - 1 && nx == ox + 2 && board[ny][nx] <= 0) { // вправо вверх
		return 1; 
	}
	if (oy + 1 >= 0 && ox + 2 < LENGTH && ny == oy + 1 && nx == ox + 2 && board[ny][nx] <= 0) { // вправо вниз
		return 1;
	}
	if (oy + 2 < LENGTH && ox + 1 < LENGTH && ny == oy + 2 && nx == ox + 1 && board[ny][nx] <= 0) { // вниз вправо
		return 1;
	}
	if (oy + 2 < LENGTH && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] <= 0) { // вниз влево
		return 1;
	}
	if (oy + 1 < LENGTH && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] <= 0) { // влево вверх
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] <= 0) { // влево вниз
		return 1;
	}
	return 0;
}

int Knight::KnightWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) {
	if (posy - 2 >= 0 && posx - 1 >= 0 && kingy == posy - 2 && kingx == posx - 1 && board[kingy][kingx] >= 0) { // вверх влево
		return 1;
	}
	if (posy - 2 >= 0 && posx + 1 < LENGTH && kingy == posy - 2 && kingx == posx + 1 && board[kingy][kingx] >= 0) { // вверх вправо
		return 1; // вправо вверх
	}
	if (posy - 1 >= 0 && posx + 2 < LENGTH && kingy == posy - 1 && kingx == posx + 2 && board[kingy][kingx] >= 0) { // вправо вверх
		return 1; // вправо 1
	}
	if (posy + 1 >= 0 && posx + 2 < LENGTH && kingy == posy + 1 && kingx == posx + 2 && board[kingy][kingx] >= 0) { // вправо вниз
		return 1; // вправо 2
	}
	if (posy + 2 < LENGTH && posx + 1 < LENGTH && kingy == posy + 2 && kingx == posx + 1 && board[kingy][kingx] >= 0) { // вниз вправо
		return 1; // вниз 1
	}
	if (posy + 2 < LENGTH && posx - 1 >= 0 && kingy == posy + 2 && kingx == posx - 1 && board[kingy][kingx] >= 0) { // вниз влево
		return 1; //вниз 2
	}
	if (posy + 1 < LENGTH && posx - 2 >= 0 && kingy == posy + 1 && kingx == posx - 2 && board[kingy][kingx] >= 0) { //влево вверх
		return 1; // влево 1
	}
	if (posy - 1 >= 0 && posx - 2 >= 0 && kingy == posy - 1 && kingx == posx - 2 && board[kingy][kingx] >= 0) { // влево вниз
		return 1; // влево 2
	}
	return 0;
}

int Knight::KnightBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) {
	if (posy - 2 >= 0 && posx - 1 >= 0 && kingy == posy - 2 && kingx == posx - 1 && board[kingy][kingx] <= 0) { // вверх влево
		return 1;
	}
	if (posy - 2 >= 0 && posx + 1 < LENGTH && kingy == posy - 2 && kingx == posx + 1 && board[kingy][kingx] <= 0) { // вверх вправо
		return 1; // вправо вверх
	}
	if (posy - 1 >= 0 && posx + 2 < LENGTH && kingy == posy - 1 && kingx == posx + 2 && board[kingy][kingx] <= 0) { // вправо вверх
		return 1; // вправо 1
	}
	if (posy + 1 >= 0 && posx + 2 < LENGTH && kingy == posy + 1 && kingx == posx + 2 && board[kingy][kingx] <= 0) { // вправо вниз
		return 1; // вправо 2
	}
	if (posy + 2 < LENGTH && posx + 1 < LENGTH && kingy == posy + 2 && kingx == posx + 1 && board[kingy][kingx] <= 0) { // вниз вправо
		return 1; // вниз 1
	}
	if (posy + 2 < LENGTH && posx - 1 >= 0 && kingy == posy + 2 && kingx == posx - 1 && board[kingy][kingx] <= 0) { // вниз влево
		return 1; //вниз 2
	}
	if (posy + 1 < LENGTH && posx - 2 >= 0 && kingy == posy + 1 && kingx == posx - 2 && board[kingy][kingx] <= 0) { //влево вверх
		return 1; // влево 1
	}
	if (posy - 1 >= 0 && posx - 2 >= 0 && kingy == posy - 1 && kingx == posx - 2 && board[kingy][kingx] <= 0) { // влево вниз
		return 1; // влево 2
	}
	return 0;
}
