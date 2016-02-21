#include "PluginAchievementJSHelper.h"
#include "cocos2d_specifics.hpp"
#include "PluginAchievement/PluginAchievement.h"
#include "SDKBoxJSHelper.h"
#include "cocos2d.h"

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginAchievementJS_helper(JSContext* cx, JS::HandleObject global) {

}
#else
void register_all_PluginAchievementJS_helper(JSContext* cx, JSObject* global) {

}
#endif
#elif defined(JS_VERSION)
void register_all_PluginAchievementJS_helper(JSContext* cx, JSObject* global) {

}
#endif

