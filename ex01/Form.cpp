/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:09:27 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 17:23:51 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

Form::Form(const Form &copy) : _name(copy._name), _is_signed(copy._is_signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade) {}

Form::~Form() {}

Form::Form(const std::string name, bool is_signed, const int sign_grade, const int exec_grade) : _name(name), _is_signed(is_signed), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1)
		throw Form::GradeTooHighException();
	else if (_sign_grade > 150)
		throw Form::GradeTooLowException();
	else if (_exec_grade < 1)
		throw Form::GradeTooHighException();
	else if (_exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &other) {return (this != &other) ? (_is_signed = other._is_signed, *this) : *this;}

const std::string	Form::getName(void) {return (_name);}

bool	Form::getBool(void) {return (_is_signed);}

int	Form::getSignG(void) {return (_exec_grade);}

int	Form::getExecG(void) {return (_sign_grade);}

void Form::beSigned(Bureaucrat &b)
{
	if (_is_signed)
	{
		std::cout << b.getName() << " couldn’t sign " << _name << " because it's already sign." << std::endl;
		return ;
	}
	if (b.getGrade() <= _sign_grade)
	{
		_is_signed = true;
		std::cout << _name << " has been signed" << std::endl;
		return ;
	}
	else if (b.getGrade() >= _sign_grade)
		throw Form::GradeTooLowException();
	return ;
}

std::ostream &operator<<(std::ostream &flux, Form &fraction)
{
	flux << ANSI_GRAY << fraction.getName() << ANSI_RESET << " form ";
	if (fraction.getBool())
		flux << ANSI_GREEN << "is signed "<< ANSI_RESET;
	else
		flux << ANSI_RED << "is not signed "<< ANSI_RESET;
	flux << "and need :" << std::endl;
	flux << "- " << fraction.getExecG() << " to be execute." << std::endl;
	flux << "- " << fraction.getSignG() << " to be signed." << std::endl;
	return (flux);
}
