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
    cin >> size;

    vector<int> p(size);
    for (int &value : p) {
        cin >> value;
        value--;
    }

    vector<long long> factorial(size);
    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i;

    long long res = 1;
    for (int i = 0; i < p.size(); i++) {
        res += p[i] * factorial[p.size() - 1 - i];
        for (int j = i + 1; j < p.size(); j++)
            p[j] -= p[i] < p[j];
    }

    cout << res;
}