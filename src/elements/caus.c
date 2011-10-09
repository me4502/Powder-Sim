#include <element.h>

int update_CAUS(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, trade, np;
    for (rx=-2; rx<3; rx++)
        for (ry=-2; ry<3; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r)
                    continue;
                if ((r&0xFF)!=PT_ACID && (r&0xFF)!=PT_CAUS)
                {
                    if (((r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && ptypes[r&0xFF].hardness>(rand()%1000))&&parts[i].life>=50)
                    {
                        if (parts_avg(i, r>>8,PT_GLAS)!= PT_GLAS)//GLAS protects stuff from acid
                        {
                            float newtemp = ((60.0f-(float)ptypes[r&0xFF].hardness))*7.0f;
                            if(newtemp < 0)
                            {
                                newtemp = 0;
                            }
                            parts[i].temp += newtemp;
                            parts[i].life--;
                            kill_part(r>>8);
                        }
                    }
                    else if (parts[i].life<=50)
                    {
                        kill_part(i);
                        return 1;
                    }
                }
            }
    return 0;
}

int graphics_CAUS(GRAPHIC_FUNC_ARGS)
{
    if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
    {
        x = nx/CELL;
        y = ny/CELL;
        cg = PIXG(ptypes[t].pcolors)/3;
        cb = PIXB(ptypes[t].pcolors)/3;
        cr = PIXR(ptypes[t].pcolors)/3;
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
