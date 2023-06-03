#pragma once
#pragma once
#include "Board.h"


class Rook {
public:
	int RookW(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int RookB(int ox, int oy, int nx, int ny, int(&board)[8][8]);

	int RookWSah(int ox, int oy, int kingx, int kingy, int(&board)[8][8]);

	int RookBSah(int ox, int oy, int kingx, int kingy, int(&board)[8][8]);
};

int Rook::RookW(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	for (int i = ox - 1; i >= 0; i--)  { // �����
		if (board[oy][i] >= 0 && (nx == i && ny == oy)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) { // �����
		if (board[i][ox] >= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) { // ������
		if (board[oy][i] >= 0 && (ny == oy && nx == i)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) { // ����
		if (board[i][ox] >= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	return 0;
}

int Rook::RookB(int ox, int oy, int nx, int ny, int(&board)[8][8]) {
	for (int i = ox - 1; i >= 0; i--) { // �����
		if (board[oy][i] <= 0 && (nx == i && ny == oy)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) { // �����
		if (board[i][ox] <= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) { // ������
		if (board[oy][i] <= 0 && (ny == oy && nx == i)) {
			return 1;
		}
		else if (board[oy][i] != 0) {
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) { // ����
		if (board[i][ox] <= 0 && (ny == i && nx == ox)) {
			return 1;
		}
		else if (board[i][ox] != 0) {
			break;
		}
	}
	return 0;
}

int Rook::RookWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // ���� ���, �� 1
	for (int i = posx - 1; i >= 0; i--) { // �����
		if (board[posy][i] >= 0 && (kingx == i && kingy == posy)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy - 1; i >= 0; i--) { // �����
		if (board[i][posx] >= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
	for (int i = posx + 1; i < LENGTH; i++) { // ������
		if (board[posy][i] >= 0 && (kingy == posy && kingx == i)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy + 1; i < LENGTH; i++) { // ����
		if (board[i][posx] >= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
	return 0;
}

int Rook::RookBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // ���� ���, �� 1
	for (int i = posx - 1; i >= 0; i--) { // �����
		if (board[posy][i] <= 0 && (kingx == i && kingy == posy)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy - 1; i >= 0; i--) { // ����
		if (board[i][posx] <= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
	for (int i = posx + 1; i < LENGTH; i++) { // ������
		if (board[posy][i] <= 0 && (kingy == posy && kingx == i)) {
			return 1;
		}
		else if (board[posy][i] != 0) {
			break;
		}
	}
	for (int i = posy + 1; i < LENGTH; i++) { // ����
		if (board[i][posx] <= 0 && (kingy == i && kingx == posx)) {
			return 1;
		}
		else if (board[i][posx] != 0) {
			break;
		}
	}
	return 0;
}
