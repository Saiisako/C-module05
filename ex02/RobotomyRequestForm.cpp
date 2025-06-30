/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:10:28 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 16:40:27 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("random_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		// what to affect.
	}
	return (*this);
}

int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getBool() && executor.getGrade() <= this->getExecG())
	{
		struct timeval tv;
		gettimeofday(&tv, NULL);
		unsigned int seed = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		srand(seed);

		int random = rand() % 2;
		std::cout << "* drilling noises *" << std::endl;
		if (random)
			std::cout << _target << " has been robotomized" << std::endl;
		else
			std::cout << "the robotomy failed" << std::endl;
		return (0);
	}
	else
		return (1);
}