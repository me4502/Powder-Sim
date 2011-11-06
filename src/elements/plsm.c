#include <element.h>
#include "hmap.h"

int graphics_PLSM(GRAPHICS_FUNC_ARGS)
{
    if (cpart->ctype!=PT_NBLE){
        int caddress = restrict_flt(restrict_flt((float)cpart->life, 0.0f, 200.0f)*3, 0.0f, (200.0f*3)-3);
        *colr = (unsigned char)plasma_data[caddress];
        *colg = (unsigned char)plasma_data[caddress+1];
        *colb = (unsigned char)plasma_data[caddress+2];

        *firea = 255;
        *firer = *colr;
        *fireg = *colg;
        *fireb = *colb;

        *pixel_mode = PMODE_GLOW | PMODE_ADD; //Clear default, don't draw pixel
        *pixel_mode |= FIRE_ADD;
        //Returning 0 means dynamic, do not cache
        return 0;
    } else {
        pixel pc;
        pc = nmenu[cpart->tmp2].colour;
        *firea = 160;
        *fireg = PIXG(pc);
        *fireb = PIXB(pc);
        *firer = PIXR(pc);
        *colg = PIXG(pc);
        *colb = PIXB(pc);
        *colr = PIXR(pc);
        *pixel_mode |= FIRE_ADD;
        return 0;
    }
}
