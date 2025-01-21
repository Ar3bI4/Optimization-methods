#include <iostream>
#include <cmath>
using namespace std;
double proX(double x1) {
    double  xp;
    if (x1 <= -2)
        xp = -2;
    if (x1 >= 2)
        xp = 2;
    if (x1 > -2 && x1 < 2)
        xp = x1;
    return xp;
}
double proY(double x2) {
    double  yp;
    if (x2 <= 0)
        yp = 0;
    if (x2 >= 3)
        yp = 3;
    if (x2 > 0 && x2 < 3)
        yp = x2;
    return yp;
}
double f(double z1, double z2) {
    double res = pow(z1, 2) + 4 * pow(z2, 2) - 8 * z1 - 8 * z2;
    return res;
}
double fpr1(double z1, double z2) {
    double res = 2 * z1 - 8;
    return res;
}
double fpr2(double z1, double z2) {
    double res = 8 * z2 - 8;
    return res;
}
double fi(double z1, double z2, double s, double h1, double h2) {
    double res = f(z1 - h1 * s, z2 - h2 * s);
    return res;
}
int main() {
    double z1p = 0, z2p = 0;
    double z1 = 1;
    double e = 0.0001;
    double z2 = 1;
    double k1 = proX(z1);
    double k2 = proY(z2);   
    double i = 0.1;
    double s = 0;
    double h1 = fpr1(z1, z2);
    double h2 = fpr2(z1, z2);
    double* a = new double[2];
    double n = sqrt(pow(h1, 2) + pow(h2, 2));
    a[0] = fi(z1, z2, s, h1, h2);
    s += i;
    int c = 0;
    a[1] = fi(z1, z2, s, h1, h2);
    while (n > e) {
        s = 0;
        i = 0.1;
        a[0] = fi(z1, z2, s, h1, h2);
        s += i;
        a[1] = fi(z1, z2, s, h1, h2);
        while (a[0] > a[1]) {
            a[0] = a[1];
            s += i;
            a[1] = fi(z1, z2, s, h1, h2);
        }
        double B;
        double A;
        A = 0;
        B = s;
        double la = (1 + sqrt(5)) / 2;
        double del = (B - A) / (pow(la, 2));
        double X = A + del;
        double Y = B - del;
        double Fx = fi(z1, z2, A, h1, h2);
        double Fy = fi(z1, z2, B, h1, h2);
        while (B - A >= 2 * e) {
            if (fi(z1, z2, X, h1, h2) >= fi(z1, z2, Y, h1, h2)) {
                A = X;
                X = Y;
                Fx = Fy;
                Y = A + B - X;
                Fy = fi(z1, z2, Y, h1, h2);
            }
            else {
                B = Y;
                Y = X;
                Fy = Fx;
                X = A + B - Y;
                Fx = fi(z1, z2, X, h1, h2);
            }
        }
        s = ((A + B) / 2);
        c++;
        z1p = z1;
        z2p = z2;
        z1 = z1 - s * h1;                                                                                                                                                s = s / 10;
        z2 = z2 - s * h2;
        n = sqrt((z1p - proX(z1)) * (z1p - proX(z1)) + (z2p - proY(z2)) * (z2p - proY(z2)));
        if (z1 <= -2 || z1 >= 2 || z2 <= 0 || z2 >= 3) {
            z1 = proX(z1);
            z2 = proY(z2);
        }
        h1 = fpr1(z1, z2);
        h2 = fpr2(z1, z2);
    }
    cout.precision(-log10(e));
    cout << "X1: " << z1 << " " << endl;
    cout << "X2: " << z2 << " " << endl;
    cout << "f(X1,X2): " << f(z1, z2) << " " << endl;
    cout << "|h|: " << n << endl;
    cout << "Number of iterations: " << c << " " << endl;

}