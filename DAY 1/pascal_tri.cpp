class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        for(int i = 0;i< v.size() ;i++)
        {
            int j = i +1;
            while(j!=0)
            {
                v[i].push_back(1);
                j--;
            }
        }
        
        for(int i = 2;i< v.size();i++)
        {
            for(int j= 1;j<v[i].size()-1;j++)
            {
                v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
        }
        return v;
        
    }
};