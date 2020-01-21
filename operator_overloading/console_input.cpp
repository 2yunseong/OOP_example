#include <iostream>


class Point
{
  
    private:
    int x,y ;
    public:
        Point(int n1=0, int n2=0):x(n1), y(n2){}
    void ShowData() const;
    void ChangeX(int k)
    {
        x = k ;
    }
    void ChangeY(int l)
    {
        y = l ;
    }
};

namespace my_standard
{
	
    using namespace std;
	
    class istream
    {
        public:
        istream& operator>>(Point& pos)
        {
            int t1, t2;
            scanf("%d %d",&t1, &t2);
            pos.ChangeX(t1);
            pos.ChangeY(t2);
        }   
    };

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
istream console_in;
}

using my_standard::console_out;
using my_standard::end_line;
using my_standard::console_in;

void Point::ShowData() const
{
    console_out<<"x Pos:"<<x<<end_line;
    console_out<<"y Pos:"<<y<<end_line;
}

int main ()
{
    Point p ;
    console_in>>p;

    p.ShowData();

    return 0 ;


}