// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    void solve(long long arr[], long long start, long long mid , long long end, long long int &ans)
    {
        long long n = mid- start +1;
        long long m = end - mid;
        long long L[n];
        long long R[m];
        for(int i = 0; i < n;i++)
        {
            L[i] = arr[i+start];
        }
        for(int j = 0; j < m; j++)
        {
            R[j] = arr[j+mid+1];
        }
        long long i = 0;
        long long j = 0;
        long long k = start;
        
        while(i < n && j < m)
        {
            if(L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else 
            {
                ans += n - i;
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < n)
        {
            arr[k++] = L[i++];
        }
        while(j < m)
        {
            arr[k++] = R[j++];
        }
    }
    void merge_sort(long long arr[] , long long start , long long end , long long int &ans)
    {
        if(start < end)
        {
            long long mid = start + (end - start)/2;
            merge_sort(arr,start,mid,ans);
            merge_sort(arr,mid+1,end,ans);
            solve(arr,start,mid,end,ans);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int answer = 0;
        merge_sort(arr,0,N-1,answer);
        return answer;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends