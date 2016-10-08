
#include "PluginLeaderboardLuaHelper.h"
#include "PluginLeaderboard/PluginLeaderboard.h"
#include "SDKBoxLuaHelper.h"

class LeaderboardListenerLua : public sdkbox::LeaderboardListener {
public:
	LeaderboardListenerLua(): mLuaHandler(0) {
	}

	~LeaderboardListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (mLuaHandler == luaHandler) {
			return;
		}
		resetHandler();
		mLuaHandler = luaHandler;
	}

	void resetHandler() {
		if (0 == mLuaHandler) {
			return;
		}

        LUAENGINE->removeScriptHandler(mLuaHandler);
		mLuaHandler = 0;
	}

	void onComplete(std::string leaderboard)
	{
		LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("name", LuaValue::stringValue("onComplete")));
        dict.insert(std::make_pair("leaderboard", LuaValue::stringValue(leaderboard)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
	}
	void onFail()
	{
		LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueDict dict;

        dict.insert(std::make_pair("name", LuaValue::stringValue("onFail")));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
	}


private:
	int mLuaHandler;
};

int lua_PluginLeaderboardLua_PluginLeaderboard_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginLeaderboard",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        LeaderboardListenerLua* lis = static_cast<LeaderboardListenerLua*> (sdkbox::PluginLeaderboard::getListener());
        if (NULL == lis) {
            lis = new LeaderboardListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginLeaderboard::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginLeaderboard::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginLeaderboardLua_PluginLeaderboard_setListener'.",&tolua_err);
#endif
    return 0;
}


int extern_PluginLeaderboard(lua_State* L) {
	if (NULL == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginLeaderboard");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginLeaderboardLua_PluginLeaderboard_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginLeaderboardLua_helper(lua_State* L) {

	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginLeaderboard(L);

	tolua_endmodule(L);
	return 1;
}


