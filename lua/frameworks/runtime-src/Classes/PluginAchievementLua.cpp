#include "PluginAchievementLua.hpp"
#include "PluginAchievement/PluginAchievement.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginAchievementLua_PluginAchievement_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAchievement",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAchievementLua_PluginAchievement_init'", nullptr);
            return 0;
        }
        sdkbox::PluginAchievement::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAchievement:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAchievementLua_PluginAchievement_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginAchievementLua_PluginAchievement_unlock(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginAchievement",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginAchievement:unlock");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginAchievementLua_PluginAchievement_unlock'", nullptr);
            return 0;
        }
        sdkbox::PluginAchievement::unlock(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginAchievement:unlock",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginAchievementLua_PluginAchievement_unlock'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginAchievementLua_PluginAchievement_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginAchievement)");
    return 0;
}

int lua_register_PluginAchievementLua_PluginAchievement(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginAchievement");
    tolua_cclass(tolua_S,"PluginAchievement","sdkbox.PluginAchievement","",nullptr);

    tolua_beginmodule(tolua_S,"PluginAchievement");
        tolua_function(tolua_S,"init", lua_PluginAchievementLua_PluginAchievement_init);
        tolua_function(tolua_S,"unlock", lua_PluginAchievementLua_PluginAchievement_unlock);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginAchievement).name();
    g_luaType[typeName] = "sdkbox.PluginAchievement";
    g_typeCast["PluginAchievement"] = "sdkbox.PluginAchievement";
    return 1;
}
TOLUA_API int register_all_PluginAchievementLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginAchievementLua_PluginAchievement(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

