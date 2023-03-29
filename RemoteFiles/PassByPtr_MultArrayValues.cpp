// PassByPtr_MultArrayValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using variable pointers to return multiple values from a function 
//

#include <iostream>
#include <array>                       // Required to implement int var = arrayName.size()
using namespace std;

// Declaration of the findMinMax() function accepting an 
// array, integer and two pointer addresses of integers
// The integer pointer addresses belong to the variable
// targets of the maximum and minimum values of the array
void findMinMax(array<int, 10>, int, int*, int*);

// ........................................................................................................................... //

int main()
{
   cout << " Using pointers To return multiple values from a function " << endl;
   cout << "---------------------------------------------------------- \n" << endl;
                                                // Define array - Note this type definition
   array<int, 10> numArray = { 2, 6, 7, 0, 9, 8, 9, 3, 5, 4 };
   int arrSize = numArray.size();               // For size() to work, had to use array type def above

   int minVal = numArray[0];                    // Initializing the value of each variable to the  
   int maxVal = numArray[0];                    // that contained in the array at element index '0'

                                                // Passing by Reference - Passing the parameters of 
                                                // the variable by using their reference addresses
   findMinMax(numArray, arrSize, &minVal, &maxVal);

   // Notice dereferencing is used here to obtain the 
   // values within the variable address locations
   cout << " The minimum and maximum values within the array are: \n      "
      << minVal << " minimum and " << maxVal << " maximum "
      << "respectively " << endl;

   system("pause>0");
   return 0;
};

// ******** Function "findMinMax()" Definition Using Passing by Pointers *********
// 
// Definition of the function 'findMinMax()' - *** Passing by Pointers ***
// The function receives both pointers addresses of two integer type variables 
// Receives pointer to the minVal variable and to the maxValue variable
// The function is operating on the original variable values 
void findMinMax(array<int, 10> arr, int arrSize, int* minVal, int* maxVal)
{   
   // Consise syntax for finding the minimum and maximum values of
   // the array using the For-Each Syntax avoids the requirement of 
   // having to provide the size of the array and pass it to the function

   for (int val : arr)
   {                                   // These deferenced variables have access to the values  
                                       // contained in the array at their perspective array indexes
                                       // The function IS changing the values within the array
      if (val < *minVal) { *minVal = val; }
      if (val > *maxVal) { *maxVal = val; }
   }
}

/*
   // Alternative Syntax using a for-next loop
   // This method needs the array size (arrsize) to implement the loop
   for (int i = 1; i < arrSize; i++)
   {
      if (arr[i] < minVal) { minVal = arr[i]; }
      if (arr[i] > maxVal) { maxVal = arr[i]; }
   }
   */


