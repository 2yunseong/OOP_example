#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	
	for(int i=0; i<100; i++)
	{
		cout<<"저장 전:"<<v.capacity()<<endl;
		v.push_back(i);
		cout<<i+1<<"개 저장:"<<v.capacity()<<endl;
	}
}
