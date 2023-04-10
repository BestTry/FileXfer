#pragma once
// This is the header file for the HeaderFileExample 
// The term #Pragma signifies that any cpp file and only include a header file once
// 
// 
#include <iostream>
using std::string;
                           // Declaration of the functions section
const char* RecommendFood(char firstLetter);
string RecommendFood(string firstLetter);
void FavoriteFood();