#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 2e7;
vector<int> isPrime(N, 1);
vector<int> twins;

void prepare() {
    for (int i = 2; i * i < N; i++)
        if (isPrime[i])
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;

    for (int i = 2; i + 2 < N; i++)
        if (isPrime[i] && isPrime[i + 2])
            twins.push_back(i);
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << "(" << twins[n - 1] << ", " << twins[n - 1] + 2 << ")\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    prepare();
    while (solve());
}