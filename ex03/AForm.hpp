/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:26:13 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 14:36:47 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>

#define ANSI_RED	"\x1b[31m"
#define ANSI_GRAY	"\x1b[90m"
#define ANSI_RESET	"\x1b[0m"
#define ANSI_GREEN "\x1b[32m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		AForm(const std::string name, bool is_signed, const int sign_grade, const int exec_grade);
		const std::string	getName(void) const;
		bool				getBool(void) const;
		int					getSignG(void) const;
		int					getExecG(void) const;
		void				beSigned(Bureaucrat &b);
		virtual int 		execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw() {
				return "grade is too high.";
			}
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw() {
			return "grade is too low";
			}
		};
};

std::ostream& operator<<(std::ostream &flux, AForm &fraction);

