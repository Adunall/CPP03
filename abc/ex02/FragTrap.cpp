/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:44 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 17:58:47 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap def constructor called!!" << std::endl;
    this->name = "DefaultName";
	this->hit_pts = 100;
    this->energy_pts = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor called!!" << std::endl;
	this->name = name;
	this->hit_pts = 100;
    this->energy_pts = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    std::cout << "FragTrap Copy Constructor Called!!" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor Called!!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    this->name = copy.getName();
    this->hit_pts = copy.getHitPoints();
    this->energy_pts = copy.getEnergyPoints();
    this->attack_damage = copy.getAtackDamage();
    return(*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hit_pts <= 0)
	{
		std::cout << "Cannot high five because: ClapTrap " << this->name << " is dead." << std::endl;
		return ;
	}

	if (this->energy_pts <= 0)
    {
        std::cout << this->name << "'s energy point run out!!" << std::endl;
        return ;
    }
	else
		std::cout << "FragTrap from ClapTrap " << this->name << " says: \"HIGH FIVE EVERYONE! :))\"." << std::endl;
}