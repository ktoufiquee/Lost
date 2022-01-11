#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "PlayerPhysics.h"
string storyTeller[15];
int currStory, storyIterator;
bool storySkip;

void Popup()
{
	if(telepopup_timer > 0)
	{
		iSetColor(255, 255, 255);
		iText(500, 250, "CAN'T TELEPORT", GLUT_BITMAP_TIMES_ROMAN_24);
		telepopup_timer--;
	}
}
void pregameTransition()
{
	iShowImage(0, 0, 1280, 720, TransitionImage[(3 * curr_frame) % TransitionImage.size()]);
	curr_frame++;
	if(3 * curr_frame > 148)
	{
		game_state = 0;
	}
}

void login()
{
	if(old_login_transition && new_login_transition)
	{
		iShowImage(0, 0, 1280, 720, login_start);
		iShowImage(old_user_button_x, 720-438, 380, 94, old_user_button);
		iShowImage(new_user_button_x, 720-570, 380, 94, new_user_button);
		if(old_login_transition)
		{
			old_user_button_x += 4;			
			if(old_user_button_x >= 436)
			{
				old_login_transition = false;
			}
		}
		if(new_login_transition)
		{
			new_user_button_x -= 7; 
			if(new_user_button_x <= 436)
			{
				new_login_transition = false;
			}
		}		
	}
	else
	{
		iShowImage(0, 0, 1280, 720, login_screen);
		curr_frame = 0;
	}
}

void Main_menu()
{
	if (h == 0)
	{
		iShowImage(0, 0, 1280, 720, Lost_menu);
	}
	if (h == 1)
	{
		iShowImage(0, 0, 1280, 720, newgame);
	}
	if (h == 2)
	{
		iShowImage(0, 0, 1280, 720, loadgame);
	}
	if (h == 3)
	{
		iShowImage(0, 0, 1280, 720, instructions);
	}
	if (h == 4)
	{
		iShowImage(0, 0, 1280, 720, highscores);
	}
	if (h == 5)
	{
		iShowImage(0, 0, 1280, 720, credit);
	}
	if (h == 6)
	{
		iShowImage(0, 0, 1280, 720, ex);
	}
	iSetColor(255, 255, 255);
	iText(50, 690, to_char("Welcome, " + users[current_user].name + "!"), GLUT_BITMAP_TIMES_ROMAN_24);
	iShowImage(50, 625, 667 / 20, 980 / 20, AchievementIcon);
	if(playsound)
	{
		iShowImage(100, 627, 10, sound_on_icon);
	}
	if(!playsound)
	{
		iShowImage(100, 627, 10, sound_off_icon);
	}
}

void Instruction()
{
	iShowImage(0, 0, 1280, 720, instruction);
}

void Credits()
{
	iShowImage(0, 0, 1280, 720, credits);
}

void Hero_selection()
{
	iShowImage(0, 0, 1280, 720, Hero);
}

void Pause_Menu()
{
	if (paused && !Inventory)
	{
		iShowImage(0, 0, 1280, 720, pauseScreen);
	}
}

void deadMenu()
{
	if(playerDead)
	{
		iShowImage(0, 0, 1280, 720, deadScreen);
	}
}

void restartLevel()
{
	if (game_state == 1)
	{
		Level1_Initialize();

	}
	if (game_state == 2)
	{
		Level2_Initialize();
	}
	if (game_state == 3)
	{
		Level3_Initialize();
	}
	if (game_state == 4)
	{
		BossLevel_Initialize();
	}
}

