/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:56:18 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 19:22:39 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {*this = copy;}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::setGrade(int grade) {_grade = grade;}

int Bureaucrat::getGrade(void) const {return (_grade);}

const std::string Bureaucrat::getName(void) {return (_name);}

void Bureaucrat::upGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::downGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	f.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
	int return_value;

	return_value = form.execute(*this);
	if (!return_value)
		std::cout << this->getName() << " executed "<< form.getName() << std::endl;
	else
	{
		std::cout << this->getName() << " failed to execute "<< form.getName() << " because ";
		throw AForm::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream &flux, Bureaucrat &fraction)
{
	flux << fraction.getName() << ", bureaucrat grade " << fraction.getGrade() << ".";
	return (flux);
}
