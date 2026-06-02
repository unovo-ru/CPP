/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:33:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/06/02 18:42:12 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		bool	isAscii = true;
		for (int i = 1; i < ac; i++)
			for (int j = 0; av[i][j]; j++)
				if ((unsigned char)av[i][j] > 127)
					isAscii = false;
		if (!isAscii)
		{
			std::cout	<< "Error, only ascii."
						<< std::endl;
			return (1);
		}
		else
			for (int i = 1; i < ac; i++)
				for (int j = 0; av[i][j]; j++)
					std::cout	<< (char)toupper(av[i][j]);
		std::cout << std::endl;
	}
	return (0);
}
