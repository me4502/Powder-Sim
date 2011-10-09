#include <element.h>

int update_FWRK(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, np;
    if ((parts[i].temp>400&&(9+parts[i].temp/40)>rand()%100000&&parts[i].life==0&&!pmap[y-1][x])||parts[i].ctype==PT_DUST)
    {
        np = create_part(-1, x , y-1 , PT_FWRK);
        if (np!=-1)
        {
            parts[np].vy = rand()%8-22;
            parts[np].vx = rand()%20-rand()%20;
            parts[np].life=rand()%15+25;
            parts[np].dcolour = parts[i].dcolour;
            kill_part(i);
            return 1;
        }
    }
    if (parts[i].life>=45)
        parts[i].life=0;
    if ((parts[i].life<3&&parts[i].life>0)||(parts[i].vy>6&&parts[i].life>0))
    {
        int q = (rand()%255+1);
        int w = (rand()%255+1);
        int e = (rand()%255+1);
        for (rx=-1; rx<2; rx++)
            for (ry=-2; ry<3; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    if (5>=rand()%8)
                    {
                        if (!pmap[y+ry][x+rx])
                        {
                            np = create_part(-1, x+rx, y+ry , PT_DUST);
                            pv[y/CELL][x/CELL] += 2.00f*CFDS;
                            if (np!=-1)
                            {
                                parts[np].vy = -(rand()%10-1);
                                parts[np].vx = ((rand()%2)*2-1)*rand()%(5+5)+(parts[i].vx)*2 ;
                                parts[np].life= rand()%37+18;
                                parts[np].tmp=q;
                                parts[np].flags=w;
                                parts[np].ctype=e;
                                parts[np].temp= rand()%20+6000;
                                parts[np].dcolour = parts[i].dcolour;
                            }
                        }
                    }
                }
        kill_part(i);
        return 1;
    }
    return 0;
}

int graphics_DUST(GRAPHIC_FUNC_ARGS)
{
    if (parts[i].life >= 1)
    {
        x = nx;
        y = ny;
        cr = parts[i].flags;
        cg = parts[i].tmp;
        cb = parts[i].ctype;
        if (decorations_enable && parts[i].dcolour)
        {
            int a = (parts[i].dcolour>>24)&0xFF;
            cr = (a*((parts[i].dcolour>>16)&0xFF) + (255-a)*cr) >> 8;
            cg = (a*((parts[i].dcolour>>8)&0xFF) + (255-a)*cg) >> 8;
            cb = (a*((parts[i].dcolour)&0xFF) + (255-a)*cb) >> 8;
        }
        if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
        {
            vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(cg,cb,cr);//yes i know this pixel is different color than the glow... i don't know why
            cg = cg/4;
            cb = cb/4;
            cr = cr/4;
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
        else
            blendpixel(vid,x,y,cg,cb,cr,255);
    }
    else
    {
        return 1;
    }
    return 0;
}
