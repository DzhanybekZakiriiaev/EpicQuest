#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "option.h"
#include "decision.h"
#include "gamestate.h"
#include "game.h"
#include "calculator.h"
#include "illustrations.h"
#define STAGE_NUM 20
#define OPTION_NUM 40
GAME createGame() {
	GAME game;
	game.stages = STAGE_NUM;
	GAMESTATE gamestate;
	OPTION optionList[OPTION_NUM] = {
		LOOK_AROUND, FEEL_WALL,
		RUN_RAND, LOOK_HARDER, KEEP_FEELING, FEEL_OTHER,
		GANDALF_BATTLE, GANDLAF_RUN, SWITCH_ON, SWITCH_OFF,
		CALL_POLICE, CALL_MOM, HONORIFICABILITUDINITATIBUS, DANCE,
		TROLL_BATTLE, TROLL_PHONE,
		FOLLOW_POTTER, TROLL_STEAL, EPIC_QUEST, CALCULATOR,
		PROVE_GOD, ATTACK_GOD, TEST_YOUR_LUCK, TROLL_WEAR, PLAY_CLUB,
		ISLAND_TUNNEL, ISLAND_SHIP, ISLAND_AIRSHIP, KILL_HERO, EXPLAIN_HERO,
		KEEP_DIGGING, DIG_UP, MASSACRE, EAT_HERO
	};
	for (int i = 0; i < OPTION_NUM; i++) {
		gamestate.decisions[i].choice = false;
		gamestate.decisions[i].option = optionList[i];
	}
	gamestate.currentStage = 0;
	game.gamestate = gamestate;
	game.isRunning = true;
	return game;
}

void startingMessage() {
	printf("ALL CHARACTERS AND EVENTS IN THIS GAME--EVEN THOSE BASED ON REAL LIFE ARE ENTIRELY FICTIONAL.\n");
	printf("THE FOLLOWING GAME CONTAINS COARSE LANGUAGE AND DUE TO ITS CONTENT IT SHOULD NOT BE PLAYED BY ANYONE.\n\n\n");
};

bool isTrue(GAME game, OPTION option) {
	for (int i = 0; i < OPTION_NUM; i++) {
		if ((game.gamestate.decisions[i].option == option) && (game.gamestate.decisions[i].choice == true)) {
			return true;
		}
	}
	return false;
}

void setTrue(GAME* game, OPTION option) {
	for (int i = 0; i < OPTION_NUM; i++) {
		if (game->gamestate.decisions[i].option == option){
			game->gamestate.decisions[i].choice = true;
		}
	}
}

void setFalse(GAME* game, OPTION option) {
	for (int i = 0; i < OPTION_NUM; i++) {
		if (game->gamestate.decisions[i].option == option) {
			game->gamestate.decisions[i].choice = false;
		}
	}
}

void setAllFalse(GAME* game) {
	for (int i = 0; i < OPTION_NUM; i++) {
		game->gamestate.decisions[i].choice = false;
	}
}

void stageZero(GAME *game) {
	int choice = 0;
	printf("You wake up in a dark room with no doors and windows. What will you do?\n");
	printf("1. Look around\n2. Feel the closest wall\n");
	printf("Your choise: ");
	if (scanf("%d", &choice) == 1) {
		switch (choice)
		{
		case 1:
			setTrue(game, LOOK_AROUND);
			break;
		case 2:
			setTrue(game, FEEL_WALL);
			break;
		default:
			break;
		}
	}
	game->gamestate.currentStage += 1;
}

void stageOne(GAME *game) {
	int choice = 0;
	if (isTrue(*game, LOOK_AROUND)) {
		printf("You looked around in hope to see something, but the room is dark. Next time read more carefully.\n");
		printf("1. Run in a random direction\n2. Look even harder\n");
	}else if (isTrue(*game, FEEL_WALL)) {
		printf("You started feeling the wall. Somehow, you feel guilty doing it. The room is still dark.\n");
		printf("1. Keep feeling the wall\n2. Feel other walls\n");
	}
	printf("Your choise: ");
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && isTrue(*game, LOOK_AROUND)) {
			setTrue(game, RUN_RAND);
		}
		else if ((choice == 2) && isTrue(*game, LOOK_AROUND)) {
			setTrue(game, LOOK_HARDER);
		}
		else if ((choice == 1) && isTrue(*game, FEEL_WALL)) {
			setTrue(game, KEEP_FEELING);
		}
		else if ((choice == 2) && isTrue(*game, FEEL_WALL)) {
			setTrue(game, FEEL_OTHER);
		}
	}
	game->gamestate.currentStage += 1;
}

