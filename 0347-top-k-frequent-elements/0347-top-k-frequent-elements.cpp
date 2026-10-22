class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        map<int,int>mpp;
        for(int num:nums)
        {
           mpp[num]++;
        }
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty())
        {
            auto it = pq.top();
            int num = it.second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};