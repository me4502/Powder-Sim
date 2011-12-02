#include <element.h>

int update_CBTY(UPDATE_FUNC_ARGS) {
	int r, rx, ry, rt;
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;
				rt = parts[r>>8].type;
				if (parts_avg(i,r>>8,PT_INSL) != PT_INSL)
				{
					if (rt==PT_SPRK && parts[r>>8].ctype == PT_PSCN)
						parts[i].life += 1;
					else if (rt==PT_SPRK && parts[r>>8].ctype ==PT_NSCN && parts[i].life > 0)
						parts[i].life -= 1;
					else if ((ptypes[rt].properties&PROP_CONDUCTS) && !(rt==PT_WATR||rt==PT_SLTW||rt==PT_NTCT||rt==PT_PTCT||rt==PT_INWR) && parts[r>>8].life==0 && abs(rx)+abs(ry) < 4)
					{
						if ( parts[i].life!=0 && rt !=PT_NSCN && rt!=PT_PSCN)
						{
							parts[r>>8].life = 4;
							parts[r>>8].ctype = rt;
							part_change_type(r>>8,x+rx,y+ry,PT_SPRK);
							parts[i].life -= 1;
						}
					}
				}
				if (parts[i].life >= parts[i].tmp2) parts[i].life = parts[i].tmp2;
				if (parts[i].life <= 0) parts[i].life = 0;
				if (rt==PT_CBTY)
                {
                    if (parts[i].life != parts[r>>8].life  && parts[i].life > 0 && parts[r>>8].life < parts[i].tmp2 && rand()%2)
                    {
                        if (parts[i].life > parts[r>>8].life)
                        {
                            parts[i].life--;
                            parts[r>>8].life++;
                        } else {
                            parts[r>>8].life--;
                            parts[i].life++;
                        }
                    }
                }
			}
	return 0;
}
