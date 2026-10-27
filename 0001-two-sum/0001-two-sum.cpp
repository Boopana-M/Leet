class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<int>st;
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            int need = target-nums[i];
            if(st.find(nums[i])!=st.end())
            {
                for(int it:mpp[need])
                {
                    if(it!=i)return {it,i};
                }
            }
            st.insert(need);
        }
        return {-1,-1};
    }
};