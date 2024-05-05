template<typename T>
void input_arr(T *a, int &size) {
    cin >> size;
    for (int i = 0; i < size; i++)
        cin >> a[i];
}


template<typename T>
void output_arr(T *a, int size) {
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
}