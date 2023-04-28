#include <iostream>
using namespace std;


class Fraction
{
private:
    int numerator_;
    int denominator_;
    void sokr(){
        for (int i = denominator_ - 1; i > 1; i--){
            if (numerator_ == denominator_){
                numerator_ = 1;
                denominator_ = 1;
            }
            else if (((numerator_%i) == 0) and ((denominator_%i) == 0)){
                numerator_ = numerator_/i;
                denominator_ = denominator_/i;
               // cout << numerator_ << "/" << denominator_ << "\n";
            }
        }
       // Print();
       // return Fraction(numerator_, denominator_);
    }

public:
    Fraction(int numerator, int denominator)
    {
        numerator_ = numerator;
        denominator_ = denominator;
        sokr();
    }
    //возрат
    int get_num()
    {return numerator_;};
    int get_den()
    {return denominator_;};
    //сравнение
    bool operator==(Fraction other) {return get_num()*other.get_den() == other.get_num()*get_den(); }
    bool operator!=(Fraction other) { return !(get_num()*other.get_den() == other.get_num()*get_den()); }
    bool operator>(Fraction other) { return get_num()*other.get_den() > other.get_num()*get_den(); }
    bool operator<(Fraction other) { return get_num()*other.get_den() < other.get_num()*get_den(); }
    bool operator>=(Fraction other) { return (get_num()*other.get_den() >= other.get_num()*get_den()); }
    bool operator<=(Fraction other) { return (get_num()*other.get_den() <= other.get_num()*get_den()); }
    
    //
    Fraction operator+(Fraction other){
        int numerator = get_num() * other.get_den() + other.get_num() * get_den();
        int denominator = get_den() * other.get_den();
        return Fraction(numerator, denominator);
    }
    
    Fraction operator-(Fraction other){
        int numerator = get_num() * other.get_den() - other.get_num() * get_den();
        int denominator = get_den() * other.get_den();
        return Fraction(numerator, denominator);
    }
    
    Fraction operator*(Fraction other){
        int numerator = get_num() * other.get_num();
        int denominator = get_den() * other.get_den();
        return Fraction(numerator, denominator);
    }
    
    Fraction operator/(Fraction other){
        int numerator = get_num() * other.get_den();
        int denominator = get_den() * other.get_num();
        return Fraction(numerator, denominator);
    }
    
    
    Fraction& operator++() { numerator_ += denominator_; sokr(); return *this;}
    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }
    Fraction& operator--() { numerator_ -= denominator_; sokr(); return *this;}
    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }
    
    
    
    //
    void Print()
    { cout << numerator_ << "/" << denominator_; }
};

int main()
{
    int numerator_;
    int denominator_;
    cout << "Введите числитель дроби 1: ";
    cin >>numerator_;
    cout << "Введите знаменатель дроби 1: ";
    cin >>denominator_;
    Fraction f1(numerator_, denominator_);
    
    cout << "Введите числитель дроби 2: ";
    cin >>numerator_;
    cout << "Введите знаменатель дроби 2: ";
    cin >>denominator_;
    Fraction f2(numerator_, denominator_);
    
    Fraction f3 = f1 + f2;
    f1.Print();
    cout << " + ";
    f2.Print();
    cout << " = ";
    f3.Print();
    cout << endl;
    
    Fraction f4 = f1 - f2;
    f1.Print();
    cout << " - ";
    f2.Print();
    cout << " = ";
    f4.Print();
    cout << endl;
    
    Fraction f5 = f1 * f2;
    f1.Print();
    cout << " * ";
    f2.Print();
    cout << " = ";
    f5.Print();
    cout << endl;
    
    Fraction f6 = f1 / f2;
    f1.Print();
    cout << "/";
    f2.Print();
    cout << " = ";
    f6.Print();
    cout << endl;
    
    Fraction f7 = ++f1 * f2;
    cout << "++";
    f1.Print();
    cout << " * ";
    f2.Print();
    cout << " = ";
    f7.Print();
    cout << endl;
    cout << "Значение дроби 1 = ";
    f1.Print();
    cout << endl;
    
    Fraction f8 = f1-- * f2;
    f1.Print();
    cout << "--" <<" * ";
    f2.Print();
    cout << " = ";
    f8.Print();
    cout << endl;
    cout << "Значение дроби 1 = ";
    f1.Print();
    cout << endl;
    
    // ++3/4 * 4/5 = 7/5
    // Значение дроби 1 = 7/4
    // 7/4-- * 4/5 = 7/5
    // Значени дроби 1 = 3/4
    
    
    return 0;
}



