#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sum(long long a, long long b) {
    string sa = to_string(a);
    string sb = to_string(b);

    if (sa.size() > sb.size())
        swap(sa, sb);

    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    string res;

    for (int i = 0; i < sa.size(); i++) {
        int da = sa[i] - '0';
        int db = sb[i] - '0';
        int sum = da + db;
        res += sum % 10 + '0';
        if (sum > 9)
            res += '1';
    }
    
    res += sb.substr(sa.size());
    reverse(res.begin(), res.end());
    return stoll(res);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<long long> a(3);
    for (long long &value : a)
        cin >> value;

    set<long long> sums;
    sort(a.begin(), a.end());
    do {
        sums.insert(sum(a[0], sum(a[1], a[2])));
    } while (next_permutation(a.begin(), a.end()));

    cout << (sums.size() > 1 ? "YES\n" : "NO\n");
    for (long long sum : sums)
        cout << sum << "\n";
}