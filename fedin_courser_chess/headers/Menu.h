#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "GamePiece.h"

//! @brief Класс меню, регулиирования времени, сохранения данных.
class Menu {
public:
	/**
	* @brief Конструктор, который задает текстуры и их положение по умолчанию
	*/
	Menu();
	/**
	* @brief Функция переводящая время в удобный формат
	*/
	void FormatOutput();
	/**
	* @brief Функция отрисовки меню и битых фигур
	* @param window Ссылка на окно SFMl
	* @param board Ссылка на объект типа Board
	*/
	void MenuDraw(sf::RenderWindow& window, Board& board);
	/**
	* @brief Функция сохранения данных в файл
	*/
	void saveData(int(&board)[8][8], int& turn, sf::Time& time_dur, int& isPausePress, int& isBeatenPress, std::vector<int>& beaten, GamePiece& figure);
	/**
	* @brief Функция чтения данных из файла
	*/
	void ReadOut(int(&board)[8][8], int& turn, Menu& time_dur, GamePiece& figure);
	/**
	* @brief Функция сохранения выбора набора текстур
	* @param temp Ссылка на объект типа Menu
	*/
	void SaveConfig(Menu& temp);
	/**
	* @brief Функция чтения выбора набора текстур
	* @param temp Ссылка на объект типа Menu
	*/
	void ReadConfig(Menu& temp);
	
	sf::Font font; 
	
	sf::Sprite text_timer, pause_off, pause_on, restart, beated_on, beated_off, menu, win_white, win_black; 
	
	sf::Text text_time, text_images, text_enter;
	
	sf::Time time_elapsed, delta_time, zero; 
	
	sf::Clock clock;
	
	int fl_time;
	sf::Texture timer, pauseoff, pauseon, res, beatedon, beatedoff, menu_, winwhite, winblack; 
	int isPausePressed = -1, isBeatenPressed = 1; 
	int boardForRestart[8][8] =
	{ 2, 3, 4, 5, 6, 4, 3, 2,
	  1, 1, 1, 1, 1, 1, 1, 1,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	 -1,-1,-1,-1,-1,-1,-1,-1,
	 -2,-3,-4,-5,-6,-4,-3,-2, };
	std::vector<int> beatBoard; 
	Board board; 
	std::string config = "images/figure"; 
	int enteringStop = 1;
};

Menu::Menu() {
	menu_.loadFromFile("images/menu/menu.png");
	menu.setTexture(menu_);
	menu.setPosition(800, 0);

	/*winwhite.loadFromFile("images/win_white.png");
	win_white.setTexture(winwhite);
	win_white.setPosition(860, 400);

	winblack.loadFromFile("images/win_black.png");
	win_black.setTexture(winblack);
	win_black.setPosition(860, 400);*/

	timer.loadFromFile("images/menu/timer.png");
	text_timer.setTexture(timer);
	text_timer.setPosition(860, 50);

	font.loadFromFile("images/test_font.ttf");
	text_time.setString("");
	text_time.setCharacterSize(35);
	text_time.setFont(font);
	text_time.setPosition(945, 150);
	zero.Zero;

	text_images.setString(config);
	text_images.setCharacterSize(35);
	text_images.setFont(font);
	text_images.setPosition(400, 400);

	text_enter.setString("Please input number of texture pack and press Enter");
	text_enter.setCharacterSize(25);
	text_enter.setFont(font);
	text_enter.setPosition(300, 370);

	pauseoff.loadFromFile("images/menu/pause_off.png");
	pause_off.setTexture(pauseoff);
	pause_off.setPosition(860, 205);

	pauseon.loadFromFile("images/menu/pause_on.png");
	pause_on.setTexture(pauseon);
	pause_on.setPosition(860, 205);

	res.loadFromFile("images/menu/restart.png");
	restart.setTexture(res);
	restart.setPosition(860, 280);

	beatedon.loadFromFile("images/menu/beated_on.png");
	beated_on.setTexture(beatedon);
	beated_on.setPosition(1100, 750);

	beatedoff.loadFromFile("images/menu/beated_off.png");
	beated_off.setTexture(beatedoff);
	beated_off.setPosition(1100, 750);
}

void Menu::FormatOutput() {
	std::string form = "0" + std::to_string((180 - fl_time) / 60) + ":";
	if ((180 - fl_time) % 60 >= 10) { 
		form += std::to_string((180 - fl_time) % 60);
	}
	else {
		form += "0";
		form += std::to_string((180 - fl_time) % 60);
	}
	text_time.setString(form);
}

