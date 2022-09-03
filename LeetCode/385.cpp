class Solution {
    NestedInteger deserialize(stringstream &ss) {
        NestedInteger res;
        
        if (ss.peek() == '[') {
            ss.get();
            while (1) {
                if (ss.peek() == ']')
                    break;
                res.add(deserialize(ss));
                if (ss.peek() == ',')
                    ss.get();
            }
            ss.get();
        } else if (ss.peek() != ']') {
            int n;
            ss >> n;
            res.setInteger(n);
        }
        
        return res;
    }
    
public:
    NestedInteger deserialize(string &s) {
        stringstream ss(s);
        return deserialize(ss);
    }
};