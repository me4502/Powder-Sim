#include <element.h>

int update_PHOT(UPDATE_FUNC_ARGS)
{
    int r, rt, rx, ry;
    float rr, rrr;
    parts[i].pavg[0] = x;
    parts[i].pavg[1] = y;
    if (!parts[i].ctype)
    {
        kill_part(i);
        return 1;
    }
    if (1>rand()%10) update_PYRO(UPDATE_FUNC_SUBCALL_ARGS);
    for (rx=-1; rx<2; rx++)
        for (ry=-1; ry<2; ry++)
            if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r)
                    continue;
                if ((r&0xFF)==PT_ISOZ && 5>(rand()%2000))
                {
                    parts[i].vx *= 0.90;
                    parts[i].vy *= 0.90;
                    create_part(r>>8, x+rx, y+ry, PT_PHOT);
                    rrr = (rand()%360)*3.14159f/180.0f;
                    rr = (rand()%128+128)/127.0f;
                    parts[r>>8].vx = rr*cosf(rrr);
                    parts[r>>8].vy = rr*sinf(rrr);
                    pv[y/CELL][x/CELL] -= 15.0f * CFDS;
                }
                if ((r&0xFF)==PT_ISZS && 5>(rand()%2000))
                {
                    parts[i].vx *= 0.90;
                    parts[i].vy *= 0.90;
                    create_part(r>>8, x+rx, y+ry, PT_PHOT);
                    rr = (rand()%228+128)/127.0f;
                    rrr = (rand()%360)*3.14159f/180.0f;
                    parts[r>>8].vx = rr*cosf(rrr);
                    parts[r>>8].vy = rr*sinf(rrr);
                    pv[y/CELL][x/CELL] -= 15.0f * CFDS;
                }
            }
    r = pmap[y][x];
    if((r&0xFF) == PT_QRTZ && r)// && parts[i].ctype==0x3FFFFFFF)
    {
        float a = (rand()%360)*3.14159f/180.0f;
        parts[i].vx = 3.0f*cosf(a);
        parts[i].vy = 3.0f*sinf(a);
        if(parts[i].ctype == 0x3FFFFFFF)
            parts[i].ctype = 0x1F<<(rand()%26);
        parts[i].life++; //Delay death
    }
    //r = pmap[y][x];
    //rt = r&0xFF;
    /*if (rt==PT_CLNE || rt==PT_PCLN || rt==PT_BCLN || rt==PT_PBCN) {
    	if (!parts[r>>8].ctype)
    		parts[r>>8].ctype = PT_PHOT;
    }*/

    return 0;
}

int graphics_PHOT(GRAPHIC_FUNC_ARGS)
{
    if (cmode == CM_FIRE||cmode==CM_BLOB || cmode==CM_FANCY)
    {
        cg = 0;
        cb = 0;
        cr = 0;
        for (x=0; x<12; x++)
        {
            cr += (parts[i].ctype >> (x+18)) & 1;
            cb += (parts[i].ctype >>  x)     & 1;
        }
        for (x=0; x<12; x++)
            cg += (parts[i].ctype >> (x+9))  & 1;
        x = 624/(cr+cg+cb+1);
        cr *= x;
        cg *= x;
        cb *= x;
        vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(cr>255?255:cr,cg>255?255:cg,cb>255?255:cb);
        cr >>= 4;
        cg >>= 4;
        cb >>= 4;
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
        cg = 0;
        cb = 0;
        cr = 0;
        for (x=0; x<12; x++)
        {
            cr += (parts[i].ctype >> (x+18)) & 1;
            cb += (parts[i].ctype >>  x)     & 1;
        }
        for (x=0; x<12; x++)
            cg += (parts[i].ctype >> (x+9))  & 1;
        x = 624/(cr+cg+cb+1);
        cr *= x;
        cg *= x;
        cb *= x;
        cr = cr>255?255:cr;
        cg = cg>255?255:cg;
        cb = cb>255?255:cb;
        if(cmode == CM_PERS)
        {
            if(parts[i].pavg[0] && parts[i].pavg[1])
            {
                draw_line(vid, nx, ny, parts[i].pavg[0], parts[i].pavg[1], cr, cg, cb, XRES+BARSIZE);
            }
            else
            {
                vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(cr, cg, cb);
            }
        }
        else
        {
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
    }
    return 0;
}
