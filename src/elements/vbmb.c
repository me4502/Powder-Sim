#include <element.h>

int update_VBMB(UPDATE_FUNC_ARGS) {
	int r,rx,ry,np,fe;
	//if (!parts[i].life) parts[i].life = rand();
	//if (!parts[i].ctype) parts[i].ctype = rand();
	if (parts[i].tmp==1)
    {
        if (parts[i].temp < MAX_TEMP)
        {
            parts[i].tmp2+=3;
            parts[i].temp = 10 + parts[i].tmp2*10;
            pv[y/CELL][x/CELL] = 2 + parts[i].tmp2;
        }
        else
        {
            pv[y/CELL][x/CELL] = 256.0f;
            hv[y/CELL][x/CELL] = MAX_TEMP;
            parts[i].life = rand()%150+50;
            parts[i].ctype = PT_VBMB;
            part_change_type(i,x,y,PT_PLSM);
        }
    }
    else if (parts[i].tmp==0)
    {
        if (parts[i].temp>0)
        {
            parts[i].temp-=5;
            pv[y/CELL][x/CELL] -=5;
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
                    fe = 1;
                    if (parts[i].tmp==1 && rand()%100==1)
                        if (np=create_part(-1,x+rx,y+ry,PT_PLSM))
                        {
                            parts[np].life = rand()%150+50;
                            parts[np].ctype = PT_VBMB;
                        }
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

    if (parts[i].tmp==1)
    {
        if (fe) {
		int orbd[4] = {0, 0, 0, 0};	//Orbital distances
		int orbl[4] = {0, 0, 0, 0};	//Orbital locations
		if (!parts[i].life) parts[i].life = rand();
		if (!parts[i].ctype) parts[i].life = rand();
		orbitalparts_get(parts[i].life, parts[i].ctype, orbd, orbl);
		for (r = 0; r < 4; r++) {
			if (orbd[r]<254) {
				orbd[r] += 16;
				if (orbd[r]>254) {
					orbd[r] = 0;
					orbl[r] = rand()%255;
				}
				//orbl[r] += 1;
				//orbl[r] = orbl[r]%255;
			} else {
				orbd[r] = 0;
				orbl[r] = rand()%255;
			}
		}
		orbitalparts_set(&parts[i].life, &parts[i].ctype, orbd, orbl);
	} else {
		parts[i].life = 0;
		parts[i].ctype = 0;
	}
    }
    else
    {
        if (fe) {
            int orbd[4] = {0, 0, 0, 0};	//Orbital distances
            int orbl[4] = {0, 0, 0, 0};	//Orbital locations
            if (!parts[i].life) parts[i].life = rand();
            if (!parts[i].ctype) parts[i].ctype = rand();
            orbitalparts_get(parts[i].life, parts[i].ctype, orbd, orbl);
            for (r = 0; r < 4; r++) {
                if (orbd[r]>1) {
                    orbd[r] -= 12;
                    if (orbd[r]<1) {
                        orbd[r] = (rand()%128)+128;
                        orbl[r] = rand()%255;
                    } else {
                        orbl[r] += 2;
                        orbl[r] = orbl[r]%255;
                    }
                } else {
                    orbd[r] = (rand()%128)+128;
                    orbl[r] = rand()%255;
                }
            }
            orbitalparts_set(&parts[i].life, &parts[i].ctype, orbd, orbl);
        } else {
            parts[i].life = 0;
            parts[i].ctype = 0;
        }
    }
	return 0;
}
