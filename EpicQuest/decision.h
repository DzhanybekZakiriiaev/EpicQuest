#pragma once
#include <stdbool.h>
#include "option.h"
typedef struct decision {
	int stageNumber;
	OPTION option;
	bool choice;
}DECISION;