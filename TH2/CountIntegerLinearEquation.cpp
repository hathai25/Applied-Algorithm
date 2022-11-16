#include <bits/stdc++.h>

using namespace std;

int solve(int arr[],int d,int c,int s){
  if(s == 0) return 1;
  int res = 0;
  for(int i = d;i <= c;i++) if(arr[i] <= s) res += solve(arr,i,c,s - arr[i]);
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  int n,m;
  int arr[100100];
  cin >> n >> m;
  int s = 0;
  for(int i = 0;i < n;i++) cin >> arr[i],s += arr[i];
  sort(arr,arr + n);
  cout << solve(arr,0,n-1,m-s);

  return 0;
}