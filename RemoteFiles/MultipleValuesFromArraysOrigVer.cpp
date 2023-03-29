// MultipleValuesFromArraysOrigVer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Using pointers to return multiple values from a function is a very common use for pointers
// This was my attempt to duplicate the example give by CodeBeauty's Tutorial ... I ended up passing by value/references instead
// Later when I reviewed the video closely, I rewrote the code and place it and documented in " PassByPtr_MultArrayValues "
//
// Appears that I actualy pass the vlaue variables without using reference or pointer symbols ('&' '*') and yet, they are still 
// modified in the main function. The reference syntax symbol is used in the Declaration section of the function. But,it is
// not used in the function call syntax itself. The function call uses just the plain original value variable and not a pointer
// or reference symbol to the variable. Within the function definition is the reference symbol ' & ' as the function definition
// uses the address of the value variable immediately for the algorithym.


#include <iostream>
#include <array>                       // Required to implement int var = arrayName.size()
using namespace std;

                                       // Declaration of the findMinMax() function accepting an 
                                       // array, integer and two reference addresses of integers
                                       // The integer reference addresses belong to the variable
                                       // targets of maximum and minimum values of an array
void findMinMax(array<int, 10>, int, int&, int&);

//...........................................................................................................................//

                                       // Declaration of the findMinMax2() function accepting an  
                                       // array, integer and two references addresses of integers
                                       // Notice array declaration has altrnate syntax
void findMinMax2(int array[], int, int&, int&);

// ........................................................................................................................... //

int main()
{
   cout << " Using pointers To return multiple values from a function " << endl;
   cout << "---------------------------------------------------------- \n" << endl;
   // Define first array
   array<int, 10> numArray = { 2, 6, 7, 0, 9, 8, 9, 3, 5, 4 };
   int arrSize = numArray.size();

                                       // Define second Array
   int numArr2[8] = { 12, 26, 17, 14, 33, 28, 25, 41 };
   int arrLenth = 8;

   int minVal = 0;                     // Initializing the results to a random value
   int maxVal = 0;                     // Value zero was chosen here

   int* minValPtr = &minVal;           // Declaring pointers for each of the 
   int* maxValPtr = &maxVal;           // integer variables minVal and maxVal

   findMinMax(numArray, arrSize, minVal, maxVal);

                                       // Notice dereferencing is used here to obtain 
                                       // the values within the address locations
   cout << " The minimum and maximum values within the array are: \n      "
      << *minValPtr << " minimum and " << *maxValPtr << " maximum "
      << "respectively " << endl;

   cout << endl << endl; // ....................................................................................................//

                                       // Finding the maximum and minimum of SECOND ARRAY with alternate array declaration syntax
   findMinMax2(numArr2, arrLenth, minVal, maxVal);

                                       // Notice dereferencing is used here to obtain 
                                       // the values within the address locations
   cout << " The minimum and maximum values within the SECOND ARRAY are: \n      "
      << *minValPtr << " minimum and " << *maxValPtr << " maximum "
      << "respectively " << endl;

   system("pause>0");
   return 0;
};

//                                      ******** Funciton Definitions *********
// 
                                       // Definition of the function 'findMinMax()
                                       // Note the function receives both refernce addresses of two integer type variables                             
void findMinMax(array<int, 10> arr, int arrSize, int& minVal, int& maxVal)
{
   minVal = arr[0];                    // Initialize the target minVal with contents of the first array's element index zero
   maxVal = arr[0];                    // Initialize the target minVal with contents of the first array's element index zero
   
                                       // Concise syntax for finding the minimum and maximum values of
                                       // the array using the For-Each Syntax avoids the requirement of 
                                       // having to provide the size of the array as a pass to the function
   for (int val : arr)
   {                                   // This variable is the value of indexed array
                                       // location and subsequent indexed location
      if (val < minVal) { minVal = val; }
      if (val > maxVal) { maxVal = val; }
   }
}

                                       // Alternative syntax for finding the minimum and maximum values of
                                       // the array using the For Loop Syntax 
void findMinMax2(int arr[], int arrSize, int& minVal, int& maxVal)
{
   minVal = arr[0];                    // Initialize the target minVal with any value from array
   maxVal = arr[0];                    // Initialize the target maxVal with any value from array

   for (int i = 1; i < arrSize; i++)
   {
      if (arr[i] < minVal) { minVal = arr[i]; }
      if (arr[i] > maxVal) { maxVal = arr[i]; }
   }
}

