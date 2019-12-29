#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        //vector<int>::iterator a=nums.begin();
        for(int i = 0; i < nums.size(); m[target - nums[i - 1]] = i++){
            if(m.count(nums[i])) return {m[nums[i]], i};
        }
        return {-1, -1};
    }
};

// template < typename T>
// int findInVector(const std::vector<T>  & vecOfElements, const T  & element)
// {
// 	int result;
 
// 	// Find given element in vector
// 	auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
 
// 	if (it != vecOfElements.end())
// 	{
// 		result = distance(vecOfElements.begin(), it);
// 	}
// 	else
// 	{
// 		result = -1;
// 	}
 
// 	return result;
// }

// class Solution1 {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size(); i++){
//             int tmp = target - nums[i]; 
//             auto index = findInVector(nums, tmp);
//             if(index!=-1) return {i, index};
//         }
//         return {-1, -1};
//     }
// };



int main() {
    //Solution s;
    Solution s = Solution();
    vector<int> nums{2, 7, 11, 15};
    //std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), 22);
    int target = 13;
    vector<int> ans = s.twoSum(nums, target);
    for(int i = 0;i <ans.size();i++){cout << ans[i] <<endl;
    //cout << nums[-1] <<endl;
    }
  return 0;
}
