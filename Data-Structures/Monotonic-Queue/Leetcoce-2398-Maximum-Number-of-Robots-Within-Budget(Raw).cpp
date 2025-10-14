// 2398. Maximum Number of Robots Within Budget (Leetcode): https://leetcode.com/problems/maximum-number-of-robots-within-budget/
// RAW CODE
const int MM = 5e4+3;
typedef long long ll;
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, ll budget) {
        int N = chargeTimes.size();
        ll psa[MM];
        for(int i = 1; i <= N; i++){
            psa[i] = psa[i-1] + runningCosts[i-1];
        }
        deque<int> dq;
        int ans = 0;
        for(int l = 1, r = 1; r <= N; r++){
            while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r-1]) dq.pop_back();
            dq.push_back(r-1); 
            while(l <= r && chargeTimes[dq.front()] + (r-l+1) * (psa[r] - psa[l-1]) > budget){
                if(!dq.empty() && dq.front() == l-1) 
                    dq.pop_front(); 
                l++; 
            }
            ans = max(ans, r-l+1); 
        }
        return ans;
    }
};                                                      
