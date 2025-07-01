/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:32:38 by skock             #+#    #+#             */
/*   Updated: 2025/07/01 08:46:54 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	*ceo = new Bureaucrat("ceo", 1);
	Intern *slave = new Intern();

	std::cout << "---------Test1---------" << std::endl;
	
	try
	{
		AForm *formx2 = slave->makeForm("RobotomyRequestForm", ceo->getName());
		ceo->signForm(*formx2);
		delete formx2;
		
		AForm *invalidForm = slave->makeForm("I want to quit the job", ceo->getName());
		delete invalidForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "---------Test2---------" << std::endl;
	AForm *formx = slave->makeForm("RobotomyRequestForm", ceo->getName());
	ceo->signForm(*formx);
	ceo->executeForm(*formx);

	delete formx;
	delete slave;
	delete ceo;
	return (0);
}

