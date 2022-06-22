class CombinationIterator {
    vector<string> combinations;
    int index = 0;
    
public:
    CombinationIterator(string s, int size) {
        string mask = string(size, '0') + string(s.size() - size, '1');
        do {
            string combination;
            for (int bit = 0; bit < mask.size(); bit++)
                if (mask[bit] == '0')
                    combination += s[bit];
            combinations.push_back(combination);
        } while (next_permutation(mask.begin(), mask.end()));
    }
    
    string next() {
        return combinations[index++];
    }
    
    bool hasNext() {
        return index < combinations.size();
    }
};