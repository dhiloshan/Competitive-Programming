// 2398. Maximum Number of Robots Within Budget (Leetcode): https://leetcode.com/problems/maximum-number-of-robots-within-budget/
// ANNOTATED CODE
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
        deque<int> dq; // based on pos
        int ans = 0;
        for(int l = 1, r = 1; r <= N; r++){
            while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r-1]) dq.pop_back();
            dq.push_back(r-1); // 0-indexed
            while(l <= r && chargeTimes[dq.front()] + (r-l+1) * (psa[r] - psa[l-1]) > budget){
                if(!dq.empty() && dq.front() == l-1) 
                    dq.pop_front(); // if the biggest number is the first element in the subarray, we have to pop it to shrink the subarray
                l++; // shrink subarray
            }
            ans = max(ans, r-l+1); // represents max for each index r
        }
        return ans;
    }
};                                                      
