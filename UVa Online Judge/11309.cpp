#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPalindrome(char time[]) {
    int l = 0, r = 3;
    while (l < 4 && time[l] == '0')
        l++;
    for (; l < r; l++, r--)
        if (time[l] != time[r])
            return 0;
    return 1;
}

void solve() {
    int h, m;
    scanf("%d:%d", &h, &m);
    int t = h * 60 + m;

    while (1) {
        t = (t + 1) % 1440;

        char time[5];
        sprintf(time, "%02d%02d", t / 60, t % 60);

        if (isPalindrome(time))
            break;
    }

    printf("%02d:%02d\n", t / 60, t % 60);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        solve();
}