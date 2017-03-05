#include "Monster.h"


Monster::Monster(MonsterType type, std::string name, std::string roar, int hitPoints)
	:m_type(type), m_name(name), m_roar(roar), m_hitPoints(hitPoints)
{
}

std::string Monster::getTypeString()
{
	switch (m_type)
	{
	case Dragon:	return "Dragon";
	case Goblin:	return "Goblin";
	case Ogre:		return "Ogre";
	case Orc:		return "Orc";
	case Skeleton:	return "Skeleton";
	case Troll:		return "Troll";
	case Vampire:	return "Vampire";
	case Zombie:	return "Zombie";
	default:		return "NOT_MONSTER_TYPE";
	}
}
void Monster::print()
{
	std::cout << m_name << " the " << getTypeString() << " has "
		<< m_hitPoints << " hit points and says " << m_roar << "\n";
}



// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int MonsterGenerator::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
Monster MonsterGenerator::generateMonster()
{
	Monster::MonsterType rdm_type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));

	static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
	static std::string s_roars[6]{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };

	std::string rdm_name = s_names[getRandomNumber(0, 5)];
	std::string rdm_roar = s_roars[getRandomNumber(0, 5)];
	int rdm_hp = getRandomNumber(0, 100);

	return Monster(rdm_type, rdm_name, rdm_roar, rdm_hp);
}
