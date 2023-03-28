// ArrayPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code sourced from watching the tutorial presented by CodeBeauty on Youtube
// The tutorial video was from CodeBeauty appoximately at the 09:18 frame time.
// Example gives insight to how an array index number designates it address.
// Also shown below the example is five diffent method of finding an array length or size

#include <iostream>
#include<array>
using namespace std;

int main()
{
	std::cout << "Array Pointer Demonstration \n" << endl;

	int someNumbers[6] = { 4, 8, 12, 15, 19, 21 };
	cout << " Using the syntax: \" cout << <arrayName> \" shown the array's first element's addressd" << endl;
	cout << someNumbers << " <-- Address of first element of the array - Same result using  < &(someNumbers[0]) > syntax" << endl;
	// Below displayed output Should be the same value as that output displayed above
	cout << &(someNumbers[0]) << " <-- Address of the first element of the array using the < &(someNumbers[0]) > syntax" << endl;
	cout << " The value of the third element of the array <'> someNumbers[2] > is: " << someNumbers[2] << endl;
	cout << " This is value '2' represents two addresses or indexes away from the first address or index[0} of the array: " << endl;
	// Two addresses from first address - Should be the same output representation as the above
	cout << " " << *(someNumbers + 2) << " Is the value of the third element of the array using < *(someNumbers + 2) > syntax " << endl;
	cout << " Above ^^^ Using dereferencing of the first address of the array plus to two more using the dereferencing '*' symbol" << endl << endl;

	cout << " Here we can display each element of the array by using the pointer dereferensing syntax." << endl;
	int arraySize = end(someNumbers) - begin(someNumbers);

	cout << " ___  Array Contents  ___ " << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << " ArrayIndexContent[" << i << "] = " << *(someNumbers + i) << endl;
	}

	system("pause>0");
	return 0;
}

/*
* 
* 
*		                       ***  Finding an Array Lenght - Multiple Methods ***
* 
* 
  #include<iostream>			// These four statements are a precursor and common to all methods 
  #include<array> 
  using namespace std;
  int main()
{   
   
  1) - *** Using for-each loop
  {
	 int c;
	 int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	 cout << "The array is: ";
	 for (auto i : arr)
	 {
		 cout << i << " ";
		 c++;
	 }
	 cout << "\nThe length of the given Array is: " << c;
	}

 2) - *** Using begin() and end()  This what was used in above code

 {
    //Given Array
    int arr[] = { 11, 22, 33, 44 };

    cout<<"The Length of the Array is : "<<end(arr)-begin(arr); //length
 }

 3) - *** Using sizeof() function to Find Array Length in C++
 {  //Given array
    int  arr[] = {10 ,20 ,30};
   
    int al = sizeof(arr)/sizeof(arr[0]); //length calculation
    cout << "The length of the array is: " << al;     
 }

 4) - *** Using the size() function in STL

 {  //Given array
    array<int,5> arr{ 1, 2, 3, 4, 5 };
    //Using the size() function from STL
    cout<<"\nThe length of the given Array is: "<<arr.size();
 }

 5) - ***

 {  //Given array
    int  arr[6] = {5,4,3,2,1,0};

    int len = *(&arr + 1) - arr;
    // *(&arr + 1) is the address of the next memory location
    // just after the last element of the array
    cout << "The length of the array is: " << len;
 }

  system("pause">0);				// These twostatements are a precursor and common to all methods 
  return o;

}
*/