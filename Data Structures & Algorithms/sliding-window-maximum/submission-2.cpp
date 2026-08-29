class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxheap;
        int n=nums.size();
        for(int i=0;i<k-1;i++) maxheap.push({nums[i],i});
        vector<int>ans;
        for(int i=k-1;i<n;i++) {
            maxheap.push({nums[i],i});
            while(maxheap.top().second+k<=i) maxheap.pop();
            ans.push_back(maxheap.top().first);
        }
        return ans;
    }
};
