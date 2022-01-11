#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "Inventory.h"

void Story_Initialize()
{
	story[0] = "December 14, 2019";
	story[1] = "A drone found a mysterious island where evolution has progressed without interference of outside world.";
	story[2] = "For further research government has sent us, a bunch of scientists to investigate the island.";
	story[3] = "December 16, 2019";
	story[4] = "We (Me and Kurama) are one day away from the island.";
	story[5] = "December 16, 2019";
	story[6] = "This island has humans on it. Are they really human? I don’t know.";
	story[7] = "But with their monstrous strength, they ripped the boat apart and took my friends. I hid under my bed to escape their wrath.";
	story[8] = "I need to find my friends.";
	story[9] = "December 18, 2019";
	story[10] = "There was some military equipment that I found. Nothing fancy but it should help. Time to test my luck.";
	storyEnd[0] = "December 21, 2019";
	storyEnd[1] = "I have barely defeated the king of the monster. Saved my almost dying friends. Time to get back to human world.";
	storyEnd[2] = "December 22, 2019";
	storyEnd[3] = "I was late. While I was running foolish errand, my friends were killed.";
}

void Level1_Initialize()
{
	paused = false;
	playerDead = false;
	total_wall = 10;
	total_troops = 4;
	total_items = 7;
	total_projectile = 1;
	MainC = Player(0, 73.01, 110.0f/1.8, 58.0f/1.8, iLoadImage("images\\male\\Idle__000.png"), 100);
	Wall[0] = Object(0, 0, 73, 1280, iLoadImage("images\\wall.jpg"));
	Wall[1] = Object(810, 145, 73, 467, iLoadImage("images\\wall.jpg"));
	Wall[2] = Object(1070, 720 - 431, 68, 210, iLoadImage("images\\wall.jpg"));
	Wall[3] = Object(330, 720 - 431, 68, 395, iLoadImage("images\\wall.jpg"));
	Wall[4] = Object(83, 720 - 431, 68, 210, iLoadImage("images\\wall.jpg"));
	Wall[5] = Object(798, 720 - 354, 68, 203, iLoadImage("images\\wall.jpg"));
	Wall[6] = Object(263, 720 - 227, 68, 203, iLoadImage("images\\wall.jpg"));
	Wall[7] = Object(0, 720 - 312, 68, 203, iLoadImage("images\\wall.jpg"));
	Wall[8] = Object(0, 0, 720, 0, iLoadImage("images\\wall.jpg"));
	Wall[9] = Object(1280, 0, 720, 0, iLoadImage("images\\wall.jpg"));
	Troops[0] = Enemy(300, 73, 80, 80, iLoadImage("images\\wall.jpg"), 200, 1, 300);
	Troops[1] = Enemy(800, 66, 80, 80, iLoadImage("images\\wall.jpg"), 200, 2, 300);
	Troops[2] = Enemy(500, 350, 56, 72, iLoadImage("images\\wall.jpg"), 200, 3, 300);
	Troops[3] = Enemy(600, 400, 31, 47, iLoadImage("images\\wall.jpg"), 200, 4, 360);
	pickup[0] = Pickup(1191, 73, 20, 20, iLoadImage("images\\Food\\apple.png"), 0, false);
	pickup[1] = Pickup(260, 357, 22, 22, iLoadImage("images\\Food\\Meat.png"), 0, false);
	pickup[2] = Pickup(901, 426, 20, 20, iLoadImage("images\\Food\\apple.png"), 0, false);
	pickup[3] = Pickup(992, 220, 20, 15, iLoadImage("images\\Flask\\A2.png"), 1, false);
	pickup[4] = Pickup(27, 477, 20, 15, iLoadImage("images\\Flask\\A3.png"), 1, false);
	pickup[5] = Pickup(684, 362, 20, 15, iLoadImage("images\\Flask\\A6.png"), 1, false);
	pickup[6] = Pickup(1091, 73, 20, 20, iLoadImage("images\\bag.png"), 2, false);
	Circle_fire[0] = Projectile(300, 530, 2);
	Next_Level = Object(420, 560, 470, 660, "Portal");
	Bat.clear();
	Fire.clear();
}

