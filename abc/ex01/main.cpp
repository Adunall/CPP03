/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:02:37 by adunal            #+#    #+#             */
/*   Updated: 2024/01/24 18:02:38 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "*--------------Testing--------------*" << std::endl;
	ClapTrap soldier;
	ClapTrap soldier_2("solider");

	soldier.attack("two enemy");
	soldier.takeDamage(10);
	soldier.takeDamage(10);
	soldier.beRepaired(5);
	soldier.attack("a enemy");
	soldier_2.beRepaired(3);
	soldier_2.takeDamage(10);

	std::cout << "*-----------------------------------*" << std::endl;

	ScavTrap scav("adem");
	scav.attack("enemies");
	scav.takeDamage(10);
	scav.beRepaired(10);
	scav.guardGate();
	scav.takeDamage(100);
	scav.takeDamage(10);
	scav.guardGate();

}