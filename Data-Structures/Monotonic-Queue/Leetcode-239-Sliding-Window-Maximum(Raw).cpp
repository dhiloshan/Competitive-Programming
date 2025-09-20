// 239. Sliding Window Maximum
// RAW CODE
struct e {
    int val, pos;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<e> dq; vector<int> ans;
        int n = nums.size();
        for(int r = 0; r < n; r++){
            while(!dq.empty() && dq.front().pos <= r-k) dq.pop_front();
            while(!dq.empty() && dq.back().val <= nums[r]) dq.pop_back();
            dq.push_back({nums[r], r});
            if(r+1>=k) ans.push_back(dq.front().val);
        }
        return ans;
    }
};
