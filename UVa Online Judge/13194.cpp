#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
	const int N = 1e6;
	vector<int> isPrime(N, 1), primes;
	for (int i = 2; i < N; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (long long j = 1LL * i * i; j < N; j += i)
				isPrime[j] = 0;
		}
	}
	return primes;
}

map<long long, int> factorize(long long n) {
    map<long long, int> f;	
	static vector<int> primes = getPrimes();
	for (int i = 0; i < primes.size() && n >= primes[i]; i++) {
        while (n % primes[i] == 0) {
            f[primes[i]]++;
            n /= primes[i];
        }
    }
    if (n != 1)
        f[n]++;
    return f;
}

long long divisorSum(long long n) {
    map<long long, int> f = factorize(n);
	long long res = 1;
	for (auto &[primeDivisor, power] : f) {
		long long sum = 0, product = 1;
		for (int i = 0; i <= power; i++) {
			sum += product;
			product *= primeDivisor;
		}
		res *= sum;
	}
    return res - n;
}

void solve() {
    long long n;
    cin >> n;

    long long sum = divisorSum(n);

    if (sum < n)
        cout << "deficient\n";
    else if (sum == n)
        cout << "perfect\n";
    else
        cout << "abundant\n"; 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}