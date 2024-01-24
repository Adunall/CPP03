/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:11 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 18:02:14 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int			hit_points;
		int			energy_points;
		int			attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
	
		~ClapTrap();
	
		ClapTrap(const ClapTrap &copy);
	
		ClapTrap &operator=(const ClapTrap &other);
	
		std::string getName() const;
		int getHitPts() const;
		int getEnergyPts() const;
		int get_AttackDamage() const;
	
		void setName(std::string name); 
		void set_hitpts(int hp);
		void set_Energypts(int energy);
		void set_attackDamage(int damage);
	
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif