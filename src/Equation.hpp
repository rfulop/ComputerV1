/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/14 02:31:54 by rfulop           ###   ########.fr       */
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
    std::string getRedExpr(void) const;
    Expression* getRight(void) const;
    Expression* getLeft(void) const;

    std::string delSpaces(const std::string & str);
    void solveDegree(void);
    void solve(void);

    void setReducedForm(void);
    void reducedForm(void);

private:
    std::string _expression;
    int _degree;
    Expression* _right;
    Expression* _left;
    std::string _red;

};

std::ostream & operator<<(std::ostream & o, const Equation & rhs);

#endif
