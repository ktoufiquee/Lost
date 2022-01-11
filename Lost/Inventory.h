#ifndef INVENTORY_H
#define INVENTORY_H
#include "Objects.h"

void Show_Inventory()
{
	if (Inventory)
	{
		iSetColor(255, 255, 255);
		if (Shuriken)
		{
			iShowImage(370, 50, 1, inventorySprite[1]);
		}
		else if (Katana)
		{
			iShowImage(370, 50, 1, inventorySprite[2]);
		}
		else if (Laser)
		{
			iShowImage(370, 50, 1, inventorySprite[3]);
		}
		else
		{
			iShowImage(370, 50, 1, inventoryScreen);
		}
		iSetColor(0, 0, 0);
		char itemCount[50];
		strcpy(itemCount, to_char(items[0]));
		iText(783, 492, itemCount);
		memset(itemCount, NULL, sizeof(itemCount));
		strcpy(itemCount, to_char(items[1]));
		iText(783, 428, itemCount);
		memset(itemCount, NULL, sizeof(itemCount));
		strcpy(itemCount, to_char(items[2]));
		iText(783, 369, itemCount);
		memset(itemCount, NULL, sizeof(itemCount));
	}
}

void consumeHealth()
{
	if (items[0] > 0)
	{
		if (MainC.health > 0)
		{
			if (MainC.health + 15 > 100)
			{
				MainC.health = 100;
			}
			else
			{
				items[0]--;
				MainC.health = MainC.health + 15;
				EatingSound();
			}
		}
	}
}

void consumeEnergy()
{
	if (items[1] > 0)
	{
		if (energy_width >= 0)
		{
			if (energy_width + 10 > 100)
			{
				energy_width = 100;
			}
			else
			{
				items[1]--;
				energy_width = energy_width + 10;
				DrinkingSound();
			}
		}
	}
}

#endif