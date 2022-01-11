#ifndef OBJECTS_H
#define OBJECTS_H
#include "Audio.h"

class Object
{
public:
	int image;
	double x, y, height, width;
	string name;
	Object()
	{
	
	}
	
	Object(double x, double y, double height, double width)
	{
		this -> x = x;
		this -> y = y;
		this -> height = height;
		this -> width = width;
	}

	Object(double lower_x, double lower_y, double upper_x, double upper_y, string name)
	{
		this->x = lower_x;
		this->y = lower_y;
		this->width = abs(upper_x - lower_x);
		this->height = abs(upper_y - lower_y);
		this->name = name;
	}

	Object(double x, double y, double height, double width, int image)
	{
		this -> x = x;
		this -> y = y;
		this -> height = height;
		this -> width = width;
		this -> image = image;
	}
	void Draw()
	{
		if (name == "Portal")
		{
			iShowImage(x, y, width, height, portalSprite[portal_frame % portalSprite.size()]);
		}
		else if (name == "Side Quest")
		{
			iShowImage(x, y, 2, sideQuest);
		}
		else
		{
			iShowImage(x, y, width, height, image);
		}

	}
	void Draw(double x, double y)
	{
		iShowImage(x, y, width, height, image);
	}


};
Object Wall[25], Next_Level, sideLevel;

bool ObjCollision(Object a, Object b)
{
	bool collisionX = a.x + a.width >= b.x && b.x + b.width > a.x || b.x + b.width >= a.x && a.x + a.width > b.x;
	bool collisionY = a.y + a.height >= b.y && b.y + b.height > a.y || b.y + b.height >= a.y && a.y + a.height > b.y;
	if (collisionX && collisionY)
	{
		return true;
	}
	return false;
}

class Projectile
{
public:
	double x1, y1, x2, y2; 
	int type;
	bool isRight;
	int image,health;	
	Projectile()
	{
	
	}

	Projectile(double x1, double y1, int type)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = 0;
		this->y2 = 0;
		this->type = type;
	}

	Projectile(double x1, double y1, int type, bool isRight)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = 0;
		this->y2 = 0;
		this->type = type;
		this->isRight = isRight;
	}

	Projectile(double x1, double x2, double y1, double y2, int type)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
		this->type = type;
	}
	void Draw()
	{

		if (type == 1)
		{
			if(curr_frame % 2 == 0)
				iSetColor(255, 0, 0);
			else
				iSetColor(255, 255, 255);
			iLine(x1, y1, x2, y2);
		}
		if (type == 2)
		{
			double distance = 0;
			if (!paused)
			{
				if (curr_frame % 2 == 0)
					iSetColor(255, 0, 0);
				else
					iSetColor(255, 255, 255);
				theta = theta % 360;
				x2 = x1 + 100 * cos(theta * degree);
				y2 = y1 + 100 * sin(theta * degree);
				theta++;
				distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			}
			iRotate(x1, y1, theta - 90);
			iShowImage(x1 - 1, y1, 15, distance, Beam_Sprite);
			iUnRotate();
		}
		if (type == 3)
		{
			a = cnt % BulletSprite.size();
			iShowImage(x1, y1, 32, 32, BulletSprite[a]);
		}		
		
	}
	void Behaviour()
	{
		if (type == 3)
		{
			if (isRight)
			{
				x1 += 5;
			}
			else
			{
				x1 -= 5;
			}
		}
		
	}
	bool checkCollision(Object b)
	{
		return ObjCollision(Object(x1, y1, 32, 32), b);
	}
};

Projectile Circle_fire[2];
vector<Projectile> Bullet;

class Pickup: public Object
{
public:
	int type;
	bool taken;
	Pickup()
	{
	
	}
	Pickup(double x, double y, double height, double width, int image, int type, bool taken)
	{
		this -> x = x;
		this -> y = y;
		this -> height = height;
		this -> width = width;
		this -> image = image;
		this -> type = type;
		this -> taken = taken;
	}
	void Draw()
	{	
		if(!taken)
			iShowImage(x, y, width, height, image);
	}
};
Pickup pickup[50];

