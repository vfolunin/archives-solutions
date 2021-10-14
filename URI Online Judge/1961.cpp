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

    int limit, n;
    cin >> limit >> n;

    vector<int> height(n);
    for (int &h : height)
        cin >> h;

    for (int i = 0; i + 1 < n; i++) {
        if (abs(height[i] - height[i + 1]) > limit) {
            cout << "GAME OVER\n";
            return 0;
        }
    }

    cout << "YOU WIN\n";
}