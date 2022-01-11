#ifndef ANIMATION_H
#define ANIMATION_H
#include "Variables.h"

int portal_frame;

vector<unsigned int> MSpriteL, MSpriteR, MSpriteJL, MSpriteJR, MSpriteI, MSpriteG, MSpriteAL, MSpriteAR, MSpriteJAL, MSpriteJAR;
vector<unsigned int> FSpriteL, FSpriteR, FSpriteJL, FSpriteJR, FSpriteI, FSpriteG, FSpriteAL, FSpriteAR, FSpriteJAL, FSpriteJAR;
vector<unsigned int> BulletSprite;
vector<unsigned int> E1_SpriteL, E1_SpriteR;
vector<unsigned int> portalSprite;
vector<unsigned int> E2_SpriteL, E2_SpriteR;
vector<unsigned int> E4_SpriteR, E4_SpriteL;
vector<unsigned int> PlantSprite;
vector<unsigned int> Meteor;
vector<unsigned int> PortalBatSprite;
vector<unsigned int> EnemyPortalSprite;
vector<unsigned int> TransitionImage;
vector<unsigned int> inventorySprite;
vector<unsigned int> BomberSpriteL, BomberSpriteR;

unsigned int E1_SpriteI;
unsigned int E3_SPriteL, E3_SPriteLA, E3_SPriteR, E3_SPriteRA, E3_SpriteFL, E3_SpriteFR;
unsigned int Beam_Sprite;
unsigned int LaserBeam;
unsigned int BossSpriteL, BossSpriteR;


void loadSprite(string path,int start, int end, vector<unsigned int> &sprite)
{
    string fullpath;
    for (int i = start; i < end; i++)
    {
        fullpath = "images\\" + path + "\\" + to_string(i) + ".png";
        sprite.push_back(iLoadImage(to_char(fullpath)));
    }
}

void Init_SpriteVector()
{
    loadSprite("maleLeft", 0, 10, MSpriteL);
    loadSprite("maleRight", 0, 10, MSpriteR);
    loadSprite("maleIdle", 0, 2, MSpriteI);
    loadSprite("maleJump", 0, 5, MSpriteJR);
    loadSprite("maleJump", 5, 10, MSpriteJL);
    loadSprite("maleGlide", 0, 2, MSpriteG);
    loadSprite("maleAttackR", 0, 10, MSpriteAR);
    loadSprite("maleAttackL", 0, 10, MSpriteAL);
    loadSprite("maleAttackJR", 0, 10, MSpriteJAR);
    loadSprite("maleAttackJL", 0, 10, MSpriteJAL);
    loadSprite("femLeft", 0, 10, FSpriteL);
    loadSprite("femRight", 0, 10, FSpriteR);
    loadSprite("femIdle", 0, 2, FSpriteI);
    loadSprite("femJump", 0, 5, FSpriteJR);
    loadSprite("femJump", 5, 10, FSpriteJL);
    loadSprite("femGlide", 0, 2, FSpriteG);
    loadSprite("femAttackR", 0, 10, FSpriteAR);
    loadSprite("femAttackL", 0, 10, FSpriteAL);
    loadSprite("femAttackJR", 0, 10, FSpriteJAR);
    loadSprite("femAttackJL", 0, 10, FSpriteJAL);

    loadSprite("bat", 0, 3, E4_SpriteL);
    loadSprite("bat", 4, 7, E4_SpriteR);
    loadSprite("e2l", 0, 20, E2_SpriteL);
    loadSprite("e2r", 0, 20, E2_SpriteR);
    loadSprite("e1l", 0, 20, E1_SpriteL);
    loadSprite("e1r", 0, 20, E1_SpriteR);
    E1_SpriteI = iLoadImage("images\\e1idle.png");
    E3_SPriteL = iLoadImage("images\\e3\\0.png");
    E3_SPriteLA = iLoadImage("images\\e3\\1.png");
    E3_SPriteR = iLoadImage("images\\e3\\2.png");
    E3_SPriteRA = iLoadImage("images\\e3\\3.png");
    E3_SpriteFL = iLoadImage("images\\e3\\4.png");
    E3_SpriteFR = iLoadImage("images\\e3\\5.png");
    Beam_Sprite = iLoadImage("images\\beam.png");
    LaserBeam = iLoadImage("images\\Laser.png");
    
    loadSprite("Shuriken", 0, 5, BulletSprite);
    loadSprite("Plant", 0, 14, PlantSprite);

    BossSpriteL = iLoadImage("images\\Boss\\1.png");
    BossSpriteR = iLoadImage("images\\Boss\\0.png");
    
    loadSprite("Meteor", 0, 9, Meteor);
    loadSprite("PortalBat", 0, 8, PortalBatSprite);

    loadSprite("bomber", 0, 8, BomberSpriteR);
    loadSprite("bomber", 8, 15, BomberSpriteL);

    loadSprite("portal", 0, 4, portalSprite);
    loadSprite("EnemyPortal", 0, 4, EnemyPortalSprite);

    loadSprite("inventory", 0, 4, inventorySprite);
}

#endif // !ANIMATION_H
