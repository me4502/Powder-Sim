#include <element.h>

int update_LCRY(UPDATE_FUNC_ARGS)
{
<<<<<<< HEAD
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
=======
	int r, rx, ry;
	if(parts[i].tmp==1 || parts[i].tmp==0)
	{
		if(parts[i].tmp==1)
		{
			if(parts[i].life<=0)
				parts[i].tmp = 0;
			else
			{
				parts[i].life-=2;
				if(parts[i].life < 0)
					parts[i].life = 0;
			}	
		}
		for (rx=-1; rx<2; rx++)
			for (ry=-1; ry<2; ry++)
				if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
				{
					r = pmap[y+ry][x+rx];
					if (!r)
						continue;
					if ((r&0xFF)==PT_LCRY && parts[r>>8].tmp == 3)
					{
						parts[r>>8].tmp = 1;
					}
				}
	}
	else if(parts[i].tmp==2 || parts[i].tmp==3)
	{
		if(parts[i].tmp==2)
		{
			if(parts[i].life>=10)
				parts[i].tmp = 3;
			else
			{
				parts[i].life+=2;
				if(parts[i].life > 10)
					parts[i].life = 10;
			}
		}
		for (rx=-1; rx<2; rx++)
			for (ry=-1; ry<2; ry++)
				if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
				{
					r = pmap[y+ry][x+rx];
					if (!r)
						continue;
					if ((r&0xFF)==PT_LCRY && parts[r>>8].tmp == 0)
					{
						parts[r>>8].tmp = 2;
					}
				}
	}
	parts[i].tmp = parts[i].tmp;
	return 0;
>>>>>>> upstream/master
}
