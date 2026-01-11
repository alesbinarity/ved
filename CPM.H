/* CPM.H */

char bios();
int bdos();

/* console status: 0 = no key, non-zero = key ready */
int cpm_kbhi();

/* console input: returns 0..127 (7-bit) */
int cpm_getc();

/* console output: prints one character */
int cpm_putc();

