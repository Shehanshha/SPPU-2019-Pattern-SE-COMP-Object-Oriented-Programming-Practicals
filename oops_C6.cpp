#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class record
{
public:
    string name, dob, phone;
    void get();
    void display();
    bool operator<(const record &stud)
    {
        return name < stud.name;
    }
    friend bool operator==(const record &r1, const record &r2)
    {
        if (r1.name == r2.name || r1.dob == r2.dob || r1.phone == r2.phone)
        {
            return true;
        }
        return false;
    }
};
void record ::get()
{
    cout << "Enter the name: " << endl;
    cin >> name;
    cout << "Enter the date of bitrh :" << endl;
    cin >> dob;
    cout << "Enter the phone number :" << endl;
    cin >> phone;
}
void record ::display()
{
    cout << name << "\t" << dob << "\t" << phone << endl;
}
class record_list
{
private:
    vector<record> myrecords;

public:
    void get();
    void display();
    void search(string data);
    void sort();
};
void record_list::get()
{
    int count;
    cout << "Enter the numbers of member in records: " << endl;
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        record myrec;
        myrec.get();
        myrecords.push_back(myrec);
    }
}
void record_list::display()
{
    for (vector<record>::iterator itr = myrecords.begin(); itr != myrecords.end(); itr++)
    {
        itr->display();
    }
}
void record_list ::search(string data)
{
    record stud;
    stud.name = data;
    stud.dob = data;
    stud.phone = data;
    vector<record>::iterator itr = find(myrecords.begin(), myrecords.end(), stud);
    if (itr != myrecords.end())
    {
        cout << "Record found!" << endl;
        itr->display();
    }
    else
    {
        cout << "record not found" << endl;
    }
}
void record_list ::sort()
{
    std::sort(myrecords.begin(), myrecords.end());
}
int main()
{
    record_list obj;
    string key;
    int ch;
    char choice;

    do
    {
        cout << "\n1.Enter details\n2.Display\n3.search\n4.Sort records\n5.Enter choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.get();
            obj.display();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "Enter data which is you find:" << endl;
            cin >> key;
            obj.search(key);
            break;
        case 4:
            obj.sort();
            obj.display();
            break;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue enter(y/n): " << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}