/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/15 15:55:24 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Equation.hpp"

Equation::Equation(std::string expression)
: _expression(expression), _degree(0)
{
    try
    {
        this->_degree = solveDegree(this->_expression);
        std::string str = delSpaces(this->_expression);
        std::string leftStr = str.substr(0, str.find('='));
        std::string rightStr = str.substr(str.find('=') + 1);
        this->_left = new Expression(leftStr, solveDegree(leftStr));
        this->_right = new Expression(rightStr, solveDegree(rightStr));
    }
    catch(std::exception & e)
    {
        std::cout << "This is not a Polynomial expression or it is not well formated." << std::endl;
        exit (-1);
    }
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

std::string Equation::getExpression(void) const { return this->_expression; }
std::string Equation::getRedExpr(void) const { return this->_red; }
int Equation::getDegree(void) const { return this->_degree; }
Expression * Equation::getRight(void) const { return this->_right; }
Expression * Equation::getLeft(void) const { return this->_left; }

int Equation::solveDegree(std::string expr)
{
    int degree = 0;
    std::string str = delSpaces(expr);
    for (unsigned int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'X' && str[i + 1] == '^' && isdigit(str[i + 2]))
        {
            if (!i || str[i - 1] != '*')
                throw std::exception();
            if (std::atoi(&str[i + 2]) > degree)
                degree = std::atoi(&str[i + 2]);
        }
    }
    if (!degree && str.rfind("X^") != std::string::npos)
        degree = 1;
    return degree;
}

std::string Equation::floatToString(float n)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << n;
    return ss.str();
}

std::string Equation::setReducedSide(std::vector<float> side)
{
    std::string str;

    str += side[0] ? (floatToString(side[0])) += X0 : "0 ";
    for (unsigned long i = 1; i < side.size(); ++i)
    {
        std::stringstream ss;
        ss << " * X^" << i << " ";
        std::string X = ss.str();
        if (side[i])
        {
            str += (side[i] < 0) ? LESS : PLUS;
            str += (side[i] < 0) ? (floatToString(side[i] * -1.0)) += X : (floatToString(side[i])) += X;
        }
    }
    return str;
}

void Equation::setReducedForm(void)
{
    std::string str;

    str = setReducedSide(this->_left->getExpr());
    str += EGUAL;
    str += setReducedSide(this->_right->getExpr());
    this->_red = str;
}

void Equation::reducedForm(void)
{
    std::vector<float> left = this->_left->getExpr();
    std::vector<float> right = this->_right->getExpr();

    for (int i = 0; i <= this->_degree; ++i)
    {
        if (left.size() >= static_cast<unsigned long>(i) &&
        right.size() >= static_cast<unsigned long>(i) && (right[i] <= left[i]))
        {
            this->_left->setI(i, left[i] - right[i]);
            this->_right->setI(i, 0.0);
        }
    }
}

void Equation::solve(void)
{
    this->_left->setSolutions(this->_degree);
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
    o << "Reduced expression : " << rhs.getRedExpr() << std::endl
    << "Polynomial degree : " << rhs.getDegree() << std::endl;
    return o;
}
