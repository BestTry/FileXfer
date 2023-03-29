// Pointers_Basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Pointers_Basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code is copied from CodeBeauty "C++ FULL COURSE for beginners (Learn C++ in 10 hours)

#include <iostream>
using namespace std;

int main()
{
   cout << "               Understanding Pointers and References " << endl;
   cout << "            -------------------------------------------\n" << endl;

   int  num = 7;   cout << " Here is the contents assigned to the variable 'num':  " << num << endl;
   cout << " The memory address of the variable num is:   " << &num << endl;
   // Using the symbol "&" ambersand before the variable retrieves the address of the variable

   cout << "\n Create a pointer '*ptrNum' and assign it an address to the num variable using 'ptrNum = &num' " << endl;
   int* ptrNum;
   // Using the symbol "*" asterisk before a variable declares variable ptrNum as a pointer of interger type                                 

   ptrNum = &num;
   
   cout << " Pointer 'ptrNum' (address) of the variable 'num' is:  " << ptrNum << endl;
   // The pointer type declared above must be of the same type as the address of the variable shown previously (num)

   cout << "\n Dereferencing pointer 'ptrNum' to retrieve its int variable value using the '*ptrNum' syntax" << endl;
   cout << " The contents of the variable 'num' stored at the pointer 'ptrNum' is:  " << *ptrNum << endl; 
   // Dereference ptrNum to acquire the value stored at the address pointed to by ptrNum using the '*' symbol

   cout << endl;

   // Assigning a value to the memory location the address of the pointer is pointing to by dereferencing
   *ptrNum = 14;
   cout << " Storing a value of 14 within the 'derefenced pointer' '*ptrNum' results in " << endl;
   cout << " that the value contained in the dereferenced pointer '*ptr' is now:  " << *ptrNum << endl;
   cout << " which is the same value contained in the variable num:  " << num << endl << endl;

   cout << " >>>    Remember! that the pointer type of a pointer to a variable must     <<< " << endl;
   cout << " >>>      be of the same type as the variable type that it points to   <<< " << endl;

   
   // ****** Problem Code: *****
   // int *ptrNum2;  // OK so far
   // *ptrNum2 = 11; // Error! the pointer 'ptrNum2' has yet to hava a address assigned to it.

   // ****** Corrected Code: *****
   // Corrected code assigns address to the pointer ptrNm2 
   // which is the address of the interger variable 'num' (&num2 address) 
   // Must happen before deferencing it and assigning a new vlaue to it
   cout << "\n\n Error Example - See source code: " << endl;
   int num2 = 11;
   int* ptrNum2;
   ptrNum2 = &num2;
   *ptrNum2 = 21;
   cout << " The value of 'num2' and '*ptrNum2' is:  " << num2 << " and " << *ptrNum2 << endl;
   cout << " Not the original value of num2 which was 11 - cause *ptrNum2 was assigned 21 " << endl;


   system("pause>0");
   return 0;

}

