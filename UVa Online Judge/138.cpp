#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<pair<long long, long long>> prepare() {
    vector<pair<long long, long long>> res;
    for (long long last = 2; res.size() < 10; last++) {
        long long product = last * (last + 1) / 2;
        long long root = sqrt(product);
        while (root * root < product)
            root++;
        if (root * root == product)
            res.push_back({ root, last });
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<pair<long long, long long>> res = prepare();

    for (auto &[num, last] : res)
        cout << setw(10) << num << setw(10) << last << "\n";
}