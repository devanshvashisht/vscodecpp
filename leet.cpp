#include<iostream>
using namespace std;
vector<int> search(vector<int> nums , int x){
    vector<int> ans(2);
    int s = 0;
    int e = nums.size()-1;
    while(s<=e){
        int mid = (s+e)/2;
        while(s<=e){
            if(nums[mid]==x){
                ans.push_back(x);
            }else if(nums[mid]>target){
                e = mid - 1;

            }else if(nums[mid]<target){
                s = mid + 1 ;
            }
        }
        
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }
    int x;
    cin >> x;
    return 0;
}