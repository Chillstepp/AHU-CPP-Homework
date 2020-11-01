#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Employee.h"
using namespace std;


//类Department
class Department
{
private:
    string DptName;
    vector<Employee*>EmployeeList;
protected:
    //编写默认构造函数，并把默认构造函数变为私有，不允许通过该函数构造对象
    Department() {}
public:
    //添加一个带参数的构造函数，传入部门名称
    Department(string _DptName) :DptName(_DptName) {}
    //添加拷贝构造函数
    Department(const Department& Dpt) :DptName(Dpt.DptName), EmployeeList(Dpt.EmployeeList) {}
    //添加赋值操作函数operator
    Department& operator=(const Department& Dpt)
    {
        DptName = Dpt.DptName;
        EmployeeList = Dpt.EmployeeList;
        return *this;
    }
public:
    //获得部门名
    string getter_DptName() const { return DptName; }
    //编写一个print函数，输出部门的名称、员工数目以及每一个员工的信息
    void print();
    //编写一个函数addEmployee，为该部门添加一位员工。参数为Employee对象指针
    void addEmployee(Employee* _Employee);
    //编写一个函数removeEmployee，删除指定工号的员工
    void removeEmployee(int JobNum);
    //编写一个函数getEmployee，返回指定姓名的Employee对象指针
    Employee* getEmployee(const string& name) const;
};
