#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> s(n+1,-1);
        s[1]=1;
        s[2]=2;
        for(int i=3;i<=n;i++)
        {
            s[i]=s[i-1]+s[i-2];
        }
        return s[n];
    }
};


int main(){
    int n = 10;
    Solution t;
    auto result = t.climbStairs(n);
    cout<<"result is : "<< result <<endl;
}