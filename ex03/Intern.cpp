/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:08:14 by skock             #+#    #+#             */
/*   Updated: 2025/07/01 08:31:35 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &copy) {*this = copy;}

AForm* createShrubbery() { return new ShrubberyCreationForm(); }

AForm* createRobotomy() { return new RobotomyRequestForm(); }

AForm* createPresidential() { return new PresidentialPardonForm(); }

AForm *Intern::makeForm(std::string f_name, std::string f_target)
{
	(void)f_target;
	AForm* (*f[])() = {createShrubbery, createRobotomy, createPresidential};
	std::string index[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; ++i) {
		if (index[i] == f_name)
		{
			std::cout << "Intern creats " << f_name << " to " << f_target << std::endl;
			return f[i]();
		}
	}
	std::cout << "Intern failed to create [" << f_name << "] form because ";
	throw Intern::FormNameNotFound();
	return (NULL);
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}