#include "ClapTrap.hpp"
#include <iostream>

const unsigned int ClapTrap::MAX_HP = 10;

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10),
						   _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _energyPoints(10),
									   _attackDamage(0)
{
	std::cout << "Parametric constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy Assignment operetor called" << std::endl;
	const_cast<std::string &>(this->_name) = other.getName() + " (clone)";
	this->
}