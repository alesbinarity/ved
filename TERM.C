/* TERM.C */
#include "TERM.H"
#include "CPM.H"

#define OUTSZ 512

char tbuf[OUTSZ];
U16  tlen;

/* internal helper — тоже лучше коротко, но он глобальный: сделаем уникальным */
int t_oraw(ch)
int ch;
{
    if (tlen >= OUTSZ) tflsh();
    tbuf[tlen] = ch;
    tlen = tlen + 1;
    return 0;
}

int tflsh()
{
    U16 i;

    i = 0;
    while (i < tlen) {
        kputc(tbuf[i]);
        i = i + 1;
    }
    tlen = 0;
    return 0;
}

int tputc(ch)
int ch;
{
    t_oraw(ch);
    return 0;
}

int tputs(s)
char *s;
{
    while (*s) {
        t_oraw(*s);
        s = s + 1;
    }
    return 0;
}

/* internal “print decimal” — уникально в первых 8 символах */
int t_pdec(v)
U16 v;
{
    char b[6];
    u16_to_dec(v, b);
    tputs(b);
    return 0;
}

int tgoto(r, c)
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

int tcls()
{
    tputc(0x1B); tputs("[2J");
    tputc(0x1B); tputs("[H");
    return 0;
}

int tel()
{
    tputc(0x1B); tputs("[K");
    return 0;
}

int tcur(hide)
int hide;
{
    tputc(0x1B);
    if (hide) tputs("[?25l");
    else      tputs("[?25h");
    return 0;
}

int tinit()
{
    tlen = 0;
    /*tcur(TRUE);*/
    tcur(0);
    tcls();
    tflsh();
    return 0;
}

int tdone()
{
    tcur(FALSE);
    tflsh();
    return 0;
}

