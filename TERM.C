/* TERM.C - VT100 terminal output with small buffer */

#include "TERM.H"
#include "CPM.H"
#include "UTIL.H"

#define OUTSZ 512


char tbuf[OUTSZ]; /* output buffer */
U16  tlen; /* current len of tbuffer */

/* internal: buffered output of one char */
int t_oraw(ch) /* put char to buffer */
int ch;
{
    if (tlen >= OUTSZ) tflsh();
    tbuf[tlen] = ch;
    tlen = tlen + 1;
    return 0;
}

int tflsh() /* send buffer to terminal */
{
    U16 i;

    i = 0;
    while (i < tlen) {
        cpm_putc(tbuf[i]);
        i = i + 1;
    }
    tlen = 0;
    return 0;
}

int tputc(ch) /* public wrapper to t_oraw */
int ch;
{
    t_oraw(ch);
    return 0;
}

int tputs(s) /* put zero terminated string to buffer */
char *s;
{
    while (*s) {
        t_oraw(*s);
        s = s + 1;
    }
    return 0;
}

/* internal: print decimal (U16) */
int t_pdec(v)
U16 v;
{
    char b[6];
    u16_to_dec(v, b);
    tputs(b);
    return 0;
}

int tgoto(r, c) /* go to cursor to position */
U8 r;
U8 c;
{
    tputc(0x1B);
    tputc('[');
    t_pdec(r);
    tputc(';');
    t_pdec(c);
    tputc('H');
    return 0;
}

int tcls() /* clear screen and home */
{
    tputc(0x1B); tputs("[2J");
    tputc(0x1B); tputs("[H");
    return 0;
}

int tel() /* clear to EOL */
{
    tputc(0x1B); tputs("[K");
    return 0;
}

int tcur(hide) /* hide cursor */
int hide;
{
    tputc(0x1B);
    if (hide) tputs("[?25l");
    else      tputs("[?25h");
    return 0;
}

int tinit() /* initilaze terminal */
{
    tlen = 0;
    tcur(0);
    tcls();
    tflsh();
    return 0;
}

int tdone() /* restore terminal status after exit */
{
    tcur(FALSE);
    tflsh();
    return 0;
}