class Player: public Object
{
public:
	double health;
	Player()
	{
	
	}
	Player(double x, double y, double height, double width, int image, double health)
	{
		this -> x = x;
		this -> y = y;
		this -> height = height;
		this -> width = width;
		this -> image = image;
		this -> health = health;
	}
	void Draw(double x, double y)
	{
		int mod1 = 9.50f;
		int mod2 = 46;
		if(male)
		{
			if (Jumping && isRight && Attacking)
			{
				iShowImage(x, y, 7.5, MSpriteJAR[FrameHolder]);
			}
			else if (Jumping && !isRight && Attacking)
			{
				iShowImage(x - 10, y, 7.5, MSpriteJAL[FrameHolder]);
			}
			else if (isRight && Attacking)
			{
				iShowImage(x, y, 7.5, MSpriteAR[FrameHolder]);
			}
			else if (!isRight && Attacking)
			{
				iShowImage(x - 10, y, 7.5, MSpriteAL[FrameHolder]);
			}
			else if (gravity && isRight && jump_velocity <= 0)
			{
				iShowImage(x, y, ceil(443.0f/mod1), ceil(454.0f/mod1), MSpriteG[0]);
			}
			else if (gravity && !isRight && jump_velocity <= 0)
			{
				iShowImage(x, y, ceil(443.0f/mod1), ceil(454.0f/mod1), MSpriteG[1]);
			}
			else if (Jumping && isRight)
			{
				a = cnt % MSpriteJR.size();
				iShowImage(x, y, 46, height, MSpriteJR[a]);
			}
			else if (Jumping && !isRight)
			{
				a = cnt % MSpriteJL.size();
				iShowImage(x, y, 46, height, MSpriteJL[a]);
			}
			else if (isRight && idle)
			{
				iShowImage(x, y, width, height, MSpriteI[0]);
			}
			else if (!isRight && idle)
			{
				iShowImage(x, y, width, height, MSpriteI[1]);
			}
			else if (isRight) 
			{
				a = cnt % MSpriteR.size();
				iShowImage(x, y, mod2, height, MSpriteR[a]);
			}
			else if(!isRight)
			{
				a = cnt % MSpriteL.size();
				iShowImage(x, y, mod2, height, MSpriteL[a]);
			}
		}
		double fem = 1.2;
		if (!male)
		{
			if (Jumping && isRight && Attacking)
			{
				iShowImage(x, y, 7.5, FSpriteJAR[FrameHolder]);
			}
			else if (Jumping && !isRight && Attacking)
			{
				iShowImage(x - 10, y, 7.5, FSpriteJAL[FrameHolder]);
			}
			else if (isRight && Attacking)
			{
				iShowImage(x, y, 7.5, FSpriteAR[FrameHolder]);
			}
			else if (!isRight && Attacking)
			{
				iShowImage(x - 10, y, 7.5, FSpriteAL[FrameHolder]);
			}
			else if (gravity && isRight && jump_velocity <= 0)
			{
				iShowImage(x, y, ceil(443.0f / mod1) * fem, ceil(454.0f / mod1) * fem, FSpriteG[0]);
			}
			else if (gravity && !isRight && jump_velocity <= 0)
			{
				iShowImage(x, y, ceil(443.0f / mod1) * fem, ceil(454.0f / mod1) * fem, FSpriteG[1]);
			}
			else if (Jumping && isRight)
			{
				a = cnt % FSpriteJR.size();
				iShowImage(x, y, 46 * fem, height * fem, FSpriteJR[a]);
			}
			else if (Jumping && !isRight)
			{
				a = cnt % FSpriteJL.size();
				iShowImage(x, y, 46 * fem, height * fem, FSpriteJL[a]);
			}
			else if (isRight && idle)
			{
				iShowImage(x, y, width * fem, height * fem, FSpriteI[0]);
			}
			else if (!isRight && idle)
			{
				iShowImage(x, y, width * fem, height * fem, FSpriteI[1]);
			}
			else if (isRight)
			{
				a = cnt % FSpriteR.size();
				iShowImage(x, y, mod2 * fem, height * fem, FSpriteR[a]);
			}
			else if (!isRight)
			{
				a = cnt % FSpriteL.size();
				iShowImage(x, y, mod2 * fem, height * fem, FSpriteL[a]);
			}
		}
	}
};
Player MainC;

bool Collision(double a_x, double a_y, double a_height, double a_width, Object b)
{
	// Collision on x axis
	bool collisionX = a_x + a_width >= b.x && b.x + b.width > a_x || b.x + b.width >= a_x && a_x + a_width > b.x;
	// collision on y axis
	bool collisionY = a_y + a_height >= b.y && b.y + b.height > a_y || b.y + b.height >= a_y && a_y + a_height > b.y;
	// collision on both axis
	if (collisionX && collisionY)
	{
		//cout << b.name << endl;
		return true;
	}
	return false;

}

