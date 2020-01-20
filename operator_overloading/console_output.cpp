#include <iostream>
namespace mystd
{
using namespace std; //only use std in this space.

class ostream
{
public:
    ostream &operator<<(char *str)
    {
        printf("%s", str);
        return *this;
    }
    ostream &operator<<(char str)
    {
        printf("%c", str);
        return *this;
    }
    ostream &operator<<(int num)
    {
        printf("%d", num);
        return *this;
    }
    ostream &operator<<(double e)
    {
        printf("%g", e);
        return *this;
    }

    ostream &operator<<(ostream &(*fp)(ostream &ostm))
    {
        fp(*this); //call fp. == end_line
        return fp(*this);
    }
};

ostream &end_line(ostream &ostm)
{
    ostm << '\n';
    fflush(stdout);
    return ostm;
}

ostream console_out;

}; // namespace mystd

int main()
{
    using mystd::console_out;
    using mystd::end_line;
    /* T E S T */
    console_out << "hello world!"; //cout.operator<<(hello world!);
    console_out << end_line;

    console_out << 3.14; //cout.operator<<(3.14);
    console_out << end_line;

    console_out << 1234; //cout.operator<<(1234);
    console_out << end_line;

    console_out << 'k'; //cout.operator<<(k);
    console_out << end_line;

    console_out << "example pos:" << '[' << 3.3 << ',' << 355 << ']' << end_line;
    end_line(console_out); //flush ostream.

    return 0;
}