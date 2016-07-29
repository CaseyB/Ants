//
// Created by Borders, Casey on 7/28/16.
//

#ifndef ANTS_ANTMANAGER_H
#define ANTS_ANTMANAGER_H

enum AntAction
{
    MOVE_NORTH,
    MOVE_SOUTH,
    MOVE_EAST,
    MOVE_WEST
};

class Ant
{
public:
    AntAction action;
    void* context;
};

class AntManager
{
public:
    AntManager();
    ~AntManager();

    int addAnt();
    AntAction takeActionWithAnt(int antID);

private:
    Ant _ants[30];
    int _antCount;
};



#endif //ANTS_ANTMANAGER_H
