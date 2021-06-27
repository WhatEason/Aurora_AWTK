#include "awtk.h"
#include "base/assets_manager.h"
#ifndef WITH_FS_RES
extern TK_CONST_DATA_ALIGN(const unsigned char strings_en_US[]);
extern TK_CONST_DATA_ALIGN(const unsigned char strings_zh_CN[]);
extern TK_CONST_DATA_ALIGN(const unsigned char style_default[]);
extern TK_CONST_DATA_ALIGN(const unsigned char ui_system_bar[]);
#ifdef WITH_STB_IMAGE
#else
#endif /*WITH_STB_IMAGE*/
#ifdef WITH_VGCANVAS
#endif /*WITH_VGCANVAS*/
#ifdef WITH_TRUETYPE_FONT
extern TK_CONST_DATA_ALIGN(const unsigned char font_default[]);
#else /*WITH_TRUETYPE_FONT*/
#endif /*WITH_TRUETYPE_FONT*/
#endif /*WITH_FS_RES*/

ret_t assets_init_dark(void) {
  assets_manager_t* am = assets_manager();
  assets_manager_set_theme(am, "dark");

#ifdef WITH_FS_RES
  assets_manager_preload(am, ASSET_TYPE_FONT, "default");
  assets_manager_preload(am, ASSET_TYPE_STYLE, "default");
#else
  assets_manager_add(am, strings_en_US);
  assets_manager_add(am, strings_zh_CN);
  assets_manager_add(am, style_default);
  assets_manager_add(am, ui_system_bar);
#ifdef WITH_VGCANVAS
#endif /*WITH_VGCANVAS*/
#ifdef WITH_TRUETYPE_FONT
  assets_manager_add(am, font_default);
#else /*WITH_TRUETYPE_FONT*/
#endif /*WITH_TRUETYPE_FONT*/
#endif

  tk_init_assets();
  return RET_OK;
}
