#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
int main() {
    float s = 0;
    int n = 20000000;
    float *a = new float[n];
    #pragma acc kernels
    #pragma data acc copyin(a) copyout(s)
    for (int i = 0; i < n; i++) {
        a[i] = sin(i * 2 * M_PI / float(n));
        s += a[i];
        //cout << (a[i]);
    }
//    for (int i = 0; i < n; i++) {
//        s += a[i];
//    }
    cout << s << endl;
    return 0;
}
