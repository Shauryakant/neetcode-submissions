class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=INT_MAX;
        if(nums[s]<=nums[e]) return nums[s];
        while(s<=e) {
            if(nums[s]<nums[e]) {
                ans=min(ans,nums[s]);
                break;
            }
            if(nums[s]<=nums[mid]) {
                ans=min(ans,nums[mid]);
                s=mid+1;
            }
            else {
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};
