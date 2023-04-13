// MultiThreadedApp_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>                  // For rand and srand
#include <ctime>                    // For time function
#include <thread>                   // Required to enable threading
#include <map>                      // Required for a map collection type
using std::cout;
using std::cin;
using std::endl;
using std::string;
#include<chrono>                    // Required to use the time in millisecond below
using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int> forecastMap) 
{   
   int val = 0;
   while (true)                        // Infinite loop created here - Always true
   {
      unsigned seed = time(0);         // Get system time as a seed
      srand(seed);                     // Seed the random number generator
      const int MIN_VALUE = 1; const int MAX_VALUE = 10;
      val = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

      if (val < 6)
      {
         for (auto& item : forecastMap)    // Generating dynamic changing data here
         {
            item.second++;                // This is increasing the temperature which is the second item in the map
            cout << item.first << " - " << item.second << endl;
         }
         // Sleep for 2 seconds
         std::this_thread::sleep_for(2000ms);
      }
      else
      {
         for (auto& item : forecastMap)    // Generating dynamic changing data here
         {
            item.second--;                // This is increasing the temperature which is the second item in the map
            cout << item.first << " - " << item.second << endl;
         }
         // Sleep for 2 seconds
         std::this_thread::sleep_for(2000ms);
      }
      cout << endl;
   }

}



int main()
{
    std::cout << "MultiThreading Example \n" << endl;
                                    // Create some dummy data placed in a map collection for use in threading example
                                    // The dummy data is used by the RefreshForcast() funciton above
    std::map<std::string, int> forecastMap = 
    {    
      {"Houston", 85},
      {"Chicago", -12},
      {"Detroit", 05},
      {"Tampa", 81},
      {"Clevland", 23}
    };

    std::thread bgWorker(RefreshForecast, forecastMap);
  
    system("pause>nul");
    return 0;

}



//
//
//
//
// Initial demonstration of multithreading - This is version may be problematic avoid this way

// Place this code before the main section
//void Function1(char symbol)         // Preparing to pass parameter to function for multithreading
//{
//   for (int i = 0; i < 300; i++)+
//      cout << symbol;
//}
//
//void Function2(char symbol)         // Preparing to pass parameter to function for multithreading
//{
//   for (int j = 0; j < 300; j++)
//      cout << symbol;
//}
//

// Place this code withing the main section
//                                // Syntax of passing parameters (char) to the functions
    //std::thread worker1(Function1, 'O');
    //std::thread worker2(Function2, '#');
