#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vData;        //declare vector.: vector<type> name
    vector<int> vData2(5);    // declare & initialize. value = 0, array length = 5 . [0][0][0][0][0]
    vector<int> vData3(5, 2); // vector<type> name(length, initial_value) [2][2][2][2][2]

    vector<int> copy(vData3); //copy vData3.

    cout << "show copy(vData3) use v.at(idx)" << endl;
    for (int i = 0; i < 5; i++)
        cout << "copy[" << i + 1 << "]:" << copy.at(i) << endl;
    cout << "show vData2 use v[idx]" << endl;
    for (int i = 0; i < 5; i++)
        cout << "vData2[" << i + 1 << "]:" << vData2[i] << endl;

    vData2.front() = 11; //reference and change!
    cout << "reference first data(get change) in vData2:" << vData2.front() << endl;
    vData2.back() = 55;
    cout << "reference last data(get change) in vData2:" << vData2.back() << endl;

    return 0;
}
