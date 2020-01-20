#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    struct Node {
        int lmax,rmax,sum,dat;
    };
    
    Node dfs(vector<int>& nums, int l, int r)
    {
        if(l==r) return {nums[l],nums[l],nums[l],nums[l]};
        
        int mid = l+r>>1;
        auto left = dfs(nums,l,mid);
        auto right = dfs(nums,mid+1,r);
        
        return {
            max(left.lmax, left.sum+right.lmax),
            max(right.rmax, left.rmax + right.sum),
            left.sum + right.sum,
            max(left.rmax+right.lmax, max(left.dat,right.dat))
        };
    }
    int maxSubArray(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1).dat;
    }
};

int main (){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    auto result = s.maxSubArray(nums);
    cout<< result <<endl;
}