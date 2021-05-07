#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ',') {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);
    return words;
}

struct Employee {
    string title;
    string firstName;
    string lastName;
    string address;
    string department;
    string homePhone;
    string workPhone;
    string campusBox;

    bool operator < (const Employee &that) const {
        return lastName < that.lastName;
    }

    void print() const {
        cout << string(40, '-') << "\n";
        cout << title << " " << firstName << " " << lastName << "\n";
        cout << address << "\n";
        cout << "Department: " << department << "\n";
        cout << "Home Phone: " << homePhone << "\n";
        cout << "Work Phone: " << workPhone << "\n";
        cout << "Campus Box: " << campusBox << "\n";
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int departmentCount;
    cin >> departmentCount;
    cin.ignore();

    vector<Employee> employees;

    for (int i = 0; i < departmentCount; i++) {
        string department;
        getline(cin, department);

        while (1) {
            string line;
            getline(cin, line);

            if (line.empty())
                break;

            vector<string> t = split(line);
            employees.push_back({ t[0], t[1], t[2], t[3], department, t[4], t[5], t[6] });
        }
    }

    sort(employees.begin(), employees.end());
    for (Employee &e : employees)
        e.print();
}