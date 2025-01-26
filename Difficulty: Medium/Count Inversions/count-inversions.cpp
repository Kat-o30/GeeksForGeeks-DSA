//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    
    int mergeAndCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
        int i = left;   // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left;   // Starting index to store in temp
        int invCount = 0;

        // Merge the two halves while counting inversions
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1); // Count inversions
            }
        }

        // Copy remaining elements of the left subarray
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of the right subarray
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted subarray into the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return invCount;
    }
    
    int mergeSortAndCount(vector<int> &arr, vector<int> &temp, int left, int right) {
        int invCount = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in the left subarray
            invCount += mergeSortAndCount(arr, temp, left, mid);

            // Count inversions in the right subarray
            invCount += mergeSortAndCount(arr, temp, mid + 1, right);

            // Count merge inversions
            invCount += mergeAndCount(arr, temp, left, mid, right);
        }

        return invCount;
    }
    
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        
         vector<int> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends