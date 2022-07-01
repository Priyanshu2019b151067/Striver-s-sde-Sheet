class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int m  = nums.size();
        if(nums.size()==1)
        {
            return;
        }
        int peak_1 = -1;
        for(int i = m-1;i>0;i--)
        {
            if(nums[i-1] < nums[i])
            {
                peak_1 = i-1;
                break;
            }
        }
        if(peak_1 ==-1)
        {
            sort(nums.begin(),nums.end());
        }
        else
        {
            int partner_index= -1;
            for(int i = m-1;i >=0 ;i--)
            {
                if(nums[i] > nums[peak_1])
                {
                    partner_index = i;
                    break;
                }
            }
            swap(nums[peak_1],nums[partner_index]);
            sort(nums.begin() + peak_1 +1,nums.end());
        }
    }
};