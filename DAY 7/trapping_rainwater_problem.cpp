class Solution {
public:
    int trap(vector<int>& height) {
     int max_left[height.size()];
     int max_l = height[0];
     for(int i = 0; i < height.size();i++){
         if(max_l  < height[i]){
             max_l = height[i];
         }
         max_left[i] = max_l;
     }
     int max_right[height.size()];
     int max_r = height[height.size()-1];
     for(int i = height.size()-1;i >= 0;i--){
         if(max_r < height[i]){
             max_r = height[i];
         }
         max_right[i] = max_r;
     }
     int ans = 0;
     for(int i = 0; i < height.size();i++){
        ans += min(max_left[i],max_right[i]) - height[i];
     }
     return ans;
    }
};