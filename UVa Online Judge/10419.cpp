#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 300;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

string rec(int sum, int count, int last, vector<int> &primes) {
    if (sum < 0 || count < 0)
        return "No Solution.";
    if (last == primes.size())
        return sum || count ? "No Solution." : "";

    static vector<vector<vector<string>>> memo(1001, vector<vector<string>>(15, vector<string>(63, "?")));
    string &res = memo[sum][count][last];
    if (res != "?")
        return res;

    res = "No Solution.";

    int maxLastCount = (last ? 2 : 1);
    for (int lastCount = 0; lastCount <= maxLastCount; lastCount++) {
        string s = rec(sum - primes[last] * lastCount, count - lastCount, last + 1, primes);
        if (s == "No Solution.")
            continue;

        string n = "";
        for (int i = 0; i < lastCount; i++)
            n += (n.empty() ? "" : "+") + to_string(primes[last]);

        string cur = n;
        cur += (cur.empty() || s.empty() ? "" : "+") + s;
        if (res == "No Solution." || res > cur)
            res = cur;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                string l = s.substr(0, i), r = s.substr(i + 1);
                string cur = l;
                cur += (cur.empty() || n.empty() ? "" : "+") + n;
                cur += (cur.empty() || r.empty() ? "" : "+") + r;
                if (res == "No Solution." || res > cur)
                    res = cur;
            }
        }

        cur = s;
        cur += (cur.empty() || n.empty() ? "" : "+") + n;
        if (res == "No Solution." || res > cur)
            res = cur;
    }
    return res;
}

bool solve(int test) {
    int sum, count;
    cin >> sum >> count;

    if (!sum && !count)
        return 0;

    static vector<int> primes = getPrimes();
    string res = rec(sum, count, 0, primes);

    cout << "CASE " << test << ":\n";
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}