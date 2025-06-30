#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool ask(int value) {
    cout << "? " << value << endl;

    string ans;
    cin >> ans;

    return ans == "YES";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (ask(m))
            l = m;
        else
            r = m;
    }

    cout << "! " << r << endl;
}