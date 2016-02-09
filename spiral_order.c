#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define ROW 6
#define COL 6
void printTopRight(int a[][COL], int x1, int y1, int x2, int y2);
void printBottomLeft(int a[][COL], int x1, int y1, int x2, int y2);
void printSpiral(int a[][COL]);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int array[6][6];
    int i,j;
    int maxSum = INT_MIN;
    int sum = 0;
    
    for (i = 0; i < 6; i++)
        {
        for (j = 0; j < 6; j++)
            {
	      array[j][i] = (i + 1) * (j + 1);
        }
    }

    printSpiral(array);
}
void printTopRight(int a[][COL], int x1, int y1, int x2, int y2)
{
  //x1 is the first col index
  //y1 is the first row index
  //y2 is the last row index
  //x2 is the last col index
  
  int i = 0, j = 0;

  for (i = x1; i <= x2; i++)
    {
      printf("%d ", a[y1][i]);
    }

  for (i = y1 + 1; i <= y2; i++)
    {
      printf("%d ", a[i][x2]);
    }

  if (x2 > x1) //if there are things left to print
    {
      /* recursively call the function to print the bottom left of the sub matrix */
      printBottomLeft(a, x1, y1 + 1, x2 - 1, y2);
    }
	
}


void printBottomLeft(int a[][COL], int x1, int y1, int x2, int y2)
{
  int i;

  for (i = x2; i >= x1; i--)
    {
      //print the last row
      printf("%d ", a[y2][i]);
    }

  for (i = y2 - 1; i >= y1; i--)
    {
      //print the first colume
      printf("%d ", a[i][x1]);
    }

  //check for anything left for print
  if (x2 > x1) {
    printTopRight(a, x1 + 1, y1, x2, y2 - 1);
  }
  
}

void printSpiral(int a[][COL])
{
  printTopRight(a, 0 ,0, COL - 1, ROW - 1);
  printf("\n");
}
