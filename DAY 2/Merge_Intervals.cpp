class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vp;
        if(intervals.size()==0)
            return vp;
        sort(intervals.begin(),intervals.end());
        vector<int> v = intervals[0];
        for(int i = 1;i<intervals.size();i++)
        {
            if(v[1] >= intervals[i][0])
            {
                v[1] = max(v[1],intervals[i][1]);
                
            }
            else{
                vp.push_back(v);
                v[0] = intervals[i][0];
                v[1] = intervals[i][1];
            }
        }
        vp.push_back(v);
        return vp;
    }
};