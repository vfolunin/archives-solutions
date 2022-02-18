#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string ask(int x) {
    cout << x << "\n";
    cout.flush();
    string ans;
    cin >> ans;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int l = 1, r = 1000;
    while (l <= r) {
        int m = l + (r - l) / 2;
        string ans = ask(m);

        if (ans == "correct")
            return 0;
        if (ans == "higher")
            l = m + 1;
        else
            r = m - 1;
    }
}