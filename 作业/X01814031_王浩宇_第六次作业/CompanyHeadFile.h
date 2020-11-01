#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Department.h"
using namespace std;


class Company
{
private:
    string CompanyName;//公司名称
    vector<Department*>DepartmentList;//公司的部门对象数组
protected:
    //编写默认构造函数，并把默认构造函数变为私有，不允许通过该函数构造对象
    Company() {}
    static int NewJobNumber;//员工编号的静态变量，用于为员工分配新的编号
public:
    //编写带参数的构造函数，传入公司名称
    Company(string _CompanyName) :CompanyName(_CompanyName) {}
    //编写拷贝构造函数和赋值运算operator=
    Company& operator=(const Company& _Company)
    {
        CompanyName = _Company.CompanyName;
        DepartmentList = _Company.DepartmentList;
        NewJobNumber = _Company.NewJobNumber;
        return *this;
    }
public:
    //编写一个函数addDepartment，用于添加一个部门，传入参数为部门名称
    void addDepartment(string DptName)
    {
        DepartmentList.push_back(new Department(DptName));
    }

    //编写一个函数addEmployee，用于添加一个员工
    void addEmployee(string _EmployeeName, float _Salary, string _DepartmentName, string _Description, PositionType PosType);

    //编写一个函数print，输出公司部门信息。该函数遍历部门数组，调用部门的print函数
    void print();

    //编写一个函数getEmployee，返回指定姓名的Employee对象指针
    Employee* getEmployee(const string& name) const;

    //编写一个函数getDepartment，返回指定名称的Department对象指针
    Department* getDepartment(const string& name) const;
};
