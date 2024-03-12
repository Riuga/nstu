#include <iostream>
using namespace std;

void sgn_arr(long s[], signed char d[], long n) {
    _asm {
        mov ecx, n
        jecxz sgn_exit

        mov esi, s
        mov edi, d
        
        sgn_loop:
            lodsd
            shl eax, 1
            seta al
            sbb al, 0
            stosb   
        loop sgn_loop
        
        sgn_exit:
    }
}

int main()
{
    long x[5] = { 1, -3, 0, -6, 2 };
    signed char y[5];
    sgn_arr(x, y, 5);

    for (int i = 0; i < 5; i++) {
        cout << x[i] << endl;
    }
    cout << "----------" << endl;
    for (int i = 0; i < 5; i++) {
        cout <<(int) y[i] << endl;
    }
}