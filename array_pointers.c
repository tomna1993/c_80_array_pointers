#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t main(void)
{
  int32_t array[2][3] = 
  {
    {1,2,3}, 
    {4,5,6}
  };

  // Simple method to go throught the array elements
  printf ("sizeof(array)= %i\n", sizeof(array));

  for (int32_t i = 0; i < 2; ++i)
  {
    for (int32_t j = 0; j < 3; ++j)
    {
      printf ("Addr: array[%i][%i]= %p\n", i, j, &array[i][j]);
      printf ("Val: array[%i][%i]= %i\n", i, j, array[i][j]);
    }
  }

  // Go throught the array elements by dereferencing the original array
  printf ("\n");
  printf ("With dereferencing the array:\n");

  printf ("sizeof(*array)= %i\n", sizeof(*array));

  // *array     == &array[0][0]
  // *array + 1 == &array[0][1]
  // *array + 2 == &array[0][2]
  // *array + 3 == &array[1][0]
  // *array + 4 == &array[1][1]
  // *array + 5 == &array[1][2]

  for (int32_t i = 0; i < 2; ++i)
  {
    for (int32_t j = 0; j < 3; ++j)
    {
      printf ("Addr: *array + (%i * 3 + %i)= %p\n", i, j, *array + (i * 3 + j));
      printf ("Val: *(*array + (%i * 3 + %i))= %i\n", i, j, *(*array + (i * 3 + j)));
    }
  }

  // Another method by dereferencing the original array
  printf ("\n");
  printf ("Another method by dereferencing the array:\n");

  printf ("sizeof(*(array))= %i\n", sizeof(*(array)));

  // *(array)     == &array[0][0]
  // *(array) + 1 == &array[0][1]
  // *(array) + 2 == &array[0][2]
  // *(array + 1) == &array[1][0]
  // *(array + 1) + 1 == &array[1][1]
  // *(array + 1) + 2 == &array[1][2]

  for (int32_t i = 0; i < 2; ++i)
  {
    for (int32_t j = 0; j < 3; ++j)
    {
      printf ("Addr: *(array + %i) + %i= %p\n", i, j, *(array + i) + j);
      printf ("Val: *(*(array + %i) + %i)= %i\n", i, j, *(*(array + i) + j));
    }
  }


  // Here we create a pointer to the 1-D array which has 3 elements
  printf ("\n");
  printf ("With pointer:\n");

  int32_t (*parray)[3] = array;

  printf ("sizeof(*parray)= %i\n", sizeof(*parray));
  
  // parray     == &array[0]; array[0] = {1,2,3}, sizeof(parray) = 12

  // parray + 1 == &array[1]; array[1] = {4,5,6}, sizeof(parray + 1) = 12

  // *parray        == &array[0][0]
  // *(parray + 1)  == &array[1][0]

  // *(parray + 1) + 1 == &array[1][1]
  // *parray + 2 == &array[0][2]

  for (int32_t i = 0; i < 2; ++i)
  {
    for (int32_t j = 0; j < 3; ++j)
    {
      printf ("Addr: *(parray + %i) + %i= %p\n", i, j, *(parray + i) + j);
      printf ("Val: *(*(parray + %i) + %i= %i\n", i, j, *(*(parray + i) + j));
    }
  }



  printf ("Exercises: \n");


  int32_t three_d_array[3][2][2][2] = 
  {
    {{{0,1}, {2,3}}, {{4,5}, {6,7}}},
    {{{8,9}, {10,11}}, {{12,13}, {14,15}}},
    {{{16,17}, {18,19}}, {{20,21}, {22,23}}}
  };

  int32_t (*ptr)[2][2][2] = three_d_array;

  printf ("Address: %d\n", three_d_array);
  printf ("Address: %d\n", &three_d_array);
  printf ("Address ptr: %d\n", ptr);


  printf ("%d\n", ****three_d_array);

  printf ("size %i\n", sizeof(****three_d_array));

  printf ("\n");

  printf ("%d\n", *(*(three_d_array[0] + 1)) + 1);
  printf ("%d\n", *(three_d_array[0][0] + 1));
  printf ("%d\n", *(*(three_d_array[1] + 1)) + 1);
  printf ("%d\n", *(*(*(three_d_array[2] + 1) + 1)));
  printf ("%d\n", (*(three_d_array + 1) + 1));
  printf ("%d\n", *(three_d_array[1][0][1]));
  printf ("%d\n", *(*(*(three_d_array + 1) + 1) + 1));
  printf ("%d\n", (*three_d_array[0][1] + 1));

  printf ("\n");

  printf ("%d\n", (ptr[0][1] + 1));


  return EXIT_SUCCESS;
}