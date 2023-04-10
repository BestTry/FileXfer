// This is the implementation file for the HeaderFileExample code
// The file contains all the Definitions of for the Declaration file Header:   "Food.h"
//
#include <iostream> 
#include "Food.h"

using std::cout;
using std::cin;
using std::endl;
//
//

                            // Definition / Implementation of the function declared in the Food.h file
const char* RecommendFood(char frstLetr)
{
    if (frstLetr == 'a' || frstLetr == 'A')
        return "Apple";

    else if (frstLetr == 'b' || frstLetr == 'B')
        return "Banana";

    else if (frstLetr == 'c' || frstLetr == 'C')
        return "Carrot";

    else return "Pizza";
};

string RecommendFood(string mystring)
{
    return mystring;
};

void FavoriteFood()
{
    cout << " the tastie dinner of mash potatoes,  gravy, stuffing and turkey" << endl;
};
