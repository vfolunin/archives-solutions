template<typename T>
T Max_Element(T *a, int size) {
    T res = a[0];
    for (int i = 1; i < size; i++)
        if (res < a[i])
            res = a[i];
    return res;
}