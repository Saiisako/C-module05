/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:32:38 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 13:10:32 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "------------first try------------" << std::endl;
	try
	{
		Bureaucrat ceo("Jean-Paul", 1);
		Bureaucrat intern("Jacouille", 150);
		Bureaucrat janitor("Magalie", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "------------second try------------" << std::endl;
	try
	{
		Bureaucrat imposter("Jean-Pol", 0);
		Bureaucrat ceo("Jean-Paul", 1);
		Bureaucrat janitor("Magalie", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl;
	std::cout << "------------third try------------" << std::endl;

	Bureaucrat ceo("Jean-Paul", 1);

	try
	{
		ceo.upGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	std::cout << "------------fourth try------------" << std::endl;
	std::cout << ceo << std::endl;
	std::cout << std::endl;
}