/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skock <skock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:10:28 by skock             #+#    #+#             */
/*   Updated: 2025/06/30 18:52:42 by skock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("random_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		// what to affect.
	}
	return (*this);
}

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getBool() && executor.getGrade() <= this->getExecG())
	{
		std::ofstream file(this->_target.c_str());
		if (file) {
			file << "                                                         .\n";
			file << "                                              .         ;  \n";
			file << "                 .              .              ;%     ;;   \n";
			file << "                   ,           ,                :;%  %;   \n";
			file << "                    :         ;                   :;%;'     .,   \n";
			file << "           ,.        %;     %;            ;        %;'    ,;\n";
			file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
			file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
			file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
			file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
			file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
			file << "                    `:%;.  :;bd%;          %;@%;'\n";
			file << "                      `@%:.  :;%.         ;@@%;'   \n";
			file << "                        `@%.  `;@%.      ;@@%;         \n";
			file << "                          `@%%. `@%%    ;@@%;        \n";
			file << "                            ;@%. :@%%  %@@%;       \n";
			file << "                              %@bd%%%bd%%:;     \n";
			file << "                                #@%%%%%:;;\n";
			file << "                                %@@%%%::;\n";
			file << "                                %@@@%(o);  . '         \n";
			file << "                                %@@@o%;:(.,'         \n";
			file << "                            `.. %@@@o%::;         \n";
			file << "                               `)@@@o%::;         \n";
			file << "                                %@@(o)::;        \n";
			file << "                               .%@@@@%::;         \n";
			file << "                               ;%@@@@%::;.          \n";
			file << "                              ;%@@@@%%:;;;. \n";
			file << "                          ...;%@@@@@%%:;;;;,..\n";
			file << "\n";
			file << "                                                         .\n";
			file << "                                              .         ;  \n";
			file << "                 .              .              ;%     ;;   \n";
			file << "                   ,           ,                :;%  %;   \n";
			file << "                    :         ;                   :;%;'     .,   \n";
			file << "           ,.        %;     %;            ;        %;'    ,;\n";
			file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
			file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
			file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
			file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
			file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
			file << "                    `:%;.  :;bd%;          %;@%;'\n";
			file << "                      `@%:.  :;%.         ;@@%;'   \n";
			file << "                        `@%.  `;@%.      ;@@%;         \n";
			file << "                          `@%%. `@%%    ;@@%;        \n";
			file << "                            ;@%. :@%%  %@@%;       \n";
			file << "                              %@bd%%%bd%%:;     \n";
			file << "                                #@%%%%%:;;\n";
			file << "                                %@@%%%::;\n";
			file << "                                %@@@%(o);  . '         \n";
			file << "                                %@@@o%;:(.,'         \n";
			file << "                            `.. %@@@o%::;         \n";
			file << "                               `)@@@o%::;         \n";
			file << "                                %@@(o)::;        \n";
			file << "                               .%@@@@%::;         \n";
			file << "                               ;%@@@@%::;.          \n";
			file << "                              ;%@@@@%%:;;;. \n";
			file << "                          ...;%@@@@@%%:;;;;,..\n";
		file.close();
		return (0);
		}
		else
		{
			std::cout << "Unable to open file" << std::endl;
			return (1);
		}
	}
	else
		return (1);
}