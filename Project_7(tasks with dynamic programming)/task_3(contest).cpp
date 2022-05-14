#include <iostream>
using namespace std;

int min_energy_m(int *array, unsigned amount, int *m_table) {
    if (amount < 2) {
        m_table[amount] = 0;
        return 0;
    }
    if (m_table[amount] >= 0) {
        return m_table[amount];
    }
    int a = min_energy_m(array + 2, amount - 2, m_table) + 3 * abs(array[2] - array[0]);
    int b = min_energy_m(array + 1, amount - 1, m_table) + abs(array[1] - array[0]);
    int min_e = min(a, b);
    m_table[amount] = min_e;
    return min_e;
}

int min_energy(int *array, unsigned amount) {
    int *table = new int[amount + 1];
    for (unsigned i = 0; i <= amount; i++) {
        table[i] = -1;
    }
    return min_energy_m(array, amount, table);
}

int main() {
    unsigned amount;
    cin >> amount;
    auto platforms = new int[amount];
    for (unsigned i = 0; i < amount; i++) {
        cin >> platforms[i];
    }
    cout << min_energy(platforms, amount);
    return 0;
}