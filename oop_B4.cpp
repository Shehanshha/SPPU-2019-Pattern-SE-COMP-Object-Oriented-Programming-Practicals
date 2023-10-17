#include<iostream>
#include<fstream>
using namespace std;

class employee
{
    char name[20];
    int id;
    double salary;
    public:
    void accept()
    {
        cout<<"Enter name:"<<endl;
        cin>>name;
        cout<<"Enter id:"<<endl;
        cin>>id;
        cout<<"Enter salary:"<<endl;
        cin>>salary;

    }
    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Id:"<<id<<endl;
        cout<<"Salary:"<<salary<<endl;

    }
};

int main(){
    employee o[5];
    fstream f;
    int i,n;
    f.open("Employee.txt");
    cout<<"How many employee information do you need to store:"<<endl;
    cin>>n;
    cout<<"Enter information of employee:"<<endl;

    for(i=0;i<n;i++)
    {
        cout<<"Enter information of:"<<i<<"\nemployee";
        o[i].accept();
        f.write((char*)&o[i],sizeof o[i]);

    }
    f.close();
    f.open("employee .txt",ios::in);
    cout<<"informtion of employee as follows:";
    for(i=0;i<n;i++)
    {
        f.write((char*)&o[i],sizeof o[i]);
        o[i].display();

    }
    f.close();
    return 0;
}