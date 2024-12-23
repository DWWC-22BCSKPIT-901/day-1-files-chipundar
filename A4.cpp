#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}

    virtual void calculateInterest() = 0;

    double getBalance() {
        return balance;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate; 
    double timePeriod;   
public:
    SavingsAccount(double initialBalance, double rate, double time)
        : Account(initialBalance), interestRate(rate), timePeriod(time) {}

    void calculateInterest() override {
        double interest = balance * interestRate * timePeriod;
        balance += interest; 
        cout << "Interest added to Savings Account: " << interest << endl;
    }
};

class CurrentAccount : public Account {
private:
    double maintenanceFee; 
public:
    CurrentAccount(double initialBalance, double fee)
        : Account(initialBalance), maintenanceFee(fee) {}

    void calculateInterest() override {
        if (balance >= maintenanceFee) {
            balance -= maintenanceFee; 
            cout << "Maintenance fee of " << maintenanceFee << " deducted from Current Account." << endl;
        } else {
            cout << "Insufficient balance for maintenance fee deduction." << endl;
        }
    }
};

int main() {
    SavingsAccount savings(1000.0, 0.05, 1);  
    CurrentAccount current(500.0, 20.0);       

    cout << "Initial Balance of Savings Account: " << savings.getBalance() << endl;
    savings.calculateInterest(); 
    cout << "New Balance of Savings Account: " << savings.getBalance() << endl;

    cout << "Initial Balance of Current Account: " << current.getBalance() << endl;
    current.calculateInterest(); 
    cout << "New Balance of Current Account: " << current.getBalance() << endl;

    return 0;
}
