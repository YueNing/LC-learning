#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        long lo = K;
        long hi = 10*K+1;
        while (lo < hi){
            long mi = lo + (hi - lo)/2;
            long K_guess =zeta(mi);
            if (K_guess == K) return 5;
            else if (K_guess < K)
            {
                lo=mi+1;
            }            
            else hi=mi;
        }
    return 0;    
    }

    long zeta(long K){
        long x=0;
        while(K!=0){
            K = K/5;
            x += K;
        }
        return x;
    }
};

int main (){
    int K = 5;
    Solution s;
    auto result = s.preimageSizeFZF(K);
    //auto result = s.zeta(K);
    cout<< result <<" ";
}