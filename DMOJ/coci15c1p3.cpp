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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int balloonCount;
    cin >> balloonCount;

    multiset<int> arrows;

    for (int i = 0; i < balloonCount; i++) {
        int height;
        cin >> height;

        if (auto it = arrows.find(height); it != arrows.end())
            arrows.erase(it);
        arrows.insert(height - 1);
    }

    cout << arrows.size();
}