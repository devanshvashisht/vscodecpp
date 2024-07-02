#include<iostream>
#include<cmath>
#define PI 3.1415

using namespace std;

class Circle{
    
    int radius;
    public:
        


        Circle (int r){
            this -> radius = r;
        }

        Circle(Circle const & c){
            this -> radius = c.radius;
        }
        double area(int r){
            double area =  PI * pow(radius,2);
            return area;
        }
};

int main(){
    int r ;
    cout << "enter the radius" << endl;
    cin >> r;

    Circle c1(r);
    double ans = c1.area(r);
    cout << ans;
}
