/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:55 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 18:02:57 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default Constructor called!!" << std::endl;
	this->name = "DefaultName";
	this->hit_pts = 10;
	this->energy_pts = 10;
	this->attack_damage = 0;
}
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called!!" << std::endl;
	this->name = name;
	this->hit_pts = 10;
	this->energy_pts = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClatTrap Copy constructor called!!" << std::endl;
	*this = copy;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment operator called!!" << std::endl;
	if(this != &other)
	{
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->energy_pts = other.energy_pts;
	this->energy_pts= other.energy_pts;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called!!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}
int ClapTrap::getHitPoints() const
{
	return (this->hit_pts);
}
int ClapTrap::getEnergyPoints() const
{
	return (this->energy_pts);
}
int ClapTrap::getAtackDamage() const
{
	return (this->attack_damage);
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}
void ClapTrap::setHitPoints(int hp)
{
	this->hit_pts = hp;
}
void ClapTrap::setEnergyPoints(int energy)
{
	this->energy_pts = energy;
}
void ClapTrap::setAttackDamage(int damage)
{
	this->attack_damage = damage;
}

void	ClapTrap::attack(const std::string &target)
{
	if(this->energy_pts > 0 && this->hit_pts > 0)
	{
		std::cout << "ClatTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!!" << std::endl;
		this->energy_pts--;
	}
	else if (this->energy_pts == 0)
		std::cout << "ClapTrap " << this->name << " is not suitable to attack their " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is not suitable to attack their " << target << ", because he has not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_pts > 0)
	{
		std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage!" << std::endl;
		this->hit_pts -= amount;
		if(!hit_pts)
			std::cout << "ClapTrap " << this->name << "  is dead :(" << std::endl;
	}
	else
		std::cout << "STOP! ClapTrap " << this->name << " is already dead :(" << std::endl;
	if (this->hit_pts < 0)
		this->hit_pts = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if(this->energy_pts > 0 && this->hit_pts > 0)
	{
		std::cout << "ClapTrap " << this->name << " healed " << amount << " Points." << std::endl;
		this->hit_pts += amount;
		this->energy_pts--;
	}
	if (this->hit_pts <= 0)
		std::cout << "Cannot repair because: ClapTrap " << this->name << " is dead." << std::endl;
	else if (!this->energy_pts)
		std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
}