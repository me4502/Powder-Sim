#include <element.h>

int update_CLNE(UPDATE_FUNC_ARGS) {
    if (parts[i].tmp3>0)parts[i].tmp3--;
	if (parts[i].ctype<=0 || parts[i].ctype>=PT_NUM || (parts[i].ctype==PT_LIFE && (parts[i].tmp<0 || parts[i].tmp>=NGOLALT))|| (parts[i].ctype==PT_NBLE && (parts[i].tmp<0 || parts[i].tmp>=NNBLALT)))
	{
		int r, rx, ry, ct;
		for (rx=-1; rx<2; rx++)
			for (ry=-1; ry<2; ry++)
				if (x+rx>=0 && y+ry>=0 && x+rx<XRES && y+ry<YRES)
				{
					r = photons[y+ry][x+rx];
					ct = parts[i].ctype;
					if (!r)
						r = pmap[y+ry][x+rx];
					if (!r)
						continue;

					if ((r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN &&
				        (r&0xFF)!=PT_BCLN && (r&0xFF)!=PT_STKM &&
				        (r&0xFF)!=PT_PBCN && (r&0xFF)!=PT_STKM2 &&
				        (r&0xFF)<PT_NUM)
					{
						parts[i].ctype = r&0xFF;
						if ((r&0xFF)==PT_LIFE)
							parts[i].tmp = parts[r>>8].ctype;
                        if ((r&0xFF)==PT_NBLE)
							parts[i].tmp = parts[r>>8].ctype;
					}
				}
	}
	else {
	    if (parts[i].tmp3 > 0) return 0;
		if (parts[i].ctype==PT_LIFE) create_part(-1, x+rand()%3-1, y+rand()%3-1, parts[i].ctype|(parts[i].tmp<<8));
        else if (parts[i].ctype==PT_NBLE) create_part(-1, x+rand()%3-1, y+rand()%3-1, parts[i].ctype|(parts[i].tmp<<8));
		else create_part(-1, x+rand()%3-1, y+rand()%3-1, parts[i].ctype);
		parts[i].tmp3 = parts[i].tmp3;
	}
	return 0;
}
