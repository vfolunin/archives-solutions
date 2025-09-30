#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string leave2(string &s) {
    int count = 0;
    for (char &c : s) {
        if (c != '0') {
            if (count < 2)
                count++;
            else
                c = '0';
        }
    }
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    if (a.size() == b.size()) {
        cout << stoi(leave2(a)) + stoi(leave2(b));
    } else {
        if (a.size() < b.size())
            swap(a, b);

        if (a.substr(a.size() - b.size()) == string(b.size(), '0'))
            cout << stoi(a) + stoi(b);
        else
            cout << "NO";
    }
}