void Level2_Initialize()
{
	paused = false;
	playerDead = false;
	total_wall = 22;
	total_troops = 6;
	total_items = 7;
	total_projectile = 0;
	MainC = Player(1200, 61, 110.0f / 1.8, 58.0f / 1.8, iLoadImage("images\\male\\Idle__000.png"), 100);
	Wall[0] = Object(0, 0, 1280, 60, "Wall 0");
	Wall[1] = Object(92, 142, 172, 175, "Wall 1");
	Wall[2] = Object(0, 168, 78, 197, "Wall 2");
	Wall[3] = Object(967, 181, 1047, 203, "Wall 3");
	Wall[4] = Object(1117, 152, 1277, 180, "Wall 4");
	Wall[5] = Object(855, 294, 938, 320, "Wall 5");
	Wall[6] = Object(1176, 261, 1278, 283, "Wall 6");
	Wall[7] = Object(852, 319, 884, 480, "Wall 7");
	Wall[8] = Object(1200, 355, 1277, 383, "Wall 8");
	Wall[9] = Object(1055, 317, 1129, 348, "Wall 9");
	Wall[10] = Object(1022, 317, 1056, 463, "Wall 10");
	Wall[11] = Object(888, 453, 1177, 480, "Wall 11");
	Wall[12] = Object(582, 529, 849, 562, "Wall 12");
	Wall[13] = Object(634, 374, 657, 529, "Wall 13");
	Wall[14] = Object(466, 467, 547, 492, "Wall 14");
	Wall[15] = Object(462, 492, 498, 718, "Wall 15");
	Wall[16] = Object(227, 370, 623, 397, "Wall 16");
	Wall[17] = Object(146, 403, 224, 425, "Wall 17");
	Wall[18] = Object(59, 422, 138, 449, "Wall 18");
	Wall[19] = Object(0, 456, 62, 482, "Wall 19");
	Wall[20] = Object(0, 0, 0, 720, "Border Left");
	Wall[21] = Object(1280, 0, 1280, 720, "Border Right");
	Troops[0] = Enemy(200, 63, 100, 63, iLoadImage("images\\bird.png"), 200, 7, 0);
	Troops[1] = Enemy(500, 63, 100, 63, iLoadImage("images\\bird.png"), 200, 7, 0);
	Troops[2] = Enemy(500, 500, 83, 106, iLoadImage("images\\bird.png"), 200, 8, 0);
	Troops[3] = Enemy(18, 201, 100, 50, iLoadImage("images\\portal.png"), 750, 5, 400);
	Troops[4] = Enemy(75, 544, 31, 47, iLoadImage("images\\bird.png"), 100, 4, 360);
	Troops[5] = Enemy(990, 479, 56, 72, iLoadImage("images\\bird.png"), 100, 3, 300);
	pickup[0] = Pickup(256, 399, 20, 20, iLoadImage("images\\Food\\apple.png"), 0, false);
	pickup[1] = Pickup(8, 201, 22, 22, iLoadImage("images\\Food\\Meat.png"), 0, false);
	pickup[2] = Pickup(904, 323, 20, 20, iLoadImage("images\\Food\\Meat.png"), 0, false);
	pickup[3] = Pickup(1009, 203, 20, 20, iLoadImage("images\\Food\\apple.png"), 0, false);
	pickup[4] = Pickup(120, 450, 20, 15, iLoadImage("images\\Flask\\A2.png"), 1, false);
	pickup[5] = Pickup(390, 66, 20, 15, iLoadImage("images\\Flask\\A6.png"), 1, false);
	pickup[6] = Pickup(1256, 383, 20, 15, iLoadImage("images\\Flask\\A4.png"), 1, false);
	Next_Level = Object(17, 482, 67, 582, "Portal");
	sideLevel = Object(890, 325, 890 + 108, 325 + 61, "Side Quest");
	Bat.clear();
	Fire.clear();
}

