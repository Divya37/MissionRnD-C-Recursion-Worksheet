/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int * get_spiral_path(int **input_array, int rows, int columns, int x, int y, int *Arr, int i)
{
	printf("\nrows=%d,columns=%d,x=%d,y=%d\n\n", rows, columns, x, y);
	if (input_array[x][y] == -9999 || rows <= 0 || columns <= 0)
		return Arr;
	while (y < columns)
	{
		if (input_array[x][y] == -9999)
			break;
		Arr[i++] = input_array[x][y];
		input_array[x][y] = -9999;
		y++;
	}
	printf("\n");
	y = y - 1;
	x = x + 1;
	while (x < rows)
	{
		if (input_array[x][y] == -9999)
			break;
		Arr[i++] = input_array[x][y];
		input_array[x][y] = -9999;
		x++;
	}
	printf("\n");
	x = x - 1;
	y = y - 1;
	while (y >= 0 && y<columns && x >= 0 && x<rows)
	{
		if (input_array[x][y] == -9999)
			break;
		Arr[i++] = input_array[x][y];
		input_array[x][y] = -9999;
		y--;
	}
	printf("\n");
	y = y + 1;
	x = x - 1;
	while (x > 0 && x<rows && y >= 0 && y<columns)
	{
		if (input_array[x][y] == -9999)
			break;
		Arr[i++] = input_array[x][y];
		input_array[x][y] = -9999;
		x--;
	}
	x = x + 1;
	y = y + 1;
	printf("\n");

	return get_spiral_path(input_array, rows - 1, columns - 1, x, y, Arr, i);

}

int *spiral(int rows, int columns, int **input_array)
{


	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	int *Arr, i = 0, x = 0, y = 0;
	Arr = (int *)malloc(sizeof(int)*(rows*columns));

	Arr = get_spiral_path(input_array, rows, columns, x, y, Arr, i);

	return Arr;

}
