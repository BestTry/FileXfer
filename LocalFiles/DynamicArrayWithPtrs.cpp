// DynamicArrayWithPtrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lifted the code from example presented by CodeBeauty of her Youtube series.
// Normally Cpp arrays are not allowed to be resized. Their size my be a constanct for the compiler to accept them
// Arrays in Cpp grab up a continuest unbroken stream of memory and that allocation is constant.  
// There is a workaround in Cpp and that is using the keyword 'new' and 'delete' for maniputlating memory usage.
// Example shows that this unique array is created at runtime!
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Dynamic Array Example \n" << endl;

    int arrSize;
    cout << " Enter the size of an array: ";
    cin >> arrSize;
                                        // Pointer 'myArray' contains first address to array 'myArray' with arrSize elements
    int* myArray = new int[arrSize];    // Array is created at runtime!  Here memory is ALLOCATED remember to de-allocate 

    cout << " Enter the value for each element in the array below " << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << " For element " << i << " Enter interger value: "; cin >> myArray[i]; 
    }
    cout << " \n\n" << " Here the contents of the array that was entered: \n" << endl;

    cout << " Array contents: {  ";
    for (int i = 0; i < arrSize; i++)
    {                                   // Value of 'i' is i addresses away from first address of the array
        cout << " " << *(myArray + i);  // <<== Altrnate syntax from common syntax: cout << " " << myArray[i]; 
        if (i != arrSize - 1) { cout << ", "; }
    }
    cout << " } " << endl;
                                        // The square brackets are require to flag the type of memory location de-allocated i.e. arrays
    delete[]myArray;                    // Memory has been de-allocated for array BUT myArray is still pointing to the address
    myArray = NULL;                     // Must assign Null to remove the address location the array was pointing to

    system("pause>0");
}
