#include<iostream>
using namespace std;

class Fraction{

    private:
        int numerator;
        int denominator;

    public:
        Fraction(int numerator, int denominator){
            this -> numerator = numerator;
            this -> denominator = denominator;
        }
        void print(){
            cout << this -> numerator << "/" << this -> denominator << endl;
        }

        void simplify(){
            int gcd = 1;
            int j = min(this -> numerator,this -> denominator);
            for(int i=1;i<=j;i++){
                if( this -> numerator % i==0 && this -> denominator % i ==0){
                    gcd = i;
                }
            }
            this -> numerator = this -> numerator / gcd;
            this -> denominator = this -> denominator / gcd;
        }
        Fraction add(Fraction const &f2){
            int lcm = this -> denominator * (f2.denominator);
            int x = lcm/ this -> denominator;
            int y = lcm/f2.denominator;
            int num = x *  this -> numerator + y * (f2.numerator);
            //numerator = num;
            //denominator = lcm;
            Fraction f3(num,lcm); 
            f3.simplify();
            return f3; 
        }
        Fraction operator+ (Fraction const &f2){
            int lcm = this -> denominator * (f2.denominator);
            int x = lcm/ this -> denominator;
            int y = lcm/f2.denominator;
            int num = x *  this -> numerator + y * (f2.numerator);
            //numerator = num;
            //denominator = lcm;
            Fraction f3(num,lcm); 
            f3.simplify();
            return f3; 
        }
        void multiply(Fraction const &f2){
            numerator = this -> numerator * (f2.numerator);
            denominator = this -> denominator * (f2.denominator);
            simplify();
        }

        Fraction operator* (Fraction const &f2){
            int num = this -> numerator * (f2.numerator);
            int den = this -> denominator * (f2.denominator);
            Fraction fnew(num,den);
            fnew.simplify();
            return fnew;

        }

        bool operator==(Fraction const &f2){
            return (this-> numerator == f2.numerator && this -> denominator == f2.denominator);
        }

        Fraction& operator++(){
            this -> numerator = this -> numerator + this -> denominator;
            simplify();
            return *this;
        }
        Fraction operator++(int){
            Fraction fnew(numerator,denominator);
            numerator = numerator + denominator;
            simplify();
            return fnew;
        }


};



int main(){
    Fraction f1(10,2);
    Fraction f2 = ++(++f1);
    f1.print();
    f2.print();`
}