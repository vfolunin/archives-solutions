class StringIterator {
    vector<pair<char, int>> parts;
    int i = 0, j = 0;

public:
    StringIterator(string &s) {
        stringstream ss(s);
        char c;
        int count;
        while (ss >> c >> count)
            parts.push_back({ c, count });
    }
    
    char next() {
        if (i == parts.size())
            return ' ';
        
        char c = parts[i].first;
        
        j++;
        if (j == parts[i].second) {
            i++;
            j = 0;
        }

        return c;
    }
    
    bool hasNext() {
        return i < parts.size();
    }
};