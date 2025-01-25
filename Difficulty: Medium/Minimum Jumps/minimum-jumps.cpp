//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if(n==1){
            return 0;
        }
        
        if(arr[0] == 0){
            return -1;
        }
        
        int jumps = 0;
        int currentEnd = 0;
        int farthestEnd = 0;
        
        for(int i=0; i<n-1; i++){
            farthestEnd = max(farthestEnd, i+arr[i]);
            
            if(i == currentEnd){
                jumps++;
                currentEnd = farthestEnd;
                
                if(currentEnd >= n-1){
                    return jumps;
                }
                else if(arr[i] == 0 && currentEnd < n-1){
                    return -1;
                }
            }
            
            
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends