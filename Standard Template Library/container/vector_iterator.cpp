#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    vector<int> v(5,0);
    vector<int> array ;
    deque<int> d;

    for(int i=0; i<10; i++)
    {
        v.push_back(i);
        array.push_back(i*10);
        d.push_back(i*5);
    }
    
    //++ iterator 
    vector<int>::iterator iter;
    for(iter = v.begin(); iter != v.end(); iter++)      // [begin,end)
        cout<<*iter<<endl;

    //random access iterator
    vector<int>::iterator arr_iter = array.begin();
    for(unsigned int i = 0; i<array.size(); i++)
        cout<<"array["<<i<<"]:"<<arr_iter[i]<<endl;
    
    deque<int>::iterator d_iter = d.begin()+2;
    cout<<*d_iter<<endl;
    cout<<*(d_iter-2)<<endl;
    
    vector<int> ran;
    vector<int>::iterator ran_iter = ran.begin();
    ran.push_back(5);        
    ran.push_back(55);        
    ran.push_back(10);        
    ran.push_back(5);        
    ran.push_back(4);        
    
    for(ran_iter = ran.begin(); ran_iter != ran.end(); ran_iter++)      // [begin,end)
        cout<<"ran : "<<*ran_iter<<endl;
    cout<<endl;

    //sort (basic)
    sort(ran.begin(), ran.end());
    for(ran_iter = ran.begin(); ran_iter != ran.end(); ran_iter++)      // [begin,end)
        cout<<"ran 1: "<<*ran_iter<<endl;
    cout<<endl;

    //sort greater<int>
    sort(ran.begin(), ran.end(), greater<int>());
    for(ran_iter = ran.begin(); ran_iter != ran.end(); ran_iter++)      // [begin,end)
        cout<<"ran 2: "<<*ran_iter<<endl;
        return 0;
}
