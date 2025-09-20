// 76. Minimum Window Substring (Leetcode): https://leetcode.com/problems/minimum-window-substring/description/
// ANNOTATED CODE
class Solution {
public:
    string minWindow(string s, string t) {
        // optimziing space is the key
        int mp[128]; int count = 0;  // count stores the number of unique letters that are currently not in t
        // map to array saves a ton of space
        for(char c : t){ 
            mp[c]++; 
        }
        for(int i = 0; i < 128; i++){
            count += mp[i] > 0;
        }
        int mi = 1e5, pl = -1, pr = -1; // storing the answer string to storing the indices save space
        for(int l = 0, r = 0; r < s.size(); r++){
            mp[s[r]]--;
            if(mp[s[r]] == 0) count--;
            while(count == 0){ // L to R is valid, maximize K such that L+K to R is valid as well
                if(mi > r-l+1){
                    pl = l; pr = r; mi = r-l+1;
                }
                if(++mp[s[l]] > 0) count++;
                l++;
            }
        }
        // checking if the values equal to 0 is smarter than checking if the current value equals the variable value (more memory required)
        if(pl == -1) return "";
        return s.substr(pl, pr-pl+1);
    }
};
