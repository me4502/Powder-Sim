#include <element.h>

int update_BARI(UPDATE_FUNC_ARGS) {
	int r, rx, ry;
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;

				if (((r&0xFF)==PT_ALCO||(r&0xFF)==PT_WATR) && 1>(rand()%500))
				{
					parts[i].tmp = PT_BARI;
					parts[r>>8].tmp = PT_BARI;
					part_change_type(r>>8,x+rx,y+ry,PT_FIRE);
					part_change_type(i,x,y,PT_FIRE);
					parts[i].temp += 100;

					parts[i].life = 16;
					parts[r>>8].life = 16;
				}
				else if (rand()%25000 == 1)
				{
					kill_part(r>>8);
					return 1;
				}
			}
	return 0;
}
