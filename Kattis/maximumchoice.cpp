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

    long long podCount, guessCount;
    cin >> podCount >> guessCount;

    int res = 1;
    while (podCount > guessCount) {
        podCount /= guessCount + 1;
        res++;
    }

    cout << res;
}