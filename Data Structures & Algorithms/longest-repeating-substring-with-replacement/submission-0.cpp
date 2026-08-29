class Solution {
public:
    int characterReplacement(string s, int k) {
        set<char>chars;
        for(int i=0;i<s.length();i++) {
            chars.insert(s[i]);
        }
        int ans=0;
        for(auto &it:chars) {
            char main=it;
            // cout<<main<<endl;
            int d=0;
            int i=0;
            int j=0;
            int n=s.length();
            int local=0;
            while(j<n) {
                if(s[j]!=main) d++;
                while (d>k&&i<n) {
                    if(s[i]!=main) d--;
                    i++;
                }
                local=max(local,j-i+1);
                j++;
            }
            ans=max(local,ans);
        }
        return ans;
    }
};
