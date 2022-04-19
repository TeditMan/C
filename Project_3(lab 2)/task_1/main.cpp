#include <cmath>
#include <iostream>
#include <iomanip>

float const pi = 3.14159265359f;
float const e = 2.718281828459f;

float f_si(float v, float T) {
    return 1.f / powf(T * pi, 1.f / 2) * powf(e, - v * v / T);
}

float f_df(float g) {
    return std::abs(g);
}

double f_si(double v, double T) {
    return 1.0 / pow(T * pi, 1.0 / 2) * pow(e, - v * v / T);
}

double f_df(double g) {
    return std::abs(g);
}

int pow(int x, int y) {
    int factor = 1;
    for (int i = 0; i < y; i++) {
        factor *= x;
    }
    return factor;
}

float mean_0(float const *psi, float const *pdf, float const dv, unsigned size) {
    float sum = 0.f;
    for (unsigned i = 0; i < size; i++) {
        sum += psi[i] * pdf[i];
    }
    return dv * sum;
}

float mean_1(float *psi, float *pdf, float dv, unsigned size) {
    if (size < 2) {
        return dv * (psi[0] * pdf[0]);
    }
    return mean_1(psi, pdf, dv, size / 2) + mean_1(psi + size / 2,
                                                    pdf + size / 2, dv, size - size / 2);
}

float mean_2(float const *psi, float const *pdf, float const dv, unsigned size) {
    auto *sum = new float[size];
    for (int i = 0; i < size; i++) {
        sum[i] = psi[i] * pdf[i];
    }
    for (int i = 0; i < log2(size); i++) {
        for (int j = 0; j < size; j += pow(2, i + 1)) {
            sum[j] = sum[j] + sum[j + pow(2, i)];
        }
    }
    return dv * sum[0];
}

float mean_3(float const *psi, float const *pdf, float const dv, unsigned size) {
    float sum = 0.f, t = 0.f;
    for (unsigned i = 0; i < size; i++) {
        float y = psi[i] * pdf[i] - t;
        float z = sum + y;
        t = (z - sum) - y;
        sum = z;
    }
    return sum * dv;
}

float mean_4(float const *psi, float const *pdf, float const dv, unsigned size) {

}

double mean_5(double const *psi, double const *pdf, double const dv, unsigned size) {
    double sum = 0;
    for (unsigned i = 0; i < size; i++) {
        sum += psi[i] * pdf[i];
    }
    return dv * sum;
}

int main() {
    unsigned size = pow(2, 25);

    float size_f = powf(2.f, 25.f);
    float gap = 1000.f, dv = gap / size_f, T = 273.16f;
    auto *psi = new float[size];
    auto *pdf = new float[size];

    double size_d = pow(2.0, 25.0), gap_d = 1000.0, dv_d = gap_d / size_d;
    auto *psi_d = new double[size];
    auto *pdf_d = new double[size];
    for (unsigned i = 0; i < size; i++) {
        psi[i] = f_si(-(gap / 2) + dv * i, T);
        pdf[i] = f_df(-(gap / 2) + dv * i);
        psi_d[i] = f_si(-(gap_d / 2) + dv_d * i, T);
        pdf_d[i] = f_df(-(gap_d / 2) + dv_d * i);
    }
    std::cout << std::fixed << std::setprecision(10) << powf(T / pi, 0.5f) << '\n' << '\n' <<
    mean_0(psi, pdf, dv, size) << '\n' <<
    mean_1(psi, pdf, dv, size) << '\n' <<
    mean_2(psi, pdf, dv, size) << '\n' <<
    mean_3(psi, pdf, dv, size) << '\n' <<
    mean_5(psi_d, pdf_d, dv_d, size) << '\n';
    delete[] psi, delete[] pdf;
    return 0;
}