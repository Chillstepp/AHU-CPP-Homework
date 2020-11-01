#include<iostream>
#include<vector>
#include<string>
#include "CompanyHeadFile.h"
using namespace std;

int Company::NewJobNumber = 0;
//编写一个函数addEmployee，用于添加一个员工
void Company::addEmployee(string _EmployeeName, float _Salary, string _DptName, string _Description, PositionType PosType)
{
    Employee _Employee(_EmployeeName, NewJobNumber, _Description);
    Employee* tep = _Employee.create(_EmployeeName, PosType, ++NewJobNumber, _Description);
    tep->setter_Salary(_Salary);
    for (auto d : DepartmentList)
    {
        if (d->getter_DptName() == _DptName)
        {
            d->addEmployee(tep);
        }
    }
}


//编写一个函数print，输出公司部门信息。该函数遍历部门数组，调用部门的print函数
void Company::print()
{
    for (auto d : DepartmentList)
    {
        cout << "==================================" << endl;
        d->print();
    }
}


//编写一个函数getEmployee，返回指定姓名的Employee对象指针
Employee* Company::getEmployee(const string& name) const
{
    for (size_t i = 0; i < DepartmentList.size(); i++)
    {
        if (DepartmentList[i]->getEmployee(name) != nullptr)
        {
            return DepartmentList[i]->getEmployee(name);
        }
    }
    return nullptr;
}

//编写一个函数getDepartment，返回指定名称的Department对象指针
Department* Company::getDepartment(const string& name) const
{
    for (size_t i = 0; i < DepartmentList.size(); i++)
    {
        if (DepartmentList[i]->getter_DptName()==name)
        {
            return DepartmentList[i];
        }
    }
    return nullptr;
}
