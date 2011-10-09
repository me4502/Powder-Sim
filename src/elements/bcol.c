#include <element.h>

int update_BCOL(UPDATE_FUNC_ARGS) {
	int r, rx, ry, trade, temp;
	if (parts[i].life<=0) {
		create_part(i, x, y, PT_FIRE);
		return 1;
	} else if (parts[i].life < 100) {
		parts[i].life--;
		create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_FIRE);
	}

	for (rx=-2; rx<3; rx++)
		for (ry=-2; ry<3; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;
				if (((r&0xFF)==PT_FIRE || (r&0xFF)==PT_PLSM) && 1>(rand()%500))
				{
					if (parts[i].life>100) {
						parts[i].life = 99;
					}
				}
				if ((r&0xFF)==PT_LAVA && 1>(rand()%500))
				{
					if (parts[r>>8].ctype == PT_IRON) {
						parts[r>>8].ctype = PT_METL;
						kill_part(i);
                                                return 1;
					}
				}
			}
	/*if(100-parts[i].life > parts[i].tmp2)
		parts[i].tmp2 = 100-parts[i].life;
	if(parts[i].tmp2 < 0) parts[i].tmp2 = 0;
	for ( trade = 0; trade<4; trade ++)
	{
		rx = rand()%5-2;
		ry = rand()%5-2;
		if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
		{
			r = pmap[y+ry][x+rx];
			if (!r)
				continue;
			if (((r&0xFF)==PT_COAL || (r&0xFF)==PT_BCOL)&&(parts[i].tmp2>parts[r>>8].tmp2)&&parts[i].tmp2>0)//diffusion
			{
				int temp = parts[i].tmp2 - parts[r>>8].tmp2;
				if(temp < 10)
					continue;
				if (temp ==1)
				{
					parts[r>>8].tmp2 ++;
					parts[i].tmp2 --;
				}
				else if (temp>0)
				{
					parts[r>>8].tmp2 += temp/2;
					parts[i].tmp2 -= temp/2;
				}
			}
		}
	}*/
	if(parts[i].temp > parts[i].tmp2)
		parts[i].tmp2 = parts[i].temp;
	return 0;
}

int graphics_BCOL(GRAPHIC_FUNC_ARGS)
{
    cr = PIXR(ptypes[t].pcolors);
    cg = PIXG(ptypes[t].pcolors);
    //cb = PIXB(ptypes[t].pcolors);

    cr += (parts[i].tmp2-295.15f)/3;
    //cg += (parts[i].tmp2-273.15f)/3;
    //cb += (parts[i].tmp2-273.15f)/3;
    if (cr>=170)
        cr = 170;
    if (cr<=cg)
        cr = cg;

    cg = cb = cr;

    if((parts[i].temp-295.15f) > 300.0f-200.0f)
    {
        float frequency = 3.1415/(2*300.0f-(300.0f-200.0f));
        int q = ((parts[i].temp-295.15f)>300.0f)?300.0f-(300.0f-200.0f):(parts[i].temp-295.15f)-(300.0f-200.0f);

        cr += sin(frequency*q) * 226;
        cg += sin(frequency*q*4.55 +3.14) * 34;
        cb += sin(frequency*q*2.22 +3.14) * 64;
    }

    if (cr>=255)
        cr = 255;
    if (cg>=255)
        cg = 255;
    if (cb>=255)
        cb = 255;
    if (cr<=0)
        cr = 0;
    if (cg<=0)
        cg = 0;
    if (cb<=0)
        cb = 0;
    blendpixel(vid, nx, ny, cr, cg, cb, 255);
    return 0;
}
