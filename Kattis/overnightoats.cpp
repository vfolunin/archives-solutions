#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount, limit;
    cin >> queryCount >> limit;

    queue<int> q;
    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "ADD") {
            q.push(i);
        } else if (type == "EAT" && !q.empty()) {
            if (i - q.front() > limit) {
                cout << "ono..";
                return 0;
            }
            q.pop();
        }
    }

    cout << "yay!";
}