#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> sum(2);
    for (int i = 0; i < s.size(); i++)
        sum[i % 2] += s[i] - '0';

    cout << sum[0] * sum[1];
}