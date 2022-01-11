#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "Achievement.h"
typedef struct Playerscore Playerscore;

struct Playerscore
{
	char name[20];
	int score;
	Playerscore()
	{

	}

	Playerscore(char* n, int s)
	{
		strcpy(name, n);
		score = s;
	}
}p[5];



bool Comparator(Playerscore a, Playerscore b)
{
	return (a.score > b.score);
}

void readScore()
{
	FILE* f;
	f = fopen("Scoreboard.txt", "r"); 
	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s %d", p[i].name, &p[i].score);
	}
	fclose(f);
}

void writeScore()
{
	FILE* f;
	f = fopen("Scoreboard.txt", "w");
	strcpy(p[4].name, to_char(users[current_user].name));
	p[4].score = Player_score;
	sort(p , p + 5, Comparator);
	for (int i = 0; i < 5; i++)
	{
			fprintf(f, "\n%s %d", p[i].name, p[i].score);
	}
	fclose(f);
}


void showScore()
{
	iShowImage(0, 0, 1280, 720, highscore_background);

	char score[1000] = { 0 };
	iText(510, 450, p[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(score, to_char(p[0].score));
	iText(650, 450, score, GLUT_BITMAP_TIMES_ROMAN_24);
	memset(score, NULL, sizeof(score));

	iText(510, 400, p[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(score, to_char(p[1].score));
	iText(650, 400, score, GLUT_BITMAP_TIMES_ROMAN_24);
	memset(score, NULL, sizeof(score));

	iText(510, 350, p[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(score, to_char(p[2].score));
	iText(650, 350, score, GLUT_BITMAP_TIMES_ROMAN_24);
	memset(score, NULL, sizeof(score));

	iText(510, 300, p[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(score, to_char(p[3].score));
	iText(650, 300, score, GLUT_BITMAP_TIMES_ROMAN_24);
	memset(score, NULL, sizeof(score));

	iText(510, 250, p[4].name, GLUT_BITMAP_TIMES_ROMAN_24);
	strcpy(score, to_char(p[4].score));
	iText(650, 250, score, GLUT_BITMAP_TIMES_ROMAN_24);
	memset(score, NULL, sizeof(score));

}



























#endif