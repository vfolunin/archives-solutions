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

    int size, limit;
    cin >> size >> limit;

    int res = 0, resScore = -1;
    for (int i = 0; i < size; i++) {
        int score = 0;

        for (int j = 1; j <= limit; j++) {
            string s;
            cin >> s;

            string correct = to_string(j);
            if (j % 15 == 0)
                correct = "fizzbuzz";
            else if (j % 3 == 0)
                correct = "fizz";
            else if (j % 5 == 0)
                correct = "buzz";

            score += s == correct;
        }

        if (resScore < score) {
            res = i + 1;
            resScore = score;
        }
    }

    cout << res;
}