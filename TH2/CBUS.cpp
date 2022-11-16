#include <bits/stdc++.h>

using namespace std;

int n, k1, res, sum = 0, cnt = 0;
int A[50], Bool[50], dis[50][50];

bool check(int x, int k) {
  if (Bool[x] == 1)
    return false;
  if (x > n && Bool[x - n] == 0)
    return false;
  if (cnt == k1 && x <= n)
    return false;
  if (sum + dis[A[k - 1]][x] > res)
    return false;
  return true;
}

void Try(int k) {
  if (sum + 2 * n + 1 - k >= res)
    return;

  for (int i = 1; i <= 2 * n; i++) {
    if (check(i, k)) {
      cnt += i <= n ? 1 : -1;
      sum += dis[A[k - 1]][i];
      A[k] = i;
      Bool[i] = 1;
      if (k == 2 * n) {
        res = min(res, sum + dis[A[2 * n]][0]);
      } else
        Try(k + 1);
      Bool[i] = 0;
      sum -= dis[A[k - 1]][i];
      cnt -= i <= n ? 1 : -1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k1;
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++)
      cin >> dis[i][j];

  res = 1e9 + 7;
  Try(1);
  cout << res << "\n";

  return 0;
}