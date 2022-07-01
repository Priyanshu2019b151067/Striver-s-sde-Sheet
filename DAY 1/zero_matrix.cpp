class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool isrow = false;
        for(int i = 0;i< n ;i++)
        {
            if(matrix[0][i] == 0)
            {
                isrow = true;
                break;
            }
        }
        bool iscolumn = false;
        for(int i = 0; i< m;i++)
        {
            if(matrix[i][0]==0)
            {
                iscolumn = true;
                break;
            }
        }
        for(int i =1;i<m;i++)
        {
            for(int j =1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = m-1;i>=1;i--)
        {
            for(int j = n-1; j >=1 ;j--)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isrow)
        {
            for(int i = 0;i< n;i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(iscolumn)
        {
            for(int i = 0 ; i< m;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};