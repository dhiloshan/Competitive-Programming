// 496. Next Greater Element I (Leetcode): https://leetcode.com/problems/next-greater-element-i/description/
// RAW CODE
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mx(10001, 0), ans(nums1.size(), 0);
        stack<int> stk;
        for(int i = nums2.size() - 1; i >= 0; i--){
            int cur = nums2[i];
            while(!stk.empty() && stk.top() <= cur) stk.pop();
            if(stk.empty()) mx[cur] = -1;
            else mx[cur] = stk.top();
            stk.push(cur);
        }
        
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = mx[nums1[i]];
        }
        return ans;
    }
}; 
