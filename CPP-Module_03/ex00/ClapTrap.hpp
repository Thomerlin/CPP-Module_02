#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <string>

class ClapTrap {
	private:
		const std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

		static const unsigned int MAX_HP;

	public:
		ClapTrap(void);
		explicit ClapTrap(const std::string name);
		explicit ClapTrap(const ClapTrap &other);
		ClapTrap(const ClapTrap &other);
		~ClapTrap(void);
		
		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;

		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;

		void setHitPoints(unsigned int hitPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setAttackDamage(unsigned int attackDamage);

		bool hasEnergy(void) const;
		bool isDead(void);
		void consumeEnergy(void) const;
};

#endif