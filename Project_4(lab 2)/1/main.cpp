#include <cmath>
#include <iostream>
#include <iomanip>

double const pi = 3.14159265359;
double const e = 2.718281828459;

double f_si(double v, double T) {
    return 1.0 / pow(T * pi, 1.0 / 2) * pow(e, - v * v / T);
}

double f_df(double g) {
    return std::abs(g);
}

double mean_0(double const psi[], double const pdf[], double const dv, unsigned size) {
    double sum = 0;
    for (unsigned idx = 0; idx != size; idx++) {
        sum += psi[idx] * pdf[idx];
    }
    return dv * sum;
}

double mean_1(double *psi, double *pdf, double dv, unsigned size) {
    if (size < 2) {
        return dv * (psi[0] * pdf[0]);
    }
    return mean_1(psi, pdf, dv, size / 2) + mean_1(psi + size / 2,
                                                    pdf + size / 2, dv, size - size / 2);
}

double mean_2(double *psi, double *pdf, double dv, unsigned size) {
    for
}

double kehen_sum(unsigned)


int main() {
    unsigned size = 100000;
    double psi[size], pdf[size], gap = 1000, dv = gap / size, T = 273.16;
    for (int i = 0; i < size; i++) {
        psi[i] = f_si(-(gap / 2) + dv * i, T);
        pdf[i] = f_df(-(gap / 2) + dv * i);
    }
    std::cout << std::fixed << std::setprecision(10) << pow(T / pi, 0.5) << "   " <<
    mean_0(psi, pdf, dv, size) << '\n' << mean_1(psi, pdf, dv, size) << '\n';
    return 0;
}