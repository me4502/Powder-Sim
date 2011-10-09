#include <element.h>

int update_FIRW(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, rt, np;
    if (parts[i].tmp==0)
    {
        for (rx=-1; rx<2; rx++)
            for (ry=-1; ry<2; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    rt = parts[r>>8].type;
                    if (rt==PT_FIRE||rt==PT_PLSM||rt==PT_THDR)
                    {
                        parts[i].tmp = 1;
                        parts[i].life = rand()%50+60;
                    }
                }
    }
    else if (parts[i].tmp==1)
    {
        if (parts[i].life==0)
        {
            parts[i].tmp=2;
        }
        else
        {
            float newVel = parts[i].life/25;
            parts[i].flags = parts[i].flags&0xFFFFFFFE;
            /* TODO:
            if ((pmap[(int)(ly-newVel)][(int)lx]&0xFF)==PT_NONE && ly-newVel>0) {
            	parts[i].vy = -newVel;
            	ly-=newVel;
            	iy-=newVel;
            }*/
            parts[i].vy = -newVel;
        }
    }
    else if (parts[i].tmp==2)
    {
        int col = rand()%200+4;
        int tmul;
        for (rx=-2; rx<3; rx++)
            for (ry=-2; ry<3; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    tmul = rand()%7;
                    np = create_part(-1, x+rx, y+ry, PT_FIRW);
                    if (np>-1)
                    {
                        parts[np].vx = (rand()%3-1)*tmul;
                        parts[np].vy = (rand()%3-1)*tmul;
                        parts[np].tmp = col;
                        parts[np].life = rand()%100+100;
                        parts[np].temp = 6000.0f;
                        parts[np].dcolour = parts[i].dcolour;
                    }
                }
        pv[y/CELL][x/CELL] += 20;
        kill_part(i);
        return 1;
    }
    else if (parts[i].tmp>=3)
    {
        if (parts[i].life<=0)
        {
            kill_part(i);
            return 1;
        }
    }
    return 0;
}

int graphics_FIRW(GRAPHIC_FUNC_ARGS)
{
    if (parts[i].tmp>=3)
    {
        float ttemp = (float)parts[i].tmp-4;
        int caddress = restrict_flt(restrict_flt(ttemp, 0.0f, 200.0f)*3, 0.0f, (200.0f*3)-3);
        uint8 R = firw_data[caddress];
        uint8 G = firw_data[caddress+1];
        uint8 B = firw_data[caddress+2];
        if (decorations_enable && parts[i].dcolour)
        {
            int a = (parts[i].dcolour>>24)&0xFF;
            R = (a*((parts[i].dcolour>>16)&0xFF) + (255-a)*R) >> 8;
            G = (a*((parts[i].dcolour>>8)&0xFF) + (255-a)*G) >> 8;
            B = (a*((parts[i].dcolour)&0xFF) + (255-a)*B) >> 8;
        }
        if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
        {
            cr = R/2;
            cg = G/2;
            cb = B/2;
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
        {
            cr = R;
            cg = G;
            cb = B;
            blendpixel(vid, nx, ny, cr, cg, cb, 192);
            blendpixel(vid, nx+1, ny, cr, cg, cb, 96);
            blendpixel(vid, nx-1, ny, cr, cg, cb, 96);
            blendpixel(vid, nx, ny+1, cr, cg, cb, 96);
            blendpixel(vid, nx, ny-1, cr, cg, cb, 96);
            blendpixel(vid, nx+1, ny-1, cr, cg, cb, 32);
            blendpixel(vid, nx-1, ny+1, cr, cg, cb, 32);
            blendpixel(vid, nx+1, ny+1, cr, cg, cb, 32);
            blendpixel(vid, nx-1, ny-1, cr, cg, cb, 32);
        }
    } else {
        return 1;
    }
    return 0;
}
