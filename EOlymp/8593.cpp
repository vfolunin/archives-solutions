#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string make(vector<int> digitCount) {
    int digit = 1;
    while (!digitCount[digit])
        digit++;

    string res(1, digit + '0');
    digitCount[digit]--;
    
    for (int digit = 0; digit < digitCount.size(); digit++)
        res += string(digitCount[digit], digit + '0');
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    string res = "-1";
    if (s.size() <= 3) {
        sort(s.begin(), s.end());
        
        do {
            if (s[0] != '0' && stoi(s) % 8 == 0 && res == "-1" || res > s)
                res = s;
        } while (next_permutation(s.begin(), s.end()));

        cout << res;
        return 0;
    }

    vector<int> digitCount(10);
    for (char c : s)
        digitCount[c - '0']++;

    for (int a = 0; a < digitCount.size(); a++) {
        if (!digitCount[a])
            continue;
        digitCount[a]--;

        for (int b = 0; b < digitCount.size(); b++) {
            if (!digitCount[b])
                continue;
            digitCount[b]--;

            for (int c = 0; c < digitCount.size(); c++) {
                if (!digitCount[c])
                    continue;
                digitCount[c]--;

                if ((a * 100 + b * 10 + c) % 8 == 0 &&
                    count(digitCount.begin() + 1, digitCount.end(), 0) < digitCount.size() - 1) {
                    string cur = make(digitCount) + string(1, a + '0') + string(1, b + '0') + string(1, c + '0');
                    if (res == "-1" || res > cur)
                        res = cur;
                }

                digitCount[c]++;
            }

            digitCount[b]++;
        }

        digitCount[a]++;
    }

    cout << res;
}