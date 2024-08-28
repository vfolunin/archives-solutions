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

    int size, targetLen;
    cin >> size >> targetLen;

    vector<int> a(size);
    for (int &value : a) {
        string s;
        cin >> s;

        value = count_if(s.begin(), s.end(), [](char c) {
            return !isdigit(c);
        });
    }

    vector<vector<long long>> ways(size, vector<long long>(targetLen + 1));
    for (int i = 0; i < size; i++) {
        ways[i][1] = 1;
        for (int len = 2; len <= targetLen; len++)
            for (int j = 0; j < i; j++)
                if (a[j] < a[i])
                    ways[i][len] += ways[j][len - 1];
    }

    long long res = 0;
    for (vector<long long> &ways : ways)
        res += ways.back();

    cout << (res ? res : -1);
}