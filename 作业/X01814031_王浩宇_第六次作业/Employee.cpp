#include<iostream>
#include<vector>
#include<string>
#include "Employee.h"
#include "Position.h"
using namespace std;

void Employee::print()
{
    cout << "===========================================" << endl;
    cout << "Employee Name:" << Name << endl;
    cout << "Job Number:" << JobNumber << endl;
    cout << "Job Description:" << Description << endl;
}


Employee* Employee::create(string _Name, PositionType _PositionType, int _JobNumber, string _Description)
{
    switch (_PositionType)
    {
    case PositionType::Developer:
        return new Developer(_Name, _JobNumber, _Description);
    case PositionType::Designer:
        return new Designer(_Name, _JobNumber, _Description);
    case PositionType::SalesPerson:
        return new Salesperson(_Name, _JobNumber, _Description);
    case PositionType::Manager:
        return new Manager(_Name, _JobNumber, _Description);
    case PositionType::Accountant:
        return new Accoutant(_Name, _JobNumber, _Description);
    default:
        return new Employee(_Name, _JobNumber, _Description);
    }
}
