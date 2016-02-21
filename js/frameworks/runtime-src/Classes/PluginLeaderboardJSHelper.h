

#ifndef __js__PluginLeaderboardJSHelper_H_
#define __js__PluginLeaderboardJSHelper_H_

#include "jsapi.h"
#include "jsfriendapi.h"

#if MOZJS_MAJOR_VERSION >= 31
void register_all_PluginLeaderboardJS_helper(JSContext* cx, JS::HandleObject global);
#else
void register_all_PluginLeaderboardJS_helper(JSContext* cx, JSObject* global);
#endif

#endif /* defined(__PluginLeaderboardJSHelper_H_) */
