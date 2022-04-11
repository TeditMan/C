#include <iostream>

struct Student{
    char name[20];
    double mean_score;
};

bool operator<(Student &left, Student &right) {
    return left.mean_score < right.mean_score;
}

bool operator<(Student &left, double &right) {
    return left.mean_score < right;
}
bool operator<(double &left, Student &right) {
    return left < right.mean_score;
}

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void qsort(Student *array, int n) {
    int l = 0, r = n - 1, k = n / 2;
    Student rep = array[k];
    if (n < 2) {
        return;
    }
    do {
        while (array[l] < rep) {
            l++;
        }
        while (rep < array[r]) {
            r--;
        }
        if (l < k and r > k) {
            swap(array[l], array[r]);
        }
        else if (l == k and r > k) {
            swap(array[k], array[r]);
            swap(array[r], array[k + 1]);
            k += 1;
            l += 1;
        }
        else if (l < k and r == k) {
            swap(array[k], array[l]);
            swap(array[l], array[k - 1]);
            k -= 1;
            r -= 1;
        }
    } while (l < r);
    qsort(array, k);
    qsort(array + k + 1, n - k - 1);
}

double mean(Student *array, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i].mean_score;
    }
    return sum / n;
}

int main() {
    int size = 8, k = 0;
    Student s_1{"a", 9.08},
            s_2{"b", 2.92},
            s_3{"c", 8.51},
            s_4{"d", 7.74},
            s_5{"e", 4.65},
            s_6{"f", 6.57},
            s_7{"g", 7.20},
            s_8{"h", 5.83};
    Student array_of_students[8] = {s_1, s_2, s_3, s_4, s_5, s_6, s_7, s_8};
    qsort(array_of_students, size);
    for (int i = size - 1; i >= 0; i--) {
        if (array_of_students[i].mean_score >= mean(array_of_students, 8)) {
            k += 1;
            std::cout << k << ". " << array_of_students[i].name << ": " << array_of_students[i].mean_score << std::endl;
        }
    }
    return 0;
}