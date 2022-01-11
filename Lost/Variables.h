#ifndef VARIABLES_H
#define VARIABLES_H
#define _USE_MATH_DEFINES
#include "iGraphics.h"
#include "bitmap_loader.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#define black 0, 0, 0
#define white 255, 255, 255
using namespace std;

template < typename T > std::string to_string( const T& n )
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}

char* to_char(string& s)
{
	return (char*)s.c_str();
}

const char* to_char(int n)
{
	char buffer[20];
	sprintf(buffer, "%d", n);
	const char* s = buffer;
	return s;
}

bool Jumping, Up, Gravity, Teleport, nTeleport, idle;
double jump_y, jump_x, jump_velocity, jump_height = 180, jump_modifier, gravity_modifier = 0.035, gravity_velocity;
double velocity_x, modifier_x;
bool isRight;
bool Attacking;
bool paused;
int Sframe = -1, FrameHolder;
long long curr_frame, next_frame;
int game_state = -97, t;
bool Inventory;
bool gravity;
int items[3] = {0, 0, 0};
int total_wall = 10, total_troops = 5, total_items = 50, total_projectile = 1;
double pi = 2*acos(0.0);
int level1, Lost_menu, Hero, level2, level3, bossLevel, pauseScreen;
double degree = M_PI/180;
int theta = 0;
double r = 100;
double X = 0,Y = 0;
int telepopup_timer;
int mainChar_state = 0;
double energy_width=0;
int a;
int cnt;
int Player_score = 0, len;
char Player_name[100];
bool male;
int raindrop; 
double distance_x, distance_y, d;
bool increase = true;
bool decrease = false;
bool Shuriken, Katana = true, Laser, CreateLaser;
bool BossLaser, AltPos;
int plant_frame, bomber_frame;
bool playsound = true, audioSetting = true;
int footstep = 0;
bool achieved[5] = {false, false, false, false, false};
bool game_end = false, playerDead;
int count_teleportation = 0;
int Achievement;
int instruction, credits;
int AchievementIcon;
bool new_login_transition = true, old_login_transition = true; 
int login_start, old_user_button, new_user_button, old_user_button_x = 0, new_user_button_x = 1280;
int login_screen, old_user_screen, new_user_screen, deadScreen, inventoryScreen, storyScreen, endScreen1, endScreen2;
int h = 0;
int sound_on_icon, sound_off_icon, backButton;
int sideQuest;
bool sideQuestPoint;
int highscore_background, newgame, loadgame, instructions, highscores, credit, ex;
char n[1000] = "Score";
//Story String
string story[15];
bool storyTrack[15];
string storyEnd[5];
bool alternateEnd;
bool gameEnd;

int ImageLoader;
bool isRaining;
int rainTimer;
int friction = 155, playerVelocity = 150, playerGravity = 0.25, playerJumpVelocity = 10;
int teleportDistance, energyRegenFactor;
#endif // !MYHEADER_H_INCLUDED