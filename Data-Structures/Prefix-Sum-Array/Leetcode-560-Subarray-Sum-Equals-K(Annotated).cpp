// Problem 560: Subarray Sum Equals K (Leetcode): https://leetcode.com/problems/subarray-sum-equals-k/
// ANNOTATED CODE - note that for array 1 to R, we can cut off some prefix and see if that remaining sum is the target
// store all prefixes (only N prefixes - 1 to 1, 1 to 2, 1 to 3,... 1 to N in a map, its value is the number of times that prefix occured
// otherwise update that prefix in the array
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixsum = 0, ans = 0; map<int, int> prefix;
        prefix[0] = 1; // if the sum is the exact target, then add 1 for now (sum 0 could appear mutliple times)
        for(int i = 0; i < nums.size(); i++){
            prefixsum += nums[i];
            int cur = prefixsum - k; // could we chop off this prefix
            if(prefix.count(cur)) ans += prefix[cur]; // yes add it to answer
            prefix[prefixsum]++; // no it wasn't here before
        }
        return ans;
    }
};
