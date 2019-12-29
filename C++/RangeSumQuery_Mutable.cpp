#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class NumArray {
public:
    vector<int> C;
    vector<int> nums;

    NumArray(vector<int> &nums) : nums(nums) {
        for (int i = 0; i <= nums.size(); ++i) {
            C.push_back(0);
        }
        for (int i = 0; i < nums.size(); ++i) {
            add(i, nums[i]);
        }
    }
    //generate the Fenwick Tree or Binary Indexed Tree
    //https://www.youtube.com/watch?v=CWDQJGaN1gY

    int lowbit(int x) {
        return x & (-x);
    }
    //pick the lowest bit with 1
    //e.g. x=10110, return 00010 = 2 

    void add(int i, int val) {
        for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
            C[k] += val;
        }
    }

    void update(int i, int val) {
        int add = val - nums[i];
        nums[i] = val;
        for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
            C[k] += add;
        }
    }

    int getSum(int i) {
        int sum = 0;
        for (int k = i; k > 0; k -= lowbit(k)) {
            sum += C[k];
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
};

int main() {
    vector<int> nums{1, 3, 5};
    NumArray s=NumArray(nums);
    auto result1 = s.sumRange(0, 2); 
    s.update(1, 2);
    auto result2 = s.sumRange(0, 2);
    cout<<result1<<" "<<result2<<endl;
    return 0;
}