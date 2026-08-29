class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int m=INT_MAX;
        for(int i=0;i<n;i++) {
            m=min(prices[i],m);
            ans=max(prices[i]-m,ans);
        }
        return ans;
    }
};
