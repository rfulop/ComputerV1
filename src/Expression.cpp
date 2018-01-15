/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/15 14:22:22 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Expression.hpp"

Expression::Expression(std::string str, int degree)
{
    int f0 = str.find("X^0");
    int f1 = str.find("X^1");
    int f2 = str.find("X^2");

    if (str == "0")
        this->_expr.push_back(std::atof(str.c_str()));
    else
    {
        if (((f1 < f0) && f1 != -1)  || ((f2 < f0) && (f2 != -1)) || f0 == -1)
            throw std::exception();
        this->_expr.push_back(std::atof(str.c_str()));
        if (degree >= 1)
            this->_expr.push_back(std::atof(str.c_str() + str.find_first_of(OP)));
        if (degree >= 2)
        this->_expr.push_back(std::atof(str.c_str() + str.find_last_of(OP)));
    }
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

float Expression::getA(void) const { return this->_expr[0]; }
float Expression::getB(void) const { return this->_expr[1]; }
float Expression::getC(void) const { return this->_expr[2]; }
float Expression::getDelta(void) const { return this->_delta; }
std::vector<float> Expression::getExpr(void) const { return this->_expr; }
std::vector<float> Expression::getSolutions(void) const { return this->_solutions; }

void Expression::setA(float n) { this->_expr[0] = n; }
void Expression::setB(float n) { this->_expr[1] = n; }
void Expression::setC(float n) { this->_expr[2] = n; }
void Expression::setDelta(void) { this->_delta = pow(this->_expr[1], 2.0) - 4.0 * (this->_expr[0] * this->_expr[2]); }

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
    if (rhs.getDelta() < 0)
        o << "Discriminant is stricty negative, there is no solution" << std::endl;
    else if (sol.size() == 1)
        o << "The solution is:" << std::endl << sol[0] << std::endl;
    else if (sol.size() == 2)
    {
        if (!rhs.getDelta())
            o << "Discriminant is zero, the solution is:" << sol[0];
        else
            o << "Discriminant is stricty positive, the two solutions are:" << std::endl
            << sol[0] << std::endl << sol[1] << std::endl;
    }
    return o;
}
