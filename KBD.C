/* KBD.C */
/* NOTE:
 * This keyboard handler assumes VT100-compatible escape sequences.
 * Host-side remapping (e.g. WordStar ^E/^X/^S/^D) is intentionally
 * not handled at this stage.
 */

#include "KBD.H"
#include "CPM.H"

int kget()
{
    int ch;
    int c1;
    int c2;

    while (cpm_kbhi() == 0) { ; }
    ch = cpm_getc();

    if (ch == 27) {
        while (cpm_kbhi() == 0) { ; }
        c1 = cpm_getc();
        if (c1 == '[') {
            while (cpm_kbhi() == 0) { ; }
            c2 = cpm_getc();
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

