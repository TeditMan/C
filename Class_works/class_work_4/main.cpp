#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int* compress(int **matrix, int n, int m) {
    int *k = new int, l = 0;
    int *compressed = new int[*k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                compressed[l] = matrix[i][j];
                l++;
            }
        }
    }
    *k = l + 1;
    return compressed;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int* compressed = compress(a, n, m);

    if (!compressed) return 0;

    for (int i = 0; i < n * 3; i++)
        cout << compressed[i] << " ";
    cout << endl;

    delete[] compressed;
    return 0;
}