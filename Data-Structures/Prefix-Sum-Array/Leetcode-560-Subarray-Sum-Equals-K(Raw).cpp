class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixsum = 0, ans = 0; map<int, int> prefix;
        prefix[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            prefixsum += nums[i];
            int cur = prefixsum - k;
            if(prefix.count(cur)) ans += prefix[cur];
            prefix[prefixsum]++;
        }
        return ans;
    }
};
