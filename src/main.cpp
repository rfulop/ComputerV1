/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/12 02:19:12 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Usage : ./computerv1 arg1" << std::endl;
	else
	{
		Equation e(argv[1]);
		e.solveDegree();
		std::cout << e;
    }
	return 0;
}
