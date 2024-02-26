#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "option.h"
#include "decision.h"
#include "gamestate.h"
#include "game.h"
#include "calculator.h"
#define STAGES 20
GAME createGame() {
	GAME game;
	game.stages = STAGES;
	GAMESTATE gamestate;
	gamestate.currentStage = 0;
	game.gamestate = gamestate;
	game.isRunning = true;
	return game;
}

void startingMessage() {
	printf("ALL CHARACTERS AND EVENTS IN THIS GAME--EVEN THOSE BASED ON REAL LIFE ARE ENTIRELY FICTIONAL.\n");
	printf("THE FOLLOWING GAME CONTAINS COARSE LANGUAGE AND DUE TO ITS CONTENT IT SHOULD NOT BE PLAYED BY ANYONE.\n\n\n");
};

void stageZero(GAME *game) {
	int choice = 0;
	printf("You wake up in a dark room with no doors and windows. What will you do?\n");
	printf("1. Look around\n2. Feel the closest wall\n");
	printf("Your choise: ");
	if (scanf("%d", &choice) == 1) {
		switch (choice)
		{
		case 1:
			game->gamestate.decisions[0].choice = true;
			game->gamestate.decisions[0].option = LOOK_AROUND;
			game->gamestate.decisions[1].choice = false;
			game->gamestate.decisions[1].option = FEEL_WALL;
			break;
		case 2:
			game->gamestate.decisions[0].choice = false;
			game->gamestate.decisions[0].option = LOOK_AROUND;
			game->gamestate.decisions[1].choice = true;
			game->gamestate.decisions[1].option = FEEL_WALL;
			break;
		default:
			break;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageOne(GAME *game) {
	int choice = 0;
	if (game->gamestate.decisions[0].choice == true) {
		printf("You looked around in hope to see something, but the room is dark. Next time read more carefully.\n");
		printf("1. Run in a random direction\n2. Look even harder\n");
	}else if (game->gamestate.decisions[1].choice == true) {
		printf("You started feeling the wall. Somehow, you feel guilty doing it. The room is still dark.\n");
		printf("1. Keep feeling the wall\n2. Feel other walls\n");
	}
	printf("Your choise: ");
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && (game->gamestate.decisions[0].choice == true)) {
			game->gamestate.decisions[2].choice = true;
			game->gamestate.decisions[2].option = RUN_RAND;
			game->gamestate.decisions[3].choice = false;
			game->gamestate.decisions[3].option = LOOK_HARDER;
			game->gamestate.decisions[4].choice = false;
			game->gamestate.decisions[4].option = KEEP_FEELING;
			game->gamestate.decisions[5].choice = false;
			game->gamestate.decisions[5].option = FEEL_OTHER;
		}
		else if ((choice == 2) && (game->gamestate.decisions[0].choice == true)) {
			game->gamestate.decisions[2].choice = false;
			game->gamestate.decisions[2].option = RUN_RAND;
			game->gamestate.decisions[3].choice = true;
			game->gamestate.decisions[3].option = LOOK_HARDER;
			game->gamestate.decisions[4].choice = false;
			game->gamestate.decisions[4].option = KEEP_FEELING;
			game->gamestate.decisions[5].choice = false;
			game->gamestate.decisions[5].option = FEEL_OTHER;
		}
		else if ((choice == 1) && (game->gamestate.decisions[1].choice == true)) {
			game->gamestate.decisions[2].choice = false;
			game->gamestate.decisions[2].option = RUN_RAND;
			game->gamestate.decisions[3].choice = false;
			game->gamestate.decisions[3].option = LOOK_HARDER;
			game->gamestate.decisions[4].choice = true;
			game->gamestate.decisions[4].option = KEEP_FEELING;
			game->gamestate.decisions[5].choice = false;
			game->gamestate.decisions[5].option = FEEL_OTHER;
		}
		else if ((choice == 2) && (game->gamestate.decisions[1].choice == true)) {
			game->gamestate.decisions[2].choice = false;
			game->gamestate.decisions[2].option = RUN_RAND;
			game->gamestate.decisions[3].choice = false;
			game->gamestate.decisions[3].option = LOOK_HARDER;
			game->gamestate.decisions[4].choice = false;
			game->gamestate.decisions[4].option = KEEP_FEELING;
			game->gamestate.decisions[5].choice = true;
			game->gamestate.decisions[5].option = FEEL_OTHER;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageTwo(GAME* game) {
	int choice = 0;
	if (game->gamestate.decisions[2].choice == true) {
		printf("Running in a random direction is surprisingly useful.\nAfter a couple of days you entered a passage lighted by a couple dozen torches.\n");
		printf("There is an old man in a grey robe. After epicly shaking his staff, he screamed: YOU SHALL NOT PASS!\n");
		printf("1. Engage in a heroic and spectacular battle with the old man.\n2. Run past him.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[3].choice == true) {
		printf("Just like you, your character doesn't know when to stop. After looking in the dark for a couple of weeks,\nhe died of starvation\n");
		printf("THE END.\n");
		game->isRunning = false;
	} 	
	else if (game->gamestate.decisions[4].choice == true) {
		printf("After several uncomfortable minutes, the Wall stated that it did not give its consent.\n");
		printf("There is a thing called personal space, learn about it on one of Conestoga's webinars: www.conestogastudents.com\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (game->gamestate.decisions[5].choice == true) {
		printf("After feeling other walls you found a switch.\n");
		printf("1. Turn it on.\n2. Keep it as it is.\n");
		printf("Your choise: ");
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && (game->gamestate.decisions[2].choice == true)) {
			game->gamestate.decisions[6].choice = true;
			game->gamestate.decisions[6].option = GANDALF_BATTLE;
			game->gamestate.decisions[7].choice = false;
			game->gamestate.decisions[7].option = GANDLAF_RUN;
			game->gamestate.decisions[8].choice = false;
			game->gamestate.decisions[8].option = SWITCH_ON;
			game->gamestate.decisions[9].choice = false;
			game->gamestate.decisions[9].option = SWITCH_OFF;
		}
		else if ((choice == 2) && (game->gamestate.decisions[2].choice == true)) {
			game->gamestate.decisions[6].choice = false;
			game->gamestate.decisions[6].option = GANDALF_BATTLE;
			game->gamestate.decisions[7].choice = true;
			game->gamestate.decisions[7].option = GANDLAF_RUN;
			game->gamestate.decisions[8].choice = false;
			game->gamestate.decisions[8].option = SWITCH_ON;
			game->gamestate.decisions[9].choice = false;
			game->gamestate.decisions[9].option = SWITCH_OFF;
		}
		else if ((choice == 1) && (game->gamestate.decisions[5].choice == true)) {
			game->gamestate.decisions[6].choice = false;
			game->gamestate.decisions[6].option = GANDALF_BATTLE;
			game->gamestate.decisions[7].choice = false;
			game->gamestate.decisions[7].option = GANDLAF_RUN;
			game->gamestate.decisions[8].choice = true;
			game->gamestate.decisions[8].option = SWITCH_ON;
			game->gamestate.decisions[9].choice = false;
			game->gamestate.decisions[9].option = SWITCH_OFF;
		}
		else if ((choice == 2) && (game->gamestate.decisions[5].choice == true)) {
			game->gamestate.decisions[6].choice = false;
			game->gamestate.decisions[6].option = GANDALF_BATTLE;
			game->gamestate.decisions[7].choice = false;
			game->gamestate.decisions[7].option = GANDLAF_RUN;
			game->gamestate.decisions[8].choice = false;
			game->gamestate.decisions[8].option = SWITCH_ON;
			game->gamestate.decisions[9].choice = true;
			game->gamestate.decisions[9].option = SWITCH_OFF;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageThree(GAME* game) {
	int choice = 0;
	if (game->gamestate.decisions[6].choice == true) {
		printf("A man should die by the hand of a worthy opponent. Unfortunately, it didn't apply to you.\n");
		printf("In the middle of the battle with wizard(that we can't show due to the lack of budget),\na small man killed you by stabing in the back.\n");
		printf("You will never know where did he come from, why he is wizard's friend or what happened to the Middle-Earth.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (game->gamestate.decisions[7].choice == true) {
		printf("Maybe running past that guy was a good idea. Nevertheless, you stepped on something.\n");
		printf("The mythical object turned out to be a phone. Battery is low, who to call?\n");
		printf("1. 911.\n2. Your mom.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[8].choice == true) {
		printf("It turned out to be a light switch. Light in the room revealed that you are standing on a stage.\n");
		printf("It's like a game show, but instead of people it's all bees. A bee host yelled: WELCOME TO ANNUAL SPELLING BEE,\n");
		printf("LOSER GETS EATEN! PLESE SPELL HONORIFICABILITUDINITATIBUS!\n");
		printf("1. H-O-N-O-R-I-F-I-C-A-B-I-L-I-T-U-D-I-N-I-T-A-T-I-B-U-S.\n2. *start dancing like crazy*.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[9].choice == true) {
		printf("Maybe dying in this dark room completely alone is not that bad.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && (game->gamestate.decisions[7].choice == true)) {
			game->gamestate.decisions[10].choice = true;
			game->gamestate.decisions[10].option = CALL_POLICE;
			game->gamestate.decisions[11].choice = false;
			game->gamestate.decisions[11].option = CALL_MOM;
			game->gamestate.decisions[12].choice = false;
			game->gamestate.decisions[12].option = HONORIFICABILITUDINITATIBUS;
			game->gamestate.decisions[13].choice = false;
			game->gamestate.decisions[13].option = DANCE;
		}
		else if ((choice == 2) && (game->gamestate.decisions[7].choice == true)) {
			game->gamestate.decisions[10].choice = false;
			game->gamestate.decisions[10].option = CALL_POLICE;
			game->gamestate.decisions[11].choice = true;
			game->gamestate.decisions[11].option = CALL_MOM;
			game->gamestate.decisions[12].choice = false;
			game->gamestate.decisions[12].option = HONORIFICABILITUDINITATIBUS;
			game->gamestate.decisions[13].choice = false;
			game->gamestate.decisions[13].option = DANCE;
		}
		else if ((choice == 1) && (game->gamestate.decisions[8].choice == true)) {
			game->gamestate.decisions[10].choice = false;
			game->gamestate.decisions[10].option = CALL_POLICE;
			game->gamestate.decisions[11].choice = false;
			game->gamestate.decisions[11].option = CALL_MOM;
			game->gamestate.decisions[12].choice = true;
			game->gamestate.decisions[12].option = HONORIFICABILITUDINITATIBUS;
			game->gamestate.decisions[13].choice = false;
			game->gamestate.decisions[13].option = DANCE;
		}
		else if ((choice == 2) && (game->gamestate.decisions[8].choice == true)) {
			game->gamestate.decisions[10].choice = false;
			game->gamestate.decisions[10].option = CALL_POLICE;
			game->gamestate.decisions[11].choice = false;
			game->gamestate.decisions[11].option = CALL_MOM;
			game->gamestate.decisions[12].choice = false;
			game->gamestate.decisions[12].option = HONORIFICABILITUDINITATIBUS;
			game->gamestate.decisions[13].choice = true;
			game->gamestate.decisions[13].option = DANCE;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageFour(GAME* game) {
	int choice = 0;
	if (game->gamestate.decisions[10].choice == true) {
		printf("The operator showed impressive patience while listening to your story.\n");
		printf("After the story, you were told that drug use is punishable by law.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (game->gamestate.decisions[11].choice == true) {
		printf("Honey, how are you? Why do you rarely call? Are you eating well?\n");
		printf("Dad also says hello. You stuck in a dark tunnel? Are you messing with a bad crowd again?\n");
		printf("It would be better if you got a girlfriend, Im actually waiting for grandchildren...\n");
		printf("Your mum's yapping attaracted a cave troll.\n");
		printf("*achivement MAMAS BOY unlocked*\n");
		printf("1. Battle this troll.\n2. Pass him the phone.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[12].choice == true) {
		printf("Fun fact: bees communicate by dancing.\n");
		printf("Hundreds of bees attacked you for the wrong answer. You tried to escape, but we will never know what happened next.\n");
		printf("TO BEE CONTINUED.\n");
		game->isRunning = false;
	}
	else if (game->gamestate.decisions[13].choice == true) {
		printf("You danced a great batch of hip-hop mixed with tap dancing and convulsions of a dying duck.\n");
		printf("It looks like you are the first person to win. The bees happily accompanied you to the exit.\n");
		printf("NICE JOB!\n");
		game->isRunning = false;
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && (game->gamestate.decisions[11].choice == true)) {
			game->gamestate.decisions[14].choice = true;
			game->gamestate.decisions[14].option = TROLL_BATTLE;
			game->gamestate.decisions[15].choice = false;
			game->gamestate.decisions[15].option = TROLL_PHONE;
		}
		else if ((choice == 2) && (game->gamestate.decisions[11].choice == true)) {
			game->gamestate.decisions[14].choice = false;
			game->gamestate.decisions[14].option = TROLL_BATTLE;
			game->gamestate.decisions[15].choice = true;
			game->gamestate.decisions[15].option = TROLL_PHONE;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageFive(GAME* game) {
	int choice = 0;
	if (game->gamestate.decisions[14].choice == true) {
		printf("You entered a hand-to-hand combat with 20 feet tall troll. Outcome was predictable, inevitable and quick... \n");
		printf("Anyway, after you had defeated the troll a bunch of people in black cloaks came out of the wall.\n");
		printf("They asked you whether you've seen a little ginger girl. Hearing a negative answer,\n");
		printf("they took 50 points from Gryffindor and disappeared by running into the wall.\n");
		printf("1. Follow them.\n2. Steal from a dead troll.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[15].choice == true) {
		printf("While troll was given a lecture on good behavior \n");
		printf("and reasons why he didn't suit you as a friend,\n");
		printf("you sneaked into a room behind him.\n");
		printf("There is a laptop in the middle of the room, what should we play?\n");
		printf("1. EpicQuest.\n2. Calculator.\n");
		printf("Your choise: ");
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && (game->gamestate.decisions[14].choice == true)) {
			game->gamestate.decisions[16].choice = true;
			game->gamestate.decisions[16].option = FOLLOW_POTTER;
			game->gamestate.decisions[17].choice = false;
			game->gamestate.decisions[17].option = TROLL_STEAL;
			game->gamestate.decisions[18].choice = false;
			game->gamestate.decisions[18].option = EPIC_QUEST;
			game->gamestate.decisions[19].choice = false;
			game->gamestate.decisions[19].option = CALCULATOR;
		}
		else if ((choice == 2) && (game->gamestate.decisions[14].choice == true)) {
			game->gamestate.decisions[16].choice = false;
			game->gamestate.decisions[16].option = FOLLOW_POTTER;
			game->gamestate.decisions[17].choice = true;
			game->gamestate.decisions[17].option = TROLL_STEAL;
			game->gamestate.decisions[18].choice = false;
			game->gamestate.decisions[18].option = EPIC_QUEST;
			game->gamestate.decisions[19].choice = false;
			game->gamestate.decisions[19].option = CALCULATOR;
		}
		else if ((choice == 1) && (game->gamestate.decisions[15].choice == true)) {
			game->gamestate.decisions[16].choice = false;
			game->gamestate.decisions[16].option = FOLLOW_POTTER;
			game->gamestate.decisions[17].choice = false;
			game->gamestate.decisions[17].option = TROLL_STEAL;
			game->gamestate.decisions[18].choice = true;
			game->gamestate.decisions[18].option = EPIC_QUEST;
			game->gamestate.decisions[19].choice = false;
			game->gamestate.decisions[19].option = CALCULATOR;
		}
		else if ((choice == 2) && (game->gamestate.decisions[15].choice == true)) {
			game->gamestate.decisions[16].choice = false;
			game->gamestate.decisions[16].option = FOLLOW_POTTER;
			game->gamestate.decisions[17].choice = false;
			game->gamestate.decisions[17].option = TROLL_STEAL;
			game->gamestate.decisions[18].choice = false;
			game->gamestate.decisions[18].option = EPIC_QUEST;
			game->gamestate.decisions[19].choice = true;
			game->gamestate.decisions[19].option = CALCULATOR;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageSix(GAME* game) {
	int choice = 0;
	if (game->gamestate.decisions[16].choice == true) {
		printf("I don't why you thought running into the wall was a good idea, but seems like\n");
		printf("you have teleported to a pirate ship.\n");
		printf("1. Go to the cabin.\n2. Jump into the ocean.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[17].choice == true) {
		printf("It's fun to abuse the dead, especially when you're not the dead one.\n");
		printf("After stealing all the things from the troll, you found a club\n");
		printf("and a rag with which he covered his private areas.\n");
		printf("1. Try wearing his clothes.\n2. Play with a club.\n");
		printf("Your choise: ");
	}
	else if (game->gamestate.decisions[18].choice == true) {
		printf("\033[H\033[2J");
		startingMessage();
		stageZero(game);
		game -> gamestate.currentStage = 0;
	}
	else if (game->gamestate.decisions[19].choice == true) {
		printf("\033[H\033[2J");
		calculator();
		game->isRunning = false;
	}
	if ((game->gamestate.decisions[18].choice != true) && (game->gamestate.decisions[19].choice != true)) {
		if ((scanf("%d", &choice) == 1)) {
			if ((choice == 1) && (game->gamestate.decisions[16].choice == true)) {
				game->gamestate.decisions[20].choice = true;
				game->gamestate.decisions[20].option = SHIP_CABIN;
				game->gamestate.decisions[21].choice = false;
				game->gamestate.decisions[21].option = JUMP_OCEAN;
				game->gamestate.decisions[22].choice = false;
				game->gamestate.decisions[22].option = TROLL_WEAR;
				game->gamestate.decisions[23].choice = false;
				game->gamestate.decisions[23].option = PLAY_CLUB;
			}
			else if ((choice == 2) && (game->gamestate.decisions[16].choice == true)) {
				game->gamestate.decisions[20].choice = false;
				game->gamestate.decisions[20].option = SHIP_CABIN;
				game->gamestate.decisions[21].choice = true;
				game->gamestate.decisions[21].option = JUMP_OCEAN;
				game->gamestate.decisions[22].choice = false;
				game->gamestate.decisions[22].option = TROLL_WEAR;
				game->gamestate.decisions[23].choice = false;
				game->gamestate.decisions[23].option = PLAY_CLUB;
			}
			else if ((choice == 1) && (game->gamestate.decisions[17].choice == true)) {
				game->gamestate.decisions[20].choice = false;
				game->gamestate.decisions[20].option = SHIP_CABIN;
				game->gamestate.decisions[21].choice = false;
				game->gamestate.decisions[21].option = JUMP_OCEAN;
				game->gamestate.decisions[22].choice = true;
				game->gamestate.decisions[22].option = TROLL_WEAR;
				game->gamestate.decisions[23].choice = false;
				game->gamestate.decisions[23].option = PLAY_CLUB;
			}
			else if ((choice == 2) && (game->gamestate.decisions[17].choice == true)) {
				game->gamestate.decisions[20].choice = false;
				game->gamestate.decisions[20].option = SHIP_CABIN;
				game->gamestate.decisions[21].choice = false;
				game->gamestate.decisions[21].option = JUMP_OCEAN;
				game->gamestate.decisions[22].choice = false;
				game->gamestate.decisions[22].option = TROLL_WEAR;
				game->gamestate.decisions[23].choice = true;
				game->gamestate.decisions[23].option = PLAY_CLUB;
			}
		}
	}
	game->gamestate.currentStage += 1;
}