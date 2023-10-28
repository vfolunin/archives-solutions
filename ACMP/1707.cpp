#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int opCount;
    cin >> opCount;

    deque<int> a;
    int errorCount = 0;

    for (int i = 0; i < opCount; i++) {
        string type, side;
        cin >> type >> side;

        if (type == "+") {
            int value;
            cin >> value;

            if (side == "bottom") {
                errorCount += !a.empty() && value + 1 != a.front();
                a.push_front(value);
            } else {
                errorCount += !a.empty() && a.back() + 1 != value;
                a.push_back(value);
            }
        } else {
            if (side == "bottom") {
                errorCount -= a.size() >= 2 && a[0] + 1 != a[1];
                a.pop_front();
            } else {
                errorCount -= a.size() >= 2 && a[a.size() - 2] + 1 != a[a.size() - 1];
                a.pop_back();
            }
        }

        cout << (!a.empty() && !errorCount ? "YES\n" : "NO\n");
    }
}