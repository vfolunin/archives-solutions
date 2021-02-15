#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int num, den;
    if (!(cin >> num >> den))
        return 0;

    cout << num << "/" << den << " = " << num / den << ".";

    num %= den;
    vector<int> seen(den, -1);
    string res;

    for (int i = 0; 1; i++) {
        if (seen[num] != -1) {
            int cycleLength = i - seen[num];
            
            if (res.size() > 50) {
                res = res.substr(0, 50) + "...";
                if (seen[num] < 49) {
                    res.insert(seen[num], 1, '(');
                    res += ')';
                }
            } else {
                res.insert(seen[num], 1, '(');
                res += ')';
            }

            cout << res << "\n";
            cout << "   " << cycleLength << " = number of digits in repeating cycle\n\n";
            break;
        }

        seen[num] = i;
        res += num * 10 / den + '0';
        num = num * 10 % den;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}