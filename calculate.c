#include "bsq.h"

/*

POPULATE WITH NUMBERS:

second line and first collum: 
"empty" = 1;
"obstacles" = 0;
start up  to down, left to right;
check the min value of grid[i-1][j] grid[i -1][j -1] grid[i][j -1];
grid[i][i] = this value +1;

New grid of numbers instead of changing the original grid, maybe?


CHECK BIGGEST NUMBER:

Check elements of number-grid until find the biggest number(n);
see the first time this number appear up-down, left-right. 
save the i and j. 

CHANGE THE ORIGINAL GRID:

from the element of the numbergrid:
    transform it into "full char";
    form a grid up /left (n-1 size) with full-chars 
*/