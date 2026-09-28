class Solution {
    string toLower(string &s) {
        for (char &c : s)
            c = tolower(c);
        return s;
    }

    string normalize(string &email) {
        int atPos = email.find('@');
        string name = email.substr(0, atPos);
        name = name.substr(0, name.find('+'));
        name.erase(remove(name.begin(), name.end(), '.'), name.end());
        string domain = email.substr(atPos + 1);
        return toLower(name) + "@" + toLower(domain);
    }

public:
    int uniqueEmailGroups(vector<string> &emails) {
        unordered_set<string> normalizedEmails;
        for (string &email : emails)
            normalizedEmails.insert(normalize(email));
        return normalizedEmails.size();
    }
};