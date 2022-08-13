class ProductOfNumbers {
    vector<int> prefixProducts = { 1 };
    
public:    
    void add(int value) {
        if (value)
            prefixProducts.push_back(prefixProducts.back() * value);
        else
            prefixProducts = { 1 };
    }
    
    int getProduct(int k) {
        if (prefixProducts.size() <= k)
            return 0;
        return prefixProducts.back() / prefixProducts[prefixProducts.size() - k - 1];
    }
};