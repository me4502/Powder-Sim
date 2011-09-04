#include <element.h>

int update_VIRS(UPDATE_FUNC_ARGS)
{
    int r, tmp, rx, ry;
    for (rx=-2; rx<3; rx++)
        for (ry=-2; ry<3; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r || (r&0xFF)==PT_VIRS || (r&0xFF)==PT_DMND || parts[r>>8].disease > 0)
                    continue;
                parts[r>>8].ctype = parts[r>>8].type;
                parts[r>>8].tmp2 = parts[r>>8].ctype;
                parts[r>>8].type = PT_VIRS;
                parts[r>>8].disease = rand()%100+50;
            }
    return 0;
}
