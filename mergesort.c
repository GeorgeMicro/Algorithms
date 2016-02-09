#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10


void printArray(int * array, int size);
void mergeSort(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);

int main()
{
  int array[SIZE] = {0};
  int i;
  srand(time(NULL));
  for(i = 0; i < SIZE; i++)
    {
      array[i] = rand() % 100;
    }
  printArray(array, SIZE);
  mergeSort(array, 0, SIZE - 1);
  printArray(array, SIZE);
}

void printArray(int * array, int size)
{
  int i;
  for(i = 0; i < SIZE; i++)
    {
      printf("%d ", array[i]);
    }
  printf("\n");
}

void mergeSort(int *array, int start, int end)
{
  if (start < end)
    {
      int mid = (start + end) / 2;
      mergeSort(array, start, mid);
      mergeSort(array, mid + 1, end);
      merge(array, start, mid, end);
    }
}

void merge(int *array, int start, int mid, int end)
{
  int i, j, k, count;
  int temp[SIZE] = {0};
  i = start; //counter of the first half
  j = mid + 1;  //counter of the second half
  k = start; //count of the new array

  //merge when both half have data left
  while (i <= mid && j <= end)
    {
      if (array[i] < array[j])
	{
	  temp[k] = array[i];
	  i++;
	}
      else
	{
	  temp[k] = array[j];
	  j++;
      }
      k++;	  
    }

  if (i > mid) //if the first half run out
    {
      for (count = j; count <= end; count++)
	{
	  temp[k] = array[count];
	  k++;
	}
    }
  else //if the second half run out
    {
      for (count = i; count <= mid; count++)
	{
	  temp[k] = array[count];
	  k++;
	}
    }


  for (k = start; k <= end; k++)
    {
      array[k] = temp[k];
    }
}

