#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len =s.length();
        int n;
        string res = "";
        for (int i=0; i<len; i++){
            int temp = 1;
            int start =i;
            while (i <len && s[i] == s[i+1]){i++; temp+=1;} 
            int end = i;
            while (start>0 && end < len-1 && s[start-1]==s[end+1]){
                //take care of this. These 2 conditions must be placed before the s[start-1]==s[end+1]\
                or it will case the problem "heap-buffer-overflow on address" when runing\
                server........
                start = start-1;
                end = end +1;
                temp = temp +2;
            }
            if (temp>res.length()){res = s.substr(start, end-start+1);}           
        }
        return res;        
    }
};
int main(){
    string s="abcdasdfghjkldcba";
    Solution t;
    auto result = t.longestPalindrome(s);
    cout<<"result is : "<< result <<endl;
}