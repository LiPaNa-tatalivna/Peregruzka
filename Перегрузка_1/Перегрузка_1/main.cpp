#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
    }
    
    int get_num(){return numerator_;};
    int get_den(){return denominator_;};
    
    bool operator==(Fraction other) {return get_num()*other.get_den() == other.get_num()*get_den(); }
    bool operator!=(Fraction other) { return !(get_num()*other.get_den() == other.get_num()*get_den()); }
    bool operator>(Fraction other) { return get_num()*other.get_den() > other.get_num()*get_den(); }
    bool operator<(Fraction other) { return get_num()*other.get_den() < other.get_num()*get_den(); }
    bool operator>=(Fraction other) { return (get_num()*other.get_den() >= other.get_num()*get_den()); }
    bool operator<=(Fraction other) { return (get_num()*other.get_den() <= other.get_num()*get_den()); }
};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
    return 0;
}
