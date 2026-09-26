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

    int count, h, m, gap;
    cin >> count >> h >> m >> gap;

    int time = count * (h * 60 + m) + (count - 1) * gap;

    cout << time / 60 << "\n" << time % 60;
}