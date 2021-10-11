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

    int answer;
    cin >> answer;

    int res = 0;

    for (int i = 0; i < 5; i++) {
        int guess;
        cin >> guess;
        res += guess == answer;
    }

    cout << res << "\n";
}