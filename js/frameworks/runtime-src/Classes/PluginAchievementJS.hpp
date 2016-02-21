#ifndef __PluginAchievementJS_h__
#define __PluginAchievementJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginAchievement_class;
extern JSObject *jsb_sdkbox_PluginAchievement_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginAchievementJS_PluginAchievement(JSContext *cx, JS::HandleObject global);
void register_all_PluginAchievementJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginAchievementJS_PluginAchievement(JSContext *cx, JSObject* global);
void register_all_PluginAchievementJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginAchievementJS_PluginAchievement_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginAchievementJS_PluginAchievement_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAchievementJS_PluginAchievement_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAchievementJS_PluginAchievement_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginAchievementJS_PluginAchievement_unlock(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginAchievementJS_PluginAchievement_unlock(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

