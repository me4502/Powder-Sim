#include <element.h>
int update_GBMB(UPDATE_FUNC_ARGS)
{
    int rx,ry,r;
    if (parts[i].life<=0)
    {
        for (rx=-2; rx<3; rx++)
            for (ry=-2; ry<3; ry++)
            {
                r = pmap[y+ry][x+rx];
                if(!r)
                    continue;
                if((r&0xFF)!=PT_BOMB && (r&0xFF)!=PT_GBMB &&
                        (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN &&
                        (r&0xFF)!=PT_DMND)
                {
                    parts[i].life=60;
                    break;
                }
            }
    }
    if(parts[i].life>20)
        gravmap[y/CELL][x/CELL] = 20;
    if(parts[i].life<20 && parts[i].life>=1)
        gravmap[y/CELL][x/CELL] = -80;
    return 0;
}

int graphics_GBMB(GRAPHIC_FUNC_ARGS)
{
    if (parts[i].life<=0)  //not yet detonated
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
    else  //exploding
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
    return 0;
}
