/* CPM.C */
#include "CPM.H"

int kgetc()
{
    return bios(3);
}

int kbhit()
{
    return bios(2);
}

int kputc(ch)
int ch;
{
    bios(4, ch);         /* CONOUT */
    return 0;
}

