#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int a = s1.size();
  int b = s2.size();
  int d[a + 1][b + 1];
 
  d[0][0] = 0;
 
  for (int i = 0; i < a + 1; ++i) {
    for (int j = 0; j < b + 1; ++j) {
      if (i == 0 || j == 0)
        d[i][j] = 0;
 
      else if (s1[i - 1] == s2[j - 1]) {
        {
          d[i][j] = d[i - 1][j - 1] + 1;
        }
      } else {
 
        d[i][j] = (d[i][j - 1] > d[i - 1][j]) ? (d[i][j - 1]) : (d[i - 1][j]);
      }
    }
  }
 
  list < char > answer;
  int i = a, j = b;
  while (i != 0 && j != 0) {
    if (d[i][j] == (d[i - 1][j - 1]) + 1) {
      answer.push_front(s1[i - 1]);
      --i;
      --j;
    } else if ((d[i][j] < d[i][j - 1])) {
      --j;
    } else {
      --i;
    }
  }
  for (char x: answer) {
    cout << x;
  }
cout<<endl;
  return 0;
}
