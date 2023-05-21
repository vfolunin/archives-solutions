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

    set<int> formSet;
    map<int, int> scoreSum, scoreCount;

    string name;
    int form, score;
    while (cin >> name >> name >> form >> score) {
        formSet.insert(form);
        scoreSum[form] += score;
        scoreCount[form]++;
    }

    vector<int> forms(formSet.begin(), formSet.end());
    stable_sort(forms.begin(), forms.end(), [&](int a, int b) {
        return scoreSum[a] * scoreCount[b] > scoreSum[b] * scoreCount[a];
    });

    for (int form : forms)
        cout << form << " ";
}