#include <iostream>
#include <sstream>
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
	stringstream ss(line);
	string word;
	while (ss >> word)
		words.push_back(word);

	return words;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<string> words = readWords();
	vector<string> names = readWords();

	cout << names[(words.size() - 1) % names.size()];
}