#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string model;
    int year;

public:
    Vehicle(string i_model, int i_year) : model(i_model), year(i_year) {}

    virtual void display() const
    {
        cout << "Model:" << model << endl;
        cout << "Year:" << year << endl;
    }
};

class Car : public Vehicle
{
private:
    int doorNumber;
    int fuelEfficinecy;

public:
    Car(string i_model, int i_year, int i_doorNumber, int i_fuelEfficinecy) : doorNumber(i_doorNumber), fuelEfficinecy(i_fuelEfficinecy), Vehicle(i_model, i_year) {}

    void display() const override
    {
        Vehicle::display();
        cout << "Door number:" << doorNumber << endl;
        cout << "Fuel Efficiency:" << fuelEfficinecy << endl;
    }
};

class ElectricCar : public Car
{
private:
    int battery;

public:
    ElectricCar(string i_model, int i_year, int i_doorNumber, int i_fuelEfficinecy, int i_battery) : battery(i_battery), Car(i_model, i_year, i_doorNumber, i_fuelEfficinecy) {}

    void display() const override
    {
        Car::display();
        cout << "Battery:" << battery << endl;
    }
};

int main()
{
    ElectricCar ecar("Tesla", 2015, 4, 40, 100);
    ecar.display();
    return 0;
}