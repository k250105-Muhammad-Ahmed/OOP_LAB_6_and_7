#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRateToBase;

public:
    Currency(double amt, string code, string sym, double rate)
        : amount(amt), currencyCode(code), currencySymbol(sym), exchangeRateToBase(rate) {}

    virtual double convertToBase() const
    {
        return amount * exchangeRateToBase;
    }

    double convertTo(const Currency &target) const
    {
        double baseValue = this->convertToBase();
        return baseValue / target.exchangeRateToBase;
    }

    virtual void displayCurrency() const = 0;
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() const override
    {
        cout << "US Format: " << currencySymbol << fixed << setprecision(2) << amount << endl;
    }
};
class Euro : public Currency
{
public:
    Euro(double amt, double rate = 1.16) : Currency(amt, "EUR", "€", rate) {}

    void displayCurrency() const override
    {
        cout << "EU Format: " << fixed << setprecision(2) << amount << " " << currencySymbol << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt, double rate = 0.0036) : Currency(amt, "PKR", "Rs", rate) {}

    void displayCurrency() const override
    {
        cout << "PAK Format: " << currencySymbol << fixed << setprecision(2) << amount << endl;
    }
};

int main()
{
    Euro myEuros(100.0, 1.16);
    Dollar myDollars(0.0);
    Rupee myRupees(5000.0, 0.0036);

    cout << "\nOriginal Balances" << endl;
    myEuros.displayCurrency();
    myRupees.displayCurrency();

    cout << "\nConversion Results" << endl;
    double convertedValue = myEuros.convertTo(myDollars);
    cout << "100 Euro in USD: $" << convertedValue << endl;

    double inrToEur = myRupees.convertTo(myEuros);
    cout << "5000 PKR in Euro: " << inrToEur << " €" << endl;

    return 0;
}