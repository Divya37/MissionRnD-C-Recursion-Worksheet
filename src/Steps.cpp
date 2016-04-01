/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n*fact(n - 1);
}

int steps_count(int s, int count1, int count2)
{
	if (count1 < 0 && count2 > s)
		return 0;
	return (fact(s) / (fact(count2)*fact(count1))) + steps_count(s - 1, count1 - 2, count2 + 1);
}

int get_steps(int s)
{
	return steps_count(s, s, 0);
}
