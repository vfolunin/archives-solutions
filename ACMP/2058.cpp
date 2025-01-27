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

    int h, w, maxJump;
    cin >> h >> w >> maxJump;
    h--;
    w--;

    if (h > w)
        swap(h, w);

    cout << (h + maxJump - 1) / maxJump + (w - h + maxJump - 1) / maxJump;
}