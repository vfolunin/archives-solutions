#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> digits(int n) {
    vector<int> res;
    for (int i = 0; i < 4; i++) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

pair<int, int> check(const vector<int> &a, const vector<int> &b) {
    int bulls = 0;
    vector<int> countInA(10), countInB(10);
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) {
            bulls++;
        } else {
            countInA[a[i]]++;
            countInB[b[i]]++;
        }
    }

    int cows = 0;
    for (int i = 0; i < 10; i++)
        cows += min(countInA[i], countInB[i]);

    return { bulls, cows };
}

bool test(vector<vector<int>> &guesses, int ans) {
    vector<int> a = digits(ans);
    for (vector<int> &guess : guesses) {
        auto [bulls, cows] = check(a, digits(guess[0]));
        if (bulls != guess[1] || cows != guess[2])
            return 0;
    }
    return 1;
}

void solve() {
    int guessCount;
    cin >> guessCount;

    vector<vector<int>> guesses(guessCount, vector<int>(3));
    for (vector<int> &guess : guesses) {
        char slash;
        cin >> guess[0] >> guess[1] >> slash >> guess[2];
    }
    
    vector<int> answers;
    for (int ans = 0; answers.size() <= 1 && ans < 10000; ans++)
        if (test(guesses, ans))
            answers.push_back(ans);

    if (answers.size() == 0)
        cout << "impossible\n";
    else if(answers.size() == 1)
        cout << setw(4) << setfill('0') << answers[0] << "\n";
    else
        cout << "indeterminate\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}