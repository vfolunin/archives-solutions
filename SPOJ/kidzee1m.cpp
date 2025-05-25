#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int time;
    cin >> time;

    vector<string> names = { "second", "minute", "hour", "day", "month", "year" };
    vector<int> divisors = { 1, 60, 60, 24, 30, 12 };
    for (int i = 1; i < divisors.size(); i++)
        divisors[i] *= divisors[i - 1];

    cout << "Case " << test << ": ";
    for (int i = divisors.size() - 1; i >= 0; i--) {
        int count = time / divisors[i];
        if (count)
            cout << count << " " << names[i] << (count > 1 ? "s " : " ");
        time %= divisors[i];
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}