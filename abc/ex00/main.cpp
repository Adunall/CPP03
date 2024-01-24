#include "ClapTrap.hpp"

int main()
{
	std::cout << "*--------------Testing--------------*" << std::endl;
	ClapTrap soldier("adem");
	ClapTrap soldier_2(soldier);
	soldier.attack("two enemy");
	soldier.takeDamage(5);
	soldier.beRepaired(5);
	soldier.takeDamage(10);
	soldier.attack("a enemy");
	soldier_2.beRepaired(3);
	soldier_2.takeDamage(10);
}