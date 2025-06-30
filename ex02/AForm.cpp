/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:09:27 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 17:23:51 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AForm"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const AForm &copy) : _name(copy._name), _is_signed(copy._is_signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade) {}

AForm::~AForm() {}

AForm::AForm(const std::string name, bool is_signed, const int sign_grade, const int exec_grade) : _name(name), _is_signed(is_signed), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1)
		throw AForm::GradeTooHighException();
	else if (_sign_grade > 150)
		throw AForm::GradeTooLowException();
	else if (_exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (_exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm &other) {return (this != &other) ? (_is_signed = other._is_signed, *this) : *this;}

const std::string	AForm::getName(void) const {return (_name);}

bool	AForm::getBool(void) const {return (_is_signed);}

int	AForm::getSignG(void) const {return (_sign_grade);}

int	AForm::getExecG(void) const {return (_exec_grade);}

void AForm::beSigned(Bureaucrat &b)
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
		throw AForm::GradeTooLowException();
	return ;
}

std::ostream &operator<<(std::ostream &flux, AForm &fraction)
{
	flux << ANSI_GRAY << fraction.getName() << ANSI_RESET << " Aform ";
	if (fraction.getBool())
		flux << ANSI_GREEN << "is signed "<< ANSI_RESET;
	else
		flux << ANSI_RED << "is not signed "<< ANSI_RESET;
	flux << "and need :" << std::endl;
	flux << "- " << fraction.getSignG() << " to be signed." << std::endl;
	flux << "- " << fraction.getExecG() << " to be execute." << std::endl;
	return (flux);
}
