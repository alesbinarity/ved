/* TERM.H */
#include "UTIL.H"

#define TROWS 24
#define TCOLS 80

int tinit();
int tdone();

int tflsh();
int tputc();
int tputs();

int tgoto();   /* (row, col) */
int tcls();
int tel();
int tcur();    /* (hide) */

