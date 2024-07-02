#include <iostream>
#include<vector>
using namespace std;
bool isMountain(vector<int> input)
{
    int s = 0;
    int l = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (i + 1 < input.size())
        {
            if (input[i] < input[i + 1])
                s++;
            else
                l++;
        }
    }
    return (s == 0 || l == 0);
}


int main(){
    vector<int> a = {6,4,2};
    cout << isMountain(a);
}