void stageTwo(GAME* game) {
	int choice = 0;
	if (isTrue(*game, RUN_RAND)) {
		printf("Running in a random direction is surprisingly useful.\nAfter a couple of days you entered a passage lighted by a couple dozen torches.\n");
		printf("There is an old man in a grey robe. After epicly shaking his staff, he screamed: YOU SHALL NOT PASS!\n");
		printf("1. Engage in a heroic and spectacular battle with the old man.\n2. Run past him.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, LOOK_HARDER)) {
		printf("Just like you, your character doesn't know when to stop. After looking in the dark for a couple of weeks,\nhe died of starvation\n");
		printf("THE END.\n");
		game->isRunning = false;
	} 	
	else if (isTrue(*game, KEEP_FEELING)) {
		printf("After several uncomfortable minutes, the Wall stated that it did not give its consent.\n");
		printf("There is a thing called personal space, learn about it on one of Conestoga's webinars: www.conestogastudents.com\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (isTrue(*game, FEEL_OTHER)) {
		printf("After feeling other walls you found a switch.\n");
		printf("1. Turn it on.\n2. Keep it as it is.\n");
		printf("Your choise: ");
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && isTrue(*game, RUN_RAND)) {
			setTrue(game, GANDALF_BATTLE);
		}
		else if ((choice == 2) && isTrue(*game, RUN_RAND)) {
			setTrue(game, GANDLAF_RUN);
		}
		else if ((choice == 1) && isTrue(*game, FEEL_OTHER)) {
			setTrue(game, SWITCH_ON);
		}
		else if ((choice == 2) && isTrue(*game, FEEL_OTHER)) {
			setTrue(game, SWITCH_OFF);
		}
	}
	game->gamestate.currentStage += 1;
}

void stageThree(GAME* game) {
	int choice = 0;
	if (isTrue(*game, GANDALF_BATTLE)) {
		printf("A man should die by the hand of a worthy opponent. Unfortunately, it didn't apply to you.\n");
		printf("In the middle of the battle with wizard(that we can't show due to the lack of budget),\na small man killed you by stabing in the back.\n");
		printf("You will never know where did he come from, why he is wizard's friend or what happened to the Middle-Earth.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (isTrue(*game, GANDLAF_RUN)) {
		printf("Maybe running past that guy was a good idea. Nevertheless, you stepped on something.\n");
		printf("The mythical object turned out to be a phone. Battery is low, who to call?\n");
		printf("1. 911.\n2. Your mom.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, SWITCH_ON)) {
		printf("It turned out to be a light switch. Light in the room revealed that you are standing on a stage.\n");
		printf("It's like a game show, but instead of people it's all bees. A bee host yelled: WELCOME TO ANNUAL SPELLING BEE,\n");
		printf("LOSER GETS EATEN! PLESE SPELL HONORIFICABILITUDINITATIBUS!\n");
		printf("1. H-O-N-O-R-I-F-I-C-A-B-I-L-I-T-U-D-I-N-I-T-A-T-I-B-U-S.\n2. *start dancing like crazy*.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, SWITCH_OFF)) {
		printf("Maybe dying in this dark room completely alone is not that bad.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && isTrue(*game, GANDLAF_RUN)) {
			setTrue(game, CALL_POLICE);
		}
		else if ((choice == 2) && isTrue(*game, GANDLAF_RUN)) {
			setTrue(game, CALL_MOM);
		}
		else if ((choice == 1) && isTrue(*game, SWITCH_ON)) {
			setTrue(game, HONORIFICABILITUDINITATIBUS);
		}
		else if ((choice == 2) && isTrue(*game, SWITCH_ON)) {
			setTrue(game, DANCE);
		}
	}
	game->gamestate.currentStage += 1;
}

void stageFour(GAME* game) {
	int choice = 0;
	if (isTrue(*game, CALL_POLICE)) {
		printf("The operator showed impressive patience while listening to your story.\n");
		printf("After the story, you were told that drug use is punishable by law.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (isTrue(*game, CALL_MOM)) {
		printf("Honey, how are you? Why do you rarely call? Are you eating well?\n");
		printf("Dad also says hello. You stuck in a dark tunnel? Are you messing with a bad crowd again?\n");
		printf("It would be better if you got a girlfriend, Im actually waiting for grandchildren...\n");
		printf("Your mum's yapping attaracted a cave troll.\n");
		printf("*achivement MAMAS BOY unlocked*\n");
		printf("1. Battle this troll.\n2. Pass him the phone.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, HONORIFICABILITUDINITATIBUS)) {
		printf("Fun fact: bees communicate by dancing.\n");
		printf("Hundreds of bees attacked you for the wrong answer. You tried to escape, but we will never know what happened next.\n");
		printf("TO BEE CONTINUED.\n");
		game->isRunning = false;
	}
	else if (isTrue(*game, DANCE)) {
		printf("You danced a great batch of hip-hop mixed with tap dancing and convulsions of a dying duck.\n");
		printf("It looks like you are the first person to win. The bees happily accompanied you to the exit.\n");
		printf("NICE JOB!\n");
		game->isRunning = false;
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && isTrue(*game, CALL_MOM)) {
			setTrue(game, TROLL_BATTLE);
		}
		else if ((choice == 2) && isTrue(*game, CALL_MOM)) {
			setTrue(game, TROLL_PHONE);
		}
	}
	game->gamestate.currentStage += 1;
}

void stageFive(GAME* game) {
	int choice = 0;
	if (isTrue(*game, TROLL_BATTLE)) {
		printf("You entered a hand-to-hand combat with 20 feet tall troll. Outcome was predictable, inevitable and quick... \n");
		printf("Anyway, after you had defeated the troll a bunch of people in black cloaks came out of the wall.\n");
		printf("They asked you whether you've seen a little ginger girl. Hearing a negative answer,\n");
		printf("they took 50 points from Gryffindor and disappeared by running into the wall.\n");
		printf("1. Follow them.\n2. Steal from a dead troll.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, TROLL_PHONE)) {
		printf("While troll was given a lecture on good behavior \n");
		printf("and reasons why he didn't suit you as a friend,\n");
		printf("you sneaked into a room behind him.\n");
		printf("There is a laptop in the middle of the room, what should we play?\n");
		printf("1. EpicQuest.\n2. Calculator.\n");
		printf("Your choise: ");
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice == 1) && isTrue(*game, TROLL_BATTLE)) {
			setTrue(game, FOLLOW_POTTER);
		}
		else if ((choice == 2) && isTrue(*game, TROLL_BATTLE)) {
			setTrue(game, TROLL_STEAL);
		}
		else if ((choice == 1) && isTrue(*game, TROLL_PHONE)) {
			setTrue(game, EPIC_QUEST);
		}
		else if ((choice == 2) && isTrue(*game, TROLL_PHONE)) {
			setTrue(game, CALCULATOR);
		}
	}
	game->gamestate.currentStage += 1;
}

void stageSix(GAME* game) {
	int choice = 0;
	if (isTrue(*game, FOLLOW_POTTER)) {
		printf("I don't why you thought running into the wall was a good idea, but seems like\n");
		printf("you have teleported to a entirely white room. A man-like figure is approaching you.\n");
		printf("The figure seems ideal, almost god-like. It's deep voice implice that it is god.\n");
		printGod();
		printf("1. Ask him to prove it.\n2. Attack God.\n3. *WOW, a third option to test your luck*\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, TROLL_STEAL)) {
		printf("It's fun to abuse the dead, especially when you're not the dead one.\n");
		printf("After stealing all the things from the troll, you found a club\n");
		printf("and a rag with which he covered his private areas.\n");
		printf("1. Try wearing his clothes.\n2. Play with a club.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, EPIC_QUEST)) {
		printf("\033[H\033[2J");
		setAllFalse(game);
		startingMessage();
		stageZero(game);
		game -> gamestate.currentStage = 0;
	}
	else if (isTrue(*game, CALCULATOR)) {
		printf("\033[H\033[2J");
		calculator();
		game->isRunning = false;
	}
	if ((!isTrue(*game, EPIC_QUEST)) && (!isTrue(*game, CALCULATOR))) {
		if ((scanf("%d", &choice) == 1)) {
			if ((choice == 1) && isTrue(*game, FOLLOW_POTTER)) {
				setTrue(game, PROVE_GOD);
			}
			else if ((choice == 2) && isTrue(*game, FOLLOW_POTTER)) {
				setTrue(game, ATTACK_GOD);
			}
			else if ((choice == 3) && isTrue(*game, FOLLOW_POTTER)) {
				setTrue(game, TEST_YOUR_LUCK);
			}
			else if ((choice == 1) && isTrue(*game, TROLL_STEAL)) {
				setTrue(game, TROLL_WEAR);
			}
			else if ((choice == 2) && isTrue(*game, TROLL_STEAL)) {
				setTrue(game, PLAY_CLUB);
			}
		}
	}
	game->gamestate.currentStage += 1;
}

void stageSeven(GAME* game) {
	int choice = 0;
	if (isTrue(*game, PROVE_GOD)) {
		godProve();
		printf("You are stranded on a desert island in the middle of the ocean.\n");
		printf("There are a couple of logs lying near you, what will you make?\n");
		printf("1. Make a tunnel to escape.\n2. Make a ship to escape.\n3. Make an airship to escape.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, ATTACK_GOD)) {
		printf("\033[H\033[2J");
		startingMessage();
		stageZero(game);
		game->gamestate.currentStage = 0;
	}
	else if (isTrue(*game, TEST_YOUR_LUCK)) {
		printf("You are stranded on a desert island in the middle of the ocean.\n");
		printf("There are a couple of logs lying near you, what will you make?\n");
		printf("1. Make a tunnel to escape.\n2. Make a ship to escape.\n3. Make an airship to escape.\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, TROLL_WEAR)) {
		printf("While you were dressing up as a troll, a blond man on a horse appeared out of nowhere.\n");
		printf("After saying that his name was Prince Charming, he demanded that you release Fiona.\n");
		printf("1. It is just a misunderstanding.\n2. I AM A TROLL(kill weak human).\n");
		printf("Your choise: ");
	}
	if (isTrue(*game, PLAY_CLUB)) {
		printf("It took many attempts to finally lift it above my head.\n");
		printf("After your triumph and new overhead press pr,");
		printf(" the club fell and crushed your skull.\nTHE END.\n");
		game->isRunning = false;
	}
	if (!isTrue(*game, ATTACK_GOD)) {
		if ((scanf("%d", &choice) == 1)) {
			if ((choice == 1) && (isTrue(*game, TEST_YOUR_LUCK) || isTrue(*game, PROVE_GOD))) {
				setTrue(game, ISLAND_TUNNEL);
			}
			else if ((choice == 2) && (isTrue(*game, TEST_YOUR_LUCK) || isTrue(*game, PROVE_GOD))) {
				setTrue(game, ISLAND_SHIP);
			}
			else if ((choice == 3) && (isTrue(*game, TEST_YOUR_LUCK) || isTrue(*game, PROVE_GOD))) {
				setTrue(game, ISLAND_AIRSHIP);
			}
			else if ((choice == 1) && isTrue(*game, TROLL_WEAR)) {
				setTrue(game, EXPLAIN_HERO);
			}
			else if ((choice == 2) && isTrue(*game, TROLL_WEAR)) {
				setTrue(game, KILL_HERO);
			}
		}
	}
	game->gamestate.currentStage += 1;
}

void stageEight(GAME* game) {
	int choice = 0;
	if (isTrue(*game, ISLAND_SHIP)) {
		printf("The ocean is full of dangers, one of them is sharks.\n");
		printf("Apparently one of them climbed onto the ship while you were sleeping.\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	else if (isTrue(*game, ISLAND_AIRSHIP)) {
		printf("You confidently sailed your airship, airbags were full of food\n");
		printf("and airstreams guided you through sky. However, you didn't account airsharks.\n");
		printf("They ate you at night.\nTHE END.\n");
		game->isRunning = false;
	}
	else if (isTrue(*game, ISLAND_TUNNEL)) {
		printf("It takes a long time to dig a tunnel, where are we digging now?\n");
		printf("1. Dig down.\n2. Dig right.\n3. Dig left.\n4. Dig up\n");
		printf("Your choise: ");
	}
	else if (isTrue(*game, EXPLAIN_HERO)) {
		printf("While you were trying to explain yourself, the blonde stabbed you with his sword.\n");
		printf("I don’t think it’s possible to explain anything to such an idiot, he didn’t even distinguish you from a troll\n");
		printf("THE END.\n");
		game->isRunning = false;
	}
	if (isTrue(*game, KILL_HERO)) {
		printf("STUPID HUMAN DOUBTED YOUR MIGHT!!!\n");
		printf("1. KILL MORE HUMANS. DO A MASSACRE!!!\n2. EAT HUMAN!!!\n");
		printf("Your choise: ");
		game->isRunning = false;
	}
	if ((scanf("%d", &choice) == 1)) {
		if ((choice != 4) && isTrue(*game, ISLAND_TUNNEL)) {
			setTrue(game, KEEP_DIGGING);
		}
		else if ((choice == 4) && isTrue(*game, ISLAND_TUNNEL)) {
			printf("Well, you kind of stupidly crawled out of the hole you dug\n");
			setFalse(game, ISLAND_TUNNEL);
			game->gamestate.currentStage = 6;
		}
		else if ((choice == 1) && isTrue(*game, KILL_HERO)) {
			setTrue(game, MASSACRE);
		}
		else if ((choice == 2) && isTrue(*game, KILL_HERO)) {
			setTrue(game, EAT_HERO);
		}
	}
	game->gamestate.currentStage += 1;
}