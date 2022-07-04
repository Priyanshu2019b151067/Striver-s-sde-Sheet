vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xo = 0;
    for(int i = 1;i <=A.size();i++){
        xo ^= i;
        xo ^= A[i-1];
    }
    int rbsv = xo&-xo;
    int x = 0, y = 0;
    for(int i = 1;i <=A.size();i++){
        if((rbsv&i)== 0){
            x ^= i;
        }else{
            y ^= i;
        }
        
        if((rbsv&A[i-1]) == 0){
            x ^= A[i-1];
        }else{
            y ^= A[i-1];
        }
    }
    vector<int> ans;
    for(auto z : A){
        if(z == x){
            ans.push_back(x);
            ans.push_back(y);
            break;
        }
        else if(z == y){
            ans.push_back(y);
            ans.push_back(x);
            break;
        }
    }
    
    return ans;
}

