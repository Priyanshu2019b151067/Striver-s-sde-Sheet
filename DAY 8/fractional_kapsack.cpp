// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        
       priority_queue<pair<double,int>> maxi;
       for(int i =0;i < n;i++){
           maxi.push({(static_cast<double>(arr[i].value)/arr[i].weight),i});
       }
       double profit = 0.0;
       while(maxi.size()!=0 && W != 0)
       {
           if(arr[maxi.top().second].weight <= W){
               profit += double(arr[maxi.top().second].value);
               W -= arr[maxi.top().second].weight;
           }else{
               profit+= static_cast<double>(W)/arr[maxi.top().second].weight * arr[maxi.top().second].value;
               W = 0;
           }
           maxi.pop();
       }
       return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends