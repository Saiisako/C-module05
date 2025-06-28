/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:32:38 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 16:34:36 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	ceo("Jean-Paul", 50);
	Form	formulaire_942("formulaire_942", false, 1, 1);
	Form	formulaire_943("formulaire_943", false, 60, 1);

	std::cout << formulaire_942 << std::endl;

	try
	{
		formulaire_943.beSigned(ceo);
		formulaire_942.beSigned(ceo);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}