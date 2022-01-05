#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int find(int book, vector<pair<int, int>> &shelf) {
    for (int i = 0; i < shelf.size(); i++)
        if (book == shelf[i].second)
            return i;
    return -1;
}

bool solve() {
    int bookCount;
    if (!(cin >> bookCount))
        return 0;

    vector<pair<int, int>> shelf;
    int missCount = 0;
    
    for (int i = 0; i < bookCount; i++) {
        int book;
        cin >> book;

        if (find(book, shelf) == -1) {
            missCount++;
            if (shelf.size() < 4)
                shelf.push_back({ i, book });
            else
                *min_element(shelf.begin(), shelf.end()) = { i, book };
        }
    }

    cout << missCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}