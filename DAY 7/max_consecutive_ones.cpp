class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int i=0;
        int j =0;
        int mx =0;
        while (j< nums.size()){
            if(nums[j]==1){
                j++;
            }else{
                mx = max(mx,j-i);
                i = j+1;
                j++;
            }
        }
        mx = max(mx,j-i);
        return mx;
    }
};