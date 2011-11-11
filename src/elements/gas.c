#include <element.h>

int update_GAS(UPDATE_FUNC_ARGS) {
	if (pv[y/CELL][x/CELL]>6.0f)
        part_change_type(i, x, y, parts[i].ctype);
    if (parts[i].temp>573.0f+273.15f && parts[i].ctype!=PT_ALCO)
    {
        parts[i].life = rand()%50+120;
        part_change_type(i, x, y, PT_FIRE);
    }
    else if (parts[i].temp>673.0f+273.15f && parts[i].ctype==PT_ALCO)
    {
        parts[i].life = rand()%50+120;
        part_change_type(i, x, y, PT_FIRE);
    }
	return 0;
}
