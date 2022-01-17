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

    int h1, w1, h2, w2;
    cin >> h1 >> w1 >> h2 >> w2;

    h2 += 2;
    w2 += 2;

    cout << (h1 >= h2 && w1 >= w2);
}