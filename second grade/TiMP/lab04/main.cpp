#include <iostream>
using namespace std;

unsigned int f(unsigned char n) {
    _asm {
        movzx eax, n
        mov ecx, eax

        f_loop:
            dec ecx
            jle f_end
            mul ecx
        jnc f_loop

        mov ecx, eax
        f_end:
        sub eax, ecx
    }
}

int main()
{
    unsigned char n = 5;
    unsigned int result = f(n);
    cout << result << endl;
}