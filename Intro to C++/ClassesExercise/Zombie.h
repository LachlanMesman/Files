#pragma once


class Zombie
{
public:
	Zombie();
	~Zombie();

	void SetHealth(int health);
	int GetHealth();
	void SetDamage(int damage);
	int GetDamage();
	void SetPreviousOccupation(char previousOccupation[20]);
	char* GetPreviousOccupation();


private:
	int health;
	int damage;
	char previousOccupation[20];
};

