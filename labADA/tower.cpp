#include<iostream>
using namespace std;
static int steps;
void towerOfHanoi(int n, char p1, char p2, char p3){
    
    if(n==1){
        steps++;
        cout << "step no. " << steps << " : " << "Move disk no." << n<<" from " <<  p1 << " to " << p3<< endl;
        return ;
    }
    towerOfHanoi(n-1,p1,p3,p2);
    steps++;
    cout << "step no. " << steps << " : " << "Move disk no." << n<<" from " <<  p1 << " to " << p3<<endl;
    towerOfHanoi(n-1,p2,p1,p3);

}

int main(){
    int n;
    cout << "enter the number " << endl;
    cin >> n;
    towerOfHanoi(n,'S','A','D');

}
