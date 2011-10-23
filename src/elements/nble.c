#include <element.h>

int update_NBLE(UPDATE_FUNC_ARGS)
{
    int ct = parts[i].ctype;
    if (ct==NBL_HELM)
    {
        if (parts[i].y > YRES -(YRES - (rand()%40 + 30)))
        {
            if (rand()%2==1)
            {
                parts[i].vy -= 1;
            }
            else
            {
                parts[i].vy = 0;
            }
        }
        else
        {
            if (rand()%2==1)
                parts[i].vy += 1;
            else
                parts[i].vy += 0.5;
        }
    }
    else if ((ct==NBL_NEON||ct==NBL_ARGN||ct==NBL_KPTN||ct==NBL_RDON||ct==NBL_XNON||ct==NBL_RDON||ct==NBL_UNCM)&&parts[i].temp>273.15+R_TEMP)
    {
        int p = rand()%4;
        if (p==0)
        {
            parts[i].vy += rand()%ct+1;
        }
        else if (p==1)
        {
            parts[i].vy -= rand()%ct+1;
        }
        else if (p==2)
        {
            parts[i].vx += rand()%ct+1;
        }
        else if (p==3)
        {
            parts[i].vx -= rand()%ct+1;
        }
    }
    return 0;
}
