#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum class PositionType { Developer, Designer, SalesPerson, Manager, Accountant };

class Employee
{
protected:
    string Name;
    int JobNumber;
    float Salary;
    string Description;
    //编写默认构造函数，并把默认构造函数变为私有，不允许通过该函数构造对象
    Employee() {}
public:
    //添加一个带参数的构造函数，传入员工的姓名、工号和岗位描述。
    Employee(string _Name, int _JobNumber, string _Description) :Name(_Name), JobNumber(_JobNumber), Description(_Description) {}
    //添加拷贝构造函数
    Employee(const Employee& v) :Name(v.Name), JobNumber(v.JobNumber), Salary(v.Salary), Description(v.Description) {}
    //添加赋值操作函数operator=
    Employee& operator=(const Employee& v)
    {
        Name = v.Name;
        JobNumber = v.JobNumber;
        Salary = v.Salary;
        Description = v.Description;
        return *this;
    }
public:
    //为类的四个成员添加getter函数，getter函数为const函数
    string getter_Name()const
    {
        return Name;
    }
    int getter_JobNumber()const
    {
        return JobNumber;
    }
    string getter_Description()const
    {
        return Description;
    }
    float getter_Salary()const
    {
        return Salary;
    }
    //为薪水添加setter函数
    void setter_Salary(float _salary)
    {
        Salary = _salary;
    }
    //添加一个print函数，输出员工的姓名、工号以及所属部门名称。
    void print();
    //添加一个函数work，用于模拟员工的工作。该函数为虚函数
    virtual void work(){}
    //编写一个静态成员函数，create，用于创建一个员工对象。
    static Employee* create(string _Name, PositionType _PositionType, int _JobNumber, string _Description);
};
