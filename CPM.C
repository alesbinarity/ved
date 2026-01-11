/* CPM.C - CP/M console I/O via BIOS calls */

#include "CPM.H"

int cpm_kbhi()
{
    return bios(2, 0) != 0;
}


int cpm_getc()
{
    return bios(3, 0);
}

int cpm_putc(ch)
int ch;
{
    bios(4, ch);
    return 0;
}

