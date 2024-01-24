/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:03:30 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 18:03:32 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Default constructor called!" << std::endl;
    this->name = "DefaultName";
	this->hit_pts = 100;
    this->energy_pts = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called!" << std::endl;
    this->name = name;
	this->hit_pts = 100;
    this->energy_pts = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.name)
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
    this->hit_pts = copy.getHitPoints();
    this->energy_pts = copy.getEnergyPoints();
    this->attack_damage = copy.getAtackDamage();
    return(*this);
}

void ScavTrap::attack(const std::string &target)
{
    if(this->energy_pts > 0 && this->hit_pts > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_pts--;
	}
	else if (this->energy_pts == 0)
		std::cout << "ScavTrap " << this->name << " is not suitable to attack their " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is not suitable to attack their " << target << ", because he has not enough hit points." << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->hit_pts <= 0)
	{
    	std::cout << "Cannot switch to gate-keeper mode because: ClapTrap " << this->name << " is dead." << std::endl;
        return ;
    }
    if (this->energy_pts <= 0)
    {
        std::cout << this->name << "'s energy point run out!!" << std::endl;
        return ;
    }
    else
		std::cout << "ScavTrap from ClapTrap " << this->name << " switched to mode: \"Guard Gate\"." << std::endl;
}