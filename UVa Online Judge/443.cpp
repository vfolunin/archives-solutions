#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> precalc() {
    vector<long long> res;
    set<long long> q = { 1 };
    while (res.size() < 6000) {
        res.push_back(*q.begin());
        q.erase(q.begin());
        q.insert(res.back() * 2);
        q.insert(res.back() * 3);
        q.insert(res.back() * 5);
        q.insert(res.back() * 7);
    }
    return res;
}

string ending(int n) {
    if (n % 100 / 10 == 1)
        return "th";
    if (n % 10 == 1)
        return "st";
    if (n % 10 == 2)
        return "nd";
    if (n % 10 == 3)
        return "rd";
    return "th";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<long long> res = precalc();

    while (1) {
        int n;
        cin >> n;

        if (n)
            cout << "The " << n << ending(n) << " humble number is " << res[n - 1] << ".\n";
        else
            break;
    }
}