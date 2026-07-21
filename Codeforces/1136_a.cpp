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

    int chapterCount;
    cin >> chapterCount;

    vector<pair<int, int>> chapters(chapterCount);
    for (auto &[l, r] : chapters)
        cin >> l >> r;

    int page;
    cin >> page;

    for (int i = 0; i < chapters.size(); i++) {
        if (chapters[i].first <= page && page <= chapters[i].second) {
            cout << chapterCount - i;
            break;
        }
    }
}