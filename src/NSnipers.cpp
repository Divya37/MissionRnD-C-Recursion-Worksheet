/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include<math.h>
#include<stdlib.h>
int field[20];


int place(int row, int column, int *flag)
{
	if (*flag == 1)
		return 0;
	for (int i = 1; i <= row - 1; ++i)
	{
		if (field[i] == column)
			return 0;
		else
			if (abs(field[i] - column) == abs(i - row))
				return 0;
	}

	return 1;
}

void get_Array(int *matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (field[i + 1] == j + 1)
				matrix[i*n + j] = 1;
		}

	}
}

void sniper(int *matrix, int row, int n, int *flag)
{
	for (int column = 1; column <= n; ++column)
	{
		if (place(row, column, flag))
		{
			field[row] = column;
			if (row == n && *flag != 1)
			{
				*flag = 1;
				get_Array(matrix, n);
			}
			else
				sniper(matrix, row + 1, n, flag);
		}
	}
}
int solve_nsnipers(int *battlefield, int n)
{
	int flag = 0;
	if (n < 0 || battlefield == NULL)
		return 0;
	
	sniper(battlefield, 1, n, &flag);

	int i = 0;
	for (int j = 0; j < n; j++)
		if (battlefield[j]!=0)
				return 1;			
	return 0;	
}
