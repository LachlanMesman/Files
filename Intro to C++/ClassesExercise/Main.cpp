#include <iostream>
#include <random>
#include <time.h>
#include "Zombie.h"
using namespace std;

int ranHealth = 0;
int ranDamage = 0;
char ranPreOcc[20] = "";

int random()
{

	//Random Health
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(50, 100);
	ranHealth = dis(gen);
	

	//Random Damage
	random_device rd1;
	mt19937 gen1(rd1());
	uniform_int_distribution<> dis1(1, 50);
	ranDamage = dis1(gen1);

	//Random Previous Occupation
	random_device rd2;
	mt19937 gen2(rd2());
	uniform_int_distribution<> dis2(1, 6);
	switch (dis2(gen2))
	{
	case 1:
		strcpy_s(ranPreOcc, "Drunk");
		break;
	case 2:
		strcpy_s(ranPreOcc, "Teacher");
		break;
	case 3:
		strcpy_s(ranPreOcc, "Banker");
		break;
	case 4:
		strcpy_s(ranPreOcc, "Game Programmer");
		break;
	case 5:
		strcpy_s(ranPreOcc, "Mailman");
		break;
	case 6:
		strcpy_s(ranPreOcc, "Football Player");
		break;
	default:
		break;
	}
	return ranDamage;
}


