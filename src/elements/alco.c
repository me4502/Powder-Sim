#include <element.h>

int update_ALCO(UPDATE_FUNC_ARGS)
{
    int r, rx, ry, rt;
    
    if(!(rand()%200))
    {
        parts[i].tmp2 = rand()%40;
    }
    else if(parts[i].tmp2!=20)
    {
        parts[i].tmp2 -= (parts[i].tmp2>20)?1:-1;
    }
    
    for (rx=-1; rx<2; rx++)
        for (ry=-1; ry<2; ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r)
                    continue;
                rt = parts[r>>8].type;
                if (parts[i].temp >= 315.15f+273.15f && rt!=PT_FIRE && rt!=PT_LAVA && rt!=PT_PLSM)
                    part_change_type(i,x,y,PT_GAS);
            }
    return 0;
}
