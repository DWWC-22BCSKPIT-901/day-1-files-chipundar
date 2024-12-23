#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(string empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    virtual void calculateEarnings() = 0;

    void displayDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: $" << salary << endl;
    }
    
    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    double bonus;
    int performanceRating; 

public:
    Manager(string empName, int empId, double empSalary, int rating)
        : Employee(empName, empId, empSalary), performanceRating(rating) {
        calculateBonus();
    }

    void calculateBonus() {
        switch (performanceRating) {
            case 5: bonus = salary * 0.2; break; 
            case 4: bonus = salary * 0.15; break; 
            case 3: bonus = salary * 0.1; break;  
            default: bonus = 0; break;             
        }
    }

    void calculateEarnings() override {
        double totalEarnings = salary + bonus;
        displayDetails();
        cout << "Performance Rating: " << performanceRating << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Earnings: $" << totalEarnings << endl;
    }
};

class Developer : public Employee {
private:
    double overtimePay;
    int overtimeHours; 

public:
    Developer(string empName, int empId, double empSalary, int hoursWorked)
        : Employee(empName, empId, empSalary), overtimeHours(hoursWorked) {
        calculateOvertime();
    }

    void calculateOvertime() {
        overtimePay = overtimeHours * 20; 
    }

    void calculateEarnings() override {
        double totalEarnings = salary + overtimePay;
        displayDetails();
        cout << "Overtime Hours: " << overtimeHours << endl;
        cout << "Overtime Pay: $" << overtimePay << endl;
        cout << "Total Earnings: $" << totalEarnings << endl;
    }
};

int main() {
    string name;
    int id, rating, overtimeHours;
    double salary;

    cout << "Enter Manager details:\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Salary: $";
    cin >> salary;
    cout << "Performance Rating (1 to 5): ";
    cin >> rating;
    cin.ignore(); 

    Manager manager(name, id, salary, rating);
    manager.calculateEarnings();
    
    cout << "\nEnter Developer details:\n";
    cout << "Name: ";
    getline(cin, name);
    cout << "ID: ";
    cin >> id;
    cout << "Salary: $";
    cin >> salary;
    cout << "Overtime Hours Worked: ";
    cin >> overtimeHours;
    
    Developer developer(name, id, salary, overtimeHours);
    developer.calculateEarnings();

    return 0;
}
