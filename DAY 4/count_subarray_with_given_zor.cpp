int Solution::solve(vector<int> &A, int B) {
    int  xr = 0;
    int cnt = 0;
    unordered_map<int,int> um;
    for(int i = 0; i< A.size() ;i++)
    {
        xr ^= A[i];
        if(xr == B)
        {   
            cnt++;
        }
        int y = xr^B;
        if(um.find(y)!=um.end())
        {
                cnt+= um[y];
        }
        um[xr]++;   
    }
    return cnt;
}
