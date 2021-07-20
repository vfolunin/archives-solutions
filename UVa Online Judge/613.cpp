#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getNext(string &num) {
    string res;
    for (char c = '0'; c <= '9'; c++) {
        int k = count(num.begin(), num.end(), c);
        if (k)
            res += to_string(k) + c;
    }
    return res;
}

bool solve() {
    string num;
    cin >> num;

    if (num == "-1")
        return 0;

    cout << num << " ";

    map<string, int> seen;
    for (int i = 0; i <= 15; i++) {
        if (seen.count(num)) {
            int period = i - seen[num];
            if (period > 1)
                cout << "enters an inventory loop of length " << period << "\n";
            else if (i > 1)
                cout << "is self-inventorying after " << i - 1 << " steps\n";
            else
                cout << "is self-inventorying\n";
            return 1;
        }

        seen[num] = i;
        num = getNext(num);
    }

    cout << "can not be classified after 15 iterations\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}