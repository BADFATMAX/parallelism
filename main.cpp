#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
int main() {
    double s;
    int n = 10000000;
    double *a = new double[n];
    #pragma acc kernels
    #pragma data acc copyin(a) copyout(s)
    for (int i = 0; i < n; i++) {
        a[i] = sin(i * 2 * M_PI / double(n));
        s += a[i];
        //cout << (a[i]);
    }
//    for (int i = 0; i < n; i++) {
//        s += a[i];
//    }
    cout << s << endl;
    return 0;
}
