#include <iostream>
#include <cmath>

using namespace std;

double k(const double x);
int factorial(int n);
int main() {
    double zp, zk, S;
    int n;
    cout << "zp = ";
    cin >> zp;
    cout << "zk = ";
    cin >> zk;
    cout << "n = ";
    cin >> n;
    double dz = (zk - zp) / n;
    double z = zp;
    while (z <= zk) {
        S = k(z * z + 1) - k(z * z - 1) + 2 * k(z);
        cout << z << " " << S << endl;
        z += dz;
    }
    return 0;
}

double k(const double x) {
    if (abs(x) >= 1)
        return (exp(x) + sin(x) / pow(cos(x), 2) + 1);
    else {
        double S = 0;
        int i = 0;
        double a = 1;
        S = a;
        do {
            i++;
            double R = 1 / exp(x) * pow(x, i) / factorial(i);
            a *= R;
            S += a;
        } while (i < 5);
        return S;
    }
}

int factorial(int n) {
    int S = 1;
    for (int i = 2; i <= n; i++) {
        S *= i;
    }
    return S;
}