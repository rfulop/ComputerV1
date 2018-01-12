/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/12 02:18:35 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATION_H
#define EQUATION_H

#include "computerv1.h"

class Equation
{
public:
    Equation(std::string expression);
    ~Equation(void);
    Equation(const Equation & src);
    Equation & operator=(const Equation & rhs);

    std::string getExpression(void) const;
    int getDegree(void) const;

    std::string delSpaces(const std::string & str);
    void solveDegree(void);

private:
    std::string _expression;
    int _degree;

};

std::ostream & operator<<(std::ostream & o, const Equation & rhs);

#endif
