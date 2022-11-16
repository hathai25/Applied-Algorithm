#include <bits/stdc++.h>
using namespace std;

int n, m, res;
int A[50], Cnt[50], Bool[50][50];
vector<int> v[50];

bool check(int x, int n) {
  if (Cnt[x] < 1)
    return false;
  for (int i = 1; i < n; i++)
    if (A[i] == x && Bool[i][n] == 1)
      return false;
  return true;
}

void Update() {
  int tmp = -1, dem[50] = {0};
  for (int i = 1; i <= n; i++) {
    dem[A[i]]++;
    tmp = max(tmp, dem[A[i]]);
  }
  res = min(res, tmp);
}

void Try(int k) {
  for (int i = 0; i < v[k].size(); i++) {
    if (check(v[k][i], k)) {
      Cnt[v[k][i]]--;
      A[k] = v[k][i];
      if (k == n) {
        Update();
      } else
        Try(k + 1);
      Cnt[v[k][i]]++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    int cnt;
    cin >> cnt;
    Cnt[i] = cnt;
    for (int j = 0; j < cnt; j++) {
      int x;
      cin >> x;
      v[x].push_back(i);
    }
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    Bool[x][y] = 1;
    Bool[y][x] = 1;
  }

  res = 100;
  Try(1);
  cout << res << "\n";

  return 0;
}