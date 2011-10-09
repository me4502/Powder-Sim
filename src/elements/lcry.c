#include <element.h>

int update_LCRY(UPDATE_FUNC_ARGS)
{
    if (parts[i].life>0 && parts[i].life!=10)
        parts[i].life--;
    if (parts[i].life==10)
    {
        int r, rx, ry;
        for (rx=-1; rx<2; rx++)
            for (ry=-1; ry<2; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    if ((r&0xFF)==PT_LCRY)
                    {
                        if (parts[r>>8].life<10&&parts[r>>8].life>0)
                            parts[i].life = 9;
                        else if (parts[r>>8].life==0)
                            parts[r>>8].life = 10;
                    }
                }
    }
    return 0;
}

int graphics_LCRY(GRAPHIC_FUNC_ARGS)
{
    uint8 GR = 0x50+((parts[i].life>10?10:parts[i].life)*10);
    vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(GR, GR, GR);
    if (cmode == CM_BLOB)
    {
        blendpixel(vid, nx+1, ny, GR, GR, GR, 223);
        blendpixel(vid, nx-1, ny, GR, GR, GR, 223);
        blendpixel(vid, nx, ny+1, GR, GR, GR, 223);
        blendpixel(vid, nx, ny-1, GR, GR, GR, 223);

        blendpixel(vid, nx+1, ny-1, GR, GR, GR, 112);
        blendpixel(vid, nx-1, ny-1, GR, GR, GR, 112);
        blendpixel(vid, nx+1, ny+1, GR, GR, GR, 112);
        blendpixel(vid, nx-1, ny+1, GR, GR, GR, 112);
    }
    return 0;
}
