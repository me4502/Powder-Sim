#include <element.h>

int update_CO2(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for (rx=-3; rx<4; rx++)
        for (ry=-3; ry<4; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if ((r>>8)>=NPART || !r)
                    continue;
                if ((r&0xFF)==PT_FIRE)
                {
                    kill_part(r>>8);
                    if(1>(rand()%150))
                    {
                        kill_part(i);
                        return 1;
                    }
                }
                if (((r&0xFF)==PT_WATR || (r&0xFF)==PT_DSTW) && 1>(rand()%250))
                {
                    part_change_type(i,x,y,PT_CBNW);
                    kill_part(r>>8);
                }
                if (tpt_comp==0)
                    parts[i].vx += rand()%3-1;
            }
    return 0;
}