void Level3_Initialize()
{
	paused = false;
	playerDead = false;
	total_wall = 13;
	total_items = 9;
	total_troops = 5;
	total_projectile = 2;
	alternateEnd = true;
	MainC = Player(1250, 73, 110.0f / 1.8, 58.0f / 1.8, iLoadImage("images\\male\\Idle__000.png"), 100);
	Wall[0] = Object(0, 0, 1280, 72, "Wall 0");
	Wall[1] = Object(912, 170, 1065, 209, "Wall 1");
	Wall[2] = Object(0, 173, 816, 210, "Wall 2");
	Wall[3] = Object(752, 217, 816, 315, "Wall 3");
	Wall[4] = Object(0, 310, 243, 346, "Wall 4");
	Wall[5] = Object(145, 457, 409, 495, "Wall 5");
	Wall[6] = Object(348, 340, 409, 458, "Wall 6");
	Wall[7] = Object(544, 461, 693, 504, "Wall 7");
	Wall[8] = Object(544, 345, 608, 455, "Wall 8");
	Wall[9] = Object(903, 506, 1054, 550, "Wall 9");
	Wall[10] = Object(1078, 604, 1278, 645, "Wall 10");
	Wall[11] = Object(0, 0, 0, 720, "Border Left");
	Wall[12] = Object(1280, 0, 1280, 720, "Border Right");
	Troops[0] = Enemy(15, 72, 100, 50, iLoadImage("images\\bird.png"), 750, 5, 0);
	Troops[1] = Enemy(10, 350, 100, 50, iLoadImage("images\\bird.png"), 750, 5, 0);
	Troops[2] = Enemy(807, 62, 80, 80, iLoadImage("images\\bird.png"), 200, 2, 0);
	Troops[3] = Enemy(240, 205, 52, 72, iLoadImage("images\\portal.png"), 200, 3, 400);
	Troops[4] = Enemy(141, 648, 83, 106, iLoadImage("images\\portal.png"), 200, 8, 400);
	pickup[0] = Pickup(1082, 645, 22, 22, iLoadImage("images\\Food\\Meat.png"), 0, false);
	pickup[1] = Pickup(655, 505, 22, 22, iLoadImage("images\\Food\\Meat.png"), 0, false);
	pickup[2] = Pickup(370, 73, 20, 20, iLoadImage("images\\Food\\apple.png"), 0, false);
	pickup[3] = Pickup(261, 497, 20, 20, iLoadImage("images\\Food\\apple.png"), 0, false);
	pickup[4] = Pickup(563, 210, 20, 15, iLoadImage("images\\Flask\\A2.png"), 1, false);
	pickup[5] = Pickup(126, 347, 20, 15, iLoadImage("images\\Flask\\A3.png"), 1, false);
	pickup[6] = Pickup(973, 209, 20, 15, iLoadImage("images\\Flask\\A6.png"), 1, false);
	pickup[7] = Pickup(55, 211, 20, 15, iLoadImage("images\\Flask\\A6.png"), 1, false);
	pickup[8] = Pickup(70, 211, 20, 20, iLoadImage("images\\bag.png"), 2, false);
	Circle_fire[0] = Projectile(971, 538, 2);
	Circle_fire[1] = Projectile(607, 498, 2);
	Next_Level = Object(1178, 645, 1228, 745, "Portal");
	Bat.clear();
	Fire.clear();
}

void BossLevel_Initialize()
{
	paused = false;
	total_wall = 8;
	total_items = 0;
	total_troops = 1;
	total_projectile = 0;
	MainC = Player(462, 448, 110.0f / 1.8, 58.0f / 1.8, iLoadImage("images\\male\\Idle__000.png"), 100);
	Wall[0] = Object(0, 0, 1280, 720 - 638, "Ground");
	Wall[1] = Object(0, 720 - 552, 166, 720 - 513, "Wall 1");
	Wall[2] = Object(173, 720 - 428, 337, 720 - 387, "Wall 2");
	Wall[3] = Object(341, 720 - 321, 938, 720 - 279, "Wall 3");
	Wall[4] = Object(939, 720 - 428, 1107, 720 - 387, "Wall 4");
	Wall[5] = Object(1109, 720 - 552, 1278, 720 - 513, "Wall 2");
	Wall[6] = Object(0, 0, 0, 720, "Border Left");
	Wall[7] = Object(1280, 0, 1280, 720, "Border Right");
	Troops[0] = Enemy(500, 50, 118, 92, NULL, 5000, 9, 0);
	Bat.clear();
	Fire.clear();
}

void toggleRain()
{
	if (playerDead)
	{
		isRaining = false;
		mciSendString("close music\\5.rain2.wav", NULL, 0, 0);
	}
	if (isRaining)
	{
		isRaining = false;
		playerVelocity = 150;
		friction = 155;
		mciSendString("close music\\5.rain2.wav", NULL, 0, 0);
	}
	else
	{
		isRaining = true;
		playerVelocity = 150;
		friction = 100;
		mciSendString("play music\\5.rain2.wav", NULL, 0, 0);
	}
}

void Rain()
{
	if (isRaining)
	{		
		for (int i = 0; i < 50; i++)
		{
			int rx1 = rand() % 1280;
			int ry1 = rand() % 720;
			int rx2 = 10 + rand() % 2;
			int ry2 = 10 + rand() % 2;
			iSetColor(3, 173, 252);
			iLine(rx1, ry1, rx1 - rx2, ry1 - ry2);
		}
	}
}

#endif