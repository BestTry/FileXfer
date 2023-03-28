// Void_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code adapted from the 'Code Beauty' tutorial video series 'C++ Full Course for Begginers (in 10 hours) 
// A void pointer to hold the address of ANY type of variable. It does have to be the same type as the variable
// Void pointers can not be directly dereferenced to the value of their variable they are pointing at.
// Therefore a function / method call Passing the var type is utilize with a switch statement to do the dereferencing 
// Note on line 23 that < (void*) > is a unique syntax is used for casting the char variable to an address

#include <iostream>
using namespace std;

void DispPtrAddrAndVal(int* ptr);               // Function Prototype of regular number argument
void DispPtrAddrAndVal(void* ptr, char type);   // Function Void Pointer type pointer receiving any type of argument


int main()
{
    std::cout << "     *** Void Pointer Example *** \n" << endl;;

    char chrVar = 'G';
    char* chrPtr;                                // Create pointer to a char var; Optional syntax: <char *chrPtr>,  <char * chrPtr>
    chrPtr = &chrVar;                            // Retrieve the address for the char pointer
    cout << " The value to the char variable is; " << chrVar << endl;
    cout << " The memory address to the char variable is: " << (void*)chrPtr << endl;  // Syntax for char ptrs are different / unique. So must use casting
    cout << " Using dereferencing pointer syntax, the char value is " << *chrPtr << endl;
    cout << " Acquiring the memory address to the char variable must use casting: \n"
         << " therefore, place the casting syntax  < (void*) > in front of chrPtr variable" << endl << endl;

    int numVar = 2;
    int* numPtr;                                // Create pointer; Optional syntax: <cint *intPtr>,  <int * intPtr>
    numPtr = &numVar;
    cout << " The value held by the int variable is; " << numVar << endl;
    cout << " The memory address to the int variable is: " << &numVar << endl;
    cout << " Using dereferencing pointer syntax, the variable numVar value is " << *numPtr << endl;;
    cout << endl << endl << endl;

                                                // Using function call that enables any type of variable argument to be displayed with "void" pointers
    cout << "              Experimenting with 'Void Pointers' " << endl;

    int num = 9;
    DispPtrAddrAndVal(&num);                     // Pass the address of the variable num using the '&' symbol

    cout << endl << endl;

    DispPtrAddrAndVal(&num, 'i');                // Same but uses the void pointer function passing it an address (pointer) to the integer variable
    cout << endl;

    char chr = 'A';
    DispPtrAddrAndVal(&chr, 'c');                // Same but uses the void pointer function passing it an address (pointer) of the char variable
    cout << endl;

    float fltNum = 613.829E2;
    DispPtrAddrAndVal(&fltNum, 'f');             // Same but uses the void pointer function passing it an address of float number
    cout << endl;

    double dbNum = 4.3367;
    DispPtrAddrAndVal(&dbNum, 'd');              // Same but uses the void pointer function passing it an address of double number
    cout << endl;

    bool blVal = false;
    DispPtrAddrAndVal(&blVal, 'b');              // Same but uses the void pointer function passing it an address of bool value


    system("pause>0");
    return 0;
}

void DispPtrAddrAndVal(int* ptr)                // Function Declaration of Function / Method
{
    cout << " The address of the pointer is:  " << ptr << endl;
    cout << " The value of the variable the pointer is pointing to is:  " << *ptr << endl;
}

void DispPtrAddrAndVal(void* ptr, char type)
{
    switch (type)                                // Since a void pointer can not be dereferenced directly, first cass address (void pointer)
    {                                            // variable into a pointer of desinated type, then dereference it

    case 'i': 
        cout << " The address of the integer variable is: " << ((int*)ptr) << endl;   // Address of the interger variable
        cout << " The value of the integer variable is: " << *((int*)ptr) << endl;    // Handles Interger type pointer
        cout << endl;
        break;

    case 'c': 
        cout << " The address of the char variable is: " << (void*)ptr << endl;       // Address of the char variable
        cout << " The value of the char variable is: " << *((char*)ptr) << endl;      // Handles char type pointer
        cout << " Acquiring char variable address works if casting (void*) is placed prior to the ptr variable" << endl;
        cout << endl;
        break;

    case 'f': 
        cout << " The address of the float variable is: " << ((float*)ptr) << endl;   // Address of the float variable
        cout << " The value of the float variable is: " << *((float*)ptr) << endl;    // Handles float type pointer
        cout << endl;
        break;

    case 'd': 
        cout << " The address of the double variable is: " << ((double*)ptr) << endl; // Address of the double variable
        cout << " The value of the double variable is: " << *((double*)ptr) << endl;  // Handles double type pointer
        cout << endl;
        break;

    case 'b': 
        cout << " The address of the bool variable is: " << ((double*)ptr) << endl;   // Address of the boolen variable 
        cout << " The value of the bool variable is: " << *((bool*)ptr) << endl;      // Handles boolean type pointer
        cout << endl;
        break;
    }


}