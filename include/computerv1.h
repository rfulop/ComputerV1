/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 05:47:13 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/15 13:56:51 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_H
# define COMPUTERV1_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>

class Equation;
class Expression;

#include "../src/Expression.hpp"
#include "../src/Equation.hpp"

#define SPACE ' '
#define OP "+-"

#define X0 " * X^0 "
#define X1 " * X^1 "
#define X2 " * X^2 "
#define EGUAL "= "
static std::string LESS = "- ";
static std::string PLUS = "+ ";


#endif
