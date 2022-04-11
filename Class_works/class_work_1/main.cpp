#include <iostream>

struct Cat {
    int start, length;
};

bool check_cats(Cat a, Cat b) {
    if (a.start + a.length - 1 < b.start or b.start + b.length - 1 < a.start and a.start + a.length - 1 < 30 and b.start + b.length - 1 < 30) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    std::cin >> n;
    Cat *array = new Cat[n];
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            std::cin >> array[i].start;
            std::cin >> array[i].length;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!check_cats(array[i], array[j])) {
                    done = false;
                    break;
                }
            }
        }
    }
    int boris_length;
    std::cin >> boris_length;
    Cat boris {boris_length, 0};
    int match = 0;
    done = false;
    while (boris.start < 30) {
        for (int j = 0; j < n; j++) {
            if (check_cats(boris, array[j])) {
                match += 1;
            }
        }
        if (match == n) {
            std::cout << boris.start;
            done = true;
            break;
        }
        boris.start += 1;
    }
    if (!done) {
        std::cout << -1;
    }
    return 0;
}