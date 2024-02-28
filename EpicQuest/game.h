#pragma once
#include <stdbool.h>
#include "gamestate.h"
typedef struct game {
	int stages;
	GAMESTATE gamestate;
	bool isRunning;
}GAME;

GAME createGame();

void startingMessage();

bool isTrue(GAME, OPTION);

void setTrue(GAME*, OPTION);

void stageZero(GAME*);

void stageOne(GAME*);

void stageTwo(GAME*);

void stageThree(GAME*);

void stageFour(GAME*);

void stageFive(GAME*);

void stageSix(GAME*);

void stageSeven(GAME*);

void stageEight(GAME*);