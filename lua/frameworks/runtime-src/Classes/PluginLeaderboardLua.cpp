#include "PluginLeaderboardLua.hpp"
#include "PluginLeaderboard/PluginLeaderboard.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginLeaderboardLua_PluginLeaderboard_getLeaderboard(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeaderboard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeaderboard:getLeaderboard");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeaderboardLua_PluginLeaderboard_getLeaderboard'", nullptr);
            return 0;
        }
        sdkbox::PluginLeaderboard::getLeaderboard(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeaderboard:getLeaderboard",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeaderboardLua_PluginLeaderboard_getLeaderboard'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeaderboardLua_PluginLeaderboard_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeaderboard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeaderboardLua_PluginLeaderboard_init'", nullptr);
            return 0;
        }
        sdkbox::PluginLeaderboard::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeaderboard:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeaderboardLua_PluginLeaderboard_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeaderboardLua_PluginLeaderboard_submitScore(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeaderboard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginLeaderboard:submitScore");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "sdkbox.PluginLeaderboard:submitScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeaderboardLua_PluginLeaderboard_submitScore'", nullptr);
            return 0;
        }
        sdkbox::PluginLeaderboard::submitScore(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeaderboard:submitScore",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeaderboardLua_PluginLeaderboard_submitScore'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeaderboardLua_PluginLeaderboard_removeListener(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeaderboard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeaderboardLua_PluginLeaderboard_removeListener'", nullptr);
            return 0;
        }
        sdkbox::PluginLeaderboard::removeListener();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeaderboard:removeListener",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeaderboardLua_PluginLeaderboard_removeListener'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginLeaderboardLua_PluginLeaderboard_getListener(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeaderboard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginLeaderboardLua_PluginLeaderboard_getListener'", nullptr);
            return 0;
        }
        sdkbox::LeaderboardListener* ret = sdkbox::PluginLeaderboard::getListener();
        object_to_luaval<sdkbox::LeaderboardListener>(tolua_S, "sdkbox.LeaderboardListener",(sdkbox::LeaderboardListener*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeaderboard:getListener",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeaderboardLua_PluginLeaderboard_getListener'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginLeaderboardLua_PluginLeaderboard_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginLeaderboard)");
    return 0;
}

int lua_register_PluginLeaderboardLua_PluginLeaderboard(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginLeaderboard");
    tolua_cclass(tolua_S,"PluginLeaderboard","sdkbox.PluginLeaderboard","",nullptr);

    tolua_beginmodule(tolua_S,"PluginLeaderboard");
        tolua_function(tolua_S,"getLeaderboard", lua_PluginLeaderboardLua_PluginLeaderboard_getLeaderboard);
        tolua_function(tolua_S,"init", lua_PluginLeaderboardLua_PluginLeaderboard_init);
        tolua_function(tolua_S,"submitScore", lua_PluginLeaderboardLua_PluginLeaderboard_submitScore);
        tolua_function(tolua_S,"removeListener", lua_PluginLeaderboardLua_PluginLeaderboard_removeListener);
        tolua_function(tolua_S,"getListener", lua_PluginLeaderboardLua_PluginLeaderboard_getListener);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginLeaderboard).name();
    g_luaType[typeName] = "sdkbox.PluginLeaderboard";
    g_typeCast["PluginLeaderboard"] = "sdkbox.PluginLeaderboard";
    return 1;
}
TOLUA_API int register_all_PluginLeaderboardLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginLeaderboardLua_PluginLeaderboard(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

