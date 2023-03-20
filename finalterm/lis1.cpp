#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    //find the longest increasing subsequence possible from left to right of A
    int LIS[n];
    LIS[0] = 1;
    for (int i = 1; i < n; i++) {
        LIS[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    //print the longest increasing subsequence from left to right of A length
    int max = LIS[0];
    for (int i = 1; i < n; i++) {
        if (max < LIS[i]) {
            max = LIS[i];
        }
    }
    cout << max;
    return 0;
    
}