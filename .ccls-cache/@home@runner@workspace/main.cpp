#include <iostream>
#include <string> 
using namespace std;

#include <iostream>
#include <string> 
using namespace std;
// Base class
class Employee {
protected:
    string name;
    string employeeNumber;
    string hireDate;

public:
// Constructor
    Employee(string n = "", string num = "", string date = "") : name(n), employeeNumber(num), hireDate(date) {}
// Accessor and Mutator functions
string getName() const { return name; }
string getEmployeeNumber() const { return employeeNumber; }
string getHireDate() const { return hireDate; }
// Mutator functions
void setName(string n) { name = n; }
void setEmployeeNumber(string num) { employeeNumber = num; }
void setHireDate(string date) { hireDate = date; }
// Print function
void printEmployee() const {
    cout << "Name: " << name << endl;
    cout << "Employee Number: " << employeeNumber << endl;
    cout << "Hire Date: " << hireDate << endl;
  }
};
// Derived class
class ProductionWorker : public Employee {
protected:
    int shift;
    double hourlyPayRate;
// Constructor
public:
    ProductionWorker(string n = "", string num = "", string date = "", int s = 0, double pay = 0.0) : Employee(n, num, date), shift(s), hourlyPayRate(pay) {}
// Accessor and Mutator functions
int getShift() const { return shift; }
double getHourlyPayRate() const { return hourlyPayRate; }
// Mutator functions
void setShift(int s) { shift = s; }
void setHourlyPayRate(double pay) { hourlyPayRate = pay; }
// Print function
void printProductionWorker() const {
    printEmployee();
    cout << "Shift: " << (shift == 1 ? "Day" : "Night") << "\nHourly Pay Rate: $" << hourlyPayRate << endl;
  }
};

class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor(string n = "", string num = "", string date = "", double salary = 0.0, double bonus = 0.0) : Employee(n, num, date), annualSalary(salary), annualBonus(bonus) {}

double getAnnualSalary() const { return annualSalary; }
double getAnnualBonus() const { return annualBonus; }

void setAnnualSalary(double salary) { annualSalary = salary; }
void setAnnualBonus(double bonus) { annualBonus = bonus; }

void printShiftSupervisor() const {
    printEmployee();
    cout << "Annual Salary: $" << annualSalary << "\nAnnual Bonus: $" << annualBonus << endl;
  }
};

class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    TeamLeader(string n = "", string num = "", string date = "", int s = 0, double pay = 0.0, double bonus = 0.0, int reqHours = 0, int attHours = 0) : ProductionWorker(n, num, date, s, pay), monthlyBonus(bonus), requiredTrainingHours(reqHours), attendedTrainingHours(attHours) {}

double getMonthlyBonus() const { return monthlyBonus; }
int getRequiredTrainingHours() const { return requiredTrainingHours; }
int getAttendedTrainingHours() const { return attendedTrainingHours; }

void setMonthlyBonus(double bonus) { monthlyBonus = bonus; }
void setRequiredTrainingHours(int reqHours) { requiredTrainingHours = reqHours; }
void setAttendedTrainingHours(int attHours) { attendedTrainingHours = attHours; }

void printTeamLeader() const {
     printProductionWorker();
    cout << "Monthly Bonus: $" << monthlyBonus << "\nRequired Training Hours: " << requiredTrainingHours << "\nAttended Training Hours: " << attendedTrainingHours << endl;
  }
};

int main() {
    ProductionWorker worker1 ("John Doe", "12345", "01/02/2022", 1, 25.50);
    ProductionWorker worker2 ("Jane Smith", "67890", "03/04/2021", 2, 27.75);
    cout << "Production Worker 1:\n";
    worker1.printProductionWorker();
    cout << "\nProduction Worker 2:\n";
    worker2.printProductionWorker();

    ShiftSupervisor supervisor1 ("Alice Johnson", "54321", "07/08/2018", 60000, 5000); 
    cout << "\nShift Supervisor:\n";
    supervisor1.printShiftSupervisor();

    TeamLeader teamLeader("Mike Brown", "99887", "11/12/2019", 1, 30.00, 1000, 40, 32);
    cout << "\nTeam Leader:\n";
    teamLeader.printTeamLeader(); 

    return 0;
} 
