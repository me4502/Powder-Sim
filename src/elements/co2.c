#include <element.h>

int update_CO2(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for (rx=-2; rx<3; rx++)
        for (ry=-2; ry<3; ry++)
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
            }
    return 0;
}

int graphics_CO2(GRAPHIC_FUNC_ARGS)
{
    if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
    {
        x = nx/CELL;
        y = ny/CELL;
        cg = PIXG(ptypes[t].pcolors)/4;
        cb = PIXB(ptypes[t].pcolors)/4;
        cr = PIXR(ptypes[t].pcolors)/4;
        cg += fire_g[y][x];
        if (cg > PIXG(ptypes[t].pcolors)/2) cg = PIXG(ptypes[t].pcolors)/2;
        fire_g[y][x] = cg;
        cb += fire_b[y][x];
        if (cb > PIXB(ptypes[t].pcolors)/2) cb = PIXB(ptypes[t].pcolors)/2;
        fire_b[y][x] = cb;
        cr += fire_r[y][x];
        if (cr > PIXR(ptypes[t].pcolors)/2) cr = PIXR(ptypes[t].pcolors)/2;
        fire_r[y][x] = cr;
    }
    else
    {
        for (x=-3; x<4; x++)
        {
            for (y=-3; y<4; y++)
            {
                if (abs(x)+abs(y) <2 && !(abs(x)==2||abs(y)==2))
                    blendpixel(vid,x+nx,y+ny, PIXR(ptypes[t].pcolors)/1.6, PIXG(ptypes[t].pcolors)/1.6, PIXB(ptypes[t].pcolors)/1.6, 30);
                if (abs(x)+abs(y) <=3 && abs(x)+abs(y))
                    blendpixel(vid,x+nx,y+ny, PIXR(ptypes[t].pcolors)/1.6, PIXG(ptypes[t].pcolors)/1.6, PIXB(ptypes[t].pcolors)/1.6, 10);
                if (abs(x)+abs(y) == 2)
                    blendpixel(vid,x+nx,y+ny, PIXR(ptypes[t].pcolors)/1.6, PIXG(ptypes[t].pcolors)/1.6, PIXB(ptypes[t].pcolors)/1.6, 20);
            }
        }
    }
    return 0;
}
