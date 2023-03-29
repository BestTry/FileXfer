// PolymorphismVehicle.cpp : This file contains the 'main' function. Program execution begins and ends there.//
// Added polymorphism feature to the previous exampmples on classes, and inheritance to show how a method 
// of the same name will behave diffenently depending on the type of class or object
// 
//
#include <iostream>
#include<list>
using namespace std;

                                // Prepare invoke tab for later display; Give it alias variable 'tb' designation
                                // Integer 9 is the number for the ASCII character Tab; Requires integer and char type casting
char tb = (char)((int)9);

class Vehicle                   // Class is a user defined data type - This is a base class for types of vehicles
{                               // Class members include properties & functions (atributes and behavior). Usually ' T ' is used as the type var
                                // Properties / attributes are normally defaulted to private and implemented here to show incapsulation
                                // Access Specifiers - private and public keyword are followed by a < : > colon character.  Protected is declared 1st.
                                // Access specifiers ***** If used with inherited class, use protected << instead of private.
                                // For some reason, keeping these private still worked (Derived class could still access these properties
                                // The access catagory of 'protected' is used when properites need protection but will be use by a subclass or object
protected:
    string color;
    string make;
    string owner;
    int hrsPower = 0;
    int speed = 0;
    int fuel = 0;
    list<int> mpgPerWk;         // Weekly mpg measurement begins at week one or mpgPerWk[0] (index zero)
    int ttlRdgs = 0;

public:                         // Constructor - Setting all the owner and default values for the instantiated object. Assesibility MUST BE PUBLIC!
    Vehicle(string clr, string mk, int pwr, string own)
    {
        color = clr;
        make = mk;
        owner = own;
        hrsPower = pwr;
        speed = 0;
        mpgPerWk = { };
    }

    // ----------------------------------------------------------------------------------------------------------------------------------------------------
                                // Class member functions or methods;  If these were defined outside of the class, 
                                // they would require prototypes with the class and   < CLASSNAME:: >  < :: >, the scope resolution designation
                                // Here is an example if declared outside the class   void DisplayVehicle() :: Vehicle  
                                // (Shows that the DisplayVehicle() function  is part of the Vehicle class
    void DisplyVehicleInfo()    // Displays most vehicle object attributes at one time with a method        
    {
        cout << tb << "  My Vehicle's color is: " << color << endl;
        cout << tb << "  My Vehicle's make is: " << make << endl;
        cout << tb << "  My Vehicle's horse power is: " << hrsPower << endl;
        cout << tb << "  My Vehicle's owner is: " << owner << endl << endl;
    }

                                // Methods created for Incapsulation access - Getters and Setter of property values
    string GetColor() { return color; }
    string GetMake() { return make; }
    string GetOwner() { return owner; }
    int    GetPower() { return hrsPower; }
    int    GetSpeed() { return speed; }
    int    GetTotalRdgs() { return ttlRdgs; }

    void SetColor(string clr) { color = clr; }
    void SetMake(string mk) { make = mk; }
    void SetOwner(string own) { owner = own; }
    void SetHrsPwr(int pwr) { hrsPower = pwr; }
    void SetSpeed(int spd) { speed = spd; }

    void IncrSpeed() { speed++; }
    void IncrSpeed(int inc) { speed += inc; }
    void DecrSpeed() { speed--; }
    void DecrSpeed(int dcr) { speed -= dcr; }

    void RecordMPG(int mpg)     // RecordMPG() method populates the list<int> with mpg/week values
    {                           // Populates the list<int> 'mpgPerWk' (Last in at the largest index)
        mpgPerWk.push_back(mpg);
        ttlRdgs++;              // Advance reading count since mpg value was added to the mpgPerWk list<int>
    }

    void DsplyMPG_PerWeek()

    {
        cout << "   Miles per gallon recorded for weeks 1 thru " << ttlRdgs << endl;
        cout << "  ----------------------------------------------" << endl;

        int week = 1;
                                // *****   Look this C++ syntax is using a FOR EACH syntax for the list "mpgPerWk"  *****
                                // It is pulling the value of each list index value sequencially and placing it the var 'readVal'
        for (int readVal : mpgPerWk)
        {
            cout << "      " << "My vehicle mpg for week " << week++ << " is:  -->   " << readVal << endl;
        }
    }

    void Refuel(int gal)
    {
        fuel += gal;
        cout << " This vehicle has added " << gal << " gallons of regular gasoline to its gas tank " << endl;
    }

    int fuelAmount()
    {
        return fuel;
    }

};                              // End of Vehicle Class  - Note the semicolon required at closing braces of the "Vehicle" class

// .....................................................................................................................................................
                                // Derived Class - 'Truck' which is drived from the base class 'Vehicle'
                                // The derived class "Truck" inherits from the base class "Vehicle"
                                // The inherited class has the same properties and methods of its parent class Vehicle
class Truck : public Vehicle
{
    string truckType;           // Added two additional properties to the Truck class in addtion to the Vehicle class properties
    int    payLoad;

                                // Constructor for inherited class "Truck" with two additional new properties for total of six required
public:
    Truck(string typ, int load, string clr, string mk, int pwr, string own) : Vehicle(clr, mk, pwr, own)
    {                           // Note here the two additional properties and their assignments
        truckType = typ;
        payLoad   = load;
    }
                                // Functions / Methods for Truck class
    void incPayLoad() { payLoad++; }
    void dcrPayLoad() { payLoad--; }
    void setPayLoad(int load) { payLoad += load; }
    int  getPayload() { return payLoad; }

