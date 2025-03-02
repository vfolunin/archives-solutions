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

    int sum = 0;

    sort(s.begin(), s.end());
    do {
        sum += stoi(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << sum;
}