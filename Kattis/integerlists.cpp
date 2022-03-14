#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

deque<int> readList() {
    int size;
    cin >> size;
    cin.ignore();

    deque<int> list(size);

    cin.ignore();
    for (int i = 0; i < list.size(); i++) {
        cin >> list[i];
        if (i + 1 < list.size())
            cin.ignore();
    }
    cin.ignore(2);

    return list;
}

void writeList(deque<int> &list) {
    cout << "[";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i];
        if (i + 1 < list.size())
            cout << ",";
    }
    cout << "]\n";
}

void solve() {
    string program;
    cin >> program;

    deque<int> list = readList();
    bool reversed = 0;

    for (char command : program) {
        if (command == 'R') {
            reversed ^= 1;
        } else {
            if (list.empty()) {
                cout << "error\n";
                return;
            }
            if (reversed)
                list.pop_back();
            else
                list.pop_front();
        }
    }

    if (reversed)
        reverse(list.begin(), list.end());

    writeList(list);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}