class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.size()==0){
          return 0;
      }
       int ws = 0;
       int we = 0;
       int ans = 1;
       unordered_map<char,int> um;
       while(we < s.size()){
           if(um.find(s[we])!=um.end()){
               if(um[s[we]] >= ws){
                   ws = um[s[we]] +1;
               }
           }
           
           
           ans = max(ans,we-ws+1);
           um[s[we]] = we;
           we++;
       }
        return ans;
    }
};