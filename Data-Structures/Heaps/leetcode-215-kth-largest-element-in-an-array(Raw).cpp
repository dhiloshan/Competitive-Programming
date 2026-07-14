// 215. Kth Largest Element in an Array (Leetcode): https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// RAW CODE
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q; // initialize min-heap
        for(int i = 0; i < k; i++){ // insert k #'s into heap
            q.push(nums[i]);
        } 
        for(int i = k; i < nums.size(); i++){
            q.push(nums[i]);
            q.pop();
        }
        return q.top(); // guaranteed k largest numbers are here. thus, the kth largest number will be at the top by the min-heap property
    }
};
