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

    string answer, guess;
    cin >> answer >> guess;

    multiset<char> answerLetters(answer.begin(), answer.end());
    string feedback(answer.size(), '-');

    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == guess[i]) {
            feedback[i] = 'G';
            answerLetters.erase(answerLetters.find(guess[i]));
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        if (feedback[i] == '-' && answerLetters.contains(guess[i])) {
            feedback[i] = 'Y';
            answerLetters.erase(answerLetters.find(guess[i]));
        }
    }

    cout << feedback;
}