class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size() ;i++){
            int front = i +1;
            int back = nums.size() -1;
            while(front < back){
                int sum = nums[front] + nums[back] + nums[i];
                if(sum < 0){
                    front++;
                }
                else if(sum > 0){
                    back--;
                }
                else{
                    vector<int> triplet = {nums[i],nums[front],nums[back]};
                    ans.push_back(triplet);
                    while(front < back && nums[front]== triplet[1]) front++;
                    while(front < back && nums[back]==triplet[2]) back--;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};