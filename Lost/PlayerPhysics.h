#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H
#include "HighScore.h"

void Moveset_Basic()
{
	if (modifier_x == 0)
	{
		idle = true;
	}
	else
	{
		idle = false;
	}
	if(!(int)(velocity_x + (1.0/60) * modifier_x))
	{
		modifier_x = 0; 
		velocity_x = 0;
	}
	velocity_x = velocity_x + (1.0/60) * modifier_x;
	for(int i = 0; i < total_wall; i++)
	{
		if(Collision(MainC.x + (1.0/60) * velocity_x, MainC.y + jump_y, MainC.height, MainC.width, Wall[i]))
		{
			velocity_x = 0, modifier_x = 0;
		}
	}
	MainC.x = MainC.x + (1.0/60) * velocity_x;
}

void Moveset_Jump()
{
	if(Jumping)
	{
			jump_velocity = jump_velocity - jump_modifier;
			if(jump_velocity <= 0)
				jump_velocity = 0, jump_modifier = 0, Jumping = false;
			for(int i = 0; i < total_wall; i++)
			{
				if(Collision(MainC.x, MainC.y + jump_velocity + 1, MainC.height, MainC.width, Wall[i]))
				{
					Jumping = false;
					jump_velocity = 0;
					jump_modifier = 0;
				}
			}
			MainC.y = MainC.y + jump_velocity;
	}
}

void Moveset_Teleport(int mx, int my)
{
	Teleport = true;
	double distance = sqrt((MainC.x - mx) * (MainC.x - mx) + (MainC.y - my) * (MainC.y - my));
	if (distance > teleportDistance)
	{
		Teleport = false;
		BlockedPathSound();
	}
	else
	{
		for(int i = 0; i < total_wall; i++)
			if(Collision(mx, my, MainC.height, MainC.width, Wall[i]))
			{
				Teleport = false;
				count_teleportation++;
				BlockedPathSound();
			}
	}
	if(Teleport)
	{					
		if(energy_width - 20 < 0)
		{
			Teleport = false;
		}
		else
		{
			energy_width = energy_width - 20;
		}	
	}
	if(Teleport)
	{ 
		MainC.x = mx, MainC.y = my;
		TeleportSound();
	}
	if (!Teleport)
		nTeleport = true, telepopup_timer = 90;
	cout<<"energy_width = "<<energy_width<<endl;
}

void Moveset_Gravity()
{
	for(int i = 0; i < total_wall; i++)
	{
		if(Collision(MainC.x, MainC.y - 1, MainC.height, MainC.width, Wall[i]))
		{
			gravity = false, Jumping = false;
			break;
		}
		else
			gravity = true, Jumping = true;
	}
	if(gravity)
	{
		MainC.y -= 1.0f;
	}
}

void Health()
{
	for(int i = 0; i < total_troops; i++)
	{
		if(!Attacking)
		{
			if(Collision(MainC.x, MainC.y - 1, MainC.height, MainC.width, Troops[i]) && !Troops[i].Dead)
			{
				MainC.health = MainC.health - (50.0f / 300);
				if(male)
				{
					MaleDamageSound();
				}
				else
				{
					FemaleDamageSound();
				}
			}
		}
		if (Attacking)
		{
			if (isRight)
			{
				if (Collision(MainC.x, MainC.y - 5, MainC.height, MainC.width + 20, Troops[i]) && !Troops[i].Dead)
				{
					if(Troops[i].type != 5)
					{
						Troops[i].health = Troops[i].health - 5;
					}
				}
				for (int j = 0; j < Bat.size(); j++)
				{
					if (Collision(MainC.x, MainC.y - 5, MainC.height, MainC.width + 20, Bat[j]))
					{
						Bat.erase(Bat.begin() + j);
						
					}
				}
			}
			if (!isRight)
			{
				if (Collision(MainC.x - 20, MainC.y - 5, MainC.height, MainC.width, Troops[i]))
				{
					if (Troops[i].type != 5)
					{
						Troops[i].health = Troops[i].health - 5;
					}
				}
				for (int j = 0; j < Bat.size(); j++)
				{
					if(Collision(MainC.x - 20, MainC.y - 5, MainC.height, MainC.width, Bat[j]))
					{
						Bat.erase(Bat.begin() + j);
					}
				}
			}
			SwordSound();
		}
	}
	if(MainC.health <= 0)
	{
		PlayerDeadSound();
		iSetColor(255, 255, 255);
		if (Player_score > p[4].score)
		{
			writeScore();
		}
		playerDead = true;
		loadAchievement();
		writeUser();
	}
}

void pickup_collision()
{	
	for(int i= 0; i< total_items; i++)
	{
		if(Collision(MainC.x, MainC.y - 1, MainC.height, MainC.width, pickup[i]) && pickup[i].taken == false)
		{
			
			pickup[i].taken = true;
			if(pickup[i].type == 2)
			{
				items[pickup[i].type] += 75;
			}
			else
			{
				items[pickup[i].type] += 1;
			}
			if (pickup[i].type == 0)
			{
				PickFoodSound();
			}
			if (pickup[i].type == 1)
			{
				PickDrinkSound();
			}
			if (pickup[i].type == 2)
			{
				PickBulletSound();
			}
		}
	}
}

