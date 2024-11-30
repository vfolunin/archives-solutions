#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int rec(int i, int mask, int curMask, vector<vector<int>> &possibleNote) {
	if (i == 6)
		return mask == curMask;

	int res = 0;
	for (int j = 0; j < 12; j++)
		if (possibleNote[i][j])
			res += rec(i + 1, mask, curMask | (1 << j), possibleNote);
	return res;
}

int x(int baseNote, vector<vector<int>> &possibleNote) {
	int a = baseNote;
	int b = (baseNote + 4) % 12;
	int c = (baseNote + 7) % 12;
	return rec(0, (1 << a) | (1 << b) | (1 << c), 0, possibleNote);
}

int xm(int baseNote, vector<vector<int>> &possibleNote) {
	int a = baseNote;
	int b = (baseNote + 3) % 12;
	int c = (baseNote + 7) % 12;
	return rec(0, (1 << a) | (1 << b) | (1 << c), 0, possibleNote);
}

int x7(int baseNote, vector<vector<int>> &possibleNote) {
	int a = baseNote;
	int b = (baseNote + 4) % 12;
	int c = (baseNote + 7) % 12;
	int d = (baseNote + 10) % 12;
	return rec(0, (1 << a) | (1 << b) | (1 << c) | (1 << d), 0, possibleNote);
}

int xm7(int baseNote, vector<vector<int>> &possibleNote) {
	int a = baseNote;
	int b = (baseNote + 3) % 12;
	int c = (baseNote + 7) % 12;
	int d = (baseNote + 10) % 12;
	return rec(0, (1 << a) | (1 << b) | (1 << c) | (1 << d), 0, possibleNote);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int size;
	cin >> size;

	unordered_map<string, int> note;
	note["A"] = 0;
	note["A#"] = note["Bb"] = 1;
	note["B"] = 2;
	note["C"] = 3;
	note["C#"] = note["Db"] = 4;
	note["D"] = 5;
	note["D#"] = note["Eb"] = 6;
	note["E"] = 7;
	note["F"] = 8;
	note["F#"] = note["Gb"] = 9;
	note["G"] = 10;
	note["G#"] = note["Ab"] = 11;

	vector<vector<int>> possibleNote(6, vector<int>(12));
	for (int i = 0; i < 6; i++) {
		string s;
		cin >> s;

		for (int j = 0; j <= size; j++)
			possibleNote[i][(note[s] + j) % 12] = 1;
	}

	string chord;
	cin >> chord;

	if (chord[chord.size() - 1] == '7') {
		if (chord[chord.size() - 2] == 'm')
			cout << xm7(note[chord.substr(0, chord.size() - 2)], possibleNote);
		else
			cout << x7(note[chord.substr(0, chord.size() - 1)], possibleNote);
	} else {
		if (chord[chord.size() - 1] == 'm')
			cout << xm(note[chord.substr(0, chord.size() - 1)], possibleNote);
		else
			cout << x(note[chord], possibleNote);
	}
}