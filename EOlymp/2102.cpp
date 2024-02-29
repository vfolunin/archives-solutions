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

    int h, w, size;
    cin >> h >> w >> size;

    int hCount = (h + size - 1) / size;
    int wCount = (w + size - 1) / size;

    cout << hCount * wCount;
}