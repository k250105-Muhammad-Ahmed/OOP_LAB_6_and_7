#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNo, string holder, double bal, string type = "General") : accountNumber(accNo), accountHolderName(holder), balance(bal), accountType(type) {}

    virtual void deposit(double amount)
    {
        balance += amount;
    }

    virtual bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
            return false;
        }
        balance -= amount;
        return true;
    }

    virtual double calculateInterest() = 0;

    virtual void printStatement()
    {
        cout << "Account Statement for " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo()
    {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, string holder, double bal, double rate, double minBal)
        : Account(accNo, holder, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override
    {
        return balance * interestRate;
    }

    bool withdraw(double amount) override
    {
        if (balance - amount < minimumBalance)
        {
            cout << "Withdrawal denied. Minimum balance requirement not met." << endl;
            return false;
        }
        return Account::withdraw(amount);
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class CheckingAccount : public Account
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string holder, double bal, double overdraft)
        : Account(accNo, holder, bal, "Checking"), overdraftLimit(overdraft) {}

    double calculateInterest() override
    {
        return 0.0;
    }

    bool withdraw(double amount) override
    {
        if (amount > balance + overdraftLimit)
        {
            cout << "Withdrawal denied. Overdraft limit exceeded.\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int accNo, string holder, double bal, double rate, string maturity)
        : Account(accNo, holder, bal, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() override
    {
        return balance * fixedInterestRate;
    }

    bool withdraw(double amount) override
    {
        cout << "Withdrawals not allowed before maturity date: " << maturityDate << endl;
        return false;
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main()
{
    SavingsAccount savings(1001, "Ali", 5000.0, 0.03, 1000.0);
    CheckingAccount checking(1002, "Salman", 2000.0, 500.0);
    FixedDepositAccount fixed(1003, "Moiz", 10000.0, 0.05, "2027-03-10");

    cout << "\nSavings Account Transactions\n";
    savings.deposit(1000);
    savings.withdraw(4500);
    savings.getAccountInfo();
    cout << "Interest: " << savings.calculateInterest() << endl;
    savings.printStatement();

    cout << "\nChecking Account Transactions\n";
    checking.withdraw(2200);
    checking.deposit(500);
    checking.getAccountInfo();
    cout << "Interest: " << checking.calculateInterest() << endl;
    checking.printStatement();

    cout << "\nFixed Deposit Account Transactions\n";
    fixed.withdraw(2000);
    fixed.getAccountInfo();
    cout << "Interest: " << fixed.calculateInterest() << endl;
    fixed.printStatement();

    return 0;
}