bool LineCollision(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	double uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
		return true;
	return false;
}

bool Line_Collision(double x1, double y1, double x2, double y2, double a1, double b1, double a2, double b2)
{
	double a = (y1 - y2);
	double b = (x2 - x1);
	double c = (x1 * y2) - (x2 * y1);
	double d = (b1 - b2);
	double e = (a2 - a1);
	double f = (a1 * b2) - (a2 * b1);
	double x = ((c * e) - (b * f)) / ((a * e) - (b * d));
	double y = ((a * f) - (c * d)) / ((a * e) - (b * d));
	bool col_X = (x >= min(x1, x2) && x <= max(x1, x2)) && (x >= min(a1, a2) && x <= max(a1, a2));
	bool col_Y = (y >= min(y1, y2) && y <= max(y1, y2)) && (y >= min(b1, b2) && y <= max(b1, b2));
	cout << col_X << " " << col_Y << endl;
	return col_X && col_Y;
}


bool ProjectileCollision(Projectile a, Object b)
{
	
	bool bottom = LineCollision(a.x1, a.y1, a.x2, a.y2, b.x, b.y, b.x + b.width, b.y);
	bool left = LineCollision(a.x1, a.y1, a.x2, a.y2, b.x, b.y, b.x, b.y + b.height);
	bool right = LineCollision(a.x1, a.y1, a.x2, a.y2, b.x + b.width, b.y, b.x + b.width, b.y + b.height);
	bool top = LineCollision(a.x1, a.y1, a.x2, a.y2, b.x, b.y + b.height, b.x + b.width, b.y + b.height);
	if (bottom || left || right || top)
		return true;
	return false;
}

