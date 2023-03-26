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

    int h, m, s;
    cin >> h >> m >> s;

    cout << h * 60 * 60 + m * 60 + s;
}