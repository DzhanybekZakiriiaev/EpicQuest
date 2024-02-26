#pragma once
#include <stdbool.h>
#include "decision.h"
#define POSIBILITIES 40
typedef struct gamestate{
	int currentStage;
	DECISION decisions[POSIBILITIES];
}GAMESTATE;