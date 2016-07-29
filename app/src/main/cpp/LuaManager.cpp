//
// Created by Borders, Casey on 7/28/16.
//

#include "LuaManager.h"


LuaManager::LuaManager()
{
    _state = luaL_newstate();
    luaL_openlibs(_state);
}

LuaManager::~LuaManager()
{
    lua_close(_state);
    _state = 0;
}

std::string LuaManager::getVersion()
{
    lua_getglobal(_state, "_VERSION");
    std::string version(lua_tostring(_state, 1));
    return version;
}

void* LuaManager::getChildContext(const char *script)
{
    lua_State *state = lua_newthread(_state);
    luaL_dostring(state, script);
    return (void*)state;
}

int LuaManager::getInt(void* context, const char *function)
{
    int result;
    lua_State *state = (lua_State*)context;

    lua_getglobal(state, function);
    lua_call(state, 0, 1);
    result = (int)lua_tointeger(state, -1);

    return result;
}
