#ifndef AUDIO_H
#define AUDIO_H
#include"Animation.h"

void sound()
{
	if (playerDead && playsound)
	{
		mciSendString("close music\\1.level1.wav", NULL, 0, 0);
		mciSendString("close music\\1.level2.wav", NULL, 0, 0);
		mciSendString("close music\\1.level3.wav", NULL, 0, 0);
		mciSendString("close music\\1.level4.wav", NULL, 0, 0);
		mciSendString("close music\\1.mainmenu.wav", NULL, 0, 0);
		mciSendString("close music\\1.sad_ending.wav", NULL, 0, 0);
		mciSendString("close music\\1.happy_ending.wav", NULL, 0, 0);
		mciSendString("close music\\5.rain2.wav", NULL, 0, 0);
	}
	else if (playsound)
	{
		
		if (game_state <= 0)
		{
			mciSendString("close music\\1.sad_ending.wav", NULL, 0 ,0);
			mciSendString("close music\\1.happy_ending.wav", NULL, 0 ,0);
			mciSendString("close music\\1.level1.wav", NULL, 0, 0);
			mciSendString("close music\\1.level2.wav", NULL, 0, 0);
			mciSendString("close music\\1.level3.wav", NULL, 0 ,0);
			mciSendString("close music\\1.level4.wav", NULL, 0 ,0);
			mciSendString("play music\\1.mainmenu.wav", NULL, 0, 0);
			mciSendString("close music\\5.rain2.wav", NULL, 0, 0);

		}
		if (game_state == 1)
		{
			mciSendString("close music\\1.mainmenu.wav", NULL, 0, 0);
			mciSendString("play music\\1.level1.wav", NULL, 0, 0);

		}
		if (game_state == 2)
		{
			mciSendString("close music\\1.mainmenu.wav", NULL, 0, 0);
			mciSendString("close music\\1.level1.wav", NULL, 0, 0);
			mciSendString("play music\\1.level2.wav", NULL, 0, 0);

		}
		if(game_state == 3)
		{
			mciSendString("close music\\1.mainmenu.wav", NULL, 0, 0);
			mciSendString("close music\\1.level2.wav", NULL, 0, 0);
			mciSendString("play music\\1.level3.wav", NULL, 0 ,0);
		}
		if(game_state == 4)
		{
			mciSendString("close music\\1.mainmenu.wav", NULL, 0, 0);
			mciSendString("close music\\1.level3.wav", NULL, 0 ,0);
			mciSendString("play music\\1.level4.wav", NULL, 0 ,0);
		}
		if (game_state == 10)
		{
			mciSendString("close music\\1.level4.wav", NULL, 0 ,0);
			if(alternateEnd)
			{
				mciSendString("play music\\1.sad_ending.wav", NULL, 0 ,0);
			}
			else
			{
				mciSendString("play music\\1.happy_ending.wav", NULL, 0 ,0);
			}
		}

	}
	else
	{
			mciSendString("close music\\1.level1.wav", NULL, 0, 0);
			mciSendString("close music\\1.level2.wav", NULL, 0, 0);
			mciSendString("close music\\1.level3.wav", NULL, 0 ,0);
			mciSendString("close music\\1.level4.wav", NULL, 0 ,0);
			mciSendString("close music\\1.mainmenu.wav", NULL, 0, 0);
			mciSendString("close music\\1.sad_ending.wav", NULL, 0 ,0);
			mciSendString("close music\\1.happy_ending.wav", NULL, 0 ,0);
			mciSendString("close music\\5.rain2.wav", NULL, 0, 0);
	}

}
/*
void NewLevelSound()
{
	if (playsound)
	{
		mciSendString("play music\\1.newlevel.wav", NULL, 0, 0);
	}
}*/
void PressButtonSound()
{
	if (playsound)
	{
		mciSendString("play music\\2.button2.wav", NULL, 0, 0);
	}
}
void HoverButtonSound()
{
	if (playsound)
	{
		mciSendString("play music\\2.button1.wav", NULL, 0, 0);
	}
}
void FootStepSound()
{
	if (playsound)
	{
		mciSendString("play music\\footstep.wav", NULL, 0, 0);
	}
}
void EatingSound()
{
	if (playsound)
	{
		mciSendString("play music\\3.eating.wav", NULL, 0, 0);
	}
}
void DrinkingSound()
{
	if (playsound && game_state > 0)
	{
		mciSendString("play music\\3.drinking.wav", NULL, 0, 0);
	}
}
void TakeBulletSound()
{
	if (playsound)
	{
		mciSendString("play music\\3.takingbullet.wav", NULL, 0, 0);
	}
}
void OpenInventorySound()
{
	if (playsound)
	{
		mciSendString("play music\\3.Inventory3.wav", NULL, 0, 0);
	}
}
void PickFoodSound()
{
	if (playsound)
	{
		mciSendString("play music\\4.pickup1.wav", NULL, 0, 0);
	}
}
void PickDrinkSound()
{
	if (playsound)
	{
		mciSendString("play music\\4.pickup2.wav", NULL, 0, 0);
	}
}
void PickBulletSound()
{
	if (playsound)
	{
		mciSendString("play music\\4.pickup3.wav", NULL, 0, 0);
	}
}
void JumpSound()
{
	if (playsound)
	{
		mciSendString("play music\\6.jump3.wav", NULL, 0, 0);
	}
}
void FallSound()
{
	if (playsound)
	{
		mciSendString("play music\\6.fall.wav", NULL, 0, 0);
	}
}
void BlockedPathSound()
{
	if (playsound)
	{
		mciSendString("play music\\7.blockedpath2.wav", NULL, 0, 0);
	}
}
void EnemyDeadSound()
{
	if (playsound)
	{
		mciSendString("play music\\8.enemydead.wav", NULL, 0, 0);
	}
}
void PlayerDeadSound()
{
	if (playsound)
	{
		mciSendString("play music\\11.playerdead.wav", NULL, 0, 0);
	}
}
void FireSound()
{
	if (playsound)
	{
		mciSendString("play music\\8.fire1.wav", NULL, 0, 0);
	}
}
void ExplosionSound()
{
	if (playsound)
	{
		mciSendString("play music\\8.explosion.wav", NULL, 0, 0);
	}
}
void ThrowSurikenSound()
{
	if (playsound)
	{
		mciSendString("play music\\9.suriken1.wav", NULL, 0, 0);
	}
}
void ImpactSuriken1Sound()
{
	if (playsound)
	{
		mciSendString("play music\\9.suriken2.wav", NULL, 0, 0);
	}
}
void ImpactSuriken2Sound()
{
	if (playsound)
	{
		mciSendString("play music\\9.suriken3.wav", NULL, 0, 0);
	}
}
void SwordSound()
{
	if (playsound)
	{
		mciSendString("play music\\9.sword.wav", NULL, 0, 0);
	}
}
void TeleportSound()
{
	if (playsound)
	{
		mciSendString("play music\\10.teleportation.wav", NULL, 0, 0);
	}
}
void MaleDamageSound()
{
	if (playsound)
	{
		mciSendString("play music\\11.maledamage.wav", NULL, 0, 0);
	}
}
void FemaleDamageSound()
{
	if (playsound)
	{
		mciSendString("play music\\11.femaledamage.wav", NULL, 0, 0);
	}
}

void LaserSound()
{
	mciSendString("play music\\laser.wav", NULL, 0, 0);
}


#endif