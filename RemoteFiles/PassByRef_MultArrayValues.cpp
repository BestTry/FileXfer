// PassByRef_MultArrayValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// Using variable references to return multiple values from a function 
// This was my attempt to remember what syntax 'Code Beauty' used to implement the passing by pointers concept
// After review and later finding out the better way presented by 'Code Beauty' for pointer value passing
//

#include <iostream>
#include <array>                       // Required to implement int var = arrayName.size()
using namespace std;

// Declaration of the findMinMax() function accepting an 
// array, integer and two reference addresses of integers
// The integer reference addresses belong to the variable
// targets of maximum and minimum values of an array
void findMinMax(array<int, 10>, int, int&, int&);

// ........................................................................................................................... //

int main()
{
   cout << " Using pointers To return multiple values from a function " << endl;
   cout << "---------------------------------------------------------- \n" << endl;
   // Define first array
   array<int, 10> numArray = { 2, 6, 7, 0, 9, 8, 9, 3, 5, 4 };
   int arrSize = numArray.size();

   int minVal = 0;                     // Initializing the results to a random vaue
   int maxVal = 0;                     // Content of variable zero was chosen here

                                       // Need pointers declared to that later can invoke
                                       // dereferencing to retreive values of variables
   int* minValPtr = &minVal;           // Declaring pointers for each of the 
   int* maxValPtr = &maxVal;           // integer variables minVal and maxVal

   findMinMax(numArray, arrSize, minVal, maxVal);
   // Notice dereferencing is used here to obtain 
   // the values within the address locations
   cout << " The minimum and maximum values within the array are: \n      "
      << *minValPtr << " minimum and " << *maxValPtr << " maximum "
      << "respectively " << endl;

   system("pause>0");
   return 0;
};

//                          ******** Function Definition Using Passing by Reference *********
// 
// Definition of the function 'findMinMax()' - *** Passing by References ***
// Note the function receives both refernce addresses of two integer type variables                             
void findMinMax(array<int, 10> arr, int arrSize, int& minVal, int& maxVal)
{
   minVal = arr[0];                    // Initialize the target minVal with contents of the first array index zero
   maxVal = arr[0];                    // Initialize the target minVal with contents of the first array index zero   

   // Best syntax for finding the minimum and maximum values of
   // the array using the For-Each Syntax avoids the requirement of 
   // having to provide the size of the array and pass it to the function

   for (int val : arr)
   {                                   // This variable is the value of indexed array
                                       // location and subsequent indexed location
      if (val < minVal) { minVal = val; }
      if (val > maxVal) { maxVal = val; }
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


