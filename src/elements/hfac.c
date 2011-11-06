#include <element.h>

int update_HFAC(UPDATE_FUNC_ARGS) {
    int r, rx, ry, trade, np;
    for (rx=-2; rx<3; rx++)
        for (ry=-2; ry<3; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry)) {
                r = pmap[y+ry][x+rx];
                if (!r)
                    continue;
                if ((r&0xFF)!=PT_HFAC && (r&0xFF)!=PT_PLAS)
                {
                    if ((r&0xFF)==PT_PLEX || (r&0xFF)==PT_NITR || (r&0xFF)==PT_GUNP || (r&0xFF)==PT_RBDM || (r&0xFF)==PT_LRBD)
                    {
                        part_change_type(i,x,y,PT_FIRE);
                        part_change_type(r>>8,x+rx,y+ry,PT_FIRE);
                        parts[r>>8].life = 4;
                    }
                    if (rand()%700 == 1)
                    {
                        kill_part(r>>8);
                        parts[i].life -= parts[i].life -1;
                        return 1;
                    }
                }
            }
    return 0;
}
