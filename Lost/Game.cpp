#include "GameManager.h"

void iPassiveMouse(int mx, int my)
{
	if(game_state == -97)
	{
		if(!old_login_transition || !new_login_transition)
		{
			if(mx >= 434 && mx <= 815 && my >= 285  && my <= 380)
			{
				HoverButtonSound();
			}
			if(mx >= 434 && mx <= 815 && my >= 152 && my <= 245)
			{
				HoverButtonSound();
			}
		}
	}
	if (game_state == 0)
	{
		if (mx >= 50 && mx <= (50 + 667 / 20) && my >= 625 && my <= (625 + 980 / 20))
		{
			HoverButtonSound();
		}
		if (mx >= 100 && mx <= 150 && my >= 625 && my <= 675)
		{
			HoverButtonSound();
		}
		if (mx >= 849 && mx <= 1209 && my >= 577 && my <= 651)
		{
			HoverButtonSound();
			h = 1;
		}
		else if (mx >= 849 && mx <= 1209 && my >= 490 && my <= 563)
		{
			HoverButtonSound();
			h = 2;
		}
		else if (mx >= 849 && mx <= 1209 && my >= 401 && my <= 475)
		{
			HoverButtonSound();
			h = 3;
		}
		else if (mx >= 849 && mx <= 1209 && my >= 311 && my <= 384)
		{
			HoverButtonSound();
			h = 4;
		}
		else if (mx >= 849 && mx <= 1209 && my >= 223 && my <= 296)
		{
			HoverButtonSound();
			h = 5;
		}
		else if (mx >= 849 && mx <= 1209 && my >= 130 && my <= 204)
		{
			HoverButtonSound();
			h = 6;
		}
		else
		{
			h = 0;
		}
	}
	if (game_state > 0 && paused)
	{
		if (mx >= 469 && mx <= 848 && my >= 314 && my <= 389)
		{
			HoverButtonSound();
		}
		if (mx >= 469 && my >= 223 && mx <= 849 && my <= 300)
		{
			HoverButtonSound();
		}
		if (mx >= 468 && my >= 133 && mx <= 848 && my <= 211)
		{
			HoverButtonSound();
		}
	}
	if (game_state == -2)
	{
		if (mx >= 252 && mx <= 491 && my >= 290 && my <= 553)
		{
			HoverButtonSound();
		}
		if (mx >= 762 && mx <= 1002 && my >= 295 && my <= 555)
		{
			HoverButtonSound();
		}
	}
}

void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (game_state == -2 || game_state == -3 || game_state == -4 || game_state == -98 || game_state == -99)
		{
			if (mx >= 1180 && mx <= 1280 && my >= 620 && my <= 720)
			{
				game_state = 0;
			}
		}
		if (game_state > 0 && playerDead)
		{
			if (mx >= 468 && mx <= 847 && my >= 231 && my <= 305)
			{
				game_state = 0;
			}
			if (mx >= 468 && mx <= 848 && my >= 321 && my <= 395)
			{
				playerDead = false;
				restartLevel();
			}
		}
		else
		{
			if (game_state == -5)
			{
				if (!storySkip)
				{
					storySkip = true;
				}
				else
				{
					game_state = 1;
					Player_score = 0;
				}
			}
			if (game_state == -97)
			{
				if (mx >= 434 && mx <= 815 && my >= 285 && my <= 380)
				{
					PressButtonSound();
					game_state = -96;
				}
				if (mx >= 434 && mx <= 815 && my >= 152 && my <= 245)
				{
					PressButtonSound();
					game_state = -1;
				}
			}

			if (game_state == 0)
			{
				if (mx >= 50 && mx <= (50 + 667 / 20) && my >= 625 && my <= (625 + 980 / 20))
				{
					game_state = -98;
					PressButtonSound();
				}
				if (mx >= 100 && mx <= 150 && my >= 625 && my <= 675)
				{
					PressButtonSound();
					if (audioSetting)
					{
						playsound = false;
						audioSetting = false;
					}
					else
					{
						playsound = true;
						audioSetting = true;
					}
				}
				if (mx >= 849 && mx <= 1209 && my >= 577 && my <= 651)
				{
					game_state = -2;
					curr_frame = 0;
					playerDead = false;
					Level1_Initialize();
					PressButtonSound();
				}
				if (mx >= 849 && mx <= 1209 && my >= 490 && my <= 563)
				{
					Load();
					PressButtonSound();
				}
				if (mx >= 849 && mx <= 1209 && my >= 401 && my <= 475)
				{
					game_state = -3;
					PressButtonSound();
				}
				if (mx >= 849 && mx <= 1209 && my >= 311 && my <= 384)
				{
					PressButtonSound();
					game_state = -99;
				}
				if (mx >= 849 && mx <= 1209 && my >= 223 && my <= 296)
				{
					PressButtonSound();
					game_state = -4;
				}
				if (mx >= 849 && mx <= 1209 && my >= 130 && my <= 204)
				{
					PressButtonSound();
					exit(0);
				}
			}
			if (game_state > 0 && paused)
			{
				if (mx >= 469 && mx <= 848 && my >= 314 && my <= 389)
				{
					paused = false;
				}
				if (mx >= 469 && my >= 223 && mx <= 849 && my <= 300)
				{
					restartLevel();
					paused = false;
				}
				if (mx >= 468 && my >= 133 && mx <= 848 && my <= 211)
				{
					game_state = 0;
				}
			}
			if (game_state == -2)
			{
				if (mx >= 252 && mx <= 491 && my >= 290 && my <= 553)
				{
					male = true;
					teleportDistance = 175;
					energyRegenFactor = 2;
					game_state = -5;
					PressButtonSound();
				}
				if (mx >= 762 && mx <= 1002 && my >= 295 && my <= 555)
				{
					male = false;
					teleportDistance = 225;
					energyRegenFactor = 1;
					game_state = -5;
					PressButtonSound();
				}
			}
			if (game_state >= 1)
			{
				if (Shuriken)
				{
					if(items[2] > 0)
					{
						Bullet.push_back(Projectile(MainC.x, MainC.y + 30, 3, isRight));
						ThrowSurikenSound();
						items[2]-- ;
					}
				}
				if (Katana)
				{
					Sframe = 0;
				}
				if (Laser)
				{
					if (!CreateLaser)
						CreateLaser = true;
					else
						CreateLaser = false;
				}
			}
			if (game_state == -3)
			{
				if (mx >= 19 && mx <= 151 && my >= 601 && my <= 703)
				{
					game_state = 0;
					PressButtonSound();
				}
			}
			if (game_state == -4)
			{
				if (mx >= 11 && mx <= 108 && my >= 641 && my <= 712)
				{
					game_state = 0;
					PressButtonSound();
				}
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (!paused && game_state > 0)
		{ 
			Moveset_Teleport(mx, my);
		}
	}
	cout<<"mx = "<<mx<<"my = "<<my<<endl;
}

