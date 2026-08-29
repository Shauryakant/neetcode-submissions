class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0;
        int j=0;
        int n=s.length();
        int count=0;
        unordered_map<char,int>m;
        while(j<n ) {
            m[s[j]]++;
            if(m[s[j]]==2) count++;
            while(count!=0 &&i<n) {
                m[s[i]]--;
                if(m[s[i]]==1) {
                    count--;
                }
                i++;
            }
            ans=max(ans,j-i+1); 
            j++;
        }
        return ans;

    }
};
