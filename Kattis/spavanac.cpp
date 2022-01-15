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

    int h, m;
    cin >> h >> m;

    int t = h * 60 + m;
    t = (t + 24 * 60 - 45) % (24 * 60);

    cout << t / 60 << " " << t % 60;
}