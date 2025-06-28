/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:38:10 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 17:14:32 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		const std::string	getName(void);
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				upGrade();
		void				downGrade();
		void				signForm(Form &f);

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw() {
			return "Grade must be greater than 0.";
		}
	};
	class GradeTooLowException : public std::exception
	{
			virtual const char* what() const throw() {
			return "Grade must be less than 151.";
		}
	};
};

std::ostream& operator<<(std::ostream &flux, Bureaucrat &fraction);