/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        int i = 0;
        while (senate.size() != 1){
            if (senate[i] == 'R'){
                if (senate.find("D") == senate.npos){
                    break;
                }
                else if (senate.find_first_of("D", i) != senate.npos){
                    senate.erase(senate.find_first_of("D", i), 1);
                    i++;
                }
                else{
                    senate.erase(senate.find_first_of("D"), 1);
                }
                if (i ==senate.size()){
                    i = 0;
                }
            }
            else {
                if (senate.find("R") == senate.npos){
                    break;
                }
                else if (senate.find_first_of("R", i) != senate.npos){
                    senate.erase(senate.find_first_of("R", i), 1);
                    i++;
                }
                else{
                    senate.erase(senate.find_first_of("R"), 1);
                }
                if (i ==senate.size()){
                    i = 0;
                }
            }
        }
        return senate[i] == 'R' ? "Radiant" : "Dire";
    }
};
// @lc code=end

