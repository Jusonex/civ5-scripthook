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

C_API void scripthook_call_vm_create(struct lua_State* luaVM);

C_API void scripthook_call_script_load(struct lua_State* luaVM, const char* path, size_t pathSize, const char* chunkName);
