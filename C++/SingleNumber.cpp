#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            a ^=*i;
        }
        return a;        
    }
};
//using XOR
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> bobo;
        int ans;
        for(auto i : nums){
            if(bobo.count(i))   bobo.erase(i);
            else    bobo.insert(i);
        }
        for(auto j : bobo)  ans = j;
        return ans;
    }
};
//////////////using hash set

int main() {
    vector<int> nums{1, 2, 2};
    Solution s;
    auto result = s.singleNumber(nums);
    cout<<result<<" ";
}