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

    int h, w, l;
    cin >> h >> w >> l;

    int parts = l / h;
    int count = (w + parts - 1) / parts;

    cout << count << " " << count * l - h * w;
}