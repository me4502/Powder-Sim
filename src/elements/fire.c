#include <element.h>

int graphics_FIRE(GRAPHICS_FUNC_ARGS)
{
	int caddress = restrict_flt(restrict_flt((float)cpart->life, 0.0f, 200.0f)*3, 0.0f, (200.0f*3)-3);
	int fr, fg, fb;
	int *pix;
	int *pixf;

	if (cpart-> tmp == PT_ALCO)
	{
		fr = 0;
		fg = 0;
		fb = 0;
	}
	else if (cpart-> tmp == PT_COAL || cpart-> tmp == PT_BCOL)
	{
		fr = 1;
		fg = 2;
		fb = 2;
	}
	else if (cpart-> tmp == PT_NITR)
	{
		fr = 2;
		fg = 1;
		fb = 2;
	}
	else if (cpart-> tmp == PT_FRAN)
	{
		fr = 2;
		fg = 2;
		fb = 1;
	}
	else if (cpart-> tmp == PT_MAGN)
	{
		fr = 1;
		fg = 1;
		fb = 1;



	}
	else
	{
		fr = 0;
		fg = 1;
		fb = 2;
	}

	*colr = (unsigned char)flm_data[caddress+fr];
	*colg = (unsigned char)flm_data[caddress+fg];
	*colb = (unsigned char)flm_data[caddress+fb];

	*firea = 255;
	*firer = *colr;
	*fireg = *colg;
	*fireb = *colb;

	*pixel_mode = PMODE_NONE; //Clear default, don't draw pixel
	if (cpart-> tmp == PT_MAGN)
		*pixel_mode |= PMODE_SPARK;	
		//*pixel_mode |= PMODE_FLARE;
	else
		*pixel_mode |= FIRE_ADD;
	//Returning 0 means dynamic, do not cache
	return 0;
}
