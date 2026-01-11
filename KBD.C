/* KBD.C */
#include "KBD.H"
#include "CPM.H"

int kget()
{
    int ch;
    int c1;
    int c2;

    while (kbhit() == 0) { ; }
    ch = kgetc();

    if (ch == 27) {
        while (kbhit() == 0) { ; }
        c1 = kgetc();
        if (c1 == '[') {
            while (kbhit() == 0) { ; }
            c2 = kgetc();
            if (c2 == 'A') return K_UP;
            if (c2 == 'B') return K_DN;
            if (c2 == 'C') return K_RT;
            if (c2 == 'D') return K_LF;
            return K_ESC;
        }
        return K_ESC;
    }

    return ch;
}

