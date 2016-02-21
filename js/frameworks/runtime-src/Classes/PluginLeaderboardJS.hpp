#ifndef __PluginLeaderboardJS_h__
#define __PluginLeaderboardJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginLeaderboard_class;
extern JSObject *jsb_sdkbox_PluginLeaderboard_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginLeaderboardJS_PluginLeaderboard(JSContext *cx, JS::HandleObject global);
void register_all_PluginLeaderboardJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginLeaderboardJS_PluginLeaderboard(JSContext *cx, JSObject* global);
void register_all_PluginLeaderboardJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginLeaderboardJS_PluginLeaderboard_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginLeaderboardJS_PluginLeaderboard_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeaderboardJS_PluginLeaderboard_getLeaderboard(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeaderboardJS_PluginLeaderboard_getLeaderboard(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeaderboardJS_PluginLeaderboard_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeaderboardJS_PluginLeaderboard_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeaderboardJS_PluginLeaderboard_submitScore(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeaderboardJS_PluginLeaderboard_submitScore(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeaderboardJS_PluginLeaderboard_removeListener(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeaderboardJS_PluginLeaderboard_removeListener(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginLeaderboardJS_PluginLeaderboard_getListener(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginLeaderboardJS_PluginLeaderboard_getListener(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

