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

	int voteCount;
	cin >> voteCount;

	map<string, int> votes;
	int maxVotes = 0;

	for (int i = 0; i < voteCount; i++) {
		string name;
		cin >> name;

		votes[name]++;
		maxVotes = max(maxVotes, votes[name]);
	}

	for (int y = maxVotes; y; y--) {
		for (auto &[name, votes] : votes)
			cout << (votes >= y ? "X" : ".");
		cout << "\n";
	}
}