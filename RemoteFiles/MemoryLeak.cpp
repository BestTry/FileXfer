// MemoryLeak.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code Beauty recommends installing error checking software titled PVS Studio.
// PVS Studio may be installed by clicking the "Extensions" tab above and then select "Manage Extensitons" 
// Search for PVS Studio, download and install it under a student license 
//
//
// Free PVS Studio:  See on-line instructions to use free vesion
// Enter: License Key:  Name: PVS-Studio Free. Key FREE-FREE-FREE-FREE
//
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string; 

void someFunction()
{
   int val = 7;                  // Every time a new keyword is referenced,  it is allocating dynamic memory 
   int* intPtr = new int[5];     // Here a dynamic memory has been allocated to an array of size 5
   intPtr[3] = val;
   cout << " The value of the array intPtr at index 3 is: " << intPtr[3];

   delete [] intPtr;             // The address memory and the contents memory have been de-allocated 
                                 // Both the delete keywork and [] are necessary! to delete both the
                                 // pointer (address) 'intPtr' to the array and its contents ' [] ' 
                                 // If this 'delete' code was missing it would cause a memory leak!
}


int main()
{
    cout << " *****************  Demonstrating a Memory Leak  ***************** \n";
     
    someFunction();
    cout << " The code has just possibily produced a MEMORY LEAK!" << endl;
    cout << " Cause: The function called was one invoked with dynamic memory " << endl;
    cout << " After the function completion the memory must be de-allocated otherwise it will cause a memory leak! " << endl;
    cout << endl;

    cout << " To correct the memory lead problem, de - allocate the memory associated with the called function" << endl;
    cout << " For every 'new' keyword invoked, a delete keyword in the code must be invoked as well " << endl;
    cout << " After the function execution was complete the function de-allocated its dynamic memory! " << endl;

    system("pause>0");
    return 0;
}

// Example code below is shown to exhibit a common error if '(i <= 5)' is the for condition
//int total = 0;
//int savedFunds[5] = { 100, 250, 200, 150, 300 };
//
//for (int i = 0; i < 5; i++)           // Invoking array index [0] to [4] -Caution! not [5]
//{
//   total += savedFunds[i];
//}
//
//cout << " The amount saved (adding values from the array) is " << total;