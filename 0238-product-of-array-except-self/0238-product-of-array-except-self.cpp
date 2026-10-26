class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //since the problem is asking the number should not be included instead of calculating traditional prefix like prefix value at i is from 0 to i , we here put as 0 to i-1 so usually a 0th index number's prefix would 
        //be 1 because before me no number so just 1 ie., instead of  prefix[i] = prefix[i-1]*nums[i]; i use
        //  prefix[i] = prefix[i-1]*nums[i-1];
        // same for suffix i+1 to n-1 
        int n = nums.size();
        vector<int>prefix(n,1);

        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        // instead of having suffix array maintain it in a single variable
        int suffix = 1;
        //representing the n-1 th index number's suffix which is 1

        // instead of creating fresh array for answer.. use prefix array itself
        for(int i=n-1;i>=0;i--)
        {
            //first time the prefix[n-1] is multiplied with 1 because prefix of 0th index and suffix of n-1th index = 0 
            prefix[i] = prefix[i]*suffix;
            suffix = suffix*nums[i]; 
        }
        return prefix;
    }
};