// HeaderFilesExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Example published on video by CodeBeauty on Youtube -  https://www.youtube.com/watch?v=qaGzc56Rekg
// Every function is usually split into two separate part a "Declaration" - place before the main section
// Then the Definition/Implementation section of the function placed after the main section of the program. These 
// two seperate parts of a funtion can also be re-located for other code to use. This re-location is
// what is meant by 'Header' files - a file for the Declaration and a file for the Definition
// One or more Function Declatations statements all go in the 'Header' file.
// Onr or more Function Definition code blocks all go into the Implementation source file.
//
#include <iostream>         // This is also a header file but it is included with the C++ compiler - provides services like cout, cin
#include "Food.h"           // The Header file for the 'RecommendFood' function must be included to enable the function
                            // It is a User Defined header file and quotation marks instead of angle brackets are used
                            // The header file is called a preprocessor directive. Any file that needs the function must include the header file
                            // Example if one has 100 files that need to utilize the function they need to include this Declaration header file
using std::cout;
using std::cin;
using std::endl;
using std::string;


//
// 
// ****** The following lines of code was commented out and removed to the header file ******
//                            // Declaration of the functions section
//const char* RecommendFood(char firstLetter);
//string RecommendFood(string firstLetter);

int main()
{
    string myString;

    cout << " Header Files Presentaiton \n" << endl;
                            // Fnction is seeking a single 'char' character
    cout << " Today I think I will eat a: ";
    char l = 'a';    
    cout << RecommendFood(l);

    cout << endl;

    cout << " Tomorrow I think I will eat a: " << RecommendFood('b');

    cout << "\n\n" << endl;

    string food;
    cout << " What do you think you would like to eat? ";
    cin >> food; 
        
    cout << " Don't think just eat a: " << RecommendFood(food) << endl;

    cout << " My favorite food is: ";
    FavoriteFood();
   
   
    system("pause>0");
    return 0;

}
//
// The code section was removed and place in the implementation file "Food_Implementation"
//                            // Definition / Implementation of the function section
//const char* RecommendFood(char frstLetr)
//{
//    if (frstLetr == 'a' || frstLetr == 'A')
//        return "Apple";
//
//    else if (frstLetr == 'b' || frstLetr == 'B')
//        return "Banana";
//
//    else if (frstLetr == 'c' || frstLetr == 'C')
//        return "Carrot";
//
//    else return "Pizza";
//};
//
//string RecommendFood(string mystring)
//{
//    return mystring;
//};
//
