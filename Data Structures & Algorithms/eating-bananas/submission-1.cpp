class Solution {
public:
    bool bs(vector<int>piles,long long rate,int h) {
        long long count=0;
        for(int i=0;i<piles.size();i++) {
            count+=(piles[i]+rate-1)/rate;
        } 
        if(count<=1LL*h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s=1;
        long long e=LLONG_MIN;
        for(int i=0;i<piles.size();i++) {
            s=min(s,1LL*piles[i]);
            e=max(e,1LL*piles[i]);
        }
        long long mid=s+(e-s)/2;
        long long ans=-1;
        while(s<=e) {
            if(bs(piles,mid,h)==false) {
                s=mid+1;
            }
            else {
                ans=mid;
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return (int )ans;
    }
};
