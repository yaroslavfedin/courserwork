#pragma once

#include "SFML/Graphics.hpp"
#include "GamePiece.h"
#include "Menu.h"

using namespace sf;
class Game {
public:
	Game();
	void GameRun();
	void ProcessEvents(Vector2i pos);
	void Render(Vector2i pos);
private:
	RenderWindow window;
	Board board;
	GamePiece figures;
	Menu time;
	const int size = 100; // размер поля 100 * 100
	int x, y;
	float dx = 0, dy = 0; // оцентрить изображение
	int noMovedPiece = 0;
	int turn = -1; // -1 - ходят белые, 1 ходят черные
	sf::Sprite MoveImages;
	int oldPozX, oldPozY;
	int move = 0;
	int checkWhite = 0, checkBlack = 0; // если шах есть то 1
	int z = 0; // восстановление времени
	int rezTime = 0;
	//int mateBlack = 0, mateWhite = 0, resFlag = 0;

	bool transformWhite = false, transformBlack = false;
	int transWX, transWY, transBX, transBY;

	int scaleX = 100, scaleY = 100;
};

Game::Game()
	: window(VideoMode(1200, 800), "Chess made by Fedin Yaroslav", Style::Default) {
	window.setFramerateLimit(60);
}

void Game::GameRun() {
	time.ReadOut(board.board, turn, time, figures);
	int temp = time.fl_time; // время с прошлой игры
	time.ReadConfig(time);
	if (time.config == "/images") {
		time.config = "/images/figure1";
	}
	while (window.isOpen()) {
		time.delta_time = time.clock.restart();
		time.time_elapsed += time.delta_time;
		if (time.time_elapsed.asSeconds() >= 180.00001) {
			turn *= -1;
			time.time_elapsed = time.zero;
		}
		else if (rezTime == 1) {
			turn = -1;
			time.time_elapsed = time.zero;
			rezTime = 0;
		}
		if (z != 0) {
			time.fl_time = time.time_elapsed.asSeconds();
		}
		else {
			time.fl_time = temp + time.time_elapsed.asSeconds();
		}
		if (time.isPausePressed == -1) {
			time.time_elapsed -= time.delta_time;
		}
		
		Vector2i pos = Mouse::getPosition(window);
		x = pos.x / scaleX;
		y = pos.y / scaleY;
		ProcessEvents(pos);
		Render(pos);
	}
}

