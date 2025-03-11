class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = nums[0];
        int n = nums.size();
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i = 1; i < nums.size(); i ++){
            int temp = nums[i];
            if(ans >= temp){
                maxheap.push(temp);
                if(maxheap.size() > n - k){
                    minheap.push(ans);
                    ans = maxheap.top();
                    maxheap.pop();
                }
            }else{
                minheap.push(temp);
                 if(minheap.size() > k - 1){
                    maxheap.push(ans);
                    ans = minheap.top();
                    minheap.pop();
                }               
            }
        }
        return ans;
    }
};