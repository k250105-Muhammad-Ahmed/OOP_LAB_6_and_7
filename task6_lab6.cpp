#include <iostream>
#include <string>
using namespace std;

class Device
{
private:
    string brand;
    string model;

public:
    Device(string i_brand, string i_model) : brand(i_brand), model(i_model) {}

    virtual void display() const
    {
        cout << "Brand:" << brand << endl;
        cout << "Model:" << model << endl;
    }
};

class Smartphone : virtual public Device
{
private:
    int SIM_slot;

public:
    Smartphone(string i_brand, string i_model, int i_SIM_slot) : SIM_slot(i_SIM_slot), Device(i_brand, i_model) {}

    void display() const override
    {
        Device::display();
        cout << "SIM slots:" << SIM_slot << endl;
    }

    int getSlots() const { return SIM_slot; }
};

class Tablet : virtual public Device
{
private:
    bool stylus_support;

public:
    Tablet(string i_brand, string i_model, bool i_stylus_support) : stylus_support(i_stylus_support), Device(i_brand, i_model) {}
    void display() const override
    {
        Device::display();
        cout << "Stylus support:" << stylus_support << endl;
    }
    bool getStylus_support() const { return stylus_support; }
};

class HybridDevice : public Smartphone, public Tablet
{
public:
    HybridDevice(string i_brand, string i_model, int i_SIM_slot, bool i_stylus_support)
        : Device(i_brand, i_model),
          Smartphone(i_brand, i_model, i_SIM_slot),
          Tablet(i_brand, i_model, i_stylus_support)
    {
    }

    void display() const override
    {
        Device::display();
        cout << "Slots:" << Smartphone::getSlots() << endl;
        cout << "Stylus support:" << (Tablet::getStylus_support() ? "Yes" : "No") << endl;
    }
};

int main()
{
    HybridDevice hy("Honor", "T1008", 2, true);
    hy.display();
    return 0;
}
