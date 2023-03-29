// MultipleValuesFromArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// MultipleValuesFromArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using pointers to return multiple values from a function is a very common use for pointers
//

#include <iostream>
#include <array>                       // Required to implement int var = arrayName.size()
using namespace std;

// Declaration of the findMinMax() function accepting 
// an array, integer and two addresses of integers
void findMinMax(array<int, 10>, int, int&, int&);

// ............................................................................................. //

int main()
{
    cout << " Using pointers To return multiple values from a function " << endl;
    cout << "---------------------------------------------------------- \n" << endl;
    array<int, 10> numArray = { 2, 6, 7, 0, 9, 8, 9, 3, 5, 4 };
    int arrSize = numArray.size();
    int minVal = 0;                     // Initializing the results to a random 
    int maxVal = 0;                     // value.  Value zero was chosen here

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


// Definition of the function 'findMinMax()
// Note the function receives both addresses of two integer type variables                             
void findMinMax(array<int, 10> arr, int arrSize, int& minVal, int& maxVal)
{
    minVal = arr[0];                    // Initialize the target minVal with any value from array
    maxVal = arr[0];                    // Initialize the target maxVal with any value from array
    

    /*
    // This method needs the array size to implement
   for (int i = 1; i < arrSize; i++)
    {
       if (arr[i] < minVal) { minVal = arr[i]; }
       if (arr[i] > maxVal) { maxVal = arr[i]; }
    }*/

    // Alternative syntax for finding the minimum and maximum values of
    // the array using the For-Each Syntax avoids the requirement of 
    // having to find the size of the array and pass it to the function

    for (int val : arr)
    {                                   // This variable is the value of indexed array
                                        // location and subsequent indexed location
        if (val < minVal) { minVal = val; }
        if (val > maxVal) { maxVal = val; }
    }
}


