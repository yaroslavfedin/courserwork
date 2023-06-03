#pragma once
#include "Board.h"


class Queen {
public:
	int QueenW(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int QueenB(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int QueenWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);

	int QueenBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);
};

int Queen::QueenW(int ox, int oy, int nx, int ny, int(&board)[8][8]) {

	for (int i = ox - 1; i >= 0; i--) { // влево
		if (board[oy][i] >= 0 && (nx == i && ny == oy)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) { // вверх
		if (board[i][ox] >= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) { // правая
		if (board[oy][i] >= 0 && (ny == oy && nx == i)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) { // вниз
		if (board[i][ox] >= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	
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
	for (int i = oy + 1, j = ox + 1; i <= 7; i++, j++) { // вправо вниз
		if (board[i][j] >= 0 && (ny == i && nx == j)) {
			return 1;
		}
		else if (board[i][j] != 0) {
			break;
		}
	}
	return 0;
}

int Queen::QueenB(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	for (int i = ox - 1; i >= 0; i--) { // влево
		if (board[oy][i] <= 0 && (nx == i && ny == oy)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) { // вверх
		if (board[i][ox] <= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) { // вправо
		if (board[oy][i] <= 0 && (ny == oy && nx == i)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) { // вниз
		if (board[i][ox] <= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}

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

int Queen::QueenWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) {
	for (int i = posx - 1; i >= 0; i--) { // влево
		if (board[posy][i] >= 0 && (kingx == i && kingy == posy)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy - 1; i >= 0; i--) { // вверх
		if (board[i][posx] >= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
	for (int i = posx + 1; i < LENGTH; i++) { // вправо
		if (board[posy][i] >= 0 && (kingy == posy && kingx == i)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy + 1; i < LENGTH; i++) { // вниз
		if (board[i][posx] >= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
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

int Queen::QueenBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) {
	for (int i = posx - 1; i >= 0; i--) { // влево
		if (board[posy][i] <= 0 && (kingx == i && kingy == posy)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy - 1; i >= 0; i--) { // вниз
		if (board[i][posx] <= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
	for (int i = posx + 1; i < LENGTH; i++) { // вправо
		if (board[posy][i] <= 0 && (kingy == posy && kingx == i)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy + 1; i < LENGTH; i++) { // вниз
		if (board[i][posx] <= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
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