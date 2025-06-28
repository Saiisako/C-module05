/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:32:38 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 17:26:28 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	
	std::cout << "-------------- TEST 1 --------------" << std::endl;
	Bureaucrat	*ceo = new Bureaucrat("Jean-Paul", 50);
	Form	*formulaire_942 = new Form("formulaire_942", false, 1, 1);
	Form	*formulaire_943 = new Form("formulaire_943", false, 60, 1);

	std::cout << *formulaire_942 << std::endl;
	std::cout << std::endl;
	std::cout << *formulaire_943 << std::endl;
	std::cout << std::endl;
	try
	{
		formulaire_943->beSigned(*ceo);
		formulaire_942->beSigned(*ceo);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "-------------- TEST 1 --------------" << std::endl;
	Form	*formulaire_944 = new Form("formulaire_944", false, 60, 1);
	std::cout << *formulaire_944 << std::endl;
	try
	{
		ceo->signForm(*formulaire_944);
		std::cout << *formulaire_944 << std::endl;
		ceo->signForm(*formulaire_944);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	delete ceo; delete formulaire_942; delete formulaire_943; delete formulaire_944;
}