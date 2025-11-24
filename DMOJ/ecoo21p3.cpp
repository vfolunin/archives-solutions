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

    int questionCount, personCount, emailCount;
    cin >> questionCount >> personCount >> emailCount;

    vector<int> res(questionCount, -1), resScore(questionCount, -1);
    for (int i = 0; i < emailCount; i++) {
        int person, question, score;
        cin >> person >> question >> score;
        question--;

        if (resScore[question] < score) {
            res[question] = person;
            resScore[question] = score;
        }
    }

    for (int value : res)
        cout << value << " ";
}