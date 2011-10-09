#include <element.h>

int update_ACID(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, trade, np;
    for (rx=-2; rx<3; rx++)
        for (ry=-2; ry<3; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r)
                    continue;
                if ((r&0xFF)!=PT_ACID)
                {
                    if ((r&0xFF)==PT_PLEX || (r&0xFF)==PT_NITR || (r&0xFF)==PT_GUNP || (r&0xFF)==PT_RBDM || (r&0xFF)==PT_LRBD)
                    {
                        part_change_type(i,x,y,PT_FIRE);
                        part_change_type(r>>8,x+rx,y+ry,PT_FIRE);
                        parts[i].life = 4;
                        parts[r>>8].life = 4;
                    }
                    else if (((r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && ptypes[r&0xFF].hardness>(rand()%1000))&&parts[i].life>=50)
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
    for ( trade = 0; trade<2; trade ++)
    {
        rx = rand()%5-2;
        ry = rand()%5-2;
        if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
        {
            r = pmap[y+ry][x+rx];
            if ((r>>8)>=NPART || !r)
                continue;
            if ((r&0xFF)==PT_ACID&&(parts[i].life>parts[r>>8].life)&&parts[i].life>0)//diffusion
            {
                int temp = parts[i].life - parts[r>>8].life;
                if (temp ==1)
                {
                    parts[r>>8].life ++;
                    parts[i].life --;
                }
                else if (temp>0)
                {
                    parts[r>>8].life += temp/2;
                    parts[i].life -= temp/2;
                }
            }
        }
    }
    return 0;
}

int graphics_ACID(GRAPHIC_FUNC_ARGS)
{
    int s,cr,cg,cb;
    if (parts[i].life>75) parts[i].life = 75;
    if (parts[i].life<49) parts[i].life = 49;
    s = (parts[i].life-49)*3;
    if (s==0) s = 1;
    cr = 0x86 + s*4;
    cg = 0x36 + s*1;
    cb = 0x90 + s*2;

    if (cr>=255)
        cr = 255;
    if (cg>=255)
        cg = 255;
    if (cb>=255)
        cb = 255;

    blendpixel(vid, nx, ny, cr, cg, cb, 255);

    if (cmode==CM_BLOB)
    {
        blendpixel(vid, nx+1, ny, cr, cg, cb, 223);
        blendpixel(vid, nx-1, ny, cr, cg, cb, 223);
        blendpixel(vid, nx, ny+1, cr, cg, cb, 223);
        blendpixel(vid, nx, ny-1, cr, cg, cb, 223);

        blendpixel(vid, nx+1, ny-1, cr, cg, cb, 112);
        blendpixel(vid, nx-1, ny-1, cr, cg, cb, 112);
        blendpixel(vid, nx+1, ny+1, cr, cg, cb, 112);
        blendpixel(vid, nx-1, ny+1, cr, cg, cb, 112);
    }
}
