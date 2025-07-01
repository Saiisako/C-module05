/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:05:15 by skock             #+#    #+#             */
/*   Updated: 2025/07/01 08:16:03 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& other);
		AForm *makeForm(std::string f_name, std::string f_target);
		class FormNameNotFound : public std::exception
		{
			virtual const char* what() const throw() {
				return "the name of the form does not exist.";
			}
		};
};
