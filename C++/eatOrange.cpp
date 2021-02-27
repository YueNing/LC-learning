#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <typeinfo>
#include <unordered_map>
#include <algorithm>
#include <stack> 
using namespace std;

// class Solution {
// public:
//     int eatOrange(int nums, int& res){
//         if (nums == 0){
//             return 0;
//         }
//         if (nums%2 == 0 && nums%3 == 0){
//             res = min(eatOrange(nums - 1, res) + 1, eatOrange(nums / 2, res) + 1, eatOrange(nums / 3, res) + 1);
//         }
//         else if (nums%2 == 0 && nums%3 != 0){
//             res = min(eatOrange(nums - 1) + 1, eatOrange(nums / 2) + 1);
//         }
//         else if (nums%2 != 0 && nums%3 == 0){
//             res = min(eatOrange(nums - 1) + 1, eatOrange(nums / 3) + 1);
//         }
//         else {
//             res = eatOrange(nums - 1) + 1;
//         }
//     }
// };

class Solution {
public:
    unordered_map<int,int>m;//离散化
    int minDays(int n) {
        if(n==0)return 0;//出口
        if(m.count(n))return m[n];//dp
        return m[n]=min({1+n%2+minDays(n/2),1+n%3+minDays(n/3),n});//分别对应/3,/2,-1.
    }
};


int main(){
    Solution s;
    int nums = 100;
    cout<<s.minDays(nums)<<" "<<nums;
    getchar();
}