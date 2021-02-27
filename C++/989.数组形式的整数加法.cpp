/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int size = A.size();
        int tmp;
        int cur = 0;
        int flag;
        while (K > 0) {
            size = A.size();
            tmp = K % 10;
            K = K / 10;
            if (cur >= size) {
                A.push_back(tmp);
            }
            else {
                flag = (A[cur] + tmp) / 10;
                A[cur] = (A[cur] + tmp) % 10;
                if (flag == 1) {
                    numberCarry(A, tmp, cur);
                }
            }
            cur++;
        }
        reverse(A.begin(), A.end());
        return A;
    }
    vector<int> numberCarry (vector<int>& A, int tmp, int cur) {
        int size = A.size();
        for (int i = 1 + cur; i < size; i++){
            A[i] = (A[i] + 1) % 10;
            if (A[i] != 0){
                return A;
            }
        }
        if (A[size - 1] == 0){
            A.push_back(1);
            size = A.size();
        }
        if (cur == size - 1) {
            A.push_back(1);
            size = A.size();
        }
        return A;                 
    }
};

// @lc code=end

