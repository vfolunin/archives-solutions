#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getIsPrime() {
    vector<int> isPrime(65, 1);
    for (int i = 2; i < 65; i++)
        if (isPrime[i])
            for (int j = i * i; j < 65; j += i)
                isPrime[j] = 0;
    return isPrime;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<unsigned long long> superpowers;
    vector<int> isPrime = getIsPrime();
    unsigned long long limit = -1;

    for (unsigned long long i = 2; i < (1 << 16); i++) {
        unsigned long long x = i * i * i;
        for (int power = 4; x <= limit / i; power++) {
            x *= i;
            if (!isPrime[power])
                superpowers.insert(x);
        }
    }

    cout << "1\n";
    for (unsigned long long x : superpowers)
        cout << x << "\n";
}