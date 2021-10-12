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

    int s, t, f;
    cin >> s >> t >> f;

    cout << (s + t + f + 24) % 24 << "\n";
}