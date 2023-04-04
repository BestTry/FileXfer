//
// MultiDimDynamicPtrArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code demonstrates an example of a two dimensional dynamic array using pointers.  Lifted from CodeBeauty time: 9:50 
// The array is dynamic and therefore it will be using the keywords 'new' amd delete for memory allocation and de-allocation
// Regular two dimensional arrays will also work within Cpp.  It appears Dynamic Arrays are more powerful and flexible
//
// A Multidimensional array is in simple words is an array of arrays 


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
// using namespace std;                   // Do not use this namespace std but be specific as shown in statements above ^
                                          // Prepare to invoke tab for a later display; Give it alias variable 'tb' designation
char tb = (char)((int)9);                 // Integer 9 is the ASCII character for 'Tab'; Requires casting as seen here


int main()                                // Example one of a multidimension array -- there is no output display in this example{                                         
{
    std::cout << "  *****  Multi Dimensional Dynamic Array With Pointers  *****\n" << endl;

    int maxRows, maxCols;                 // Integer variables hold row and column size of multidimensional array
    cout << " Enter the number of rows and columns to generate a two dimension array: " << endl;;
    cout << " maxRows: "; cin >> maxRows;
    cout << " Columns: "; cin >> maxCols;
    cout << " An array size of " << maxRows << " rows and " << maxCols << " columns was entered" << endl;

                                          // Allocation of Mememory  -  Begin allocating memory for the two dimensional array
    int** dblDimArrayPtr;                 // A pointer to a pointer is created here - Assign the pointer below
    dblDimArrayPtr = new int* [maxRows];  // Creates a pointer to dynamic arrays of int type pointers 'maxRows' arrays deep which dblDimArrayPtr contains

    for (int rowNum = 0; rowNum < maxRows; rowNum++)    // For each row element created, create a pointer to an array of maxCols column elements
    {
        dblDimArrayPtr[rowNum] = new int[maxCols];      // For each row element, create a separate dynamic array of maxCols columns elements
    }

    //dblDimArrayPtr[1][2] = 88;          // Don't understand this how you can store a value here - unless by adding the [][] syntax,                  
    //                                    // it automatically deferences the pointer.  I do not understand .... 
    //                                    // but the the display of 88 is correct. I would think that *( ... ) would have to be used
    //cout << "\n\n The contents of dblDimArrayPtr[1][2] was loaded with a value of 88\n"
    //     << " Checking its contents now the value is: " << (dblDimArrayPtr[1][2]) << " ??? " << endl;
    //Note that element [1][2] is in the second row of columns array (index[1]) and at the third element (column) of (index[2])  

                                          // De-allocation of Mememory
                                          // De-allocation - Each time the 'new' keyword is used the corresponding 'delete' keyword must be used!
    for (int rowNum = 0; rowNum < maxRows; rowNum++)    // For each row number,, deleted the array of maxCols column elements
    {
        delete[] dblDimArrayPtr[rowNum];  // For each row number, deleted the pointer of the array of maxCols column elements
    }

                                          // De-allocation - Each time the 'new' keyword is used the corresponding 'delete' keyword must be used!
    delete[] dblDimArrayPtr;              // De-allocation - delete the pointer to the double array 
    dblDimArrayPtr = NULL;                // Remove the memory address of the 'dbleDimArrayPtr' pointer



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



    cout << "      >>>>> The sequencial element contents of the " << maxRows << " by " << maxCols << " array <<<<<" << endl;
    cout << "     ----------------------------------------------------------------- " << endl;
                                                // Traverse the 2D array - Display values to the block of memory in a row by column format                                        
    for (int rowNum = 0; rowNum < maxRows; rowNum++)
    {                                           // I now understand this but I did not come up with it myself  ...... boo
        for (int colNum = 0; colNum < maxCols; colNum++)
        {                                       // Array address + ( (rowNum=0 thru (rowNum=maxCols-1)  ) * maxCols) + colNum )
            cout << tb << " " << *(arry + (rowNum * maxCols) + colNum);
        }
        cout << endl;
    }

   
                              // De-allocation of Mememory
                              // De-allocation - Each time the 'new' keyword is used the corresponding 'delete' keyword must be used!
    delete[] arry;            // De-allocation - delete the pointer to the array 
    arry = NULL;              // Remove the memory address of the 'arry' pointer

    cout << "\n\n\n" << endl;


    system("pause>0");
    return 0;
}


