class TimeMap {
public:
unordered_map<string ,vector<pair<int,string>>>m;
    TimeMap() {
            
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>temp=m[key];
        int s=0;
        int e=temp.size()-1;
        string ans="";
        while(s<=e) {
            int mid=s+(e-s)/2;
            if(temp[mid].first==timestamp) return temp[mid].second;
            if(temp[mid].first<timestamp) {
                ans=temp[mid].second;
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        return ans;
    }
};
