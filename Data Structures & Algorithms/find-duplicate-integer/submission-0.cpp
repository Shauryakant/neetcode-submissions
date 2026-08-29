class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int r=0;
        vector<int>n(nums.size()+1,1);
        for(int i=0;i<nums.size();i++) {
            if(n[nums[i]]<0) return nums[i];
            else n[nums[i]]=-nums[i];
        }
        return 0;
        
    }
};
