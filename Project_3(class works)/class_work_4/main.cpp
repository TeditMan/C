#include <iostream>

double cross(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double &x, double &y) {
    double r1 = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    double r2 = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    x = x1 + r1 * (x2 - x1);
    y = y1 + r2 * (y2 - y1);
}

struct line {
    double x, y, x2, y2;
};

int main() {
    int M = 15, N = 20;
    double length_1 = 5.0, length_2 = 10.0

}