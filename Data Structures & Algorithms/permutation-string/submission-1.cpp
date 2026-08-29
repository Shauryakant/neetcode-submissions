class Solution {
public:
    bool check(vector<int>&s1,vector<int>&s2) {
        for(int i=0;i<26;i++) {
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int>freq_count_of_s1(26,0);
        vector<int>freq_count_of_s2(26,0);
        for(int i=0;i<s1.length();i++) {
            freq_count_of_s1[s1[i]-'a']++;
        }
        int n=s2.length();
        int i=0;
        int j=0;
        while(j<n) {
            if(j<s1.length()) {
                if(freq_count_of_s1[s2[j]-'a']!=0) {
                    freq_count_of_s2[s2[j]-'a']++;
                }
                j++;
            }
            else {
                if(j==s1.length() && check(freq_count_of_s1,freq_count_of_s2)) return true; 
                if(freq_count_of_s1[s2[j]-'a']!=0) {
                    freq_count_of_s2[s2[j]-'a']++;
                }
                j++;
                if(freq_count_of_s1[s2[i]-'a']!=0) {
                    freq_count_of_s2[s2[i]-'a']--;
                }
                i++;
                if(check(freq_count_of_s1,freq_count_of_s2)) return true;
            }
        }
        if(check(freq_count_of_s1,freq_count_of_s2)) return true;
        return false;

    }
};
