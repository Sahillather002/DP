// good ubounded knapsack dp question
// sol of gfg
// here we needed to initialsize the second row of our dp

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int sum){
	    //special question :-)
	    //need to initialsize the second row of dp too
	    int dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<sum+1;j++){
	            //picking from empty is illogical that is not possible 
	            //so fill it with max so it won't count
	            if(i==0)dp[i][j]=INT_MAX-1;
	            //to get sum=0 we need 0 coins needed
	            if(j==0)dp[i][j]=0;
	            //now for second row initialization
	            if(i==1){
	                if(j%coins[0]==0)dp[i][j]=j/coins[0];
	                else dp[i][j]=INT_MAX-1;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<sum+1;j++){
	            if(coins[i-1]<=j){
	                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    if(dp[n][sum]>1e9)return -1;
	    return dp[n][sum];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