void iKeyboard(unsigned char key)
{
	if (game_state == 2)
	{
		if (ObjCollision(sideLevel, MainC))
		{
			if (key == '\r')
			{
				sideQuestPoint = true;
			}
		}
	}
	if(game_state == -96)
	{
		if(key == '1')
		{
			current_user = 0;
			game_state = -95;
		}
		if(key == '2')
		{
			current_user = 1;
			game_state = -95;
		}
		if(key == '3')
		{
			current_user = 2;
			game_state = -95;
		}
		if(key == '4')
		{
			current_user = 3;
			game_state = -95;
		}
		if(key == '5')
		{
			current_user = 4;
			game_state = -95;
		}
	}
	if (game_state == -1)
	{
		if (key == '\r')
		{
			f_name = Player_name;
			newUser();
			writeUser();
			game_state = -95;
			memset(Player_name, NULL, sizeof(Player_name));
		}
		else if (key == '\b')
		{
			if(len > 0)
			{
				len--;
			}
			Player_name[len] = NULL;
		}
		else
		{
			Player_name[len] = key;
			len++;
		}
	}
	if (game_state > 0)
	{
		if (key == 'a')
		{
			isRight = false;
			if (!Jumping)
			{
				FootStepSound();
				footstep++;
				velocity_x = (-1) * playerVelocity;
				modifier_x = friction;
			}
			else
			{
				velocity_x = (-1) * (playerVelocity - 50);
				modifier_x = (friction / 2.0f);
			}
		}
		if (key == 'd')
		{
			isRight = true;
			if (!Jumping)
			{
				FootStepSound();
				footstep;
				velocity_x = playerVelocity;
				modifier_x = (-1) * (friction);
			}
			else
			{
				velocity_x = (playerVelocity - 50);
				modifier_x = (-1) * (friction / 2);
			}
		}
		if (key == '3')
		{
			Shuriken = true;
			Katana = false;
			Laser = false;
		}
		if (key == '4')
		{
			Katana = true;
			Shuriken = false;
			Laser = false;
		}
		if (key == '5')
		{
			Katana = false;
			Shuriken = false;
			Laser = true;
		}
		if (key == '0')
		{
			game_state = -98;
		}
		if (key == ' ')
		{
			if (!Jumping)
			{
				JumpSound();
				jump_velocity = 10;
				Jumping = true;
				jump_modifier = 0.25;
			}
		}
		if (key == 'i')
		{
			if (Inventory)
			{
				Inventory = false;
				paused = false;
			}
			else
			{
				OpenInventorySound();
				Inventory = true;
				paused = true;
			}
		}
		if (key == 'p')
		{
			if (!paused)
			{
				paused = true;
			}
			else
			{
				paused = false;
			}
		}
		if (Inventory)
		{
			if (key == '1')
			{
				consumeHealth();
			}
			if (key == '2')
			{
				consumeEnergy();
			}
		}
	}
	if (game_state != -1)
	{
		if (key == '\b')
		{
			if (game_state != 0)
			{
				game_state = 0;
			}
			else
			{
				game_state = -97;
			}
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_UP)
	{
		
	}
	if (key == GLUT_KEY_DOWN)
	{	
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		isRight = false;
		if (!Jumping)
		{
			FootStepSound();
			footstep++;
			velocity_x = (-1) * playerVelocity;
			modifier_x = friction;
		}
		else
		{
			velocity_x = (-1) * (playerVelocity - 50);
			modifier_x = (friction / 2.0f);
		}
	}
	if (key == GLUT_KEY_RIGHT)
	{
		isRight = true;
		if (!Jumping)
		{
			FootStepSound();
			footstep;
			velocity_x = playerVelocity;
			modifier_x = (-1) * (friction);
		}
		else
		{
			velocity_x = (playerVelocity - 50);
			modifier_x = (-1) * (friction / 2);
		}
	}
	if (key == GLUT_KEY_F5)
	{
		Save();
	}
}

void iDraw()
{
	iClear();
	if (game_state == -1)
	{
		iShowImage(0, 0, 1280, 720, new_user_screen);
		iSetColor(255, 255, 255);
		iText(400, 350, "ENTER YOUR NAME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(648, 350, Player_name, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if (game_state == -2)
	{
		Hero_selection();
	}
	if (game_state == -3)
	{
		Instruction();
	}
	if (game_state == -4)
	{
		Credits();
	}
	if (game_state == -5)
	{
		storyTransition();
	}
	if (game_state == -95)
	{
		pregameTransition();
	}
	if (game_state == -96)
	{
		iShowImage(0, 0, 1280, 720, old_user_screen);
		showUser();
		iText(300, 5, "USE NUM 1-5 TO SELECT USER", GLUT_BITMAP_HELVETICA_18);
	}
	if (game_state == -97)
	{
		login();
	}
	if (game_state == -98)
	{
		iShowImage(0, 0, 1280, 720, Achievement);
		showAchievement();
	}
	if (game_state == -99)
	{
		showScore();
	}
	if (game_state == 0)
	{
		Main_menu();
	}
	if (game_state == 1)
	{
		Level_1();
	}
	if (game_state == 2)
	{
		Level_2();
	}
	if (game_state == 3)
	{
		Level_3();
	}	
	if (game_state == 4)
	{
		BossLevel();
	}
	if (game_state == 10)
	{
		storyEndTransition();
	}
	if (game_state == -2 || game_state == -3 || game_state == -4 || game_state == -98 || game_state == -99)
	{
		iShowImage(1180, 620, 100, 100, backButton);
	}
	sound();
	AudioFix();
}

void initializeAllSprites()
{
	//iPauseTimer(ImageLoader);
}

int main()
{
	Story_Initialize();
	iInitialize(1280, 720, "Lost");
	readUser();
	readScore();
	raindrop = iLoadImage("images\\raindrop.png");
	level1 = iLoadImage("images\\Level1.png");
	Lost_menu = iLoadImage("images\\Lost_menu.png");
	Hero = iLoadImage("images\\hero.png");
	level2 = iLoadImage("images\\level2.png");
	level3 = iLoadImage("images\\level3.png");
	bossLevel = iLoadImage("images\\BossLevel.png");
	instruction = iLoadImage("images\\Demo_instruction.png");
	credits = iLoadImage("images\\Credit.jpg");
	Achievement = iLoadImage("images\\Achievment.png");
	AchievementIcon = iLoadImage("images\\pass.png");
	pauseScreen = iLoadImage("images\\pause.png");
	login_start = iLoadImage("images\\login_start.png");
	old_user_button = iLoadImage("images\\old_user_button.png");
	new_user_button = iLoadImage("images\\new_user_button.png");
	login_screen = iLoadImage("images\\login.png");
	old_user_screen = iLoadImage("images\\old_user.png");
	new_user_screen = iLoadImage("images\\new_user.png");
	sound_on_icon = iLoadImage("images\\sound_on.png");
	sound_off_icon = iLoadImage("images\\sound_off.png");
	deadScreen = iLoadImage("images\\dead.png");
	sideQuest = iLoadImage("images\\side.png");
	highscore_background = iLoadImage("images\\Background.png");
	newgame = iLoadImage("images\\New Game.png");
	loadgame = iLoadImage("images\\Load Game.png");
	instructions = iLoadImage("images\\Instructions.png");
	highscores = iLoadImage("images\\High Scores.png");
	credit = iLoadImage("images\\Credits.png");
	ex = iLoadImage("images\\Exit.png");
	backButton = iLoadImage("images\\backButton.png");
	storyScreen = iLoadImage("images\\story.jpg");
	endScreen1 = iLoadImage("images\\endScreen.jpg");
	endScreen2 = iLoadImage("images\\happB.jpg");
	loadSprite("Transition", 1000, 1001, TransitionImage);
	rainTimer = iSetTimer(20000, toggleRain);
	//ImageLoader = iSetTimer(1, initializeAllSprites);
	Init_SpriteVector();
	inventoryScreen = inventorySprite[0];
	iStart();
	return 0;
}











