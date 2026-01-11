/* MAIN.C */
#include "TERM.H"
#include "KBD.H"
#include "UTIL.H"

/* draw top/bottom lines and two vertical borders */
int mbox()
{
    U16 i;
    U8 r;

    /* top line */
    tgoto(1,1);
    i = 0;
    while (i < TCOLS) { tputc('='); i = i + 1; }

    /* bottom line */
    tgoto(TROWS,1);
    i = 0;
    while (i < TCOLS) { tputc('='); i = i + 1; }

    /* vertical borders */
    r = 2;
    while (r < TROWS) {
        tgoto(r,1);      tputc('|');
        tgoto(r,TCOLS);  tputc('|');
        r = r + 1;
    }

    return 0;
}

int main()
{
    tinit();
    tcls();

    mbox();

    tgoto(3,4);
    tputs("TERM SMOKE TEST");
    tgoto(5,4);
    tputs("Arrows/hjkl should move the cursor.");
    tgoto(6,4);
    tputs("Press 'q' to quit.");

    tgoto(8,4);
    tputs("If you see this, VT100 output works.");

    tgoto(10,4);
    tputs("Last key code:");

    tflsh();

    {
        U8 r;
        U8 c;
        int k;
        char b[6];

        r = 12;
        c = 4;



        while (1) {
            tgoto(r,c);
            tflsh();

            k = kget();


            if (k == 'q') break;

            if (k == 'h') k = K_LF;
            if (k == 'j') k = K_DN;
            if (k == 'k') k = K_UP;
            if (k == 'l') k = K_RT;

            if ((k == K_UP) && (r > 2)) r = r - 1;
            else if ((k == K_DN) && (r < (TROWS - 1))) r = r + 1;
            else if ((k == K_LF) && (c > 2)) c = c - 1;
            else if ((k == K_RT) && (c < (TCOLS - 1))) c = c + 1;

            /* show key code */
            u16_to_dec(k, b);
            tgoto(10,18);
            tputs("     ");
            tgoto(10,18);
            tputs(b);

            tflsh();
        }
    }

    tdone();
    return 0;
}

