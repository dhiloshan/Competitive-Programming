// 76. Minimum Window Substring (Leetcode): https://leetcode.com/problems/minimum-window-substring/description/
// RAW CODE
class Solution {
public:
    string minWindow(string s, string t) {
        int mp[128]; int count = 0;  
        for(char c : t){ 
            mp[c]++; 
        }
        for(int i = 0; i < 128; i++){
            count += mp[i] > 0;
        }
        int mi = 1e5, pl = -1, pr = -1; 
        for(int l = 0, r = 0; r < s.size(); r++){
            mp[s[r]]--;
            if(mp[s[r]] == 0) count--;
            while(count == 0){
                if(mi > r-l+1){
                    pl = l; pr = r; mi = r-l+1;
                }
                if(++mp[s[l]] > 0) count++;
                l++;
            }
        }
        if(pl == -1) return "";
        return s.substr(pl, pr-pl+1);
    }
};
