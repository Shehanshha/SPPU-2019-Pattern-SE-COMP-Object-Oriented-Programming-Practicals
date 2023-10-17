#include<iostream>
using namespace std;
#define size 20
int n;
template<typename T>T selection(T a[10])
{
    int i,j;
    T temp;
    for(i = 0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<"After sorting is :"<<a[i]<<endl;

    }

    
}

int main(){
    int i;
    int a[size];
    float b[size];
    cout<<"how many integer:"<<endl;
    cin>>n;
    cout<<"Enter the values: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selection(a);
    cout<<"how many floats:"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    selection(b);
    return 0;
}
/*#include<iostream>
using namespace std;
#define size 20 
int n;
template<typename T> T selection(T a[10])
{ int i,j;
  T temp ;
  for(i=0;i<n;i++)
  {  
     for(j=i+1;j<n;j++)
     {
         if(a[j]<=a[i])
         { temp=a[i];
        a[i]=a[j];
        a[j]=temp;
         }
         
     }
   
  }

for(i=0;i<n;i++)
{
  cout<<"\n after sorting is"<<a[i];
}
}

int main()
{
 int i;
 int a[size];
 float b[size];
 cout<<"how many integer";
 
 cin>>n;
 cout<<"how many floats";
 cout<<"enter the values";
 for(i=0;i<n;i++)
 {
 cin>>b[i];
 }
 selection(b);
 cout<<"\n\n";



return 0;
}*/