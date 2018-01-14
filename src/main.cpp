/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/14 02:36:12 by rfulop           ###   ########.fr       */
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
		e.reducedForm();
		e.setReducedForm();
		e.solveDegree();
		e.solve();
		std::cout << e;
		std::cout << *e.getLeft();

    }
	return 0;
}
