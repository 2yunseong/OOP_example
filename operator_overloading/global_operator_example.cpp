#include <iostream>
using namespace std;

class Data
{
private:
    int x, y;

public:
    Data(int v1 = 0, int v2 = 0) : x(v1), y(v2) {}

    void ShowData() const
    {
        cout << "Data:" << x << endl;
        cout << "Data:" << y << endl;
    }
    Data &operator=(const Data &ref) //assignment operator(only)
    {
        //  must overload operator= to member function.
        //  and it allow right associative.(primitive type)
        //  and operator chaining too.

        if (this == &ref) //if Same object?
            return *this; //just return itself(this).

        //must check self-assignment.
        //if not check self-assignment, it make a series of problem.
        // in main function, declared class 'Data dt'
        //and then, 'dt = dt'(this '' code maybe make a problem.)
        //that's why we check self- assignment.

        x = ref.x;
        y = ref.y;
        return *this;

    } //Q. what is non_static_member_function?

    Data &operator+=(const Data &ref) //compound assignment operators
    {
        //return type Data& can write that
        //for example, (class+=3)+=5
        x += ref.x;
        x += ref.y;
        return *this;
    } //hw.make -=, *=.

    const Data operator+(const Data &ref) const //binary arithmetic operators
    {
        //use compound assignment operator!
        Data copy = *this; //same as Data copy(*this);
        copy += ref;
        return result;
    }
};

int main()
{
    Data dt1(2, 2);
    Data dt2(3, 3);

    dt1 = dt2; //same as dt1.operator=(dt2);
}
