#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  
    int w, h, y1, y2;
    cin >> w >> h >> y1 >> y2;

    cout << (y1 > w - y2 || h - y1 > w - h + y2 ? "No" : "Yes");
}