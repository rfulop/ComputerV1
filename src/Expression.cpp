/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/14 02:36:29 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Expression.hpp"

Expression::Expression(std::string str, int degree)
{
    // std::cout << "Ex str = " << str << std::endl;
    this->_expr.push_back(std::atof(str.c_str()));
    if (degree >= 1)
        this->_expr.push_back(std::atof(str.c_str() + str.find_first_of(OP)));
    if (degree >= 2)
    this->_expr.push_back(std::atof(str.c_str() + str.find_last_of(OP)));
    // if (degree == 2)
        // setDelta();
    // setSolutions(degree);
}

Expression::~Expression(void)
{
}

Expression::Expression(const Expression & src)
{
    *this = src;
}

Expression & Expression::operator=(const Expression & rhs)
{
    this->_expr = rhs._expr;
    return *this;
}

float Expression::getA(void) const
{
    return this->_expr[0];
}

float Expression::getB(void) const
{
    return this->_expr[1];
}

float Expression::getC(void) const
{
    return this->_expr[2];
}

void Expression::setA(float n)
{
    this->_expr[0] = n;
}

void Expression::setB(float n)
{
    this->_expr[1] = n;
}

void Expression::setC(float n)
{
    this->_expr[2] = n;
}

float Expression::getDelta(void) const
{
    return this->_delta;
}

std::vector<float> Expression::getExpr(void) const
{
    return this->_expr;
}

std::vector<float> Expression::getSolutions(void) const
{
    return this->_solutions;
}

void Expression::setDelta(void)
{
    this->_delta = pow(this->_expr[1], 2.0) - 4.0 * (this->_expr[0] * this->_expr[2]);
}

void Expression::setSolutions(int degree)
{
    if (degree == 2)
        setDelta();
    if (degree == 1)
        this->_solutions.push_back(-1.0 * (this->_expr[0] / this->_expr[1]));
    else
    {
        if (this->_delta < 0)
         this->_solutions.clear();
        else if (!this->_delta)
            this->_solutions.push_back((this->_expr[1] * - 1.0) / (2.0 * this->_expr[0]));
        else
        {
            float r = sqrt(this->_delta);
            this->_solutions.push_back(((this->_expr[1] * -1.0) + r) / (2.0 * this->_expr[2]));
            this->_solutions.push_back(((this->_expr[1] * -1.0) + (r * -1.0)) / (2.0 * this->_expr[2]));
        }
    }
}

std::ostream & operator<<(std::ostream & o, const Expression & rhs)
{
    std::vector<float> sol = rhs.getSolutions();
    // if (rhs.getA())
        // o << "A : " << rhs.getA() << std::endl;
    // if (rhs.getB())
        // o << "B = " << rhs.getB() << std::endl;
    // if (rhs.getC())
        // o << "C = " << rhs.getC() << std::endl;
    // o << "Delta = " << rhs.getDelta() << std::endl;
    if (sol.empty())
        o << "No solution" << std::endl;
    else if (sol[0])
        o << "First solution = " << sol[0] << std::endl;
    if (!sol.empty() && sol[1])
        o << "Second solution = " << sol[1] << std::endl;
    return o;
}
