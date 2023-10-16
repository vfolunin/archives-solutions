#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPermutation(string &a, string &b) {
    vector<int> count(10);
    for (char c : a)
        count[c - '0']++;
    for (char c : b)
        count[c - '0']--;

    if (count[0] < 0)
        return 0;
    for (int i = 1; i < count.size(); i++)
        if (count[i])
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    int sum;
    cin >> a >> b >> sum;

    sort(a.begin(), a.end());
    do {
        string bp = to_string(sum - stoll(a));
        if (isPermutation(b, bp)) {
            cout << "YES\n" << stoi(a) << " " << stoi(bp);
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "NO";
}