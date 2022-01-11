#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H
#include "GameWorld.h"
string f_name = "new_user";
int current_user;

struct user
{
	string name;
	bool achievement[5];
}users[5];

void trackAchievement()
{
	
	if(footstep == 2)
	{
		achieved[0] = true;
	}
	if(game_state > 0 )
	{
		if(total_items == 20)
		{
			achieved[1] = true;
		}
	}
	if(count_teleportation == 0 && game_end == true)
	{
		achieved[2] = true;
	}
	if(Player_score > 10000)
	{
		achieved[4] = true;
	}
}

void readUser()
{
	fstream file;
	file.open("Userinfo.txt",ios::in);
	for(int i = 0; i < 5; i++)
	{
		file>>users[i].name;
		for( int j = 0; j <5 ;j++)
		{
			file>>users[i].achievement[j];
		}
	}
	file.close();
}

void showUser()
{
	int text_y = 450;
	for(int i = 0; i < 5; i++)
	{
		iText(615, text_y, to_char(users[i].name), GLUT_BITMAP_TIMES_ROMAN_24);
		text_y = text_y - 50;
	}
}
void showAchievement()
{
	int text_y = 600;
	for(int i = 0; i < 5; i++)
	{
		if(users[current_user].achievement[i])
		{
			iText(800, text_y, "Unlocked", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else
		{
			iText(800, text_y, "Locked", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		text_y = text_y - 118;
	}
}

void newUser()
{
	for(int i = 4; i > 0; i--)
	{
		users[i] = users[i-1];
	}
	users[0].name = Player_name;
	memset(users[0].achievement, false, sizeof(users[0].achievement));
	current_user = 0;
}

void loadAchievement()
{
	for(int i = 0; i < 5; i++)
	{
		users[current_user].achievement[i] = achieved[i];
	}
}

void writeUser()
{
	fstream file;
	file.open("Userinfo.txt", ios::out);
	for(int i = 0; i < 5; i++)
	{
		file<<users[i].name<<endl;
		 for(int j = 0 ;j < 5 ; j++)
		 {
			 file<<users[i].achievement[j]<<endl;
		 }
	}
	file.close();
}

#endif