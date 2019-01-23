#include "Cell.h"

Cell CL_new(int x, int y)
{
	Cell ans; // Answer cell is created.
	ans.x=x; // x element of the answer cell is given a value.
	ans.y=y; // y element of the answer cell is given a value.
	return ans; // The answer cell is returned.
}

// Considering that "c" is a non-heap object,
// I don't see how the following function might be used.
// Besides, this function uses reference to the value,
// not reference to the address.
void CL_free(Cell c)
{
	free(&c); // The memory block where cell "c" is stored is freed.(Supposedly)
}

void CL_check(Cell c, char *label)
{
	printf("%d %d :%s\n", c.x, c.y, label); // x element, y element of cell "c" and the label is printed.
}

int CL_isTheSame(Cell c1, Cell c2)
{
	if(c1.x==c2.x && c1.y==c2.y) // If "c1" and "c2" both have the same x and y elements:
		return 1; // 1 is returned.
	return 0; // 0 is returned as default.
}

Cell CL_entrance(Maze mz)
{
	Cell ans; // Answer cell is created.
	MZ_entrance(mz, &ans.x, &ans.y); // x element and y element of cell "c" are given values of coordinates of the entrance cell.
	return ans; // The answer cell is returned.
}

Cell CL_exit(Maze mz)
{
	Cell ans; // Answer cell is created.
	MZ_exit(mz, &ans.x, &ans.y); // x element and y element of cell "c" are given values of coordinates of the exit cell.
	return ans; // The answer cell is returned.
}

int CL_linkedCells(Maze mz, Cell c, Cell linked_cells[])
{
	int tmp[8]; // Temporary integer array is created to store the linked cells as pairs of integers.
	int nb_links=MZ_linkedCells(mz, c.x, c.y, tmp); // The temporary integer array is initialized and the number of cells is obtained.
	for(int i=0; i<nb_links; i++) // For each one of "linked_cells":
	{
		linked_cells[i].x=tmp[2*i]; // x element of that cell is given the value of corresponding even element of the temporary array.
		linked_cells[i].y=tmp[2*i+1]; // y element of that cell is given the value of corresponding odd element of the temporary array.
	}
	return nb_links; // The number of cells is returned.
}

void CL_setSolution(Maze mz, Cell solution_cells[], int nb_cells)
{
	int* tmp=(int*)calloc(nb_cells*2, sizeof(int)); // Temporary integer array is created to store cells of the path as pairs of integers.
	for(int i=0; i<nb_cells; i++) // For each one of "solution_cells":
	{
		tmp[2*i]=solution_cells[i].x; // Corresponding even element of the temporary array is given the value of x element of that cell.
		tmp[2*i+1]=solution_cells[i].y; // Corresponding odd element of the temporary array is given the value of y element of that cell.
	}
	MZ_setSolution(mz, tmp, nb_cells); // The solution is set based on that temporary array.
}
