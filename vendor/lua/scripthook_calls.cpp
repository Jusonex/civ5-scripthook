#include "scripthook_calls.h"
#include "../../include/ScriptHook.h"

C_API void scripthook_call_vm_create(lua_State* luaVM)
{
	GetScriptHook()->GetEvents().OnVmCreate(luaVM);
}

C_API void scripthook_call_script_load(struct lua_State* luaVM, const char* buffer, size_t pathSize, const char* chunkName)
{
	GetScriptHook()->GetEvents().OnScriptLoad(luaVM, std::string{ buffer, pathSize }, std::string{ chunkName });
}
