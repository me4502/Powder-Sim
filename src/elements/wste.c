#include <element.h>

int update_WSTE(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, trade, np;
    for (rx=-2; rx<3; rx++)
        for (ry=-2; ry<3; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r || (r&0xFF)==PT_WSTE)
                    continue;
                if ((r&0xFF)!=PT_DMND && (r&0xFF)!=PT_URAN && (r&0xFF)!=PT_PLUT && (r&0xFF)!=PT_DEUT && (r&0xFF)!=PT_NEUT && (r&0xFF)!=PT_WATR && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN)
                {
                    if ((r&0xFF)==PT_PLEX || (r&0xFF)==PT_NITR || (r&0xFF)==PT_GUNP || (r&0xFF)==PT_RBDM || (r&0xFF)==PT_LRBD)
                    {
                        part_change_type(i,x,y,PT_FIRE);
                        part_change_type(r>>8,x+rx,y+ry,PT_FIRE);
                        parts[r>>8].life = 4;
                    }
                    if (parts[i].life < 2)
                        part_change_type(i,x,y,PT_GLOW);
                    else if (rand()%700 == 1)
                    {
                        kill_part(r>>8);
                        parts[i].life -= parts[i].life -1;
                        return 1;
                    }
                }
                if ((r&0xFF)==PT_WATR||(r&0xFF)==PT_DSTW)
                {
                    parts[r>>8].tmp2 += 1;
                }
            }
    return 0;
}

