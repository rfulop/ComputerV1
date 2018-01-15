# ComputerV1
Program that solves polynomial equations.

## Project Overview
Your equation must always be well formated. Example: "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^2 = 3 * X^0. <br/>
It will solve a polynomial equation of degree less than or equal to 2 and display:
* The reduced form of the equation.
* The degree of the equation.
* Its solution(s), as well as the sign of the discriminant when it makes sense.. <br/>

## Installation:
```
git clone https://github.com/rfulop/ComputerV1 && cd ComputerV1 && make
```

## Usage:
With an equation as parameter:
```
./computerV1 "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
```
Or you can edit "tests.sh" and add equations:
```
./tests.sh
```
