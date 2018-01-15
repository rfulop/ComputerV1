/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/15 14:22:08 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Equation.hpp"

Equation::Equation(std::string expression)
: _expression(expression), _degree(0)
{
    solveDegree();
    std::string str = delSpaces(this->_expression);
    try
    {
        this->_left = new Expression(str.substr(0, str.find('=')), this->_degree);
        this->_right = new Expression(str.substr(str.find('=') + 1), this->_degree);
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

std::string Equation::floatToString(float n)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << n;
    return ss.str();
}

void Equation::setReducedForm(void)
{
    std::vector<float> left = this->_left->getExpr();
    std::vector<float> right = this->_right->getExpr();
    std::string str;

    str += left[0] ? (floatToString(left[0])) += X0 : "0 ";
    if (left.size() == 2)
        str += (left[1] < 0) ? LESS += (floatToString(left[1] * -1.0)) += X1 : (PLUS += floatToString(left[1])) += X1;
    if (left.size() == 3)
        str += (left[2] < 0) ? LESS += (floatToString(left[2] * -1.0)) += X2 : (PLUS += floatToString(left[2])) += X2;
    str += EGUAL;
    str += right[0] ? floatToString(right[0]) += X0 : "0 ";
    if (right.size() == 2)
        str += (right[1] < 0) ? LESS += (floatToString(right[1] * -1.0)) += X1 : (PLUS += floatToString(right[1])) += X1;
    if (right.size() == 3)
        str += (right[2] < 0) ? LESS += (floatToString(left[2] * -1.0)) += X2 : (PLUS += floatToString(right[2])) += X2;
    this->_red = str;
}

void Equation::reducedForm(void)
{
    std::vector<float> left = this->_left->getExpr();
    std::vector<float> right = this->_right->getExpr();

    if (left[0] && right[0] && (right[0] <= left[0]))
    {
        this->_left->setA(left[0] - right[0]);
        this->_right->setA(0.0);
    }
    if (left[1] && right[1] && (right[1] <= left[1]))
    {
        this->_left->setB(left[1] - right[1]);
        this->_right->setB(0.0);
    }
    if (left[2] && right[2] && (right[2] <= left[2] ))
    {
        this->_left->setC(left[2] - right[2]);
        this->_right->setC(0.0);
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
    // o << "Expression : " << rhs.getExpression() << std::endl
    o << "Reduced expression : " << rhs.getRedExpr() << std::endl
    << "Polynomial degree : " << rhs.getDegree() << std::endl;
    return o;
}
