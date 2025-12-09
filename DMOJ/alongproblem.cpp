#include <algorithm>
#include <unordered_set>
#include <numeric>
using namespace std;

int divide(int a, int b) {
    return a / b;
}

int count_occurrences(string s, string pattern) {
    int res = 0;
    for (int i = 0; i + pattern.size() <= s.size(); i++)
        res += s.substr(i, pattern.size()) == pattern;
    return res;
}

vector<int> sort_array(vector<int> a) {
    sort(a.begin(), a.end());
    return a;
}

int max_size_k(vector<int> a, int width) {
    int cur = 0;
    for (int i = 0; i < width; i++)
        cur += a[i];

    int res = cur;
    for (int i = width; i < a.size(); i++) {
        cur += a[i] - a[i - width];
        res = max(res, cur);
    }
    return res;
}

char find_upper(char c) {
    return toupper(c);
}


bool is_prime(int n) {
    if (n < 2)
        return 0;

    for (long long d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;

    return 1;
}

int distinct_integers(vector<int> a) {
    return unordered_set<int>(a.begin(), a.end()).size();
}

bool is_inside(int x, int y, int rx, int ry, int w, int h) {
    return x <= rx && rx <= x + w && y <= ry && ry <= y + h;
}

bool is_even(int n) {
    return n % 2 == 0;
}

bool is_bit_on(int bit, int value) {
    return value & (1 << bit);
}

int create_max(vector<int> a) {
    sort(a.rbegin(), a.rend());
    int res = 0;
    for (int digit : a)
        res = res * 10 + digit;
    return res;
}

int factorial(int n, int mod) {
    long long res = 1 % mod;
    for (int i = 2; i <= n; i++)
        res = res * i % mod;
    return res;
}

bool should_feed(int a, int b, int c) {
    return a * b >= c;
}

pair<int, int> lowest_terms(int num, int den) {
    int d = gcd(num, den);
    return { num / d, den / d };
}

int find_sum(int n) {
    return n * (n + 1) / 2;
}

string find_type(int index) {
    static vector<string> res = {
        "max, do", "dhruv, fold", "abayomi, open", "snjezana, write", "yuxuan, close",
        "mohamed, move", "scarlet, crush", "anastasia, tear", "aksana, press", "alejandro, cut"
    };
    return res[index - 1];
}

string largest_lex(vector<string> a) {
    return *max_element(a.begin(), a.end());
}

vector<int> add_colours(vector<int> a, vector<int> b) {
    vector<int> res(a.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = min(a[i] + b[i], 255);
    return res;
}

string remove_occurrences(string s, string pattern) {
    string res;
    for (int i = 0; i < s.size(); ) {
        if (i + pattern.size() <= s.size() && s.substr(i, pattern.size()) == pattern) {
            i += pattern.size();
        } else {
            res += s[i];
            i++;
        }
    }
    return res;
}

bool AC() {
    return 1;
}