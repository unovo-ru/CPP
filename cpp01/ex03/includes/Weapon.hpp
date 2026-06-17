#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Weapon
{
	private:

		const std::string	type;

	public:

		const std::string&	getType(void) const;
};

#endif
