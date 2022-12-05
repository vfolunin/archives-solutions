struct VarComparator {
    bool operator() (const vector<string> &a, const vector<string> &b) const {
        if (a.size() != b.size())
            return a.size() > b.size();
        return a < b;
    }
};

struct Polynomial {
    map<vector<string>, int, VarComparator> coeffs;

    void removeZeros() {
        for (auto it = coeffs.begin(); it != coeffs.end(); ) {
            if (it->second)
                it++;
            else
                it = coeffs.erase(it);
        }
    }

    Polynomial() {}

    Polynomial(int coeff) {
        coeffs[{}] = coeff;
        removeZeros();
    }

    Polynomial(const string &var) {
        coeffs[{ var }] = 1;
    }

    Polynomial operator + (const Polynomial &that) {
        Polynomial res = *this;
        for (auto &[vars, coeff] : that.coeffs)
            res.coeffs[vars] += coeff;
        res.removeZeros();
        return res;
    }

    Polynomial operator - (const Polynomial &that) {
        Polynomial res = *this;
        for (auto &[vars, coeff] : that.coeffs)
            res.coeffs[vars] -= coeff;
        res.removeZeros();
        return res;
    }

    Polynomial operator * (const Polynomial &that) {
        Polynomial res;
        for (auto &[varsA, coeffA] : coeffs) {
            for (auto &[varsB, coeffB] : that.coeffs) {
                vector<string> vars;
                merge(varsA.begin(), varsA.end(), varsB.begin(), varsB.end(), back_inserter(vars));
                res.coeffs[vars] += coeffA * coeffB;
            }
        }
        res.removeZeros();
        return res;
    }

    vector<string> toString() {
        vector<string> res;
        for (auto &[vars, coeff] : coeffs) {
            res.push_back(to_string(coeff));
            for (const string &var : vars)
                res.back() += "*" + var;
        }
        return res;
    }
};

void addToken(vector<Polynomial> &polynomials, unordered_map<string, int> &vars, string &token) {
    if (token.empty())
        return;
    if (isdigit(token[0]))
        polynomials.push_back(Polynomial(stoi(token)));
    else if (vars.count(token))
        polynomials.push_back(Polynomial(vars[token]));
    else
        polynomials.push_back(Polynomial(token));
    token.clear();
}

void performOp(vector<Polynomial> &polynomials, string &ops) {
    Polynomial b = polynomials.back();
    polynomials.pop_back();

    Polynomial &a = polynomials.back();

    if (ops.back() == '+')
        a = a + b;
    else if (ops.back() == '-')
        a = a - b;
    else
        a = a * b;

    ops.pop_back();
}

Polynomial eval(string &s, unordered_map<string, int> &vars) {
    vector<Polynomial> polynomials;
    string ops, token;

    for (char c : s) {
        if (isalnum(c)) {
            token += c;
        } else {
            addToken(polynomials, vars, token);

            if (c == '(') {
                ops.push_back(c);
            } else if (c == ')') {
                while (ops.back() != '(')
                    performOp(polynomials, ops);
                ops.pop_back();
            } else if (!isspace(c)) {
                if (c != '*')
                    while (!ops.empty() && ops.back() != '(')
                        performOp(polynomials, ops);
                ops.push_back(c);
            }
        }
    }
    addToken(polynomials, vars, token);

    while (!ops.empty())
        performOp(polynomials, ops);

    return polynomials[0];
}

class Solution {
public:
    vector<string> basicCalculatorIV(string &s, vector<string> &names, vector<int> &values) {
        unordered_map<string, int> vars;
        for (int i = 0; i < names.size(); i++)
            vars[names[i]] = values[i];

        return eval(s, vars).toString();
    }
};