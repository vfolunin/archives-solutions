#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int wordCount, wordSize, targetDiff;
    cin >> wordCount >> wordSize >> targetDiff;

    vector<vector<int>> words(wordCount, vector<int>(wordSize));
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        for (int j = 0; j < word.size(); j++) {
            static string letters = "ACGT";
            words[i][j] = letters.find(word[j]);
        }
    }

    vector<unsigned int> wordWeight(words.size());
    unsigned int wordWeightSum = 0;
    for (int i = 0; i < words.size(); i++) {
        static minstd_rand generator;
        static uniform_int_distribution<unsigned int> distribution;
        wordWeight[i] = distribution(generator);
        wordWeightSum += wordWeight[i];
    }

    vector<vector<unsigned int>> letterColumnWeightSum(4, vector<unsigned int>(wordSize));
    for (int i = 0; i < words.size(); i++)
        for (int j = 0; j < words[i].size(); j++)
            letterColumnWeightSum[words[i][j]][j] += wordWeight[i];

    for (int i = 0; i < words.size(); i++) {
        unsigned int sum = 0;
        for (int j = 0; j < words[i].size(); j++)
            sum += wordWeightSum - letterColumnWeightSum[words[i][j]][j];

        if (sum == (wordWeightSum - wordWeight[i]) * targetDiff) {
            cout << i + 1 << "\n";
            break;
        }
    }
}