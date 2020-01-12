#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        string res;
        int len=dominoes.length();

        int start = 0, end = 0;
        if (len == 0){return res;}
        while (end < len && dominoes[end]!='.'){end++;}
        for (auto i=0; i<end; i++){res += dominoes[i];}
        while (end < len){
            start = end;
            while (end < len && dominoes[end] == '.'){end++;}
            if (start == 0 && end == len){for (auto i=0; i<end; i++){res +='.';}}
            else if (start == 0){
                if (dominoes[end] == 'L'){for (auto i=0; i<end; i++){res +='L';}}
                else {
                    for (auto i=0; i<end; i++){res+='.';}
                }                   
            }
            else if (end == len){
                if (dominoes[start-1] == 'R'){for (auto i=start+1; i<=end; i++){res +='R';}}
                else {for (auto i=start+1; i<=end; i++){res +='.';}}
            }
            else {
                if (dominoes[start-1] == 'L' && dominoes[end] == 'L'){
                    for (auto i=start; i<end; i++){res +='L';}}
                else if (dominoes[start-1] == 'L' && dominoes[end] == 'R'){
                    for (auto i=start; i<end; i++){res +='.';}}
                else if (dominoes[start-1] == 'R' && dominoes[end] == 'R'){
                    for (auto i=start; i<end; i++){res +='R';}}
                else {
                    int mid = start + (end - start)/2;
                    for (auto i=start; i<mid; i++){res +='R';}
                    if ((end-start) % 2 != 0){
                        res +='.';
                        for (auto i=mid+1; i<end; i++){res +='L';}
                        }
                    else {for (auto i=mid; i<end; i++){res +='L';}}
                }
            }
            res+=dominoes[end];
            end++;    
        }
        return res;
    }
};

int main (){
    Solution s;
    string dominoes{".R...L"};
    //string dominoes{".LR"};
    auto result=s.pushDominoes(dominoes);
    cout<< result <<endl; 
}
