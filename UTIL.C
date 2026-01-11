/* UTIL.C */
#include "UTIL.H"

int u16_to_dec(v, out)
U16 v;
char *out;
{
    char tmp[6];
    int i;
    int j;
    unsigned digit;

    i = 0;
    j = 0;

    if (v == 0) {
        out[0] = '0';
        out[1] = 0;
        return 1;
    }

    while (v > 0) {
        if (i >= 5) break;

        digit = (v % 10);
        tmp[i] = '0' + digit;

        i = i + 1;
        v = v / 10;
    }

    while (i > 0) {
        i = i - 1;
        out[j] = tmp[i];
        j = j + 1;
    }

    out[j] = 0;
    return j;
}

