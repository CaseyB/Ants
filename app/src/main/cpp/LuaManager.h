//
// Created by Borders, Casey on 7/28/16.
//

#ifndef ANTS_LUAMANAGER_H
#define ANTS_LUAMANAGER_H

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

#include <string>

class LuaManager
{
public:
    LuaManager();
    ~LuaManager();

    std::string getVersion();
    void* getChildContext(const char *script);

    int getInt(void* context, const char *function);

private:
    lua_State *_state;
};

#endif //ANTS_LUAMANAGER_H
