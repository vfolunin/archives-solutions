#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Student {
	string surname, name, formLetter, birthDate;
	int form;

	bool operator < (const Student &that) const {
		if (form != that.form)
			return form < that.form;
		if (formLetter != that.formLetter)
			return formLetter < that.formLetter;
		return surname < that.surname;
	}

	friend istream &operator >> (istream &in, Student &s) {
		return in >> s.surname >> s.name >> s.form >> s.formLetter >> s.birthDate;
	}

	friend ostream &operator << (ostream &out, Student &s) {
		return out << s.form << s.formLetter << " " << s.surname << " " << s.name << " " << s.birthDate;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int studentCount;
	cin >> studentCount;

	vector<Student> students(studentCount);
	for (Student &student : students)
		cin >> student;

	sort(students.begin(), students.end());

	for (Student &student : students)
		cout << student << "\n";
}