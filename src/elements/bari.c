#include <element.h>

int update_BARI(UPDATE_FUNC_ARGS)
{
	int r, rx, ry, rt;
	
	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				if ((r&0xFF)==PT_ALCO || (r&0xFF)==PT_WATR) {
					part_change_type(i,x,y,PT_FIRE);
					part_change_type(r>>8,x+rx,y+ry,PT_FIRE);
				}
			}
	return 0;
}
