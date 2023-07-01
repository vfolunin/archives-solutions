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
  
    int n;
    cin >> n;

    int t = 9 * 60;
    for (int i = 1; i < n; i++)
        t += 45 + (i % 2 ? 5 : 15);
    t += 45;

    cout << t / 60 << " " << t % 60;
}