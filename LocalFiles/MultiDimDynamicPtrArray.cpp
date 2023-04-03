//
// MultiDimDynamicPtrArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code demonstrates an example of a two dimensional dynamic array using pointers.  Lifted from CodeBeauty time: 9:50 
// The array is dynamic and therefore will be using the keywords 'new' amd delete for memory allocation and de-allocation
// Regular two dimensional arrays will also work within Cpp.  It appears Dynamic Arrays are more powerful and flexible
//
// A Multidimensional array is in simple workds an array of arrays (


#include <iostream>
using namespace std;


// Prepare invoke tab for later display; Give it alias variable 'tb' designation
// Integer 9 is the ASCII character Tab; Requires casting
char tb = (char)((int)9);

int main()
{
    std::cout << "  *****  Multi Dimensional Dynamic Array With Pointers  *****5\n" << endl;

    int maxRows, maxCols;                // Integer variables hold row and column size of multidimensional array
    cout << " Enter the number of maxRows and columns a new array should have: " << endl;;
    cout << " maxRows: "; cin >> maxRows;
    cout << " Columns: "; cin >> maxCols;
    cout << " An array size of " << maxRows << " maxRows and " << maxCols << " columns was entered" << endl;

    // Allocation of Mememory  -  Begin allocating memory for the two dimensional array
    int** dblDimArrayPtr;               // A pointer to a pointer is created here
    dblDimArrayPtr = new int* [maxRows];// Creates a pointer to dynamic arrays of 'maxRows' arrays deep which dblDimArrayPtr contains

    for (int rowNum = 0; rowNum < maxRows; rowNum++)    // For each row number created, create a pointer to an array of maxCols column elements
    {
        dblDimArrayPtr[rowNum] = new int[maxCols];       // For each row, create a separate dynamic array of maxCols columns
    }

    dblDimArrayPtr[1][2] = 88;          // Don't understand this how you can store a value here - unless by adding                   
    // the [][] syntax, it automatically deferences the pointer

// De-allocation of Mememory
    for (int rowNum = 0; rowNum < maxRows; rowNum++)    // For each row number,, deleted the array of maxCols column elements
    {
        delete[] dblDimArrayPtr[rowNum];// For each row number, deleted the pointer of the array of maxCols column elements
    }

    delete[] dblDimArrayPtr;           // De-allocation - delete the pointer to the double array 

    dblDimArrayPtr = NULL;             // Remove the memory address of the dbleDimArrayPtr



    // ****************************************      Example Two - Alternate Algorythm / Syntax      **********************************************//

    cout << "\n\n\n" << endl;
    int num = 0;
    int* arry = new int[maxRows * maxCols];     // Declare a memory block size of (row * col)
    // Traverse the 2D array - Assigning sequencial values to the block of memory
    for (int rowNum = 0; rowNum < maxRows; rowNum++)
    {
        for (int colNum = 0; colNum < maxCols; colNum++)
        {
            *(arry + rowNum * maxCols + colNum) = ++num;
        }
    }

    // Traverse the 2D array - Display values to the block of memory in a row by column format                                        
    for (int rowNum = 0; rowNum < maxRows; rowNum++)
    {                                           // I now understand this but I did not come up with it myself  ...... boo
        for (int colNum = 0; colNum < maxCols; colNum++)
        {                                       // Array address + ( (rowNum=0 thru (rowNum=maxCols-1)  ) * maxCols) + colNum )
            cout << tb << " " << *(arry + (rowNum * maxCols) + colNum);
        }
        cout << endl;
    }

    // Code below is causing a runtime error ????????????????????????
    // De-allocation of Mememory  -  // Row ear row number deleted the array of maxCols column elements
    //for (int rowNum = 0; rowNum < maxRows; rowNum++)    
    //{
    //    delete[] &arry[rowNum]; // For each row number, deleted the pointer of the array of maxCols column elements
    //}

    delete[] arry;            // De-allocation - delete the pointer to the array 
    arry = NULL;              // Remove the memory address of the arry pointer

    cout << "\n\n\n" << endl;


    system("pause>0");
    return 0;
}


