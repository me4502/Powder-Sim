#ifndef LUACONSOLEH
#define LUACONSOLEH
#ifdef LUA_R_INCL
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <CaLua.h>
#else
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <CaLua.h>
#endif
#include <defines.h>

#define LOCAL_LUA_DIR "Lua"

#define LUACON_MDOWN 1
#define LUACON_MUP 2
#define LUACON_MPRESS 3
#define LUACON_KDOWN 1
#define LUACON_KUP 2
#define LUACON_CREATE 1
#define LUACON_BCREATE 2
#define LUACON_ERASE 1
#define LUACON_BERASE 2


int *lua_el_func, *lua_el_mode;

void luacon_open();
int luacon_step(int mx, int my, int selectl, int selectr);
int luacon_mouseevent(int mx, int my, int mb, int event);
int luacon_createevent(int x, int y, int type, int event);
int luacon_eraseevent(int x, int y, int type, int event);
int luacon_loadevent(int event);
int luacon_keyevent(int key, int modifier, int event);
int luacon_eval(char *command);
int luacon_part_update(int t, int i, int x, int y, int surround_space, int nt);
char *luacon_geterror();
void luacon_close();
int process_command_lua(pixel *vid_buf, char *console, char *console_error);

int getPartIndex_curIdx;

//TPT Interface
int luatpt_test(lua_State* l);
int luatpt_getelement(lua_State *l);
int luatpt_element_func(lua_State *l);
int luatpt_drawtext(lua_State* l);
int luatpt_create(lua_State* l);
int luatpt_setpause(lua_State* l);
int luatpt_togglepause(lua_State* l);
int luatpt_togglewater(lua_State* l);
int luatpt_setconsole(lua_State* l);
int luatpt_log(lua_State* l);
int luatpt_set_pressure(lua_State* l);
int luatpt_set_gravity(lua_State* l);
int luatpt_reset_gravity_field(lua_State* l);
int luatpt_reset_velocity(lua_State* l);
int luatpt_reset_spark(lua_State* l);
int luatpt_set_property(lua_State* l);
int luatpt_get_property(lua_State* l);
int luatpt_drawpixel(lua_State* l);
int luatpt_drawrect(lua_State* l);
int luatpt_fillrect(lua_State* l);
int luatpt_fillgradrect(lua_State* l);
int luatpt_drawline(lua_State* l);
int luatpt_textwidth(lua_State* l);
int luatpt_get_name(lua_State* l);
int luatpt_set_shortcuts(lua_State* l);
int luatpt_delete(lua_State* l);
int luatpt_register_step(lua_State* l);
int luatpt_unregister_step(lua_State* l);
int luatpt_register_mouseclick(lua_State* l);
int luatpt_unregister_mouseclick(lua_State* l);
int luatpt_register_keypress(lua_State* l);
int luatpt_unregister_keypress(lua_State* l);
int luatpt_register_createevent(lua_State* l);
int luatpt_unregister_createevent(lua_State* l);
int luatpt_register_eraseevent(lua_State* l);
int luatpt_unregister_eraseevent(lua_State* l);
int luatpt_input(lua_State* l);
int luatpt_message_box(lua_State* l);
int luatpt_get_numOfParts(lua_State* l);
int luatpt_start_getPartIndex(lua_State* l);
int luatpt_getPartIndex(lua_State* l);
int luatpt_next_getPartIndex(lua_State* l);
int luatpt_hud(lua_State* l);
int luatpt_gravity(lua_State* l);
int luatpt_airheat(lua_State* l);
int luatpt_active_menu(lua_State* l);
int luatpt_decorations_enable(lua_State* l);
int luatpt_cmode_set(lua_State* l);
int luatpt_error(lua_State* l);
int luatpt_heat(lua_State* l);
int luatpt_setfire(lua_State* l);
int luatpt_setdebug(lua_State* l);
int luatpt_setfpscap(lua_State* l);
int luatpt_getscript(lua_State* l);
int luatpt_setwindowsize(lua_State* l);
int luatpt_showcursor(lua_State* l);
int luatpt_screenshot(lua_State* l);
int luatpt_overgraph(lua_State* l);
int luatpt_setgraph(lua_State* l);
int luatpt_setgraphmode(lua_State* l);
#endif
