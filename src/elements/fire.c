#include <element.h>

int graphics_FIRE(GRAPHICS_FUNC_ARGS)
{
	int caddress = restrict_flt(restrict_flt((float)cpart->life, 0.0f, 200.0f)*3, 0.0f, (200.0f*3)-3);	
	if (cpart-> tmp == PT_ALCO)
	{
		*colr = (unsigned char)flm_data[caddress];
		*colg = (unsigned char)flm_data[caddress];
		*colb = (unsigned char)flm_data[caddress];
	} 	
	else if (cpart-> tmp == PT_COAL)
	{		
		*colr = (unsigned char)flm_data[caddress+1];
		*colg = (unsigned char)flm_data[caddress+2];
		*colb = (unsigned char)flm_data[caddress+2];
	}
	else
	{		
		*colr = (unsigned char)flm_data[caddress];
		*colg = (unsigned char)flm_data[caddress+1];
		*colb = (unsigned char)flm_data[caddress+2];
	}		
	*firea = 255;
	*firer = *colr;
	*fireg = *colg;
	*fireb = *colb;
	
	*pixel_mode = PMODE_NONE; //Clear default, don't draw pixel
	*pixel_mode |= FIRE_ADD;
	//Returning 0 means dynamic, do not cache
	return 0;
}
