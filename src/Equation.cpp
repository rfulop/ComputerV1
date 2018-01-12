/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/12 02:24:55 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Equation.hpp"

Equation::Equation(std::string expression)
: _expression(expression), _degree(0)
{
}

Equation::~Equation(void)
{
}

Equation::Equation(const Equation & src)
{
    *this = src;
}

Equation & Equation::operator=(const Equation & rhs)
{
    this->_expression = rhs._expression;
    return *this;
}

std::string Equation::getExpression(void) const
{
    return this->_expression;
}

int Equation::getDegree(void) const
{
    return this->_degree;
}

void Equation::solveDegree(void)
{
    std::string str = delSpaces(this->_expression);
    for (unsigned int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '^' && isdigit(str[i + 1]))
        {
            if (std::atoi(&str[i + 1]) > this->_degree)
                this->_degree = std::atoi(&str[i + 1]);
        }
    }
    if (!this->_degree && str.find_first_of('X') != std::string::npos)
        this->_degree = 1;
}

std::string Equation::delSpaces(const std::string & str)
{
    std::string ret = str;
    for (unsigned int i = 0; i < ret.size(); ++i)
    {
        if (ret[i] == SPACE)
            ret.erase(i, 1);
    }
    return ret;
}

std::ostream & operator<<(std::ostream & o, const Equation & rhs)
{
    o << "Expression : " << rhs.getExpression() << std::endl
    << "Degree : " << rhs.getDegree() << std::endl;
    return o;
}
