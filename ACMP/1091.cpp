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

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    a.push_back(" ");

    for (int i = 1; 1; i++) {
        if (tolower(a[i - 1].back()) != tolower(a[i].front())) {
            cout << i << "\n" << (i % 2 ? "Shrek" : "Rumpelstiltskin");
            break;
        }
    }
}