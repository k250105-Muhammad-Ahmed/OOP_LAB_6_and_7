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
    Account(int accNo, string holder, double bal, string type = "General")
        : accountNumber(accNo), accountHolderName(holder), balance(bal), accountType(type) {}

    virtual void deposit(double amount)
    {
        balance += amount;
    }

    virtual bool withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds.\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    virtual double calculateInterest() = 0;

    virtual void printStatement()
    {
        cout << "Account Statement for " << accountHolderName << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }

    void getAccountInfo()
    {
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Type: " << accountType << "\n";
        cout << "Balance: " << balance << "\n";
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
            cout << "Withdrawal denied. Minimum balance requirement not met.\n";
            return false;
        }
        return Account::withdraw(amount);
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "\n";
        cout << "Minimum Balance: " << minimumBalance << "\n";
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
            std::cout << "Withdrawal denied. Overdraft limit exceeded.\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    void printStatement() override
    {
        Account::printStatement();
        cout << "Overdraft Limit: " << overdraftLimit << "\n";
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    std::string maturityDate;

public:
    FixedDepositAccount(int accNo, std::string holder, double bal, double rate, std::string maturity)
        : Account(accNo, holder, bal, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() override
    {
        return balance * fixedInterestRate;
    }

    bool withdraw(double amount) override
    {
        std::cout << "Withdrawals not allowed before maturity date: " << maturityDate << "\n";
        return false;
    }

    void printStatement() override
    {
        Account::printStatement();
        std::cout << "Fixed Interest Rate: " << fixedInterestRate << "\n";
        std::cout << "Maturity Date: " << maturityDate << "\n";
    }
};

int main()
{
    SavingsAccount savings(1001, "Alice", 5000.0, 0.03, 1000.0);
    CheckingAccount checking(1002, "Bob", 2000.0, 500.0);
    FixedDepositAccount fixed(1003, "Charlie", 10000.0, 0.05, "2027-03-10");

    cout << "\nSavings Account Transactions\n";
    savings.deposit(1000);
    savings.withdraw(4500);
    savings.getAccountInfo();
    cout << "Interest: " << savings.calculateInterest() << "\n";
    savings.printStatement();

    cout << "\nChecking Account Transactions\n";
    checking.withdraw(2200);
    checking.deposit(500);
    checking.getAccountInfo();
    cout << "Interest: " << checking.calculateInterest() << "\n";
    checking.printStatement();

    cout << "\nFixed Deposit Account Transactions\n";
    fixed.withdraw(2000);
    fixed.getAccountInfo();
    cout << "Interest: " << fixed.calculateInterest() << "\n";
    fixed.printStatement();

    return 0;
}
