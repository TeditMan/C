#include <iostream>
#include <cassert>
struct Cat {
    unsigned start = 0;
    unsigned length = 0;
};

bool check_cats(Cat a, Cat b) {
    if (a.start + a.length <= b.start or b.start + b.length <= a.start) {
        return true;
    }
    else return false;
}

bool check_array(Cat *array, Cat Boris, unsigned array_length) {
    bool answer = true;
    for (unsigned i = 0; i < array_length; i++) {
        if (!check_cats(array[i], Boris)) {
            answer = false;
            break;
        }
    }
    return answer;
}

int main() {
    unsigned n;
    std::cin >> n;
    assert(n <= 30);
    Cat *array = new Cat[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i].start;
        std::cin >> array[i].length;
        assert(array[i].start < 30 and array[i].start + array[i].length <= 30);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            assert(check_cats(array[i], array[j]));
        }
    }
    Cat Boris;
    std::cin >> Boris.length;
    while (!check_array(array, Boris, n)) {
        Boris.start += 1;
        if (Boris.start + Boris.length > 30) {
            std::cout << -1;
            break;
        }
    }
    if (Boris.start + Boris.length <= 30) {
        std::cout << Boris.start;
    }
    return 0;
}