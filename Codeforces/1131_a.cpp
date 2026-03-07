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

    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    cout << (h1 + h2 + 2 + max(w1, w2)) * 2;
}