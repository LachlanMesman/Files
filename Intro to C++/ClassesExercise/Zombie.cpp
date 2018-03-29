#include "Zombie.h"
#include <iostream>
using namespace std;


Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

//Sets the health
void Zombie::SetHealth(int health)
{
	this->health = health;

}

int  Zombie::GetHealth()
{
	return health;
}




//Sets the damage
void Zombie::SetDamage(int damage)
{
	this->damage = damage;
}

int Zombie::GetDamage()
{
	return damage;
}

void Zombie::SetPreviousOccupation(char previousOccupation[20])
{
	strcpy_s(this->previousOccupation, previousOccupation);
}

char * Zombie::GetPreviousOccupation()
{
	return previousOccupation;
}









