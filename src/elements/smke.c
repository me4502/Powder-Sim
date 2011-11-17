#include <element.h>

int graphics_SMKE(GRAPHICS_FUNC_ARGS)
{
    int deftype = 1, cleartype = 1, ret = 0;
    *pixel_mode = PMODE_NONE;
    if (cpart->tmp==PT_COAL)
    {
		cleartype = 0;
		//deftype = 0;
		*colr = PIXR(ptypes[cpart-> tmp].pcolors);
		*colg = PIXG(ptypes[cpart-> tmp].pcolors);
		*colb = PIXB(ptypes[cpart-> tmp].pcolors);

        *firea = 255;
		*firer = PIXR(ptypes[cpart-> tmp].pcolors);
		*fireg = PIXG(ptypes[cpart-> tmp].pcolors);
		*fireb = PIXB(ptypes[cpart-> tmp].pcolors);
		*pixel_mode |= PMODE_GLOW;
		//*pixel_mode |= FIRE_ADD;
    }
    else
    {
        *colr = 55;
        *colg = 55;
        *colb = 55;

        *firea = 75;
        *firer = 55;
        *fireg = 55;
        *fireb = 55;
    }

    if (cleartype)
        *pixel_mode = PMODE_NONE; //Clear default, don't draw pixel
	if (deftype)
        *pixel_mode |= FIRE_BLEND;
	//Returning 1 means static, cache as we please
	return ret;
}
