#!/bin/bash

clear

operations=("42 * X ^ 2 + 21 * X ^ 1 + 10 * X ^ 0 = 0"
			"42 * X ^ 2 + 21 * X + 10 = 0"
			"42 * X ^ 2 + 21 * X - 10 = 0"
			"42 * X ^ 2 + 21 * X - - 10 = 0"
			"42 * X ^ 2 + 21 * X - - - 10 = 0"
			"5 * X ^ 2 = 42"
			"5 * X ^ 2 - 2 * X ^ 2 = 42"
			"5 * X ^ 2 - 2 * X ^ 2 - 1 * X ^ 2 = 42"
			"5 * X ^ 2 - 2 * X ^ 2 - 1 * X ^ 2 - X ^ 2 = 42"
			"5 * X ^ 2 - 2 * X ^ 2 - 1 * X ^ 2 - X ^ 2 + 3 * X - 1 * X - X = 42"
			"X + X ^ 2 = 0"
			" - X - X ^ 2 = 0"
			"X = 42"
			"X = 38 + 2 + 1 + 1"
			"5 + X = -5"
			"2 * X = 5"
			"5 * X ^ 0 + 4 * X ^ 1 = 4 * X ^ 0"
			"5 + 4 * X + X^2= X^2"
			"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
			"X ^ 2 + 1 = 0"
			"X^2 + 2*X + 5 = 0"
			"169 - X^2 = 0"
			"169 + X^2 = 0"
			"X^2-5*X=0"
			"-2*X^2 +16*X -32 = 0"
			"4*X^2 + 4*X + 1 = 0"
			"X + X + X = 3"
			"42*X^2+21*X^1-10*X^0=0*X^0"
			"42*X^0+21*X^1-10*X^2=0*X^0"
			"42*X^2+21*X-10=0"
			"42*X^0+21*X^1-10*X^2=0"
			"1 + 2 + 3 + 4 + 5 = 5 + 4 + 3 + 2 + 1"
			"X = X + 1"
			"X = X"
			"42=42"
			"X^2 + 4*X = X^2 + 4*X + 4 - 4"
			"8 * X^0 - 6 * X^1 + 0 * X^2 - 56 * X^3 = 3 * X^0"
			"XXX = 4"
			".5 = 2"
			"2^2 = 4"
			"4/2 = 2"
			"-.=1"
			"-=1"
			"+=1"
			"314"
			"5="
			"=5"
			"42 error")

i=0;
while [ ! -z "${operations[$i]}" ]; do
	printf "[%s]:\n" "${operations[$i]}"
	./computerV1 "${operations[$i]}"
	i=$((i + 1))
	if [ ! -z "${operations[$i]}" ]; then
		printf "\n"
	fi
done
