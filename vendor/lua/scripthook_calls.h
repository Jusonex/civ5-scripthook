/*****************************************************************************
*
*  PROJECT:     CIV5: Scripthook
*  LICENSE:     See LICENSE in the top level directory
*  PURPOSE:     Scripthook C wrapper
*
*****************************************************************************/
#pragma once
#include <stdint.h>

//
// Since we're going to mix C and C++, we've to
// provide a C wrapper for our C++ functions
//
#ifdef __cplusplus
	#define C_API extern "C"
#else
	#define C_API
#endif

//
// Since we use Lua C API functions in civ5_scripthook which is linked
// by this project, we cannot link this project.
// Instead, we go for a hack and just compile Lua two times: One with
// our patches and one without. This macro helps doing this
//
#ifdef SCRIPTHOOK_PATCHES_ENABLED
	#define SCRIPTHOOK_ZONE(CODE) CODE
#else
	#define SCRIPTHOOK_ZONE(CODE)
#endif


C_API void scripthook_call_vm_create(struct lua_State* luaVM);

C_API void scripthook_call_script_load(struct lua_State* luaVM, const char* path, size_t pathSize, const char* chunkName);

