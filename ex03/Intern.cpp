/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:14 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 20:57:11 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &copy) {*this = copy;}

Intern& Intern::operator=(const Intern &other) {(void)other;}

AForm *Intern::makeForm(std::string f_name, std::string f_target)
{
		// Fonctions factory
	AForm* createShrubbery() { return new ShrubberyCreationForm("target"); }
	AForm* createRobotomy() { return new RobotomyRequestForm(...); }
	AForm* createPresidential() { return new PresidentialPardonForm(...); }

	// Tableau de pointeurs vers fonctions
	AForm* (*factories[])() = { &createShrubbery, &createRobotomy, &createPresidential };

	// Utilisation
	for (int i = 0; i < 3; ++i) {
		if (index[i] == f_name)
			return factories[i]();
	}

}

	// typedef AForm * (*FormFactory)();

	// AForm *createPresidential() {return (new ShrubberyCreationForm());}
	// AForm *createShrubbery() {new RobotomyRequestForm()}
	// AForm *createRobotomy() {new PresidentialPardonForm()}
	
	// for (int j = 0; j < 3; j++)
	// {
	// 	if (!index[j].compare(f_name))
	// 	{
	// 		(this->*f[j])();
	// 		return (new);
	// 	}
	// }
}