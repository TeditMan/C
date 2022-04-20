#include "C:\Users\User\CLionProjects\C\Project_5(tasks with pointers and structs)\task_1(single list)\SingleList.h"

struct Lecture{
    unsigned start = 0;
    unsigned end = 0;
};

bool intersection(Lecture a, Lecture b) {
    if ((a.end > b.start and a.start <= b.start) or (b.end > a.start and b.start <= a.start)) {
        return true;
    }
    else return false;
}

void swap(Lecture &a, Lecture &b) {
    Lecture tmp = a;
    a = b;
    b = tmp;
}

void qsort(Lecture *array, unsigned n) {
    if (n < 2) {
        return;
    }
    unsigned left_pointer = 0, right_pointer = n - 2;
    while (left_pointer < right_pointer or (n == 2 and left_pointer == right_pointer and array[0].end <= array[1].end)){
        while (array[left_pointer].end <= array[n - 1].end and left_pointer < n - 1) {
            left_pointer++;
        }
        while (array[right_pointer].end > array[n - 1].end and right_pointer > 0) {
            right_pointer--;
        }
        if (left_pointer < right_pointer) {
            swap(array[left_pointer], array[right_pointer]);
        }
    }
    swap(array[left_pointer], array[n - 1]);
    qsort(array, left_pointer);
    qsort(array + left_pointer + 1, n - left_pointer - 1);
}

int main() {
    unsigned N;
    std::cin >> N;
    assert(N <= 1000);
    auto *lectures = new Lecture[N];
    for (unsigned i = 0; i < N; i++) {
        std::cin >> lectures[i].start >> lectures[i].end;
        assert(lectures[i].start < lectures[i].end && "wrong input");
    }
    qsort(lectures, N);
    List *tmp_list = new List, *counter_list = new List;
    push_back(counter_list, 0);
    for (int i = 1, j; i < N; i = j) {
        for (j = i; lectures[i].end == lectures[j].end and j < N; j++) {
            push_back(tmp_list, j);
        }
        Lecture tmp {0, lectures[i - 1].end};
        for (unsigned k = 0; k < length(tmp_list); k++) {
            if (!intersection(tmp, lectures[get(tmp_list, k)])) {
                push_back(counter_list, get(tmp_list, k));
                break;
            }
        }
        clear(tmp_list);
    }
    std::cout << length(counter_list);
    return 0;
}