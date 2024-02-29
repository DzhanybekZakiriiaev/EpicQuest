#pragma once
#include <stdbool.h>
#include "decision.h"
#define OPTION_NUM 60
typedef struct gamestate{
	int currentStage;
	DECISION decisions[OPTION_NUM];
}GAMESTATE;