#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include <ctime>// for time()
#include <cstdlib>// for rand() and srand()

class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitPoints;

public:
	Monster(MonsterType type, std::string name, std::string roar, int hitPoints);
	std::string getTypeString();
	void print();
};

class MonsterGenerator
{
public:

	static int getRandomNumber(int min, int max);
	static Monster generateMonster();

};




#endif // !MONSTER_H
