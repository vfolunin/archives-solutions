#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Trie {
    struct Vertex {
        map<char, Vertex> next;
    } root;

    void add(const string &s) {
        Vertex *v = &root;
        for (const char &c : s)
            v = &v->next[c];
    }
};

vector<Trie> getDict() {
    int dictSize;
    cin >> dictSize;

    vector<Trie> dict(17);
    for (int i = 0; i < dictSize; i++) {
        string s;
        cin >> s;
        dict[s.size()].add(s);
    }

    return dict;
}

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    string word;

    for (char c : line) {
        if (c != ' ') {
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

struct Solver {
    vector<Trie> dict;
    vector<string> words;
    string cypher, used;

    bool recWord(int wi, int i, Trie::Vertex *v) {
        if (i == words[wi].size())
            return rec(wi + 1);

        char letter = words[wi][i], &codeLetter = cypher[letter - 'a'];

        if (codeLetter != '*')
            return v->next.count(codeLetter) && recWord(wi, i + 1, &v->next[codeLetter]);

        for (auto &[nextLetter, nextVertex] : v->next) {
            if (used[nextLetter - 'a'] == '1')
                continue;

            codeLetter = nextLetter;
            used[nextLetter - 'a'] = '1';

            if (recWord(wi, i + 1, &nextVertex))
                return 1;

            codeLetter = '*';
            used[nextLetter - 'a'] = '0';
        }

        return 0;
    }

    bool rec(int wi) {
        if (wi == words.size())
            return 1;

        string prevP = cypher, prevU = used;

        if (recWord(wi, 0, &dict[words[wi].size()].root))
            return 1;

        cypher = prevP;
        used = prevU;

        return 0;
    }

    bool solve() {
        words = readWords();
        if (words.empty())
            return 0;

        cypher.assign(26, '*');
        used.assign(26, '0');
        rec(0);

        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i])
                cout << cypher[c - 'a'];
            cout << (i + 1 < words.size() ? " " : "\n");
        }
        return 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solver solver;
    solver.dict = getDict();
    cin.ignore();

    while (solver.solve());
}