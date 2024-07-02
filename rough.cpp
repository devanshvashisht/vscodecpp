#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<string> summaryRanges(vector<int>& nums){
    vector<string> ans;
    int begin, 
    intend = nums[0];
    for(int i=0;i<nums.size();i++){
        // int begin,end = nums[i];
        if(nums[i+1]==nums[i]+1){
            end = nums[i+1];
        }else{
            if(begin==end){
                ans.push_back(to_string(nums[i]));
                if(i+1<nums.size()){
                    begin=nums[i+1];
                    end = nums[i+1];
                }else{
                    break;
                }

            }else{
                ans.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
                if(i+1<nums.size()){
                    begin=nums[i+1];
                    end = nums[i+1];
                }else{
                    break;
                }
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);
    
    vector<string> ans = summaryRanges(nums);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] <<" ";
    }
    
}