#include<iostream>
using namespace std;

class Complex{
    private:
        int real;
        int imaginary;

    public:

        Complex(int real , int imaginary){
            this -> real = real;
            this -> imaginary = imaginary;
        }

        void print(){
            cout << this -> real << "+" << this -> imaginary << "i" << endl;
        }
};


int main{
    Complex c1(3,4)
}