#include <element.h>

int update_GLOW(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    for (rx=-1; rx<2; rx++)
        for (ry=-1; ry<2; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r)
                    continue;
                if ((r&0xFF)==PT_WATR&&5>(rand()%2000))
                {
                    parts[i].type = PT_NONE;
                    part_change_type(r>>8,x+rx,y+ry,PT_DEUT);
                    parts[r>>8].life = 10;
                }
            }
    parts[i].ctype = pv[y/CELL][x/CELL]*16;

    parts[i].tmp = abs((int)((vx[y/CELL][x/CELL]+vy[y/CELL][x/CELL])*16.0f)) + abs((int)((parts[i].vx+parts[i].vy)*64.0f));
    //printf("%f %f\n", parts[i].vx, parts[i].vy);
    if (parts[i].type==PT_NONE)
    {
        kill_part(i);
        return 1;
    }
    return 0;
}

int graphics_GLOW(GRAPHIC_FUNC_ARGS)
{
    fr = restrict_flt(parts[i].temp-(275.13f+32.0f), 0, 128)/50.0f;
    fg = restrict_flt(parts[i].ctype, 0, 128)/50.0f;
    fb = restrict_flt(parts[i].tmp, 0, 128)/50.0f;

    cr = restrict_flt(64.0f+parts[i].temp-(275.13f+32.0f), 0, 255);
    cg = restrict_flt(64.0f+parts[i].ctype, 0, 255);
    cb = restrict_flt(64.0f+parts[i].tmp, 0, 255);

    vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(cr, cg, cb);
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

    for (x=-1; x<=1; x++)
    {
        for (y=-1; y<=1; y++)
        {
            if ((abs(x) == 0) && (abs(y) == 0))
                blendpixel(vid,x+nx,y+ny,cr,cg,cb,100);
            else if (abs(y) != 0 || abs(x) != 0)
                blendpixel(vid,x+nx,y+ny,cr,cg,cb,50);
        }
    }
}
