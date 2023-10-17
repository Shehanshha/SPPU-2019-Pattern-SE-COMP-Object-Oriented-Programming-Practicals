#include<iostream>
#include <map>
#include<string>
using namespace std;

int main(){
    typedef map<string,int>maptype;
    maptype population;
    population.insert(pair<string,int>("Maharashtra",1200));
    population.insert(pair<string,int>("karanataka",780));
    population.insert(pair<string,int>("Goa",50));
    population.insert(pair<string,int>("kerala",2110));
    population.insert(pair<string,int>("Rajastan",1500));

    maptype::iterator itr;
    /*cout<<"Size of the population:"<<population.size()<<endl;
    for(itr = population.begin();itr!=population.end();itr++)
    {
        cout<<itr->first<<":"<<itr->second<<" millon"<<endl;

    }*/
    string state;
    cout<<"Enter the state name:"<<endl;
    cin>>state;
    itr=population.find(state);
    if(itr!=population.end())
    cout<<state<<" 's population is"<<itr->second<<"millon"<<endl; 
    else{
    cout<<"key is not found in population"<<endl;
    }
    population.clear();
    return 0;
}
/*#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
typedef map<string,int> mapType;
mapType populationMap;
populationMap.insert(pair<string, int>("Maharashtra", 7026357));
populationMap.insert(pair<string, int>("Rajasthan", 6578936));
populationMap.insert(pair<string, int>("Karanataka", 6678993));
populationMap.insert(pair<string, int>("Punjab", 5789032));
populationMap.insert(pair<string, int>("West Bengal", 6676291));
mapType::iterator iter;
cout<<"========Population of states in India==========\n";
cout<<"\n Size of populationMap"<<populationMap.size()<<"\n";
string state_name;
cout<<"\n Enter name of the state :";
cin>>state_name;
iter = populationMap.find(state_name);
if( iter!= populationMap.end() )
 cout<<state_name<<" 's population is "
 <<iter->second ;
else
cout<<"Key is not populationMap"<<"\n";
populationMap.clear();
}*/




