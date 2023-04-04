// Structures_Example.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code is lifted from CodeBeauty Tutorials on the topic of structures.
// Structures are similar to 'Classes' except all properties and methods/functions are public

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// ............................................................................................................................... /

struct Vehicle          // This struct has to be defined BEFORE person  struct cause person objecs must know about vehicles
{                       // Attributes - Properties of Vehicle
   string make;
   string color;
   int year;
   int mpg;
   string type;         // Truck Car Bicycle

   void DisplayVehicleData()
   {
      cout << " Vehicles Data: " << endl;
      cout << " Type: " << type << endl;
      cout << " Make: " << make << endl;
      cout << " Year: " << year << endl;
      cout << " Color: " << color << endl;
      cout << " MPG: " << mpg << endl;
   }
};                      // Semicolon is required here!

struct Person
{
   int age;             // Attributes - Properties of Person
   string firstName;
   string  lastName;
   int weight;
   Vehicle vehicle;    // Within the person struct include a Vehicle attribute.

   void DisplayPersonData()
   {
      cout << " Person Data: " << endl;
      cout << " First Name: " << firstName << endl;
      cout << " LastName: " << lastName << endl;
      cout << " weight: " << weight << endl;

   }
};



void DisplayAllData(Vehicle vehicle, Person person)
{
   vehicle.DisplayVehicleData();
   cout << "\n\n " << endl;
   person.DisplayPersonData();
}

// ................................................................................................................... 


int main()              
{
   cout << " Structures Example\n" << endl;

   Vehicle fourRunner;   // This struct instantiation has to be defined BEFORE person tom has to know the vehicle object
   fourRunner.make = "Toyota";
   fourRunner.color = "Dark Green";
   fourRunner.year = 1997;
   fourRunner.mpg = 19;
   fourRunner.type = "SUV";


   Person tom;          // This struct does not have a parametized constructor: Assign params this way
   tom.firstName = "Thomas";
   tom.lastName = "Ricci";
   tom.weight = 167;
   tom.age = 75; 
   tom.vehicle = fourRunner;
   


   tom.DisplayPersonData();

   cout << "\n\n " << endl;   

   fourRunner.DisplayVehicleData();

   cout << "\n\n Displaying all data with one function call: " << endl;

   DisplayAllData(fourRunner, tom);
}

