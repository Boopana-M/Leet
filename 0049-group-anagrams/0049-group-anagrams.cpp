class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(string s:strs)
        {
            vector<int>vec(26,0);
            for(char c:s)
            {
                vec[c-'a']++;
            }
            string key = "";
            for(int i:vec)
            {
                key+=to_string(i)+'#';
            }
            mpp[key].push_back(s);
            
        }
        vector<vector<string>>ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};