vector<Object> MeteorStrike;
vector<Object> Bat;
vector<Object> Fire; 
class Enemy: public Object
{
public:
	int type, health;
	double target_distance;
	bool isRight, active, Dead;
	Enemy()
	{
	
	}
	Enemy(double x, double y, double height, double width, int image, int health, int type, double target_distance)
	{
		this -> x = x; 
		this -> y = y;
		this -> height = height;
		this -> width = width;
		this -> image = image;
		this -> health = health;
		this -> type = type;
		this -> active = false;
		this -> Dead = false;
		this -> isRight = true;
		this -> target_distance = 300;
	}
	void Draw()
	{
		if (!Dead)
		{
			if (type == 1)
			{
				if (!active)
				{
					iShowImage(x, y, width, height, E1_SpriteI);
				}
				else 
				{
					if (isRight)
					{
						a = cnt % E1_SpriteR.size();
						iShowImage(x, y, width, height, E1_SpriteR[a]);
					}
					else
					{
						a = cnt % E1_SpriteL.size();
						iShowImage(x, y, width, height, E1_SpriteL[a]);
					}
				}
			}
			else if (type == 2)
			{
				if (isRight)
				{
					a = cnt % E2_SpriteR.size();
					iShowImage(x, y, width, height, E2_SpriteR[a]);
				}
				else
				{
					a = cnt % E2_SpriteL.size();
					iShowImage(x, y, width, height, E2_SpriteL[a]);
				}
			}
			else if (type == 3)
			{
				if (!active && isRight)
				{
					iShowImage(x, y, width, height, E3_SPriteR);
				}
				else if (!active && !isRight)
				{
					iShowImage(x, y, width, height, E3_SPriteL);
				}
				else if (active && isRight)
				{
					FireSound();
					iShowImage(x, y, width, height, E3_SPriteRA);
					iShowImage(x - 120, y + 5, 147, 42, E3_SpriteFL);
				}
				else if (active && !isRight)
				{
					FireSound();
					iShowImage(x, y, width, height, E3_SPriteLA);
					iShowImage(x + 45, y + 5, 162, 42, E3_SpriteFR);
				}
			}
			else if (type == 4)
			{
				if (isRight)
				{
					a = cnt % E4_SpriteR.size();
					iShowImage(x, y, width, height, E4_SpriteR[a]);
				}
				else
				{
					a = cnt % E4_SpriteL.size();
					iShowImage(x, y, width, height, E4_SpriteL[a]);
				}
			}
			else if (type == 5)
			{
				iShowImage(x, y, width, height, EnemyPortalSprite[cnt % EnemyPortalSprite.size()]);
			}
			else if (type == 7)
			{
				iShowImage(x, y, 5, PlantSprite[plant_frame % PlantSprite.size()]);
			}
			else if (type == 8)
			{
				if (isRight)
				{
					iShowImage(x, y, width, height, BomberSpriteR[bomber_frame % BomberSpriteR.size()]);
				}
				else
				{
					iShowImage(x, y, width, height, BomberSpriteL[bomber_frame % BomberSpriteL.size()]);
				}
			}
			else if (type == 9)
			{
				if (isRight)
					iShowImage(x, y, 1, BossSpriteR);
				if (!isRight)
					iShowImage(x, y, 1, BossSpriteL);
			}
			else
			{
				iShowImage(x, y, width, height, image);
			}
		}
	}
	void Draw(double x, double y)
	{
		if (!Dead)
			iShowImage(x, y, width, height, image);
	}
	void CheckPlayer()
	{
		if(type == 1)
		{
			if(x - MainC.x <= 200 && (y == floor(MainC.y) || y == ceil(MainC.y)) && x - MainC.x > 0)//if enemy and hero are on the same y axis and their distance is equal to or less than defined length
			{         
				isRight = false;
				active = true;
			}
			if(MainC.x - x <= 200 && (y == floor(MainC.y) || y == ceil(MainC.y)) && MainC.x - x > 0)
			{
				isRight = true;
				active = true;
			}
		}
		if(type == 3)
		{
			double distance_x = x - MainC.x;
			double distance_y = y - MainC.y;
			double distance = sqrt((distance_x * distance_x) + (distance_y * distance_y));
			if(distance <= target_distance)
			{
				active = true;
				if(distance_x < 0)
				{
					isRight = false;
				}
				else if(distance_x > 0)
				{
					isRight = true;
				}
			//	cout << distance_x << endl;
			}
			else
			{
				active = false;
			}
		}
	
	}
	void Behaviour()
	{
		if (!Dead)
		{
			if (type == 1)
			{
				if (active)
				{
					if (!isRight)
					{
						x--;
						target_distance--;
						if (x - MainC.x <= 0 || target_distance <= 100)
						{
							Dead = true;
							ExplosionSound();
						}
					}
					else
					{
						x++;
						target_distance--;
						if (x - MainC.x >= 0 || target_distance <= 100)//if the enemy crooses 200m while chasing the hero,it will die automatically
						{
							Dead = true;
							ExplosionSound();
						}
					}
				}
			}
			if (type == 2)
			{
				if (isRight)
				{
					x++;
					target_distance--;
					if (target_distance == 0)
					{
						isRight = false;
					}
				}
				else
				{
					x--;
					target_distance++;
					if (target_distance == 300)
					{
						isRight = true;
					}
				}
				if (ceil(MainC.x) == ceil(x) && ceil(MainC.y) == ceil(y))
				{
					Dead = true;
				}
			}
			if (type == 3)
			{
				if (active)
				{
					if (!isRight)
					{
						if (Collision(MainC.x, MainC.y, MainC.height, MainC.width, Object(x + 45, y + 5, 42, 162)))
						{
							MainC.health = MainC.health - (1.0f / 60);
						}
					}
					if (isRight)
					{
						if (Collision(MainC.x, MainC.y, MainC.height, MainC.width, Object(x - 120, y + 5, 42, 147)))
						{
							MainC.health = MainC.health - (1.0f / 60);

						}
					}
				}
			}
			if (type == 4)
			{
				if (isRight) // isRight is the direction on enemy's path
				{
					x++;
					target_distance--;
					y = y + cos(x * pi / 180);
				}
				else
				{
					x--;
					target_distance++;
					y = y + cos(x * pi / 180);
				}
				if (target_distance == 0)
					isRight = false;
				if (target_distance == 360)
					isRight = true;
			}
			if(type == 5)
			{	
				if(health > 0 && curr_frame % 150 == 0)
				{
					Bat.push_back(Object(x, y, 30, 30));
				}
				if(!Bat.empty())
				{
					for(int i = 0; i < Bat.size();i++)
					{				
						distance_x = Bat[i].x - MainC.x;
						distance_y = Bat[i].y - MainC.y;
						d = sqrt((distance_x * distance_x) + (distance_y * distance_y));
						distance_x = distance_x / d;
						distance_y = distance_y / d;			
						iShowImage(Bat[i].x, Bat[i].y, 30, 30,PortalBatSprite[cnt % PortalBatSprite.size()]);
						Bat[i].x = Bat[i].x - 2 * distance_x;
						Bat[i].y = Bat[i].y - 2 * distance_y;
						if (ObjCollision(Bat[i], MainC))
						{
							MainC.health = MainC.health - 0.5;
						}
					}
				}
			} 
			if(type == 7) 
			{ 
				     if(isRight)
	                 {
		                height += 0.1;
		                if (height >= 86)
		                {
			                 isRight = false;
		                }
	                 }  
	                 if(!isRight)
	                 {
		                height -= 0.1;
		                if (height <= 63)
		                {
			                 isRight = true;
		                }
	                 } 
			}
			if (type == 8)
			{

				if (isRight)
				{
					x++;
					target_distance--;
					if (target_distance == 0)
					{
						isRight = false;
					}
				}
				else
				{
					x--;
					target_distance++;
					if (target_distance == 300)
					{
						isRight = true;
					}
				}
				if(curr_frame % 180 == 0 && health > 0)
				{
					Fire.push_back(Object(x, y, 20, 20));
					
				}
				for (int i = 0; i < Fire.size(); i++)
				{
					iShowImage(Fire[i].x, Fire[i].y, 20, 20, Meteor[cnt % Meteor.size()]);
					Fire[i].y--;
					if (ObjCollision(Fire[i], MainC))
					{
						Fire.erase(Fire.begin() + i);
						MainC.health = MainC.health - 3;
						i = 0;
					}
					if (ObjCollision(Fire[i], Wall[0]))
					{
						Fire.erase(Fire.begin() + i);
						i = 0;
					}
				}
			}
			if (type == 9)
			{
				if (isRight)
				{
					if (x > 1100)
					{
						isRight = false;
					}
					else
					{
						x++;
					}
				}
				if (!isRight)
				{
					if (x < 20)
					{
						isRight = true;
					}
					else
					{
						x--;
					}
				}
				if (cnt % 2 == 0)
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				if (curr_frame % 500 == 0)
				{
					MeteorStrike.push_back(Object(100 + rand() % 1000, 720, 25, 25));
					MeteorStrike.push_back(Object(100 + rand() % 1000, 720, 25, 25));
					MeteorStrike.push_back(Object(100 + rand() % 1000, 720, 25, 25));
					cout << curr_frame << endl;
				}
				for (int i = 0; i < MeteorStrike.size(); i++)
				{
					if (MeteorStrike[i].y <= 60)
					{
						MeteorStrike.erase(MeteorStrike.begin() + i);
						continue;
					}
					MeteorStrike[i].y = MeteorStrike[i].y - 2;
					MeteorStrike[i].x = MeteorStrike[i].x - 0.57;
					iShowImage(MeteorStrike[i].x, MeteorStrike[i].y, 1, Meteor[cnt % Meteor.size()]);
					if (ObjCollision(MeteorStrike[i], MainC))
					{
						MainC.health = MainC.health - 2;
					}
				}
				if (curr_frame % 500 == 0)
				{
					if (BossLaser)
					{
						BossLaser = false;
					}
					else
					{
						BossLaser = true;
					}
				}
				if (BossLaser == true)
				{
					iShowImage(300, -100, 15, 1000, Beam_Sprite);
					if (ObjCollision(Object(300, 0, 720, 15), MainC))
					{
						MainC.health = MainC.health - 2;
					}
					iShowImage(600, -100, 15, 1000, Beam_Sprite);
					if (ObjCollision(Object(600, 0, 720, 15), MainC))
					{
						MainC.health = MainC.health - 2;
					}
					iShowImage(900, -100, 15, 1000, Beam_Sprite);
					if (ObjCollision(Object(900, 0, 720, 15), MainC))
					{
						MainC.health = MainC.health - 2;
					}
					iShowImage(1200, -100, 15, 1000, Beam_Sprite);
					if (ObjCollision(Object(1200, 0, 720, 15), MainC))
					{
						MainC.health = MainC.health - 2;
					}
				}
			}
		}
		if (health <= 0)
		{
			if (!Dead)
			{
				EnemyDeadSound();
				Player_score += 2;
				Dead = true;
			}
		}	
	}
};
Enemy Troops[10];



#endif