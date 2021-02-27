/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         map<char, vector<int>> a, b;
//         int n = s.size();
//         for (int i = 0; i < n; ++i)
//         {
//             a[s[i]].push_back(i);
//             b[t[i]].push_back(i);
//         }
//         for (auto i = a.begin(); i != a.end(); ++i){
//             for (auto j = b.begin(); j != b.end(); ++j){
//                 if (i->second == j->second){
//                     break;
//                 }
//                 auto tmp = b.end() - 1;
//                 // else if (j - b.end() == 1){
//                 //     return false;
//             }
//         }
//     return true;
//     }
// };
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i=0;i<s.size();i++){
            if(s.find(s[i])!=t.find(t[i]))
            return false;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char,char> smap;
//         unordered_map<char,char> tmap;
//         for(int i = 0; s[i] != '\0'; ++ i){
//             char ss = s[i];
//             char tt = t[i];
//             if(smap.count(ss)){
//                 if(smap[ss] != tt)    return false;
//             }
//             else if(tmap.count(tt)){
//                 if(tmap[tt] != ss)  return false;
//             }
//             else{
//                 smap[ss] = tt;
//                 tmap[tt] = ss;
//             }
//         }
//         return true;
//     }
// };
// @lc code=end

