#include<iostream>
using namespace std;

class Polynomial{
    
    public:
        int * degCoeff;
        int capacity;


    

        Polynomial(){
            this -> degCoeff = new int[6];
            this -> capacity = 5;
            for(int i=0;i<=capacity;i++){
                degCoeff[i] = 0;
            }
        }
        Polynomial(int capacity){
            this -> degCoeff = new int[capacity+1];
            this -> capacity = capacity;
            for(int i=0;i<=capacity;i++){
                degCoeff[i] = 0;
            }
        }
        Polynomial(Polynomial const &p){
            this -> degCoeff = new int [p.capacity+1];
            for(int i=0;i<=capacity;i++){
                this -> degCoeff[i] = p.degCoeff[i];
            }
            this -> capacity = p.capacity;
            
        }

        void operator=(Polynomial const & p){
            this -> degCoeff = new int [p.capacity+1];
            for(int i=0;i<=capacity;i++){
                this -> degCoeff[i] = p.degCoeff[i];
            }
            this -> capacity = p.capacity;
        }

        void setCoefficient(int degree, int coefficient){
            if(degree>capacity){
                int newcap = degree;
                int * arr= new int[newcap+1];
                for(int i=0;i<=capacity;i++){
                    arr[i] = degCoeff[i];
                }
                this -> degCoeff = arr;
                this -> capacity = newcap;
            }else{
                degCoeff[degree] = coefficient;
            }
        }


        void print(){
            for(int i=0;i<capacity;i++){
                if(degCoeff[i]!=0){
                    cout << degCoeff[i] << "x" << i << " ";
                }
            }
        }
        Polynomial operator+ (Polynomial const & p2){
            int newcap = max(this -> capacity, p2.capacity);
            Polynomial p3(newcap);

            for(int i=0;i<=newcap;i++){
                if(i<=capacity && i<=p2.capacity){
                    int ans = this -> degCoeff[i] + p2.degCoeff[i];
                    p3.setCoefficient(i,ans);
                }else if(i<=capacity){
                    p3.degCoeff[i] = this -> degCoeff[i];
                }else{
                    p3.degCoeff[i] = p2.degCoeff[i];
                }
            }
            return p3;
        }

        Polynomial operator- (Polynomial const &p2){
            int newcap = max(this -> capacity, p2.capacity);
            Polynomial p3(newcap);

            for(int i=0;i<=newcap;i++){
                if(i<=capacity && i<=p2.capacity){
                    int ans = this -> degCoeff[i]-p2.degCoeff[i];
                    p3.setCoefficient(i,ans);
                }else if(i<=capacity){
                    p3.setCoefficient(i,this -> degCoeff[i]);
                }else{
                    p3.setCoefficient(i,-p2.degCoeff[i]) ;
                }
            }
            return p3;
        }

        Polynomial operator* (Polynomial const &p2){
            int newcap=this->capacity+p2.capacity;
            Polynomial P3(newcap);
        
            for(int i=0;i<=this->capacity;i++){
            
                for(int j=0;j<=p2.capacity;j++){
                    P3.degCoeff[i+j]+=this->degCoeff[i]*p2.degCoeff[j];
                }
            }
            return P3;
        }
};

int main(){
    Polynomial p1;
    p1.setCoefficient(3,2);
    p1.setCoefficient(0,4);
    p1.setCoefficient(6,4);
    p1.print();
    Polynomial p2;
    p2.setCoefficient(3,6);
    p2.setCoefficient(0,-2);
    p2.setCoefficient(4,10);
    p2.print();
    Polynomial p3 = p1 +p2;
    p3.print();
}