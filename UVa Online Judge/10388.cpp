#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string s;
    cin >> s;
    deque<char> aUp(s.begin(), s.end()), aDown;
    cin >> s;
    deque<char> bUp(s.begin(), s.end()), bDown;

    if (test)
        cout << "\n";

    for (int i = 0; i < 1000; i++) {
        if (aUp.empty()) {
            if (aDown.empty()) {
                cout << "John wins.\n";
                return;
            }
            aUp.swap(aDown);
            reverse(aUp.begin(), aUp.end());
        }
        aDown.push_front(aUp.front());
        aUp.pop_front();

        if (bUp.empty()) {
            if (bDown.empty()) {
                cout << "Jane wins.\n";
                return;
            }
            bUp.swap(bDown);
            reverse(bUp.begin(), bUp.end());
        }
        bDown.push_front(bUp.front());
        bUp.pop_front();

        if (aDown.front() == bDown.front()) {
            int r = rand() / 141 % 2;
            if (r) {
                bDown.insert(bDown.begin(), aDown.begin(), aDown.end());
                aDown.clear();
                cout << "Snap! for John: ";
                for (char c : bDown)
                    cout << c;
                cout << "\n";
            } else {
                aDown.insert(aDown.begin(), bDown.begin(), bDown.end());
                bDown.clear();
                cout << "Snap! for Jane: ";
                for (char c : aDown)
                    cout << c;
                cout << "\n";
            }
        }
    }

    cout << "Keeps going and going ...\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}