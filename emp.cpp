#include <iostream>
#include <limits>

#define BONUS_FOR_RATING 0.1
#define OVERTIME_RATE 500
#define MIN_RATING 1
#define MAX_RATING 5

using namespace std;
typedef unsigned int uint;

class Employee {
protected:
    uint Emp_Id;
    string Emp_Name;
    uint Emp_Salary;

public:
    Employee(uint Emp_Id, string& Emp_Name, uint Emp_Salary) {
        this->Emp_Id = Emp_Id;
        this->Emp_Name = Emp_Name;
        this->Emp_Salary = Emp_Salary;
    }

    virtual void Display_Employee() = 0; // Pure virtual function
    virtual ~Employee() = default;      // Virtual destructor
};

class Manager : public Employee {
private:
    uint Rating;
    float Bonus;

public:
    Manager(uint Emp_Id, string& Emp_Name, uint Emp_Salary, uint Rating)
        : Employee(Emp_Id, Emp_Name, Emp_Salary) {
        if (Rating < MIN_RATING || Rating > MAX_RATING) {
            this->Rating = 1; // Default rating if out of range
        } else {
            this->Rating = Rating;
        }
        this->Bonus = this->Emp_Salary * this->Rating * BONUS_FOR_RATING;
    }

    void Display_Employee() override {
        cout << "Name   : " << this->Emp_Name << endl
             << "ID     : " << this->Emp_Id << endl
             << "Salary : " << this->Emp_Salary << endl
             << "Bonus  : " << this->Bonus << endl
             << "Total  : " << this->Emp_Salary + this->Bonus << endl;
    }
};

class Developer : public Employee {
private:
    uint Overtime_Hours;
    uint Overtime_Compensation;

public:
    Developer(uint Emp_Id, string& Emp_Name, uint Emp_Salary, uint Overtime_Hours)
        : Employee(Emp_Id, Emp_Name, Emp_Salary) {
        this->Overtime_Hours = Overtime_Hours;
        this->Overtime_Compensation = this->Overtime_Hours * OVERTIME_RATE;
    }

    void Display_Employee() override {
        cout << "Name                  : " << this->Emp_Name << endl
             << "ID                    : " << this->Emp_Id << endl
             << "Salary                : " << this->Emp_Salary << endl
             << "Overtime Compensation : " << this->Overtime_Compensation << endl
             << "Total                 : " << this->Emp_Salary + this->Overtime_Compensation << endl;
    }
};

int main() {
    int n = 0;
    uint id = 1; // Default ID for demonstration purposes
    uint salary = 0;
    uint rating = 0;
    uint ot_hrs = 0;
    string Name;

    cout << "Enter 1 for Manager or 2 for Developer: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    switch (n) {
    case 1: {
        cout << "Name: ";
        getline(cin, Name);
        cout << "Salary: ";
        cin >> salary;
        cout << "Rating (1 - 5): ";
        cin >> rating;

        Manager mgr(id, Name, salary, rating);
        mgr.Display_Employee();
        break;
    }

    case 2: {
        cout << "Name: ";
        getline(cin, Name);
        cout << "Salary: ";
        cin >> salary;
        cout << "Overtime Hours: ";
        cin >> ot_hrs;

        Developer dev(id, Name, salary, ot_hrs);
        dev.Display_Employee();
        break;
    }

    default:
        cout << "Invalid Choice!" << endl;
    }

    return 0;
}
