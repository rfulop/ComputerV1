/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/13 19:46:03 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Equation.hpp"

Equation::Equation(std::string expression)
: _expression(expression), _degree(0)
{
    solveDegree();
    std::string str = delSpaces(this->_expression);
    this->_left = new Expression(str.substr(0, str.find('=')), this->_degree);
    this->_right = new Expression(str.substr(str.find('=') + 1), this->_degree);

    std::cout << *this->_left << std::endl << *this->_right;
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
        if (str[i] == 'X' && str[i + 1] == '^' && isdigit(str[i + 2]))
        {
            if (std::atoi(&str[i + 2]) > this->_degree)
                this->_degree = std::atoi(&str[i + 2]);
        }
    }
    if (!this->_degree && str.rfind("X^") != std::string::npos)
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
