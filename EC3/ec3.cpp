#include<iostream>
#include<string>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accountNumber, string accountHolder, double balance)
         : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

    virtual void displayDetails() {
        cout << "   Holder: " << accountHolder << "\n"
             << "   Balance: $" << balance << "\n";
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    double getBalance() {
        return balance;
    }

    void setBalance(double amount) {
        balance = amount;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accountNumber, string accountHolder, double balance, double interestRate)
         : Account(accountNumber, accountHolder, balance), interestRate(interestRate) {}

    void displayDetails() override {
        cout << "Account Details for Savings Account (ID: " << accountNumber << "):\n";
        Account::displayDetails();
        cout << "   Interest Rate: " << interestRate*100 << "%\n\n";
    }

    void withdraw(double amount) override {
        if (balance - amount >= 500)
            balance -= amount;
        else
            cout << "Minimum balance should be maintained\n";
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accountNumber, string accountHolder, double balance, double overdraftLimit)
         : Account(accountNumber, accountHolder, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails() override {
        cout << "Account Details for Current Account (ID: " << accountNumber << "):\n";
        Account::displayDetails();
        cout << "   Overdraft Limit: $" << overdraftLimit << "\n\n";
    }

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit)
            balance -= amount;
        else
            cout << "Overdraft limit exceeded\n";
    }
};

CurrentAccount operator+(CurrentAccount& c, SavingsAccount& s){
    double transferAmount = 300;
    double savingsBalance = s.getBalance();
    double currentBalance = c.getBalance();

    if(savingsBalance >= transferAmount){
        s.setBalance(savingsBalance - transferAmount);
        c.setBalance(currentBalance + transferAmount);
    }else{
        cout<<"Insufficient balance in savings account for transfer\n";
    }

    return c;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    cout << "Account Details after deposit and withdrawal:\n";
    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    current = current + savings;

    cout << "Account Details after transfer:\n";
    savings.displayDetails();
    current.displayDetails();

    return 0;
}
