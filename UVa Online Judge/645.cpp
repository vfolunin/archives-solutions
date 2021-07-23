#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Dir {
    string name;
    vector<Dir *> subdirs;
    vector<string> files;
};

struct DirStorage {
    list<Dir> dirs;

    Dir *add(const string &name) {
        dirs.push_back({ name });
        return &dirs.back();
    }
};

void print(const string &name, int offset) {
    for (int i = 0; i < offset; i++)
        cout << "|     ";
    cout << name << "\n";
}

void print(Dir *dir, int offset) {
    print(dir->name, offset);
    for (Dir *subDir : dir->subdirs)
        print(subDir, offset + 1);
    sort(dir->files.begin(), dir->files.end());
    for (const string &file : dir->files)
        print(file, offset);
}

bool solve(int test) {
    DirStorage dirs;
    Dir *root = dirs.add("ROOT");
    vector<Dir *> stack = { root };

    while (1) {
        string name;
        cin >> name;

        if (name == "#")
            return 0;

        if (name == "*")
            break;

        if (name == "]") {
            stack.pop_back();
        } else if (name[0] == 'd') {
            Dir *dir = dirs.add(name);
            stack.back()->subdirs.push_back(dir);
            stack.push_back(dir);
        } else {
            stack.back()->files.push_back(name);
        }
    }

    if (test > 1)
        cout << "\n";
    cout << "DATA SET " << test << ":\n";
    print(root, 0);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}