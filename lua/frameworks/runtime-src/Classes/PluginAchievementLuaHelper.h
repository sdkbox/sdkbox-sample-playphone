
#ifndef __PLUGIN_ACHIEVEMENT_LUA_HELPER_H__
#define __PLUGIN_ACHIEVEMENT_LUA_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int register_all_PluginAchievementLua_helper(lua_State* L);

#endif
