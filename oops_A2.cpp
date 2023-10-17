/*
Problem statement:
Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the
database with suitable member functions for initializing and destroying the data viz
constructor, default constructor, Copy constructor, destructor, static member functions, friend
class, this pointer, inline code and dynamic memory allocation operators-new and delete.
*/
#include <iostream>  //header file used for cin and cout
#include <string.h>  //header file for string class
using namespace std; // refer cin and cout
#define max 100;

class per_info // stud_info is friend class of per_info
{
    string lic, dob, bldgrp;

public:
    per_info();
    per_info(per_info &);
    ~per_info()
    {
        cout << "\n DESTRUCTOR CALLED!!" << endl
             << "\n RECORD DELETED SUCCESSFULLY" << endl;
    }
    friend class student;
};

class student
{
    string name, address, year;
    char div;
    int roll_no;
    long long mob;
    static int cnt;

public:
    void create(per_info &);
    void display(per_info &);

    inline static void inccnt()
    {
        cnt++;
    }
    inline static void showcnt()
    {
        cout << "\n Enter number of students:" << cnt << endl;
    }
    student();
    student(student &);
    ~student()
    {
        cout << "\n DESTRUCTOR CALLED!!" << endl
             << "\n RECORD DELETED SUCCESSFULLY" << endl;
    }
};

int student::cnt;
student::student()
{
    name = "OMKAR LATPATE";
    address = "BOYS HOSTEL , WADIA CAMPUS ,PUNE";
    year = "SE COMPUTER";
    div = 'A';
    roll_no = 43;
    mob = 8973673673;
}
per_info::per_info()
{
    lic = "ab123";
    dob = "20.07.2003";
    bldgrp = "B+";
}
student::student(student &obj)
{
    this->name = obj.name;
    this->address = obj.address;
    this->year = obj.year;
    this->div = obj.div;
    this->roll_no = obj.roll_no;
    this->mob = obj.mob;
}
per_info::per_info(per_info &obj)
{
    lic = obj.lic;
    dob = obj.dob;
    bldgrp = obj.bldgrp;
}

void student::create(per_info &obj)
{
    cout << "\n NAME" << endl;
    cin >> name;
    cout << "\n ADDRESS" << endl;
    cin >> address;
    cout << "\n DATE OF BIRTH" << endl;
    cin >> obj.dob;
    cout << "\n YEAR" << endl;
    cin >> year;
    cout << "\n DIVISION" << endl;
    cin >> div;
    cout << "\n ROLL NUMBER:" << endl;
    cin >> roll_no;
    cout << "\n BLOOD GROUP" << endl;
    cin >> obj.bldgrp;
    cout << "\n LICENSE NUMBER" << endl;
    cin >> obj.lic;
    cout << "\n PHONE NUMBER" << endl;
    cin >> mob;
    int count = 0;
    long long tmob = mob;

    while (tmob > 0)
    {
        count++;
        tmob = tmob / 10;
    }
    cout << "Total digits in mobile number are:" << count << endl;

    try
    {
        if (count == 10)
        {
            cout << "valid mobile number!" << endl;
        }
        else
        {
            throw(mob);
        }
    }
    catch (long long num)
    {
        cout << "Mobile number is incorrect" << endl;
    }
}

void student::display(per_info &obj)
{
    cout << "\n*STUDENT DATABASE*" << endl;
    cout << "\nNAME OF STUDENT : " << name << endl;
    cout << "\nADDRESS OF STUDENT : " << address << endl;
    cout << "\nDATE OF BIRTH : " << obj.dob << endl;
    cout << "\nYEAR : " << year << endl;
    cout << "\nDIVISION : " << div << endl;
    cout << "\nROLL NO : " << roll_no << endl;
    cout << "\nBLOOD GROUP : " << obj.bldgrp << endl;
    cout << "\nLICEINCE NUMBER : " << obj.lic << endl;
    cout << "\nPHONE NUMBER : " << mob << endl;
    cout << "\n*THANK-YOU*" << endl;
}

int main()
{
    int n; // COUNT OF NUMBER OF STUDENTS
    int ch;
    char ans;

    cout << "\nENTER NO OF STUDENTS :" << endl;
    cin >> n;
    cout << "\n*****" << endl;
    student *sobj = new student[n];   // NEW IS DYNAMIC MEMORY ALLOCATION OPERATOR, sobj IS POINTER OF TYPE STUDENT AND IT IS A ARRAY OF OBJECT OF SIZE n
    per_info *pobj = new per_info[n]; // NEW IS DYNAMIC MEMORY ALLOCATION OPERATOR, pobj IS POINTER OF TYPE STUDENT AND IT IS A ARRAY OF OBJECT OF SIZE n

    do
    {
        cout << "\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete (Destructor)";
        cout << "\n Enter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: // create database
        {
            for (int i = 0; i < n; i++)
            {
                sobj[i].create(pobj[i]);
                sobj[i].inccnt();
            }
        }
        break;
        case 2: // Display Database
        {
            sobj[0].showcnt(); // to display the total count of students
            // we can use any object of student class as it is static member function
            for (int i = 0; i < n; i++)
            {
                sobj[i].display(pobj[i]);
            }
        }
        break;
        case 3: // Copy Constructor
        {
            student obj1;
            per_info obj2;
            obj1.create(obj2);
            student obj3(obj1); // invoking copy constructor of student info to copy contents from object 1 to 3

            per_info obj4(obj2); // invoking copy constructor of personal info to copy contents from object 2 to 4
            cout << "\n Copy Constructor is called ";
            obj3.display(obj4);
        }
        break;
        case 4: // Default Constructor
        {
            student obj1;  // obj1 is invoking default constructor of class student
            per_info obj2; // obj2 is invoking default constructor of class personal
            cout << "\n Default Constructor is called ";
            obj1.display(obj2);
        }
        break;
        case 5: // destructor is called

            delete[] sobj; // invoking destructor and delete sobj dynamically
            delete[] pobj; // invoking destructor and delete pobj dynamically
        }                  // end of switch case
        cout << "\n Want to continue:(y/n)";
        cin >> ans;
    } while (ans == 'y');

    return 0;
}