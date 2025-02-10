#include <bits/stdc++.h>
using namespace std;
 
 
int a(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
 
int l(int x1, int y1, int x2, int y2) {
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
 
 
 
 
 
int main() {
 
int N;
  cin >> N;
 
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int s = a(x1, y1, x2, y2, x3, y3);
  if (s < 0) {
    swap(x2, x3);
    swap(y2, y3);
    s = a(x1, y1, x2, y2, x3, y3);
    
  }
  int l1 = l(x1, y1, x2, y2);
  int l2 = l(x2, y2, x3, y3);
  int l3 = l(x3, y3, x1, y1);
 
  while (--N) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int s = a(x1, y1, x2, y2, x3, y3);
    if (s < 0) {
      swap(x2, x3);
      swap(y2, y3);
      s = a(x1, y1, x2, y2, x3, y3);
    }
    int c1 = l(x1, y1, x2, y2);
    int c2 = l(x2, y2, x3, y3);
    int c3 = l(x3, y3, x1, y1);
    if ((l1 != c1 || l2 != c2 || l3 != c3) &&
        (l1 != c2 || l2 != c3 || l3 != c1) &&
        (l1 != c3 || l2 != c1 || l3 != c2)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
return 0;
}
