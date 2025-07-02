#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct File {
    string name;
    string extension;
    bool hasDot = 0;
    int index;

    friend istream &operator >> (istream &in, File &file) {
        in >> file.name;
        if (int dot = file.name.find("."); dot != -1) {
            file.extension = file.name.substr(dot + 1);
            file.name = file.name.substr(0, dot);
            file.hasDot = 1;
        }
        return in;
    }

    friend ostream &operator << (ostream &out, File &file) {
        return out << file.name << (file.hasDot ? "." : "") << file.extension;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int fileCount, moveCount;
    cin >> fileCount >> moveCount;

    vector<File> files(fileCount);
    unordered_map<string, int> nameCount, extensionCount;

    for (int i = 0; i < files.size(); i++) {
        cin >> files[i];
        files[i].index = i;

        nameCount[files[i].name]++;
        extensionCount[files[i].extension]++;
    }

    for (int i = 0; i < moveCount; i++) {
        vector<File> nextFiles;

        for (File &file : files) {
            if ((i % 2 ? nameCount[file.name] : extensionCount[file.extension]) == 1) {
                nameCount[file.name]--;
                extensionCount[file.extension]--;
            } else {
                nextFiles.push_back(file);
            }
        }

        files.swap(nextFiles);
    }

    sort(files.begin(), files.end(), [](File &a, File &b) {
        return a.index < b.index;
    });

    cout << files.size() << "\n";
    for (File &file : files)
        cout << file << "\n";
}