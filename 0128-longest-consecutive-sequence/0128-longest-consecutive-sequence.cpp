class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int maxi = 1;
        for(int num:st)
        {
            int cnt = 1;
            if(st.find(num-1)==st.end())
            {
                while(st.find(num+1)!=st.end())
                {
                    cnt++;
                    num++;
                }
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};