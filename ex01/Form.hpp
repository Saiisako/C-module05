/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:26:13 by skock             #+#    #+#             */
/*   Updated: 2025/06/28 16:29:36 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define ANSI_RED	"\x1b[31m"
#define ANSI_GRAY	"\x1b[90m"
#define ANSI_RESET	"\x1b[0m"
#define ANSI_GREEN "\x1b[32m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		Form();
		~Form();
		Form(const Form& copy);
		Form& operator=(const Form& other);
		Form(const std::string name, bool is_signed, const int sign_grade, const int exec_grade);
		const std::string	getName(void);
		bool				getBool(void);
		int					getSignG(void);
		int					getExecG(void);
		void				beSigned(Bureaucrat b);
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw() {
				return "Grade is too high.";
			}
		};
		class GradeTooLowException : public std::exception
		{
				virtual const char* what() const throw() {
				return "Grade is too low";
			}
		};
};

std::ostream& operator<<(std::ostream &flux, Form &fraction);

