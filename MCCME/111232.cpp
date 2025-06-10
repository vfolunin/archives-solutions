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

    int w, h;
    cin >> w >> h;
    cin.ignore();

    vector<string> a(h);
    for (string &s : a)
        getline(cin, s);

    for (int x = 0; x < w; x++) {
        vector<int> count(26);
        for (int y = 0; y < h; y++)
            if (isalpha(a[y][x]))
                count[tolower(a[y][x]) - 'a']++;

        cout << (char)(max_element(count.begin(), count.end()) - count.begin() + 'a');
    }
}