    void DisplyTruckInfo()    // Displays most Truck object attributes at one time with a method design to show its attributes
    {
        cout << tb << "  My Truck's type is: " << truckType << endl;
        cout << tb << "  My Trucks's payload is: " << payLoad << " tons" << endl;
        DisplyVehicleInfo();  // Invoking the properties of the inherited Vehicle class properties
    }

    void Refuel(int gal)
    {
        fuel += gal;
        cout << " This truck took in " << gal << " gallons of diesel fuel to its fuel tank " << endl;
    }

    int fuelAmount()
    {
        return fuel;
    }

};

// .......................................................................................................................................................
// .......................................................................................................................................................
// *******************************************************************************************************************************************************

int main()
{                               // Instantiating a Vehicle class named myCar (myCar 'Car' is a type of vehicle)
    Vehicle myCar("Green", "Mazda", 140, "Suzie Smith");
                                // Filling average weekly mileage numbers by invoking RecordMPG() method that fills
                                // the list<int> with values (Last in is stuff at the next ++index (top) of the list<int>
    myCar.RecordMPG(21); myCar.RecordMPG(22); myCar.RecordMPG(20);
    myCar.RecordMPG(23); myCar.RecordMPG(23); myCar.RecordMPG(24);
    myCar.RecordMPG(25); myCar.RecordMPG(26); myCar.RecordMPG(24);

                                // Total readings of average weekly recorded mpg for all weeks
    int readings = myCar.GetTotalRdgs();

    cout << "*************************************************" << endl;
    cout << "** Code demonstrates class and object creation **  " << endl;
    cout << "** Invoking properties - Getter/Setter Methods **" << endl;
    cout << "**      Car object of base Vehicle class       **" << endl;
    cout << "-------------------------------------------------" << endl << endl;

    myCar.DisplyVehicleInfo();  // Display all Car object 'myCar' attributes

    myCar.DsplyMPG_PerWeek();

    cout << endl;

    cout << tb << tb << " Car speed: " << myCar.GetSpeed() << endl;
    myCar.IncrSpeed(); myCar.IncrSpeed(36);
    cout << tb << tb << " Car speed: " << myCar.GetSpeed() << endl;
    myCar.DecrSpeed();  myCar.DecrSpeed(8);
    cout << tb << tb << " Car speed: " << myCar.GetSpeed() << endl;
    myCar.IncrSpeed(20);
    cout << tb << tb << " Car speed: " << myCar.GetSpeed() << endl;

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

                                    // Instantiating a Truck class named myTruck
    Truck myTruck("Semi", 8, "Black", "MAX", 410, "Butch Hunker");
                                    // Filling list of average weekly mileage numbers by invoking RecordMPG() 
                                    // method which is a method within the inherited Vehicle class
    myTruck.RecordMPG(11); myTruck.RecordMPG(12); myTruck.RecordMPG(10);
    myTruck.RecordMPG(13); myTruck.RecordMPG(10); myTruck.RecordMPG(14);
    myTruck.RecordMPG(15); myTruck.RecordMPG(16); myTruck.RecordMPG(14);

                                    // Total readings of ave weekly recorded mpg for all weeks - Another inherited vehicle method
    readings = myTruck.GetTotalRdgs();

    cout << "\n\n" << endl;

    cout << "*************************************************" << endl;
    cout << "** Truck class is inherited from the the base  ** " << endl;
    cout << "**              class Vehicle                  **" << endl;
    cout << "**    Truck object data is displayed below     **" << endl;
    cout << "-------------------------------------------------" << endl << endl;

    myTruck.DisplyTruckInfo();      // Display all the Truck attributes of 'myTruck' object attributes plus it displays all the Vehicle 
                                    // attributes of the 'myTruck' object   -  since the class Truck inherits from the Vehicle class

    myTruck.DsplyMPG_PerWeek();

    cout << endl;

    cout << tb << tb << " Truck speed: " << myTruck.GetSpeed() << endl;
    myTruck.IncrSpeed(); myTruck.IncrSpeed(26);
    cout << tb << tb << " Truck speed: " << myTruck.GetSpeed() << endl;
    myTruck.DecrSpeed();  myTruck.DecrSpeed(5);
    cout << tb << tb << " Truck speed: " << myTruck.GetSpeed() << endl;
    myTruck.IncrSpeed(16);
    cout << tb << tb << " Truck speed: " << myTruck.GetSpeed() << endl;

    // Polymorphism *****
    // Example of methods with an identical name calling two different class objects
    // resulting in different behavior or return value for each object type
    cout << "\n\n Time to refuel vehicles: " << endl;
    cout << " Car refuels: ";  myCar.Refuel(18);
    cout << " Truck refuels: "; myTruck.Refuel(254);

    cout << endl << " Check fuel gages:" << endl;
    cout << " The car has " << myCar.fuelAmount() << " gallons of gasoline" << endl;
    cout << " The truck has " << myTruck.fuelAmount() << " gallons of deisel fuel" << endl;

    cout << endl;

    cout << "\n Topping off fuel in each of the vehicles: " << endl;
    cout << " Car refuels: ";  myCar.Refuel(2);
    cout << " Truck refuels: "; myTruck.Refuel(16);

    cout << endl << " Check fuel gages:" << endl;
    cout << " The car has a total of " << myCar.fuelAmount() << " gallons of gasoline" << endl;
    cout << " The truck has a totol of " << myTruck.fuelAmount() << " gallons of deisel fuel" << endl;


    system("pause>0");
    return 0;
}