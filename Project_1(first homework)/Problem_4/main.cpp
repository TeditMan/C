#include "iostream"

using namespace std;

void spaces(int k) {
    for (int i = 1; i <= k; i++) {
        cout << char(32);
    }
}
int number_of_spaces(int counter) {
    int t = 0;
    if (counter == 2) {
        t = 1;
    }
    if (counter > 2) {
        t = 1 + 2 * (counter - 2);
    }
    return t;
}

int main() {
    int n;
    std::cin >> n;
    for (int k = 1; k <= n; k++) {
        int t = 0, z = 0;
        if (k > 1) {
            t = 1;
        }
        if (k > 2) {
            z = k - 2;
        }
        for (int i = 1; i <= n + t - k; i++) {
            cout << char(64 + i);
        }
        if (k == 1) {
            cout << char(64 + n);
        }
        spaces(number_of_spaces(k));
        for (int i = 1; i <= n + t - k; i++) {
            cout << char(64 + n - i - z);
        }
        cout << '\n';
    }
    return 0;
}
