#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

char ask(int n) {
    cout << n << endl;
    char ans;
    cin >> ans;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int l = 1, r = 1e9;
    while (1) {
        int m = l + (r - l) / 2;
        char ans = ask(m);

        if (ans == '=')
            return 0;
        if (ans == '>')
            l = m + 1;
        else
            r = m - 1;
    }
}