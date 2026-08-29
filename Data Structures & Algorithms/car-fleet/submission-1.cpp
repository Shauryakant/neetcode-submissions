class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>pairs;
        int n=speed.size();
        for(int i=0;i<n;i++) {
            pairs.push_back({position[i],speed[i]});
        }
        sort(pairs.begin(),pairs.end());
        stack<double>st;
        for(int i=n-1;i>=0;i--) {
            double r=(double)(target-pairs[i].first)/pairs[i].second;
            if (!st.empty()&&st.top()>=r) {}
            else st.push(r);
        }
        return st.size();
    }
};