void Menu::MenuDraw(sf::RenderWindow& window, Board& board) {
	window.draw(menu);
	window.draw(text_timer);
	FormatOutput();
	window.draw(text_time);
	if (isPausePressed == 1) { window.draw(pause_off); }
	else { window.draw(pause_on); }
	window.draw(restart);
	if (isBeatenPressed == 1) { window.draw(beated_on); }
	else { window.draw(beated_off); }
	if (isBeatenPressed == 1) {
		int shiftWhite = 0, shiftBlack = 0;
		for (int i = 0; i != beatBoard.size(); i++) {
			if (beatBoard[i] != 0) {
				if (beatBoard[i] == PawnBlack) {
					board.figures[1].setPosition(860 + shiftBlack * 10, 550);
					window.draw(board.figures[1]);
					shiftBlack += 1;
				}
				if (beatBoard[i] == PawnWhite) {
					board.figures[2].setPosition(860 + shiftWhite * 10, 450);
					window.draw(board.figures[2]);
					shiftWhite += 1;
				}
				if (beatBoard[i] == RookBlack) {
					shiftBlack += 1;
					board.figures[3].setPosition(860 + shiftBlack * 10, 550);
					window.draw(board.figures[3]);
					shiftBlack += 2;
				}
				if (beatBoard[i] == RookWhite) {
					shiftWhite += 1;
					board.figures[4].setPosition(860 + shiftWhite * 10, 450);
					window.draw(board.figures[4]);
					shiftWhite += 2;
				}
				if (beatBoard[i] == KnightWhite) {
					shiftWhite += 1;
					board.figures[6].setPosition(860 + shiftWhite * 10, 450);
					window.draw(board.figures[6]);
					shiftWhite += 2;
				}
				if (beatBoard[i] == KnightBlack) {
					shiftBlack += 1;
					board.figures[5].setPosition(860 + shiftBlack * 10, 550);
					window.draw(board.figures[5]);
					shiftBlack += 2;
				}
				if (beatBoard[i] == BishopBlack) {
					shiftBlack += 1;
					board.figures[7].setPosition(860 + shiftBlack * 10, 550);
					window.draw(board.figures[7]);
					shiftBlack += 2;
				}
				if (beatBoard[i] == BishopWhite) {
					shiftWhite += 1;
					board.figures[8].setPosition(860 + shiftWhite * 10, 450);
					window.draw(board.figures[8]);
					shiftWhite += 2;
				}
				if (beatBoard[i] == QueenWhite) {
					shiftWhite += 1;
					board.figures[10].setPosition(860 + shiftWhite * 10, 450);
					window.draw(board.figures[10]);
					shiftWhite += 2;
				}
				if (beatBoard[i] == QueenBlack) {
					shiftBlack += 1;
					board.figures[9].setPosition(860 + shiftBlack * 10, 550);
					window.draw(board.figures[9]);
					shiftBlack += 2;
				}
			}
		}
	}
}

void Menu::saveData(int(&board)[8][8], int& turn ,sf::Time& time_dur, int& isPausePress, int& isBeatenPress, std::vector<int>& beaten, GamePiece& figure) {
	std::ofstream file("datas/data.txt");
	if (file.is_open()) {
		for (int i = 0; i != LENGTH; i++) {
			for (int j = 0; j != LENGTH; j++) {
				file << board[i][j] << " ";
			}
			file << std::endl;
		}
	}
	file << turn << std::endl;
	// сохранение рокировки белых
	file << figure.GetWKFM() << std::endl;
	file << figure.GetRWRM() << std::endl;
	file << figure.GetLWRM() << std::endl;
	// сохранение рокировки черных
	file << figure.GetBKFM() << std::endl;
	file << figure.GetRBRM() << std::endl;
	file << figure.GetLBRM() << std::endl;
	// сохранение времени
	file << time_dur.asSeconds() << std::endl;
	file << isPausePress << std::endl;
	file << isBeatenPress << std::endl;
	file << beaten.size() << std::endl;
	for (int i = 0; i != beaten.size(); i++) {
		file << beaten[i] << " ";
	}
	file.close();
}

