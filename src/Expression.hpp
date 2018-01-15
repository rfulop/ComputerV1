/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expression.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/15 15:51:24 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "computerv1.h"

class Expression
{
public:
    Expression(std::string expression, int degree);
    ~Expression(void);
    Expression(const Expression & src);
    Expression & operator=(const Expression & rhs);

    void setDelta(void);
    void setSolutions(int degree);

    float getA(void) const;
    float getB(void) const;
    float getC(void) const;
    float getDelta(void) const;
    std::vector<float> getExpr(void) const;
    std::vector<float> getSolutions(void) const;

    void setI(int i, float n);
    void setA(float n);
    void setB(float n);
    void setC(float n);

private:
    std::vector<float> _expr;
    float _delta;
    std::vector<float> _solutions;

};

std::ostream & operator<<(std::ostream & o, const Expression & rhs);

#endif
