#!/bin/bash

make
# small test; memory usage unimportant, so we store everything:
testlist=(`<somenumbers`)
rightanswers=(`<rightanswers`)
youranswers=(`./primetest <somenumbers`)

failcount=0

# now just compare the differences:
for (( i = 0; i < ${#testlist[@]}; i++ )); do
	if [[ -z "${youranswers[$i]}" ]] ; then
		failcount=1
		echo -en "Too few output lines!  Be sure to print"
		echo -e  "\033[1;31m exactly one\033[0m 1/0 per input number."
		exit 1
	fi

	if (( ${youranswers[$i]} != ${rightanswers[$i]} )); then
		echo "Program fails on input ${testlist[$i]}"
		echo "(Output was ${youranswers[$i]}; answer is ${rightanswers[$i]})"
		(( failcount++ ))
	fi
done

[[ "$failcount" == 0 ]] && echo -e "\033[32mTest passed :D\033[0m"