void Menu::ReadOut(int(&board)[8][8], int& turn, Menu& time_dur, GamePiece& figure) {
	std::ifstream file("datas/data.txt");
	if (file.peek() != EOF) {
		for (int i = 0; i != LENGTH; i++) {
			std::string temp;
			std::getline(file, temp);
			int j = 0;
			int temp_min = 1;
			for (int k = 0; k != temp.size(); k++) {
				if (temp[k] == '-') {
					temp_min *= -1;
				}
				else if (isdigit(temp[k]) && temp_min == -1) {
					if (temp[k] == '0') {
						board[i][j] = 0;
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '1') {
						board[i][j] = -1;
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '2') {
						board[i][j] = -2;
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '3') {
						board[i][j] = -3;
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '4') {
						board[i][j] = -4;
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '5') {
						board[i][j] = -5;
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '6') {
						board[i][j] = -6;
						temp_min *= -1;
						j++;
					}
				}
				else if (isdigit(temp[k])) {
					if (temp[k] == '0') {
						board[i][j] = 0;
						j++;
					}
					else if (temp[k] == '1') {
						board[i][j] = 1;
						j++;
					}
					else if (temp[k] == '2') {
						board[i][j] = 2;
						j++;
					}
					else if (temp[k] == '3') {
						board[i][j] = 3;
						j++;
					}
					else if (temp[k] == '4') {
						board[i][j] = 4;
						j++;
					}
					else if (temp[k] == '5') {
						board[i][j] = 5;
						j++;
					}
					else if (temp[k] == '6') {
						board[i][j] = 6;
						j++;
					}
				}
			}
		}
		std::string temp;
		std::getline(file, temp);
		if (temp[0] == '-') {
			turn = -1;
		}
		else {
			turn = 1;
		}
		// сохранение рокировки белых 
		std::getline(file, temp);
		if (temp[0] == '1') {
			figure.SetWKFM(1);
		}
		else {
			figure.SetWKFM(0);
		}
		std::getline(file, temp);
		if (temp[0] == '1') {
			figure.SetRWRM(1);
		}
		else {
			figure.SetRWRM(0);
		}
		std::getline(file, temp);
		if (temp[0] == '1') {
			figure.SetLWRM(1);
		}
		else {
			figure.SetLWRM(0);
		}
		// сохранение рокировки черных
		std::getline(file, temp);
		if (temp[0] == '1') {
			figure.SetBKFM(1);
		}
		else {
			figure.SetBKFM(0);
		}
		std::getline(file, temp);
		if (temp[0] == '1') {
			figure.SetRBRM(1);
		}
		else {
			figure.SetRBRM(0);
		}
		std::getline(file, temp);
		if (temp[0] == '1') {
			figure.SetLBRM(1);
		}
		else {
			figure.SetLBRM(0);
		}
		// сохранение времени
		std::getline(file, temp);
		time_dur.fl_time = stoi(temp);
		std::getline(file, temp);
		time_dur.isPausePressed = -1;

		std::getline(file, temp);
		if (temp[0] == '-') {
			time_dur.isBeatenPressed = -1;
		}
		else {
			time_dur.isBeatenPressed = 1;
		}
		std::getline(file, temp);
		int size = stoi(temp);
		if (size) {
			std::getline(file, temp);
			int j = 0;
			int temp_min = 1;
			for (int k = 0; k != temp.size(); k++) {
				if (temp[k] == '-') {
					temp_min *= -1;
				}
				else if (isdigit(temp[k]) && temp_min == -1) {
					if (temp[k] == '1') {
						time_dur.beatBoard.push_back(-1);
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '2') {
						time_dur.beatBoard.push_back(-2);
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '3') {
						time_dur.beatBoard.push_back(-3);
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '4') {
						time_dur.beatBoard.push_back(-4);
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '5') {
						time_dur.beatBoard.push_back(-5);
						temp_min *= -1;
						j++;
					}
					else if (temp[k] == '6') {
						time_dur.beatBoard.push_back(-6);
						temp_min *= -1;
						j++;
					}
				}
				else if (isdigit(temp[k])) {
					if (temp[k] == '1') {
						time_dur.beatBoard.push_back(1);
						j++;
					}
					else if (temp[k] == '2') {
						time_dur.beatBoard.push_back(2);
						j++;
					}
					else if (temp[k] == '3') {
						time_dur.beatBoard.push_back(3);
						j++;
					}
					else if (temp[k] == '4') {
						time_dur.beatBoard.push_back(4);
						j++;
					}
					else if (temp[k] == '5') {
						time_dur.beatBoard.push_back(5);
						j++;
					}
					else if (temp[k] == '6') {
						time_dur.beatBoard.push_back(6);
						j++;
					}
				}
			}
		}
	}	
}

void Menu::SaveConfig(Menu& temp) {
	std::ofstream file("datas/config.txt");
	file << temp.config;
}

void Menu::ReadConfig(Menu& temp) {
	std::ifstream file("datas/config.txt");
	if (file.peek() != EOF) {
		std::getline(file, temp.config);
	}
}