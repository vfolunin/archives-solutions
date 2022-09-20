class Solution {
    string readElement(stringstream &ss) {
        char c;
        ss >> c;
        
        string element(1, c);
        
        while (islower(ss.peek())) {
            ss >> c;
            element += c;
        }
        
        return element;
    }
    
    pair<string, int> readMolecule(stringstream &ss) {
        string element = readElement(ss);
        int count = 1;
        
        if (isdigit(ss.peek()))
            ss >> count;
        
        return { element, count };
    }
    
    map<string, int> readBracket(stringstream &ss) {
        map<string, int> atoms;
        
        ss.get();
        while (ss.peek() != ')') {
            if (ss.peek() == '(') {
                for (auto &[element, count] : readBracket(ss))
                    atoms[element] += count;
            } else {
                auto [element, count] = readMolecule(ss);
                atoms[element] += count;
            }
        }
        ss.get();
        
        if (isdigit(ss.peek())) {
            int factor;
            ss >> factor;
            
            for (auto &[element, count] : atoms)
                count *= factor;
        }
        
        return atoms;
    }
    
    map<string, int> readFormula(stringstream &ss) {
        map<string, int> atoms;
        
        while (ss.peek() != EOF) {
            if (ss.peek() == '(') {
                for (auto &[element, count] : readBracket(ss))
                    atoms[element] += count;
            } else {
                auto [element, count] = readMolecule(ss);
                atoms[element] += count;
            }
        }
        
        return atoms;
    }
    
public:
    string countOfAtoms(string &s) {
        stringstream ss(s);
        map<string, int> atoms = readFormula(ss);
        
        stringstream ress;
        for (auto &[element, count] : atoms) {
            ress << element;
            if (count > 1)
                ress << count;
        }
        return ress.str();
    }
};