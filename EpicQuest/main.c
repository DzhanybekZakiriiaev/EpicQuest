#include "option.h"
#include "decision.h"
#include "gamestate.h"
#include "game.h"
int main(void) {
	GAME game = createGame();
	startingMessage();
	do {
		if (game.gamestate.currentStage == 0) {
			stageZero(&game);
		}
		else if (game.gamestate.currentStage == 1) {
			stageOne(&game);
		}
		else if (game.gamestate.currentStage == 2) {
			stageTwo(&game);
		}
		else if (game.gamestate.currentStage == 3) {
			stageThree(&game);
		}
		else if (game.gamestate.currentStage == 4) {
			stageFour(&game);
		}
		else if (game.gamestate.currentStage == 5) {
			stageFive(&game);
		}
		else if (game.gamestate.currentStage == 6) {
			stageSix(&game);
		}
		else if (game.gamestate.currentStage == 7) {
			stageSeven(&game);
		}
		else if (game.gamestate.currentStage == 8) {
			stageEight(&game);
		}
	} while(game.isRunning);
	return 0;
}

