#include <element.h>

int update_BOMB(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, nb;
    if (parts[i].tmp==1)
    {
        for (rx=-2; rx<3; rx++)
            for (ry=-2; ry<3; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    if ((r&0xFF)!=PT_BOMB)
                    {
                        kill_part(i);
                        return 1;
                    }
                }
    }
    else if (parts[i].tmp==0)
    {
        for (rx=-2; rx<3; rx++)
            for (ry=-2; ry<3; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    if ((r&0xFF)!=PT_BOMB && (r&0xFF)!=PT_DMND && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_BCLN)
                    {
                        int rad = 8;
                        int nxi;
                        int nxj;
                        pmap[y][x] = 0;
                        for (nxj=-(rad+1); nxj<=(rad+1); nxj++)
                            for (nxi=-(rad+1); nxi<=(rad+1); nxi++)
                                if ((pow(nxi,2))/(pow((rad+1),2))+(pow(nxj,2))/(pow((rad+1),2))<=1)
                                {
                                    nb = create_part(-1, x+nxi, y+nxj, PT_BOMB);
                                    if (nb!=-1)
                                    {
                                        parts[nb].tmp = 1;
                                        parts[nb].life = 50;
                                        parts[nb].temp = MAX_TEMP;
                                        parts[nb].vx = rand()%20-10;
                                        parts[nb].vy = rand()%20-10;
                                    }
                                }
                        for (nxj=-rad; nxj<=rad; nxj++)
                            for (nxi=-rad; nxi<=rad; nxi++)
                                if ((pow(nxi,2))/(pow(rad,2))+(pow(nxj,2))/(pow(rad,2))<=1)
                                    if ((pmap[y+nxj][x+nxi]&0xFF)!=PT_DMND && (pmap[y+nxj][x+nxi]&0xFF)!=PT_CLNE && (pmap[y+nxj][x+nxi]&0xFF)!=PT_PCLN && (pmap[y+nxj][x+nxi]&0xFF)!=PT_BCLN)
                                    {
                                        delete_part(x+nxi, y+nxj, 0);//it SHOULD kill anything but the exceptions above, doesn't seem to always work
                                        pv[(y+nxj)/CELL][(x+nxi)/CELL] += 0.1f;
                                        nb = create_part(-1, x+nxi, y+nxj, PT_BOMB);
                                        if (nb!=-1)
                                        {
                                            parts[nb].tmp = 2;
                                            parts[nb].life = 2;
                                            parts[nb].temp = MAX_TEMP;
                                        }
                                    }
                        //create_parts(x, y, 9, 9, PT_BOMB);
                        //create_parts(x, y, 8, 8, PT_NONE);
                        kill_part(i);
                        return 1;
                    }
                }
    }
    return 0;
}

int graphics_BOMB(GRAPHIC_FUNC_ARGS)
{
    if (parts[i].tmp==0)
    {
        cr = PIXR(ptypes[t].pcolors);
        cg = PIXG(ptypes[t].pcolors);
        cb = PIXB(ptypes[t].pcolors);
        if (cmode != CM_CRACK)
        {
            int newx = 0;
            float flicker = rand()%20;
            float gradv = flicker + fabs(parts[i].vx)*17 + fabs(parts[i].vy)*17;
            blendpixel(vid, nx, ny, cr, cg, cb, (gradv*4)>255?255:(gradv*4) );
            blendpixel(vid, nx+1, ny, cr, cg, cb, (gradv*2)>255?255:(gradv*2) );
            blendpixel(vid, nx-1, ny, cr, cg, cb, (gradv*2)>255?255:(gradv*2) );
            blendpixel(vid, nx, ny+1, cr, cg, cb, (gradv*2)>255?255:(gradv*2) );
            blendpixel(vid, nx, ny-1, cr, cg, cb, (gradv*2)>255?255:(gradv*2) );
            if (gradv>255) gradv=255;
            blendpixel(vid, nx+1, ny-1, cr, cg, cb, gradv);
            blendpixel(vid, nx-1, ny-1, cr, cg, cb, gradv);
            blendpixel(vid, nx+1, ny+1, cr, cg, cb, gradv);
            blendpixel(vid, nx-1, ny+1, cr, cg, cb, gradv);
            for (newx = 1; gradv>0.5; newx++)
            {
                addpixel(vid, nx+newx, ny, cr, cg, cb, gradv);
                addpixel(vid, nx-newx, ny, cr, cg, cb, gradv);

                addpixel(vid, nx, ny+newx, cr, cg, cb, gradv);
                addpixel(vid, nx, ny-newx, cr, cg, cb, gradv);
                gradv = gradv/1.2f;
            }
        }
        else
        {
            blendpixel(vid, nx, ny, cr, cg, cb, 255);
        }
    }
    else if (parts[i].tmp==1)
    {
        cr = PIXR(ptypes[t].pcolors);
        cg = PIXG(ptypes[t].pcolors);
        cb = PIXB(ptypes[t].pcolors);
        if (cmode != CM_CRACK)
        {
            int newx = 0;
            float flicker = rand()%20;
            float gradv = 4*parts[i].life + flicker;
            for (newx = 0; gradv>0.5; newx++)
            {
                addpixel(vid, nx+newx, ny, cr, cg, cb, gradv);
                addpixel(vid, nx-newx, ny, cr, cg, cb, gradv);

                addpixel(vid, nx, ny+newx, cr, cg, cb, gradv);
                addpixel(vid, nx, ny-newx, cr, cg, cb, gradv);
                gradv = gradv/1.5f;
            }
        }
        else
        {
            blendpixel(vid, nx, ny, cr, cg, cb, 255);
        }
    }
    else
    {
        blendpixel(vid, nx, ny, 255, 255, 255, 255);
    }
    return 0;

}
