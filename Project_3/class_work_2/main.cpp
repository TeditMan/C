#include <iostream>
// 3, 4

int n = 100;

void function() {
    int *d_array = new int[n];
    for (int i = 0; i < n; i++) {
        d_array[i] = i;
    }
    n += 1;
}

int main() {
    for (int i = 0; i < n; i++){
        function();
    }
    return 0;
}
