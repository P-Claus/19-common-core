#include "../includes/Harl.hpp"


Harl::Harl(void)
{
	std::cout << "Harl has been created" << std::endl; 
}

Harl::~Harl(void)
{
	std::cout << "Harl has been killed" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]		I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]		I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]  	I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]		This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*f)(void);
	int		code;
	std::string	log[4]; 

	log[0] = "debug";
	log[1] = "info";
	log[2] = "warning";
	log[3] = "error";

	for (int i = 0; i < 4; i++)
	{
		if (level == log[i])
			code = i;
	}
	switch (code)
	{
		case 0:
			f = &Harl::debug;
			break ;
		case 1:
			f = &Harl::info;
			break ;
		case 2:
			f = &Harl::warning;
			break ;
		case 3:
			f = &Harl::error;
			break ;
	};
	(this->*f)();
}
