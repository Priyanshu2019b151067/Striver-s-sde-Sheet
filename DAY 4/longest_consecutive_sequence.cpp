class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() ==0)
            return 0;
        unordered_set<int> s;
        for(auto x : nums)
        {
            s.insert(x);
        }
        int c = 1;
        int max_length = 1;
        for(int i = 0;i< nums.size();i++)
        {
            if(s.find(nums[i]-1) ==s.end())
            {
                c = 1; 
                int k = nums[i]+1;
                for(;;k++)
                {
                    if(s.find(k)!=s.end())
                    {
                        c++;
                    }else
                    {
                        break;
                    }
                        
                }
                max_length = max(c,max_length);
            }
        }
        return max_length;
    }
};