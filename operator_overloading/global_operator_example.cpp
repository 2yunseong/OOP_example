#include <iostream>
using namespace std;
/*
1.compound assignment operator +=, -=, *= ...
2.binary arithmatic operator +,-,* ... and so on
*/
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

    /**
         *   must overload operator= to member function.
         * because This operator makes sense if you target with the object.
         *  and it allow right associative.(primitive type)
         *  and operator chaining too.
         */

    /**
        * must check self-assignment.
        * if not check self-assignment, it make a series of problem.
        * in main function, declared class 'Data dt'
        *and then, 'dt = dt'(this '' code maybe make a problem.)
        *that's why we check self- assignment.
        */

    Data &operator=(const Data &ref) //assignment operator(only)
    {
        if (this == &ref) //if Same object?
            return *this; //just return itself(this).

        x = ref.x;
        y = ref.y;
        return *this;

    } //Q. what is non_static_member_function?

    Data &operator+=(const Data &ref) //compound assignment operators
    {
        /**
        * return type Data& can write that
        * for example, (class+=3)+=5
        */

        x += ref.x;
        x += ref.y;
        return *this;

    } //hw.make -=, *=.

    const Data operator+(const Data &other) const //binary arithmetic operators
    {
        //1. return const type: return const Data value.
        //use compound assignment operator!

        Data copy = *this; //make copy object :: this code same as Data copy(*this);
        copy += other;     //now, plus other object on copy. use previous function,(+=) the code are Shorten.
        return copy;
    }
    /* p r e f i x o p e r a t o r */

    Data &operator++() //prefix increment operator.(in book.)
    {
        x += 1;
        y += 1;
        return *this;
    }

    Data &operator--() //prefix decrement operator.(in myhead.) (in the book, this function declared on global scope.)
    {
        x -= 1;
        y -= 1;
        return *this;
    }
};

int main()
{
    Data dt1(2, 2);
    Data dt2(3, 3);

    dt1 = dt2; //same as dt1.operator=(dt2);
}
