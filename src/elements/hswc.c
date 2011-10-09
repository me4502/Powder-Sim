#include <element.h>

int update_HSWC(UPDATE_FUNC_ARGS)
{
    int r, rx, ry;
    if (parts[i].life>0 && parts[i].life!=10)
        parts[i].life--;
    if (parts[i].life==10)
    {
        for (rx=-2; rx<3; rx++)
            for (ry=-2; ry<3; ry++)
                if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
                {
                    r = pmap[y+ry][x+rx];
                    if (!r)
                        continue;
                    if ((r&0xFF)==PT_HSWC)
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

int graphics_HSWC(GRAPHIC_FUNC_ARGS)
{
    uint8 GR = 0x3B+((parts[i].life>10?10:parts[i].life)*19);
    vid[ny*(XRES+BARSIZE)+nx] = PIXRGB(GR, 10, 10);
    if (cmode == CM_BLOB)
    {
        blendpixel(vid, nx+1, ny, GR, 10, 10, 223);
        blendpixel(vid, nx-1, ny, GR, 10, 10, 223);
        blendpixel(vid, nx, ny+1, GR, 10, 10, 223);
        blendpixel(vid, nx, ny-1, GR, 10, 10, 223);

        blendpixel(vid, nx+1, ny-1, GR, 10, 10, 112);
        blendpixel(vid, nx-1, ny-1, GR, 10, 10, 112);
        blendpixel(vid, nx+1, ny+1, GR, 10, 10, 112);
        blendpixel(vid, nx-1, ny+1, GR, 10, 10, 112);
    }
    return 0;
}
