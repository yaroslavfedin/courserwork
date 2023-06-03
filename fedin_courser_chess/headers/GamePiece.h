#pragma once
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"

class GamePiece :  public  Pawn, public Bishop, public Knight, public Queen, public Rook, public King {

};