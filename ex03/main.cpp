/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:32:38 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 19:39:34 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	AForm *form = new ShrubberyCreationForm("file.txt");
	AForm *form2 = new RobotomyRequestForm("RACAILLOU");
	AForm *form3 = new PresidentialPardonForm("MACRON");
	Bureaucrat	*ceo = new Bureaucrat("ceo", 1);
	Bureaucrat	*intern = new Bureaucrat("Max", 71);
	
	std::cout << "------------ TEST 1 ------------" << std::endl;
	std::cout << *form << std::endl;
	ceo->signForm(*form);
	std::cout << std::endl;
	std::cout << *form << std::endl;
	ceo->executeForm(*form);
	
	std::cout << std::endl;
	std::cout << "------------ TEST 2 ------------" << std::endl;
	std::cout << *form2 << std::endl;
	intern->signForm(*form2);
	std::cout << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << std::endl;
	ceo->signForm(*form2);
	try
	{
		intern->executeForm(*form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	ceo->executeForm(*form2);
	std::cout << std::endl;
	std::cout << "------------ TEST 3 ------------" << std::endl;
	ceo->signForm(*form3);
	form3->execute(*ceo);
	std::cout << std::endl;
	delete form;
	delete form2;
	delete form3;
	delete ceo;
	delete intern;

	return (0);
}
