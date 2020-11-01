#include<iostream>
#include<vector>
#include<string>
#include"Department.h"
using namespace std;


void Department::print()
{
    cout << "Department Name:" << DptName << endl;
    cout << "Employee Ammount:" << EmployeeList.size() << endl;
    cout << "Employee List:" << endl;
    for (auto e : EmployeeList)
    {
        cout << "Employee Name:" << e->getter_Name() << "   Job Number:" << e->getter_JobNumber() <<
            "   Salary:" << e->getter_Salary() << "   Job Description:" << e->getter_Description() << endl;
    }
}

void Department::addEmployee(Employee* _Employee)
{
    EmployeeList.push_back(_Employee);
}
//编写一个函数removeEmployee，删除指定工号的员工
void Department::removeEmployee(int JobNum)
{
    for (size_t i = 0; i < EmployeeList.size(); i++)
    {
        if (EmployeeList[i]->getter_JobNumber() == JobNum)
            EmployeeList.erase(EmployeeList.begin() + i);
    }
}
//编写一个函数getEmployee，返回指定姓名的Employee对象指针
Employee* Department::getEmployee(const string& name) const
{
    for (size_t i = 0; i < EmployeeList.size(); i++)
    {
        if (EmployeeList[i]->getter_Name() == name)
        {
            return EmployeeList[i];
        }
    }
    return nullptr;
}
