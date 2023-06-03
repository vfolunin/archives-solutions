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

    int size;
    string s;
    cin >> size >> s;

    vector<int> factorial = { 1 };
    for (int i = 1; i < size; i++)
        factorial.push_back(factorial[i - 1] * i);

    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        res += (s[i] - 'a') * factorial[size - 1 - i];
        for (int j = i + 1; j < s.size(); j++)
            s[j] -= s[i] < s[j];
    }

    cout << res;
}