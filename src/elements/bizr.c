#include <element.h>

//Used by ALL 3 BIZR states
int update_BIZR(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, nr, ng, nb, na;
    float tr, tg, tb, ta, mr, mg, mb, ma;
    float blend;
    if(parts[i].dcolour)
    {
        for (rx=-2; rx<3; rx++)
            for (ry=-2; ry<3; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    if ((r&0xFF)!=PT_BIZR && (r&0xFF)!=PT_BIZRG  && (r&0xFF)!=PT_BIZRS)
                    {
                        blend = 0.95f;
                        tr = (parts[r>>8].dcolour>>16)&0xFF;
                        tg = (parts[r>>8].dcolour>>8)&0xFF;
                        tb = (parts[r>>8].dcolour)&0xFF;
                        ta = (parts[r>>8].dcolour>>24)&0xFF;

                        mr = (parts[i].dcolour>>16)&0xFF;
                        mg = (parts[i].dcolour>>8)&0xFF;
                        mb = (parts[i].dcolour)&0xFF;
                        ma = (parts[i].dcolour>>24)&0xFF;

                        nr = (tr*blend) + (mr*(1-blend));
                        ng = (tg*blend) + (mg*(1-blend));
                        nb = (tb*blend) + (mb*(1-blend));
                        na = (ta*blend) + (ma*(1-blend));

                        parts[r>>8].dcolour = nr<<16 | ng<<8 | nb | na<<24;
                    }
                }
    }
    return 0;
}

int graphics_BIZR(GRAPHIC_FUNC_ARGS)
{
    if (!parts[i].ctype)
        return 1;
    cg = 0;
    cb = 0;
    cr = 0;
    for (x=0; x<12; x++)
    {
        cr += (parts[i].ctype >> (x+18)) & 1;
        cb += (parts[i].ctype >>  x)     & 1;
    }
    for (x=0; x<14; x++)
        cg += (parts[i].ctype >> (x+9))  & 1;
    x = 624/(cr+cg+cb+1);
    cr *= x;
    cg *= x;
    cb *= x;
    cr = cr>255?255:cr;
    cg = cg>255?255:cg;
    cb = cb>255?255:cb;
    if (fabs(parts[i].vx)+fabs(parts[i].vy)>0 &&(cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY))
    {
        fg = 0;
        fb = 0;
        fr = 0;
        fg = cg/40 * fabs(parts[i].vx)+fabs(parts[i].vy);
        fb = cb/40 * fabs(parts[i].vx)+fabs(parts[i].vy);
        fr = cr/40 * fabs(parts[i].vx)+fabs(parts[i].vy);
        vid[ny*(XRES+BARSIZE)+nx] = PIXRGB((int)restrict_flt(cr, 0, 255), (int)restrict_flt(cg, 0, 255), (int)restrict_flt(cb, 0, 255));
        x = nx/CELL;
        y = ny/CELL;
        fg += fire_g[y][x];
        if (fg > 255) fg = 255;
        fire_g[y][x] = fg;
        fb += fire_b[y][x];
        if (fb > 255) fb = 255;
        fire_b[y][x] = fb;
        fr += fire_r[y][x];
        if (fr > 255) fr = 255;
        fire_r[y][x] = fr;
    }
    else
        blendpixel(vid, nx, ny, cr, cg, cb, 255);

    return 0;
}
