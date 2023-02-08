class FirstUnique {
    unordered_map<int, int> count;
    queue<int> unique;

public:
    FirstUnique(vector<int> &a) {
        for (int value : a)
            count[value]++;
        
        for (int value : a)
            if (count[value] == 1)
                unique.push(value);
    }
    
    int showFirstUnique() {
        while (!unique.empty() && count[unique.front()] > 1)
            unique.pop();
        return unique.empty() ? -1 : unique.front();
    }
    
    void add(int value) {
        count[value]++;
        if (count[value] == 1)
            unique.push(value);
    }
};