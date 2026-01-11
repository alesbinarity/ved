/* CPM.H */
#define BDOS_CONIN   1
#define BDOS_CONOUT  2
#define BDOS_CONST   11

char bios();
/*
int bdos();
*/

int cpm_kbhi();
int cpm_getc();
int cpm_putc();

