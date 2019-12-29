#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid=0;
        int head=0;
        int last=nums.size()-1;
        while(head<last)
        {
            mid=(last-head)/2+head;
            if(target>nums[mid])
            {
                head=mid+1;
            }
            else if(target<nums[mid])
            {
                last=mid-1;
            }
            else return mid;
        }
        if(target<=nums[head])//插入位置在开头的情况
            return head;
        return head+1;//插入位置在结尾的情况
    }
};

int main() {
    vector<int> nums{1, 3, 5, 6};
    int target = 5;
    Solution s;
    auto result = s.searchInsert(nums, target);
    cout<< result <<endl;
    return 0;
}
