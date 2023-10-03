#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
	string line;
	getline(cin, line);

	vector<string> words;
	string word;
	for (char c : line) {
		if (isalpha(c)) {
			word += c;
		} else if (!word.empty()) {
			words.push_back(word);
			word.clear();
		}
	}
	if (!word.empty())
		words.push_back(word);

	return words;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	map<string, vector<string>> anagrams;
	for (string word : readWords()) {
		string sortedWord;
		for (char c : word)
			sortedWord += tolower(c);
		sort(sortedWord.begin(), sortedWord.end());

		anagrams[sortedWord].push_back(word);
	}

	for (auto &[_, words] : anagrams)
		if (words.size() == 2)
			cout << words[0] << " " << words[1];
}