void projectile_collision()
{
	for (int i = 0; i < total_projectile; i++)
	{
		if (ProjectileCollision(Circle_fire[i], MainC))
		{
			MainC.health = MainC.health - ((1.0f / 60) * 5);
			if (male)
			{
				MaleDamageSound();
			}
			else
			{
				FemaleDamageSound();
			}
		}
	}
}

void GunCollision()
{
	if(!Bullet.empty())
	{
		for (int i = 0; i < Bullet.size(); i++)
		{
			for (int j = 0; j < total_wall; j++)
			{
				if (Bullet[i].checkCollision(Wall[j]))
				{
					Bullet.erase(Bullet.begin() + i);
					ImpactSuriken1Sound();
					if (Bullet.empty() == true)
						break;
					else
						i = 0, j = 0;
				}
			}
		}
	}
	if (!Bullet.empty())
	{
		for (int i = 0; i < Bullet.size(); i++)
		{
			for (int j = 0; j < total_troops; j++)
			{
				if (Bullet[i].checkCollision(Troops[j]) && !Troops[j].Dead)
				{
					Bullet.erase(Bullet.begin() + i);
					ImpactSuriken2Sound();
					Troops[j].health -= 50;
					if (Bullet.empty() == true)
						break;
					else
						i = 0, j = 0;
				}
			}
		}
	}
	if(!Bullet.empty())
	{
		for (int i = 0; i < Bullet.size(); i++)
		{
			for (int j = 0; j < Bat.size(); j++)
			{
				if (Bullet[i].checkCollision(Bat[j]))
				{
					Bullet.erase(Bullet.begin() + i);
					Bat.erase(Bat.begin() + j);
					ImpactSuriken2Sound();
					if (Bullet.empty() == true)
						break;
					else
						i = 0, j = 0;
				}
			}
		}
	}
}

void ShowBullets()
{
	if (!Bullet.empty())
	{
		for (int i = 0; i < Bullet.size(); i++)
		{
			Bullet[i].Behaviour();
			Bullet[i].Draw();
		}
	}
}

void SwordAttack()
{
	if (Sframe >= 0)
	{
		if (Sframe == 10)
		{
			Sframe = -1;
			Attacking = false;
		}
		else
		{
			FrameHolder = Sframe;
			Attacking = true;
			Sframe++;
		}
	}

}

void ShowLaser()
{
	if (energy_width <= 0)
	{
		CreateLaser = false;
		Laser = false;
		energy_width = 0;
	}
	if (energy_width > 0 && Laser == true)
	{
		if (CreateLaser == true)
		{
			if (isRight)
			{
				if(Jumping)
					iShowImage(MainC.x + MainC.width + 20, MainC.y + 25, 130, 15, LaserBeam);
				else if(!idle)
					iShowImage(MainC.x + MainC.width + 20, MainC.y + 40, 130, 15, LaserBeam);
				else
					iShowImage(MainC.x + MainC.width + 10, MainC.y + 40, 130, 15, LaserBeam);
				for (int i = 0; i < total_troops; i++)
				{
					if(ObjCollision(Object(MainC.x, MainC.y, 130, 510), Troops[i]))
					{
						Troops[i].health = Troops[i].health - 2;
					}
				}
				for (int i = 0; i < Bat.size(); i++)
				{
					if (ObjCollision(Object(MainC.x, MainC.y, 130, 510), Bat[i]))
					{
						Bat.erase(Bat.begin() + i);
					}
				}
			}
			if (!isRight)
			{
				if(Jumping)
					iShowImage(MainC.x - 130, MainC.y + 25, 130, 15, LaserBeam);
				else if(!idle)
					iShowImage(MainC.x - 130, MainC.y + 40, 130, 15, LaserBeam);
				else
					iShowImage(MainC.x - 130, MainC.y + 40, 130, 15, LaserBeam);
				for (int i = 0; i < total_troops; i++)
				{
					if (ObjCollision(Object(MainC.x - 130 , MainC.y, 130 + MainC.width, 510), Troops[i]))
					{
						Troops[i].health = Troops[i].health - 2;
					}
				}
				for (int i = 0; i < Bat.size(); i++)
				{
					if (ObjCollision(Object(MainC.x, MainC.y, 130, 510), Bat[i]))
					{
						Bat.erase(Bat.begin() + i);
					}
				}
			}
			energy_width -= (1.0f / 60) * 300;
			LaserSound();
		}
	}
}

void Hud()
{
	iSetColor(255, 255, 255);
	iFilledRectangle(30, 655, 104, 22);
	iSetColor(0, 0, 0);
	iFilledRectangle(32, 657, 100, 18);
	iSetColor(265, 0, 0);
	if(MainC.health > 0)
	{
		iFilledRectangle(32, 657, MainC.health, 18);
	}
	else
	{
		iFilledRectangle(32 ,657, 0, 18);
	}
	iSetColor(255, 255, 255);
	iFilledRectangle(30, 630, 104, 22);
	iSetColor(0, 0, 0);
	iFilledRectangle(32, 632, 100, 18);
	iSetColor(0, 0, 204);
	if(energy_width > 100)
	{
		iFilledRectangle(32, 632, 100, 18);
	}
	else
	{
		iFilledRectangle(32, 632, energy_width, 18);
	}
}

#endif