void storyTransition()
{
	iShowImage(0, 0, 1280, 720, storyScreen);
	if(!storySkip)
	{ 
		if (currStory < 11 && !storyTrack[currStory])
		{
			storyTeller[currStory] = story[currStory].substr(0, storyIterator);
			if(curr_frame % 3 == 0)
			{
				storyIterator++;
			}
			if (storyIterator > story[currStory].size())
			{
				storyTrack[0] = true;
				storyIterator = 0;
				currStory++;
			}
		}
		iSetColor(255, 64, 64);
		iText(50, 600, to_char(storyTeller[0]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 575, to_char(storyTeller[1]), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(50, 550, to_char(storyTeller[2]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(50, 500, to_char(storyTeller[3]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 475, to_char(storyTeller[4]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(50, 425, to_char(storyTeller[5]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 400, to_char(storyTeller[6]), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(50, 375, to_char(storyTeller[7]), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(50, 350, to_char(storyTeller[8]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(50, 300, to_char(storyTeller[9]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 275, to_char(storyTeller[10]), GLUT_BITMAP_TIMES_ROMAN_24);
		curr_frame++;
	}
	else
	{
		iSetColor(255, 64, 64);
		iText(50, 600, to_char(story[0]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 575, to_char(story[1]), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(50, 550, to_char(story[2]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(50, 500, to_char(story[3]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 475, to_char(story[4]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(50, 425, to_char(story[5]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 400, to_char(story[6]), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(50, 375, to_char(story[7]), GLUT_BITMAP_TIMES_ROMAN_24);
		iText(50, 350, to_char(story[8]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 64, 64);
		iText(50, 300, to_char(story[9]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 275, to_char(story[10]), GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iText(450, 100, "DOUBLE PRESS LMB TO SKIP", GLUT_BITMAP_TIMES_ROMAN_24);
}

void storyEndTransition()
{
	if(alternateEnd)
	{
		iShowImage(0, 0, 1280, 720, endScreen1);
	}
	else
	{
		iShowImage(0, 0, 1280, 720, endScreen2);
	}
	if (alternateEnd)
	{
		iSetColor(255, 64, 64);
		iText(50, 460, to_char(storyEnd[2]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 410, to_char(storyEnd[3]), GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		iSetColor(255, 64, 64);
		iText(50, 460, to_char(storyEnd[0]), GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(white);
		iText(50, 410, to_char(storyEnd[1]), GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iText(500, 100, "---THE END---", GLUT_BITMAP_TIMES_ROMAN_24);
}

void AudioFix()
{
	if (audioSetting)
	{
		if (game_state <= 0)
		{
			playerDead = false;
		}
		if (playerDead || paused)
		{
			playsound = false;
		}
		else
		{
			playsound = true;
		}
	}
	else
	{
		playsound = false;
	}
}

void moveFunctions()
{
	trackAchievement();
	if(!paused && !playerDead)
	{
		MainC.Draw(MainC.x, MainC.y + jump_y);
		if (energy_width < 100)
		{
			energy_width += (energyRegenFactor * (1.0f / 60)) ;
		}
		Rain();
		SwordAttack();
		Hud();
		Health();
		pickup_collision();
		Moveset_Basic();
		Moveset_Jump();
		Moveset_Gravity();
		ShowBullets();
		GunCollision();
		Popup();
		ShowLaser();
		if( game_state == 1 || game_state == 3)
		{
			projectile_collision();
		}
	}
}

void drawEnemy()
{
	if(!paused)
	{
		for (int i = 0; i < total_troops; i++)
		{
			Troops[i].Draw();
			Troops[i].CheckPlayer();
			Troops[i].Behaviour();
		}
		if (game_state == 1)
		{
			Circle_fire[0].Draw();
		}
		if (game_state == 3)
		{
			Circle_fire[0].Draw();
			Circle_fire[1].Draw();
		}
		if (game_state == 4)
		{
			if (Troops[0].Dead == true)
			{
				game_state = 10;
			}
		}
	}
}

void drawPickup()
{
	for (int i = 0; i < total_items; i++)
	{
		pickup[i].Draw();
	}
}

void frameCount()
{
	curr_frame++;
	if (curr_frame % 4 == 0)
		cnt++;
	if (curr_frame % 6 == 0)
		plant_frame++;
	if (curr_frame % 8 == 0)
		portal_frame++;
	if (curr_frame % 4 == 0)
		bomber_frame++;
}

void viewScore()
{
	if(!paused && !Inventory && !playerDead)
	{
		iSetColor(255, 255, 255);
		char score[1000] = { 0 };
		strcpy(score, n);
		strcat(score, " ");
		strcat(score, to_char(Player_score));
		iText(1145, 637, score, GLUT_BITMAP_9_BY_15);
	}
}

void Level_1()
{
	iShowImage(0, 0, 1289, 724, level1);
	Next_Level.Draw();
	moveFunctions();
	frameCount();
	drawEnemy();
	drawPickup();
	viewScore();
	if (ObjCollision(MainC, Next_Level))
	{
		if (MainC.health == 100)
		{
			achieved[3] = true;
		}
		game_state = 2;
		Level2_Initialize();
	}
	Player_score++;
	Show_Inventory();
	Pause_Menu();
	deadMenu();
}

void Level_2()
{
	iShowImage(0, 0, 1280, 720, level2);
	Next_Level.Draw();
	sideLevel.Draw();
	moveFunctions();
	frameCount();
	drawEnemy();
	drawPickup();
	if (ObjCollision(Next_Level, MainC))
	{
		if (MainC.health == 100)
		{
			achieved[3] = true;
		}
		BossLevel_Initialize();
		game_state = 4;
	}
	Player_score++;
	Show_Inventory();
	Pause_Menu();
	deadMenu();
	viewScore();
	if (ObjCollision(sideLevel, MainC))
	{
		iSetColor(255, 255, 255);
		if (MainC.health == 100)
		{
			achieved[3] = true;
		}
		iText(400, 5, "PRESS ENTER TO ACCEPT SIDE QUEST", GLUT_BITMAP_HELVETICA_18);
		if (sideQuestPoint)
		{
			Level3_Initialize();
			game_state = 3;
			sideQuestPoint = false;
		}
	}
}

void Level_3()
{
	iShowImage(0, 0, 1280, 720, level3);
	Next_Level.Draw();
	moveFunctions();
	frameCount();
	drawEnemy();
	drawPickup();
	Show_Inventory();
	Pause_Menu();
	deadMenu();
	viewScore();
	if (ObjCollision(Next_Level, MainC))
	{
		if (MainC.health == 100)
		{
			achieved[3] = true;
		}
		BossLevel_Initialize();
		game_state = 4;
	}
}

void BossLevel()
{
	iShowImage(0, 0, 1280, 720, bossLevel);
	moveFunctions();
	frameCount();
	drawEnemy();
	Show_Inventory();
	Pause_Menu();
	deadMenu();
	viewScore();
}

void Save()
{

	FILE* f = fopen("Save.txt", "w");
	fprintf(f, "%d %d\n", male, game_state);
	fprintf(f, "%lf %lf %lf %d %d %lf\n", MainC.x, MainC.y, MainC.height, MainC.width, MainC.health, MainC.image, jump_y);
	for (int i = 0; i < total_troops; i++)
	{
		fprintf(f, "%lf %lf %d %lf %lf %d %d %lf %d %d %d\n", Troops[i].x, Troops[i].y, Troops[i].health, Troops[i].height, Troops[i].width, Troops[i].image, Troops[i].type, Troops[i].target_distance, Troops[i].active, Troops[i].Dead, Troops[i].isRight);
	}
	fclose(f);
}

void Load()
{
	FILE* f = fopen("Save.txt", "r");
	if(f != NULL)
	{
		fscanf(f, "%d %d", &male, &game_state);
		if (game_state == 1)
		{
			Level1_Initialize();
		}
		if (game_state == 2)
		{
			Level2_Initialize();
		}
		if (game_state == 3)
		{
			Level3_Initialize();
		}
		if (game_state == 4)
		{
			BossLevel_Initialize();
		}
		fscanf(f, "%lf %lf %lf %d %d %lf", &MainC.x, &MainC.y, &MainC.height, &MainC.width, &MainC.health, &MainC.image, &jump_y);
		for (int i = 0; i < total_troops; i++)
		{
			fscanf(f, "%lf %lf %d %lf %lf %d %d %lf %d %d %d", &Troops[i].x, &Troops[i].y, &Troops[i].health, &Troops[i].height, &Troops[i].width, &Troops[i].image, &Troops[i].type, &Troops[i].target_distance, &Troops[i].active, &Troops[i].Dead, &Troops[i].isRight);
		}
	}
	fclose(f);
}


#endif // !GAMEMANAGER_H