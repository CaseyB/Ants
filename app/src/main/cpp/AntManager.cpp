//
// Created by Borders, Casey on 7/28/16.
//

#include "AntManager.h"
#include "LuaManager.h"

extern LuaManager luaManager;

const char *script = "require \"math\"\
                      \
                      local MOVE_NORTH, MOVE_SOUTH, MOVE_EAST, MOVE_WEST = 0, 1, 2, 3\
                      \
                      function takeAction()\
                      	return math.floor(math.random(0, 3) + 0.5)\
                      end";

AntManager::AntManager()
{
    _antCount = 0;
}

AntManager::~AntManager()
{

}

int AntManager::addAnt()
{
    int antID = _antCount;
    _antCount++;
    _ants[antID].action = MOVE_NORTH;
    _ants[antID].context = luaManager.getChildContext(script);
    return antID;
}

AntAction AntManager::takeActionWithAnt(int antID)
{
    _ants[antID].action = (AntAction)luaManager.getInt(_ants[antID].context, "takeAction");
    return _ants[antID].action;
}
