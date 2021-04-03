#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    long long cookieCount, resCookie;
    cin >> cookieCount >> resCookie;
    cookieCount -= resCookie;

    cout << "Case #" << test << ":";
    if (!cookieCount) {
        cout << " 0\n";
        return;
    }
    
    vector<long long> cookiesPerGuest;
    for (long long guestCount = 1; guestCount * guestCount <= cookieCount; guestCount++) {
        if (cookieCount % guestCount == 0) {
            if (cookieCount / guestCount > resCookie)
                cookiesPerGuest.push_back(cookieCount / guestCount);
            if (guestCount * guestCount < cookieCount && guestCount > resCookie)
                cookiesPerGuest.push_back(guestCount);
        }
    }
    sort(cookiesPerGuest.begin(), cookiesPerGuest.end());

    for (long long c : cookiesPerGuest)
        cout << " " << c;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}