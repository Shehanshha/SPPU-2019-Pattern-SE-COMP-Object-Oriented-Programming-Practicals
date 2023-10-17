#include <iostream>
using namespace std;
class complex
{
    float x;
    float y;

public:
    complex()
    {
        x = 0;
        y = 0;
    }
    complex operator+(complex);
    complex operator*(complex);
    friend istream &operator>>(istream &input, complex &t)
    {
        cout << "Enter the real part";
        input >> t.x;
        cout << "Enter the imaginary part";
        input >> t.y;
    }
    friend ostream &operator<<(ostream &output, complex &t)
    {
        output << t.x << "+" << t.y << "i\n";
    }
};
complex complex::operator+(complex c)
{
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return (temp);
}
complex complex::operator*(complex c)
{
    complex temp2;
    temp2.x = (x * c.x) - (y * c.y);
    temp2.y = (y * c.x) + (x * c.y);
    return (temp2);
}
int main()
{
    complex c1, c2, c3, c4;
    cout << "Default constructor value=\n";
    cout << c1;
    cout << "\nEnter the 1st number\n";
    cin >> c1;
    cout << "\nEnter the 2nd number\n";
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "\nThe first number is ";
    cout << c1;
    cout << "\nThe second number is ";
    cout << c2;
    cout << "\nThe addition is ";
    cout << c3;
    cout << "\nThe multiplication is ";
    cout << c4;
    return 0;
}

/*#include<iostream>
using namespace std;

class complex
{
    float real,imag;
    
    public:
        complex()
        {
            real=0;
            imag=0;
        }
        complex operator + (complex &);
        complex operator * (complex &);
        complex(float,float);
        
        friend istream & operator>>(istream &,complex&);   
        friend ostream & operator<<(ostream &,complex&);
};

complex::complex(float x,float y)       
{
    real=x;
    imag=y;
}         
istream& operator>>(istream& qin,complex &c)
{
    cout<<"enter the real part of complex:"<<endl;
    qin>>c.real;
    cout<<"enter the imaginary part :"<<endl;
    qin>>c.imag;
    return qin;
}    
    
ostream& operator<<(ostream& qout , complex &c)
{
    cout<<c.real<<" + "<<c.imag<<"i";
    qout<<endl;
    return qout;
}

complex complex::operator+(complex &c)
{
    complex temp;
    temp.real=real + c.real;			
    temp.imag=imag + c.imag;			
    return temp;
}

complex complex::operator*(complex &c)
{
    complex mul;
    mul.real=(real*c.real) - ( imag*c.imag);
    mul.imag=(imag*c.real) + (real*c.imag);
    return mul;
}
int main()
{
    complex c1,c2,c3;     
      
    cout<<"Complex no 1 is:\n";
    cin>>c1;
    cout<<"Enter complex no 2:\n";
    cin>>c2;     
    cout<<"Complex number 1 is :";
    cout<<c1;
    cout<<"Complex number 2 is :";
    cout<<c2;
    cout<<"Value of default constructor :";
    cout<<c3;
    cout<<"\nAddition of two complex numbers is: ";
    c3=c1+c2;
    cout<<c3;
    cout<<"\nMultiplication of two complex number is: ";
    c3=c1*c2;     
    cout<<c3;       
    return 0;
}*/