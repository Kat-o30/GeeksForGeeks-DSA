//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int leftsum = 0, totalsum = 0;
        for(int num: arr){
            totalsum += num;
        }
        for(int i=0; i<arr.size(); i++){
            if (leftsum == (totalsum - arr[i] - leftsum)){
                return "true";
            }
            leftsum += arr[i];
        }
        return "false";
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        string res = obj.equilibrium(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends