/* TERM.H - VT100 terminal output (strings are '\0'-terminated) */
#include "UTIL.H"

/* VT100 screen size used by ntvcm auto 80x24 mode */
#define TROWS 24
#define TCOLS 80

#define TCUR_SHOW 0
#define TCUR_HIDE 1


int tinit();
int tdone();

int tflsh();
int tputc();
int tputs();

int tgoto();   /* (row, col) */
int tcls();    /* clear + home */
int tel();     /* erase to end of line */
int tcur();    /* (hide!=0 hides cursor) */

