#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n, m;
    cin >> n ;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> m;
    int B[m];
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}