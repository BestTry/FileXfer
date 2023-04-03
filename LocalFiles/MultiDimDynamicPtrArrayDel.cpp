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

   int rows, cols;                     // Integer variables hold row and column size of multidimensional array
   cout << " Enter the number of rows and columns a new array should have: " << endl;;
   cout << " Rows: "; cin >> rows;
   cout << " Columns: "; cin >>  cols;
   cout << " An array size of " << rows << " rows and " << cols << " columns was entered" << endl;

                                       // Allocation of Mememory  -  Begin allocating memory for the two dimensional array
   int** dblDimArrayPtr;               // A pointer to a pointer is created here
   dblDimArrayPtr = new int* [rows];   // Creates a pointer to dynamic arrays of 'rows' arrays deep which dblDimArrayPtr contains
                                       
   for (int rowNum = 0; rowNum < rows; rowNum++)    // For each row number created, create a pointer to an array of cols column elements
   {
      dblDimArrayPtr[rowNum] = new int[cols];       // For each row, create a separate dynamic array of cols columns
   }

   dblDimArrayPtr[1][2] = 88;          // Don't understand this how you can store a value here - unless by adding                   
                                       // the [][] syntax, it automatically deferences the pointer

                                       // De-allocation of Mememory
   for (int rowNum = 0; rowNum < rows; rowNum++)    // For each row number,, deleted the array of cols column elements
   {
      delete[] dblDimArrayPtr[rowNum]; // For each row number, deleted the pointer of the array of cols column elements
   }

   delete[] dblDimArrayPtr;            // De-allocation - delete the pointer to the double array 

   dblDimArrayPtr = NULL;              // Remove the memory address of the dbleDimArrayPtr



   // ****************************************      Example Two - Alternate Alorythm / Syntax      **********************************************//

   cout << "\n\n\n" << endl;
   int num = 0;
   int* arry = new int[rows * cols];     // Declare a memory block size of (row * col)

   for (int rowNum = 0; rowNum < rows; rowNum++)
   {                                   // Traverse the 2D array - Assigning values to the block of memory
      for (int colNum = 0; colNum < cols; colNum++)
      {
         *(arry + rowNum * cols + colNum) = ++num;
      }
   }

   for (int rowNum = 0; rowNum < rows; rowNum++)
   {                                   // Traverse the 2D array - Display values to the block of memory in a row by column format
      for (int colNum = 0; colNum < cols; colNum++)
      {
         
         cout << *(arry + rowNum * cols + colNum) << tb << " ";
      }
      cout << endl;
   }

   system("pause>0");
   return 0;
}
