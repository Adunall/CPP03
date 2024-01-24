/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:42:21 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 16:00:08 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default constructor called!" << std::endl;
    this->name = "DefaultName";
	this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called!" << std::endl;
    this->name = name;
	this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "ScavTrap Copy Constructor Called!" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor Called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    this->name = copy.getName();
    this->hit_points = copy.getHitPoints();
    this->energy_points = copy.getEnergyPoints();
    this->attack_damage = copy.getAtackDamage();
    return(*this);
}

void ScavTrap::attack(const std::string &target)
{
    if(this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout << "ScavTrap " << this->name << " is not suitable to attack their" << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is not suitable to attack their " << target << ", because he has not enough hit points." << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->hit_points <= 0)
	{
    	std::cout << "Cannot switch to gate-keeper mode because: ClapTrap " << this->name << " is dead." << std::endl;
        return ;
    }
    if (this->energy_points <= 0)
    {
        std::cout << this->name << "'s energy point run out!!" << std::endl;
        return ;
    }
    else
		std::cout << "ScavTrap from ClapTrap " << this->name << " switched to mode: \"Guard Gate\"." << std::endl;
}