void Game::ProcessEvents(Vector2i pos) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Resized) {
			scaleX = (event.size.width - event.size.width / 3) / 8;
			scaleY = event.size.height / 8;
			x = pos.x / scaleX;
			y = pos.y / scaleY;
		}
		if (event.type == Event::Closed) {
			time.saveData(board.board, turn, time.time_elapsed, time.isPausePressed, time.isBeatenPressed, time.beatBoard, figures);
			time.SaveConfig(time);
			window.close();
		}
		if (event.type == Event::TextEntered && time.enteringStop != 0) {
			if (int(static_cast<char>(event.text.unicode)) == 13) {
				time.enteringStop = -1;
			}
			else if (int(static_cast<char>(event.text.unicode)) == 8) {
				time.config.erase(time.config.size() - 1);
				time.text_images.setString(time.config);
			}
			else {
				time.config += static_cast<char>(event.text.unicode);
				time.text_images.setString(time.config);
			}
		}
		if (event.type == sf::Event::LostFocus) {
			time.isPausePressed = -1;
		}
		if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				if (8.6 * scaleX <= pos.x && 11.4 * scaleX >= pos.x && pos.y >= 2.05 * scaleY && pos.y <= 2.8 * scaleY) {
					time.isPausePressed *= -1;
				}
				if (11 * scaleX <= pos.x && 11.8 * scaleX >= pos.x && pos.y >= 7.5 * scaleY && pos.y <= 7.9 * scaleY) {
					time.isBeatenPressed *= -1;
				}
				if (8.6 * scaleX <= pos.x && 11.4 * scaleX >= pos.x && pos.y >= 2.8 * scaleY && pos.y <= 3.55 * scaleY) {
					rezTime = 1;
					z--;
					time.beatBoard.clear();
					for (int i = 0; i != LENGTH; i++) {
						for (int j = 0; j != LENGTH; j++) {
							board.board[i][j] = time.boardForRestart[i][j];
						}
					}
				}
				if (transformWhite) {
					if (pos.y >= transWY * size && pos.y <= (transWY + 1) * size && pos.x >= transWX * size && pos.x <= (transWX + 1) * size) {
						int xx = pos.x % 100, yy = pos.y % 100;
						
						if (xx < 50 && yy < 50 && xx > 0 && yy > 0) {
							board.board[transWY][transWX] = RookWhite;
							transformWhite = 0;
						}
						if (xx > 50 && xx < 100 && yy < 50 && yy > 0) {
							board.board[transWY][transWX] = QueenWhite;
							transformWhite = 0;
						}
						if (xx > 50 && xx < 100 && yy>50 && yy < 100) {
							board.board[transWY][transWX] = KnightWhite;
							transformWhite = 0;
						}
						if (xx < 50 && xx>0 && yy > 50 && y < 100) {
							board.board[transWY][transWX] = BishopWhite;
							transformWhite = 0;
						}
						if (transformWhite == 0) {
							figures.pozKingBlack(board.board);
							int h = figures.KingBlackSahCheck(figures.kingBX, figures.kingBY, board.board);
							if (h == 0) {
								checkBlack = 1;
							}
						}
					}
				}
				if (transformBlack)	{
					if (pos.y >= transBY * size && pos.y <= (transBY + 1) * size && pos.x >= transBX * size && pos.x <= (transBX + 1) * size) {
						int xx = pos.x % 100, yy = pos.y % 100;
						if (xx < 50 && yy < 50 && xx > 0 && yy > 0)	{
							board.board[transBY][transBX] = RookBlack;
							transformBlack = 0;
						}
						if (xx > 50 && xx < 100 && yy < 50 && yy > 0) {
							board.board[transBY][transBX] = QueenBlack;
							transformBlack = 0;
						}
						if (xx > 50 && xx < 100 && yy>50 && yy < 100) {
							board.board[transBY][transBX] = KnightBlack;
							transformBlack = 0;
						}
						if (xx < 50 && xx>0 && yy > 50 && y < 100) {
							board.board[transBY][transBX] = BishopBlack;
							transformBlack = 0;
						}
						if (transformBlack == 0) {
							figures.pozKingWhite(board.board);
							int h = figures.KingWhiteSahCheck(figures.kingWX, figures.kingWY, board.board);
							if (h == 0)	{
								checkWhite = 1;
							}
						}
					}
				}
				if (board.board[y][x] != 0 && time.isPausePressed == 1) {
					dx = pos.x - x * 100;
					dy = pos.y - y * 100;
					if (board.board[y][x] == PawnBlack && turn == 1) {
						noMovedPiece = PawnBlack;
						MoveImages = board.figures[1];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == PawnWhite && turn == -1) {
						noMovedPiece = PawnWhite;
						MoveImages = board.figures[2];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == RookBlack && turn == 1) {
						noMovedPiece = RookBlack;
						MoveImages = board.figures[3];
						board.board[y][x] = 0;

					}
					if (board.board[y][x] == RookWhite && turn == -1) {
						noMovedPiece = RookWhite;
						MoveImages = board.figures[4];
						board.board[y][x] = 0;

					}
					if (board.board[y][x] == KnightBlack && turn == 1) {
						noMovedPiece = KnightBlack;
						MoveImages = board.figures[5];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == KnightWhite && turn == -1) {
						noMovedPiece = KnightWhite;
						MoveImages = board.figures[6];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == BishopBlack && turn == 1) {
						noMovedPiece = BishopBlack;
						MoveImages = board.figures[7];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == BishopWhite && turn == -1) {
						noMovedPiece = BishopWhite;
						MoveImages = board.figures[8];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == QueenBlack && turn == 1) {
						noMovedPiece = QueenBlack;
						MoveImages = board.figures[9];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == QueenWhite && turn == -1) {
						noMovedPiece = QueenWhite;
						MoveImages = board.figures[10];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == KingBlack && turn == 1) {
						noMovedPiece = KingBlack;
						MoveImages = board.figures[11];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == KingWhite && turn == -1) {
						noMovedPiece = KingWhite;
						MoveImages = board.figures[12];
						board.board[y][x] = 0;
					}
					if (board.board[y][x] == 0) {
						move = 1;
						oldPozX = x;
						oldPozY = y;
					}
				}
			}
		}
		if (event.type == Event::MouseButtonReleased) {
			if (event.key.code == Mouse::Left) {
				int ok = 2;
				if (noMovedPiece == PawnWhite && move == 1) {
					ok = figures.PawnW(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == PawnBlack && move == 1) {
					ok = figures.PawnB(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == RookWhite && move == 1) {
					ok = figures.RookW(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == RookBlack && move == 1) {
					ok = figures.RookB(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == BishopWhite && move == 1) {
					ok = figures.BishopW(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == BishopBlack && move == 1) {
					ok = figures.BishopB(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == QueenWhite && move == 1) {
					ok = figures.QueenW(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == QueenBlack && move == 1) {
					ok = figures.QueenB(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == KnightWhite && move == 1) {
					ok = figures.KnightW(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == KnightBlack && move == 1) {
					ok = figures.KnightB(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == KingBlack && move == 1) {
					ok = figures.KingB(oldPozX, oldPozY, x, y, board.board);
				}
				if (noMovedPiece == KingWhite && move == 1) {
					ok = figures.KingW(oldPozX, oldPozY, x, y, board.board);
				}
				if (ok == 1) {
					int nr = board.board[y][x];
					board.board[y][x] = noMovedPiece;
					if (y == 0 && noMovedPiece == PawnWhite)
					{
						transformWhite = true;
						transWX = x;
						transWY = y;
						board.board[y][x] = 0;
					}
					if (y == 7 && noMovedPiece == PawnBlack)
					{
						transformBlack = 1;
						transBX = x;
						transBY = y;
						board.board[y][x] = 0;
					}
					if (turn == -1) {
						if (checkWhite == 1) {
							figures.pozKingWhite(board.board);
							/*if (mateWhite == 0) {
								mateWhite = figures.mateWhiteCheck(figures.kingWX, figures.kingWY, board.board);
							}*/
							int s = figures.KingWhiteSahCheck(figures.kingWX, figures.kingWY, board.board);
							if (s == 0) {
								board.board[oldPozY][oldPozX] = noMovedPiece;
								board.board[y][x] = nr;
							}
							else {
								checkWhite = 0;
								figures.pozKingBlack(board.board);
								int sah = figures.KingBlackSahCheck(figures.kingBX, figures.kingBY, board.board);
								if (sah == 0) {
									checkBlack = 1;
									/*if (mateBlack == 0) {
										mateBlack = figures.mateBlackCheck(figures.kingBX, figures.kingBY, board.board);
									}*/
								}
								if (noMovedPiece == KingWhite || noMovedPiece == RookWhite) {
									figures.SetWKFM(1);
									figures.SetRWRM(1);
									figures.SetLWRM(1);
								}
								turn *= -1;
								if (nr != 0) {
									time.beatBoard.push_back(nr);
								}
								time.time_elapsed = time.zero;
								z = -1;
							}
						}
						else {
							figures.pozKingWhite(board.board);							
							int sa = figures.KingWhiteSahCheck(figures.kingWX, figures.kingWY, board.board);
							if (sa == 0) {
								board.board[oldPozY][oldPozX] = noMovedPiece;
								board.board[y][x] = nr;
								/*if (mateWhite == 0) {
									mateWhite = figures.mateWhiteCheck(figures.kingWX, figures.kingWY, board.board);
								}*/
							}
							else {
								figures.pozKingBlack(board.board);
								int sah = figures.KingBlackSahCheck(figures.kingBX, figures.kingBY, board.board);
								if (sah == 0) {
									checkBlack = 1;
									/*if (mateBlack == 0) {
										mateBlack = figures.mateBlackCheck(figures.kingBX, figures.kingBY, board.board);
									}*/
								}								
								if (noMovedPiece == KingWhite || noMovedPiece == RookWhite) {
									figures.SetWKFM(1);
									figures.SetRWRM(1);
									figures.SetLWRM(1);
								}
								turn *= -1;
								if (nr != 0) {
									time.beatBoard.push_back(nr);
								}
								time.time_elapsed = time.zero;
								z = -1;
							}
						}
					}
					else {
						if (checkBlack == 1) {
							figures.pozKingBlack(board.board);	
							/*if (mateBlack == 0) {
								mateBlack = figures.mateBlackCheck(figures.kingBX, figures.kingBY, board.board);
							}*/
							int s = figures.KingBlackSahCheck(figures.kingBX, figures.kingBY, board.board);
							if (s == 0) {
								board.board[oldPozY][oldPozX] = noMovedPiece;
								board.board[y][x] = nr;								
							}
							else {
								checkBlack = 0;
								figures.pozKingWhite(board.board);
								int sah = figures.KingWhiteSahCheck(figures.kingWX, figures.kingWY, board.board);
								if (sah == 0) {
									checkWhite = 1;
									/*if (mateWhite == 0) {
										mateWhite = figures.mateWhiteCheck(figures.kingWX, figures.kingWY, board.board);
									}*/
								}								
								if (noMovedPiece == KingBlack || noMovedPiece == RookBlack) {
									figures.SetBKFM(1);
									figures.SetRBRM(1);
									figures.SetLBRM(1);
								}
								turn *= -1;
								if (nr != 0) {
									time.beatBoard.push_back(nr);
								}
								time.time_elapsed = time.zero;
								z = -1;
							}
						}
						else {
							figures.pozKingBlack(board.board);
							int sa = figures.KingBlackSahCheck(figures.kingBX, figures.kingBY, board.board);
							if (sa == 0) {
								board.board[oldPozY][oldPozX] = noMovedPiece;
								board.board[y][x] = nr;
								/*if (mateBlack == 0) {
									mateBlack = figures.mateBlackCheck(figures.kingBX, figures.kingBY, board.board);
								}*/
							}
							else {
								figures.pozKingWhite(board.board);
								int sah = figures.KingWhiteSahCheck(figures.kingWX, figures.kingWY, board.board);
								if (sah == 0) {
									checkWhite = 1;
									/*if (mateWhite == 0) {
										mateWhite = figures.mateWhiteCheck(figures.kingWX, figures.kingWY, board.board);
									}*/
								}
								if (noMovedPiece == KingBlack || noMovedPiece == RookBlack) {
									figures.SetBKFM(1);
									figures.SetRBRM(1);
									figures.SetLBRM(1);
								}
								turn *= -1;
								if (nr != 0) {
									time.beatBoard.push_back(nr);
								}
								time.time_elapsed = time.zero;
								z = -1;
							}
						}
					}
				}
				else if (ok == 0) {
					board.board[oldPozY][oldPozX] = noMovedPiece;
				}
				move = 0;
			}
		}
	}
}

void Game::Render(Vector2i pos) {
	window.clear();
	if (time.enteringStop == 0) {
		window.draw(board.figures[0]);
		board.Drawing(window);
		if (move == 1) {
			MoveImages.setPosition(pos.x - dx, pos.y - dy);
			window.draw(MoveImages);
		}
		if (transformBlack) {
			board.figures[13].setPosition(transBX * size, transBY * size);
			window.draw(board.figures[13]);
		}
		if (transformWhite) {
			board.figures[14].setPosition(transWX * size, transWY * size);
			window.draw(board.figures[14]);
		}
		time.MenuDraw(window, board);
	}
	else if (time.enteringStop == -1) {
		board.ReSetSprite(time.enteringStop, time.config);
	}
	else {
		window.draw(time.text_enter);
		window.draw(time.text_images);
	}
	/*if (resFlag == 10) {
		resFlag = 0;
		mateBlack = 0;
		mateWhite = 0;
	}
	else if (mateBlack) {
		window.draw(time.win_white);
	}
	else if (mateWhite) {
		window.draw(time.win_black);
	}*/
	window.display();
}
