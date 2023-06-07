#pragma once
#include "Board.h"

/**
 @brief ����� �����. �������� ������ �������� 
 * �� ����������� ����, ��� �� ������ �������� ����
*/
class Pawn {
public:
	/**
	* @brief ������� �������� ����� ����� �� ��������� ���
	* @param ox oy ������ ������� �����
	* @param nx ny ����� ������� �����
	* @param int(&board)[8][8] �����
	* @return [int] 1 - ���� ��� ������ � ������������ � �������, 0 - � ������ ������
	*/
	int PawnW(int ox, int oy, int nx, int ny, int(&board)[8][8]);
	/**
	* @brief ������� �������� ������ ����� �� ��������� ���
	* @param ox oy ������ ������� �����
	* @param nx ny ����� ������� �����
	* @param int(&board)[8][8] �����
	* @return [int] 1 - ���� ��� ������ � ������������ � �������, 0 - � ������ ������
	*/
	int PawnB(int ox, int oy, int nx, int ny, int(&board)[8][8]);
	/**
	* @brief ������� �������� ����� ����� �� ��������� ��� ������� ������
	* @param posx posy ������� ������� �����
	* @param kingx kingy ������� ������� ������
	* @param int(&board)[8][8] �����
	* @return [int] 1 - ���� ���, 0 - � ������ ������
	*/
	int PawnWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]);
	/**
	* @brief ������� �������� ������ ����� �� ��������� ��� ������ ������
	* @param posx posy ������� ������� �����
	* @param kingx kingy ������� ������� ������
	* @param int(&board)[8][8] �����
	* @return [int] 1 - ���� ���, 0 - � ������ ������
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

int Pawn::PawnWSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // ���� ���, �� 1
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

int Pawn::PawnBSah(int posx, int posy, int kingx, int kingy, int(&board)[8][8]) { // ���� ���, �� 1
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