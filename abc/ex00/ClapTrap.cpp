/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:05 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 18:04:27 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap def Constructor called!!" << std::endl;
	this->name = "Unknown person";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor with parameter called!!" << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClatTrap Copy constructor called!!" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called!!" << std::endl;
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	this->energy_points= other.energy_points;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}
int ClapTrap::getHitPts() const
{
	return (this->hit_points);
}
int ClapTrap::getEnergyPts() const
{
	return (this->energy_points);
}
int ClapTrap::get_AttackDamage() const
{
	return (this->attack_damage);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}
void ClapTrap::set_hitpts(int hp)
{
	this->hit_points = hp;
}
void ClapTrap::set_Energypts(int energy)
{
	this->energy_points = energy;
}
void ClapTrap::set_attackDamage(int damage)
{
	this->attack_damage = damage;
}

void	ClapTrap::attack(const std::string &target)
{
	if(this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << "ClatTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " is not suitable to attack their " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is not suitable to attack their " << target << ", because he has not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage!!" << std::endl;
		this->hit_points -= amount;
		if(!hit_points)
			std::cout << "ClapTrap " << this->name << "  is dead :(" << std::endl;
	}
	else
		std::cout << "Stop now! ClapTrap " << this->name << " is already dead ..." << std::endl;
	if (this->hit_points < 0)
		this->hit_points = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if(this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " unsuring his/her health " << amount << " Points." << std::endl;
		this->hit_points += amount;
		this->energy_points--;
	}
	if (this->hit_points <= 0)
		std::cout << "Cannot repair. Because ClapTrap " << this->name << " is dead." << std::endl;
	else if (!this->energy_points)
		std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
}