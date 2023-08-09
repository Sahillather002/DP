//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int validSubset(int arr[],int n,vector<int>& valids,int sum){
        bool dp[n+1][sum+1];
        //initialising the dp
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)dp[i][j]=false;
                if(j==0)dp[i][j]=true;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    //pick or not pick 
                    //anyone of true will make our that dp indexed value true :-)
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        //now storing last row value into the valid vertex for our final answer calculation
        for(int j=1;j<sum/2+1;j++){
            //cout<<dp[n][j];
            //cout<<endl;
            if(dp[n][j])
            {
                valids.push_back(j);
                //cout<<j;
            }
            
        }
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    if(n==1)return arr[0];
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    //calculating the valid subset that we could take
	    vector<int>valids;
	    validSubset(arr,n,valids,sum);
	    //now we have all valid possibel subset values
	    int mini=1e9;
	    for(int i=0;i<valids.size();i++){
	        mini=min(mini,abs(sum-2*valids[i]));
	    }
	    
	    //cout<<sum;
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