int main()
{
	Zombie zombie[3];
	bool fight = false;
	int done = 0;

	for (int i = 0; i < 3; i++)
	{
		//Gives the zombies health, damage and a previous occupation
		cout << "Zombie " << i + 1 << endl;
		random();
		zombie[i].SetHealth(ranHealth);
		cout << "Health : " << zombie[i].GetHealth() << endl;;
		zombie[i].SetDamage(ranDamage);
		cout << "Damage : " << zombie[i].GetDamage() << endl;;
		zombie[i].SetPreviousOccupation(ranPreOcc);
		cout << "Previous Occupation : " << zombie[i].GetPreviousOccupation() << endl;;
		//+1 to done 
		done++;		
		//Only once done = 3(lets the zombies their variables before fight happens)
		if (done == 3)
		{
			fight = true;
		}
		cin.get();
		while (fight)
		{
			//For loop for the rounds
			for (int a = 1; a < 100; a++)
			{
				if (zombie[0].GetHealth() <= 0 && zombie[1].GetHealth() <= 0 && zombie[2].GetHealth() <= 0)
				{
					cout << "IT'S A TIE" << endl;
					cout << "Press 'Enter to quit";
					cin.get();
					return false;
				}
				else
					if (zombie[0].GetHealth() <= 0 && zombie[1].GetHealth() <= 0)
					{
						cout << "ZOMBIE 3 IS THE WINNER" << endl;
						cout << "Press 'Enter to quit";
						cin.get();
						return false;
					}
					else
						if (zombie[0].GetHealth() <= 0 && zombie[2].GetHealth() <= 0)
						{
							cout << "ZOMBIE 2 IS THE WINNER" << endl;
							cout << "Press 'Enter to quit";
							cin.get();
							return false;
						}
						else
							if (zombie[1].GetHealth() <= 0 && zombie[2].GetHealth() <= 0)
							{
								cout << "ZOMBIE 1 IS THE WINNER" << endl;
								cout << "Press 'Enter' to quit";
								cin.get();
								return false;
							}
				cout << "Round " << a << "\n" << endl;;
				//For loop for the turns
				for (int i = 1; i < 4; i++)
				{
					switch (i)
					{
					case 1:
					{
						//Gets a random number to choose what action Zombie 1 will do
						random_device rd;
						mt19937 gen(rd());
						uniform_int_distribution<> dis(1, 3);
						int random = dis(gen);
						//Switch thats holds the action Zombie 1 can do
						switch (random)
						{
						case 1:
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Zombie 1's body moves a little" << endl;
								cin.get();
								break;
							}
							//Gets zombie 1's health and takes away by his damage giving him his new health
							zombie[0].SetHealth((zombie[0].GetHealth()) - (zombie[0].GetDamage()));
							cout << "Zombie 1 hit himself and dealt " << zombie[0].GetDamage() << " of damage" << endl;
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Killing himself";
							}	
							else
								cout << "Leaving him with " << zombie[0].GetHealth() << " health" << endl;
							cin.get();
							break;
						case 2:
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Zombie 1's body moves a little towards Zombie 2" << endl;
								cin.get();
								break;
							}
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Zombie 1 bashes Zombie 2 body" << endl;
								cin.get();
								break;
							}
							//Gets zombie 2's health and takes away by Zombie 1's damage giving him his new health
							zombie[1].SetHealth((zombie[1].GetHealth()) - (zombie[0].GetDamage()));
							cout << "Zombie 1 hit Zombie 2 and dealt " << zombie[0].GetDamage() << " of damage" << endl;
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Killing Zombie 2";
							}
							else
								cout << "Leaving him with " << zombie[1].GetHealth() << " health" << endl;		
							cin.get();
							break;
						case 3:
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Zombie 1's body moves a little towards Zombie 3" << endl;
								cin.get();
								break;
							}
							//Checks if Zombie 3's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Zombie 1 bashes Zombie 3 body" << endl;
								cin.get();
								break;
							}
							//Gets zombie 3's health and takes away by Zombie 1's damage giving him his new health
							zombie[2].SetHealth((zombie[2].GetHealth()) - (zombie[0].GetDamage()));
							cout << "Zombie 1 hit Zombie 3 and dealt " << zombie[0].GetDamage() << " of damage" << endl;
							//Checks if Zombie 3's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Killing Zombie 3";
							}
							else
								cout << "Leaving him with " << zombie[2].GetHealth() << " health" << endl;						
							cin.get();
							break;
						default:
							break;
						}
					}
						break;
					case 2:
					{
						//Gets a random number to choose what action Zombie 2 will do
						random_device rd1;
						mt19937 gen1(rd1());
						uniform_int_distribution<> dis1(1, 3);
						int random1 = dis1(gen1);
						//Switch thats holds the action Zombie 2 can do
						switch (random1)
						{
						case 1:
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Zombie 2's body moves a little" << endl;
								cin.get();
								break;
							}
							//Gets zombie 2's health and takes away by Zombie 2's damage giving him his new health
							zombie[1].SetHealth((zombie[1].GetHealth()) - (zombie[1].GetDamage()));
							cout << "Zombie 2 hit himself and dealt " << zombie[1].GetDamage() << " of damage" << endl;
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Killing himself" << endl;
							}
							else
								cout << "Leaving him with " << zombie[1].GetHealth() << " health" << endl;
							cin.get();
							break;
						case 2:
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Zombie 2's body moves a little towards Zombie 3" << endl;
								cin.get();
								break;
							}
							//Checks if Zombie 23s is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Zombie 2 bashes Zombie 3 body" << endl;
								cin.get();
								break;
							}
							//Gets zombie 3's health and takes away by Zombie 2's damage giving him his new health
							zombie[2].SetHealth((zombie[2].GetHealth()) - (zombie[1].GetDamage()));
							cout << "Zombie 2 hit Zombie 3 and dealt " << zombie[1].GetDamage() << " of damage" << endl;
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Killing Zombie 3" << endl;
							}
							else
								cout << "Leaving him with " << zombie[2].GetHealth() << " health" << endl;
							cin.get();
							break;
						case 3:
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Zombie 2's body moves a little towards Zombie 1" << endl;
								cin.get();
								break;
							}
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Zombie 2 bashes Zombie 1 body" << endl;
								cin.get();
								break;
							}
							//Gets zombie 1's health and takes away by Zombie 2's damage giving him his new health
							zombie[0].SetHealth((zombie[0].GetHealth()) - (zombie[1].GetDamage()));
							cout << "Zombie 2 hit Zombie 1 and dealt " << zombie[1].GetDamage() << " of damage" << endl;
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Killing Zombie 1" << endl;
							}
							else
								cout << "Leaving him with " << zombie[0].GetHealth() << " health" << endl;
							cin.get();
							break;
						default:
							break;
						}
					}
						break;
					case 3:
					{
						//Gets a random number to choose what action Zombie 2 will do
						random_device rd2;
						mt19937 gen2(rd2());
						uniform_int_distribution<> dis2(1, 3);
						int random2 = dis2(gen2);
						//Switch thats holds the action Zombie 2 can do
						switch (random2)
						{
						case 1:
							//Checks if Zombie 3's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Zombie 3's body moves a little" << endl;
								cin.get();
								break;
							}
							//Gets zombie 3's health and takes away by Zombie 3's damage giving him his new health
							zombie[2].SetHealth((zombie[2].GetHealth()) - (zombie[2].GetDamage()));
							cout << "Zombie 3 hit himself and dealt " << zombie[2].GetDamage() << " of damage" << endl;
							//Checks if Zombie 3's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Killing himself" << endl;
							}
							else
								cout << "Leaving him with " << zombie[2].GetHealth() << " health" << endl;
							cin.get();
							break;
						case 2:
							//Checks if Zombie 3's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Zombie 3's body moves a little towards Zombie 1" << endl;
								cin.get();
								break;
							}
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Zombie 3 bashes Zombie 1 body" << endl;
								cin.get();
								break;
							}
							//Gets zombie 1's health and takes away by Zombie 3's damage giving him his new health
							zombie[0].SetHealth((zombie[0].GetHealth()) - (zombie[2].GetDamage()));
							cout << "Zombie 3 hit Zombie 1 and dealt " << zombie[2].GetDamage() << " of damage" << endl;
							//Checks if Zombie 1's is equal to or below 0
							if (zombie[0].GetHealth() <= 0)
							{
								cout << "Killing Zombie 1" << endl;
							}
							else
								cout << "Leaving him with " << zombie[0].GetHealth() << " health" << endl;					
							cin.get();
							break;
						case 3:
							//Checks if Zombie 3's is equal to or below 0
							if (zombie[2].GetHealth() <= 0)
							{
								cout << "Zombie 3's body moves a little towards Zombie 2" << endl;
								cin.get();
								break;
							}
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Zombie 3 bashes Zombie 2 body" << endl;
								cin.get();
								break;
							}
							//Gets zombie 2's health and takes away by Zombie 3's damage giving him his new health
							zombie[1].SetHealth((zombie[1].GetHealth()) - (zombie[2].GetDamage()));
							cout << "Zombie 3 hit Zombie 2 and dealt " << zombie[2].GetDamage() << " of damage" << endl;
							//Checks if Zombie 2's is equal to or below 0
							if (zombie[1].GetHealth() <= 0)
							{
								cout << "Killing Zombie 2" << endl;
							}
							else
								cout << "Leaving him with " << zombie[1].GetHealth() << " health" << endl;						
							cin.get();
							break;
						default:
							break;
						}
					}
						break;
					default:
						break;
					}
				}				
			}
			cout << "\n";
		}
	}
} 