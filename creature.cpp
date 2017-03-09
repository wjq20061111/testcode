#include <iostream>
#include <string>

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_attack;
	int m_gold;
public:
	Creature(std::string name,char symbol,int health,int attack,int gold)
		:m_name(name), m_symbol(symbol), m_health(health),m_attack(attack),m_gold(gold)
	{
	}
	std::string& getName()
	{
		return m_name;
	}

	char getSymbol()
	{
		return m_symbol;
	}

	int getHealth()
	{
		return m_health;
	}

	int getAttack()
	{
		return m_attack;
	}

	int getGold()
	{
		return m_gold;
	}
	void addGold(int gold)
	{
		m_gold = m_gold + gold;
	}
	void reduceHealth(int health)
	{
		m_health = m_health - health;
	}
	bool isDead()
	{
		return m_health <= 0;
	}
};

class Player:public Creature
{
private:
	int m_level;
public:
	Player(std::string name) :Creature(name, '@', 10, 1, 0), m_level(0)
	{
	}
	void levelUp()
	{
		m_level = m_level + 1;
		m_attack = m_attack + 1;
	}
	int getLevel()
	{
		return m_level;
	}
	bool hasWon()
	{
		return m_level >= 20;
	}
};
class Monster:public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	struct MonsterData
	{
		const char* name;
		char symbol;
		int health;
		int attack;
		int gold;
	};
	static MonsterData monsterData[MAX_TYPES];
public:
	Monster(Type type):
		Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, 
			monsterData[type].attack, monsterData[type].gold)
	{
	}
};

Monster::MonsterData 
Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

int main()
{
	
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	Player p(name);
	std::cout << "Welcome, " << p.getName() << ".\n";
	std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";

	Monster m(Monster::ORC);
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

	return 0;
}