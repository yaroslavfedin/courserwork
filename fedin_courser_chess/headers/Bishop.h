#pragma once
#pragma once
#include "Board.h"


class Bishop {
public:
	int BishopW(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int BishopB(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int BishopWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);

	int BishopBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);
};

int Bishop::BishopW(int ox, int oy, int nx, int ny, int(&board)[8][8]) {

	for (int i = oy - 1, j = ox - 1; i >= 0; i--, j--) { // влево вверх
		if (board[i][j] >= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = oy - 1, j = ox + 1; i >= 0; i--, j++) { // вправо вверх
		if (board[i][j] >= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = oy + 1, j = ox - 1; i <= 7; i++, j--) { // влево вниз
		if (board[i][j] >= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = oy + 1, j = ox + 1; i <= 7; i++, j++)  { // вправо вниз
		if (board[i][j] >= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	return 0;
}

int Bishop::BishopB(int ox, int oy, int nx, int ny, int(&board)[8][8]) {

	for (int i = oy - 1, j = ox - 1; i >= 0; i--, j--) { // влево вверх
		if (board[i][j] <= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = oy - 1, j = ox + 1; i >= 0; i--, j++) { // вправо вверх
		if (board[i][j] <= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = oy + 1, j = ox - 1; i <= 7; i++, j--) { // влево вниз
		if (board[i][j] <= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = oy + 1, j = ox + 1; i <= 7; i++, j++) { // вправо вниз
		if (board[i][j] <= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	return 0;
}

int Bishop::BishopWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // если шах, то 1

	for (int i = posy - 1, j = posx - 1; i >= 0; i--, j--) { // влево вверх
		if (board[i][j] >= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = posy - 1, j = posx + 1; i >= 0; i--, j++) { // вправо вверх
		if (board[i][j] >= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = posy + 1, j = posx - 1; i <= 7; i++, j--) { // влево вниз
		if (board[i][j] >= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = posy + 1, j = posx + 1; i <= 7; i++, j++) { // вправо вниз
		if (board[i][j] >= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	return 0;
}

int Bishop::BishopBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // если шах, то 1
	for (int i = posy - 1, j = posx - 1; i >= 0; i--, j--) { // влево вверх
		if (board[i][j] <= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = posy - 1, j = posx + 1; i >= 0; i--, j++) { // вправо вверх
		if (board[i][j] <= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = posy + 1, j = posx - 1; i <= 7; i++, j--) { // влево вниз
		if (board[i][j] <= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	for (int i = posy + 1, j = posx + 1; i <= 7; i++, j++) { // вправо вниз
		if (board[i][j] <= 0 && (kingy == i && kingx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	return 0;
}