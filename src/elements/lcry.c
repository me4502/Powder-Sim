#include <element.h>

int update_LCRY(UPDATE_FUNC_ARGS)
{
    if (parts[i].life>0 && parts[i].life!=10)
        parts[i].life--;
    if (parts[i].life==10)
    {
        int r, rx, ry;
        for (rx=-1; rx<2; rx++)
            for (ry=-1; ry<2; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    if ((r&0xFF)==PT_LCRY)
                    {
                        if (parts[r>>8].life<10&&parts[r>>8].life>0)
                            parts[i].life = 9;
                        else if (parts[r>>8].life==0)
                            parts[r>>8].life = 10;
                    }
                }
    }
    return 0;
}

int graphics_LCRY(GRAPHIC_FUNC_ARGS)
{
    uint8 GR = 0x50+((parts[i].life>10?10:parts[i].life)*10);
    vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(GR, GR, GR);
    if (parts[i].life>9)
    {
        if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
        {
            if (decorations_enable && parts[i].dcolour!=NULL)
            {
                cr = (parts[i].dcolour>>16)&0xFF;
                cg = (parts[i].dcolour>>8)&0xFF;
                cb = (parts[i].dcolour)&0xFF;
                vid[ny*(XRES+BARSIZE)+nx] = parts[i].dcolour;
                x = nx/CELL;
                y = ny/CELL;
                fire_g[y][x] = cg;
                fire_b[y][x] = cb;
                fire_r[y][x] = cr;
            }
            else
            {
                cr = 0x1;
                cg = 0x1;
                cb = 0x1;
                vid[ny*(XRES+BARSIZE)+nx] = ptypes[t].pcolors;
                x = nx/CELL;
                y = ny/CELL;
                cg += fire_g[y][x];
                if (cg > 255) cg = 255;
                fire_g[y][x] = cg;
                cb += fire_b[y][x];
                if (cb > 255) cb = 255;
                fire_b[y][x] = cb;
                cr += fire_r[y][x];
                if (cr > 255) cr = 255;
                fire_r[y][x] = cr;
            }
        }
    }
    else
    {
        x = nx/CELL;
        y = ny/CELL;
        fire_g[y][x] = 0;
        fire_b[y][x] = 0;
        fire_r[y][x] = 0;
        uint8 GR = 0x50+((parts[i].life>10?10:parts[i].life)*10);
        vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(GR, GR, GR);
    }

    return 0;
}
