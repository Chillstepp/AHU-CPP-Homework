//Chillstep ^_^
#include "CompanyHeadFile.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{

    Company myCompany("Alibaba");
    myCompany.addDepartment("Board of Directors");
    myCompany.addDepartment("Research Unit");
    myCompany.addDepartment("Financial Office");
    myCompany.addDepartment("Product Unit");
    myCompany.addDepartment("Bussiness Unit");

    myCompany.addEmployee("Jack Ma", 20000, "Board of Directors", "CEO", PositionType::Manager);
    myCompany.addEmployee("Tony", 1000, "Product Unit", "Front End Software Development", PositionType::Developer);
    myCompany.addEmployee("Levin", 8000, "Product Unit", "User Interface Designment", PositionType::Designer);
    myCompany.addEmployee("Katty", 12000, "Research Unit", "Computer Vision Algorithm Development", PositionType::Developer);
    myCompany.addEmployee("Woods", 8000, "Bussiness Unit", "pre-saling support", PositionType::SalesPerson);
    myCompany.addEmployee("Lily", 8000, "Financial Office", "Accountant", PositionType::Manager);
 
    myCompany.getEmployee("Tony")->work();
    cout << "=======================================" << endl;
    cout << "Department Information:" << endl;
    myCompany.print();
    string name("sam");
    Employee* pStaff = myCompany.getEmployee("Sam");
    if (pStaff == nullptr)
        cout << "Cannot find " << name << endl;
    else
        pStaff->work();


    return 0;
}


