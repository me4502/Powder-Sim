#include <element.h>

int update_FRAN(UPDATE_FUNC_ARGS) {
	int r, rx, ry;
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;
				if (((r&0xFF)!=PT_FRAN && parts[r>>8].temp<100)||(r&0xFF)==PT_FIRE)
				{
					if (1>rand()%6)
					{
						parts[i].tmp = PT_FRAN;
						part_change_type(i,x,y,PT_FIRE);
						parts[r>>8].temp = parts[i].temp = 2000+273.15;
						parts[i].life = rand()%650+50;
						pv[y/CELL][x/CELL] += 14.5;
					}
				}
			}
	return 0;
}
