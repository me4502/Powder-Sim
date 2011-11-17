#include <element.h>
#include "hmap.h"

int graphics_PLSM(GRAPHICS_FUNC_ARGS)
{
    int fr = 0,fg = 1,fb = 2;
    int fire = 1,pmode = 1, ret = 0, override = 0;
    int caddress = restrict_flt(restrict_flt((float)cpart->life, 0.0f, 200.0f)*3, 0.0f, (200.0f*3)-3);
    if (cpart->ctype==PT_NBLE)
    {
        pixel pc;
        pc = nmenu[cpart->tmp2].colour;
        *firea = 160;
        *fireg = PIXG(pc);
        *fireb = PIXB(pc);
        *firer = PIXR(pc);
        *colg = PIXG(pc);
        *colb = PIXB(pc);
        *colr = PIXR(pc);
        *pixel_mode |= PMODE_FLARE|PMODE_GLOW|PMODE_BLEND;
        *pixel_mode |= FIRE_BLEND;
        override = 1;
        fire = 0;
        pmode = 0;
    }
    else if (cpart->ctype==PT_FUSE)
    {
        *firea = 75;
        *fireg = 193;
        *fireb = 0;
        *firer = 227;
        *colg = 193;
        *colb = 0;
        *colr = 227;
        *pixel_mode |= PMODE_FLARE;
        *pixel_mode |= FIRE_BLEND;
        override = 1;
        fire = 0;
        pmode = 0;
    }
    if (!override)
    {
        *colr = (unsigned char)plasma_data[caddress+fr];
        *colg = (unsigned char)plasma_data[caddress+fg];
        *colb = (unsigned char)plasma_data[caddress+fb];

        *firea = 255;
        *firer = *colr;
        *fireg = *colg;
        *fireb = *colb;
    }

    if (pmode)
        *pixel_mode = PMODE_GLOW | PMODE_ADD; //Clear default, don't draw pixel
    if (fire)
        *pixel_mode |= FIRE_ADD|DECO_FIRE;
    //Returning 0 means dynamic, do not cache
    return ret;
}
