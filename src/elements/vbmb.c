#include <element.h>

int update_VBMB(UPDATE_FUNC_ARGS) {
	int r,rx,ry,np;
	if (parts[i].tmp==1)
    {
        if (parts[i].temp < MAX_TEMP)
        {
            parts[i].tmp2++;
            parts[i].temp = 10 + parts[i].tmp2*50;
            pv[y/CELL][x/CELL] = 2 + parts[i].tmp2;
        }
        else
        {
            pv[y/CELL][x/CELL] = 256.0f;
            hv[y/CELL][x/CELL] = MAX_TEMP;
            parts[i].life = rand()%150+50;
            part_change_type(i,x,y,PT_PLSM);
        }
    }
    else if (parts[i].tmp==0)
    {
        if (parts[i].temp>0)
        {
            parts[i].temp-=1;
            pv[y/CELL][x/CELL] -=1;
        }
        else
        {
            pv[y/CELL][x/CELL] = -256.0f;
            hv[y/CELL][x/CELL] = 0;
            parts[i].tmp = 1;
        }
    }
	for (rx=-1;rx<2;rx++)
        for (ry=-1;ry<2;ry++)
            if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if (!r)
                {
                    if (parts[i].tmp==1 && rand()%100==1)
                        if (np=create_part(-1,x+rx,y+ry,PT_PLSM))
                            parts[np].life = rand()%150+50;
                    continue;
                }
                if ((r&0xFF)==PT_PLSM)
                    parts[i].temp+=100;

                if ((r&0xFF)!=PT_VBMB)
                {
                    if (parts[i].tmp==0)
                    parts[i].temp-=20;
                    else
                    parts[i].temp+=100;
                    parts[i].tmp2++;
                    kill_part(r>>8);
                }
                else
                {
                    if (parts[r>>8].tmp==1 && parts[i].tmp==0) parts[i].tmp==1;
                    if (parts[r>>8].tmp==0 && parts[i].tmp==1) parts[r>>8].tmp==1;
                }
            }
	return 0;
}
