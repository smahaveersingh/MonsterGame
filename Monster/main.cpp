//
//  main.cpp
//  Monster
//
//  Created by Mahaveer Singh on 19/08/2020.
//  Copyright © 2020 Mahaveer Singh. All rights reserved.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include "file.h"
using namespace std;


void updateBoard(map<pair<int, int>, vector<Monster *>> *board, vector<Monster *> monster_vector)
{
    (*board).clear();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            (*board)[make_pair(i, j)];
    }
    for (auto i : monster_vector)
    {
        (*board)[i->getPosition()].push_back(i);
    }
    cout<<"\n";
    cout<<"Board Intialiazed!\n";
}


void displayAllCell(map<pair<int, int>, vector<Monster *>> *board)
{
    cout<<"\n";
    cout << "cells in sequence\n";
    for (auto i : (*board))
    {
        cout << "(" << i.first.first << " " << i.first.second << "): ";
        if (i.second.size() > 0)
        {
            for (auto j : i.second)
            {
                cout << ((j->getFlightDistance() == 1) ? "Hill Giant " : "Dragon ") << j->getId() << " ";
            }
            cout << "\n";
        }
        else
            cout << "empty\n";
    }
}
void LifeHistory(vector<Monster *> monster_vector)
{
    cout<<"\n";
    cout << "Monster path history\n";
    for (auto i : monster_vector)
    {
        cout << i->getId() << " " << ((i->getFlightDistance() == 1) ? "Hill Giant " : "Dragon ") << " path: ";
        for (auto j : i->getPath())
            cout << "(" << j.first << "," << j.second << ")";
        if (i->getAlive())
        {
            cout << ", Alive!\n";
        }
        else {
            cout<<" Eaten by "<<i->getKillerMonster()<<"\n";
        }
    }
}

void findMonster(vector<Monster *> monster_vector)
{
    int id, j = 0;
    cout << "\n";
    cout << "enter id of monster: ";
    cin >> id;
    for (auto i : monster_vector)
    {
        if (i->getId() == id)
        {
            cout << *i;
            j = 1;
            break;
        }
    }
    if (j == 0)
        cout << "not found\n";
}

void FightLogic(map<pair<int, int>, vector<Monster *>> *board)
{
    for (auto i : (*board))
    {
        if (i.second.size() > 1)
        {
            for (auto j = i.second.begin(); j != --i.second.end(); j++)
            {
                auto k = j;
                auto l = k;
                l++;
                if ((*k)->getAlive() && (*l)->getAlive())
                {
                    if ((*k)->getSize() > (*l)->getSize())
                    {
                        (*l)->setAlive(false);
                        (*l)->setKillerMonster((*k)->getId());
                    }
                    else
                    {
                        (*k)->setAlive(false);
                        (*k)->setKillerMonster((*l)->getId());
                    }
                }
            }
        }
    }
}

void moveMonster(vector<Monster *> monster_vector, map<pair<int, int>, vector<Monster *>> *board)
{

    cout << "\n";
    for (auto i : monster_vector)
    {
        if (i->getAlive())
            i->move();
    }
    updateBoard(board, monster_vector);
    FightLogic(board);
    cout<<"\n";
    cout << "Fight action started! \n";
}
void displayMonsterPath(vector<Monster *> monster_vector)
{
    list<pair<int, int>> path;
    for (auto i : monster_vector)
    {
        path = i->getPath();
        for (auto i : path)
        {
            cout << i.first << " " << i.second << "\t";
        }
    }
}

void displayMonster(vector<Monster *> monster_vector)
{
    cout<<"\n";
    cout << "All monsters\n";
    for (auto i : monster_vector)
        cout << *i;
    cout << "\n";
}


int main()
{
    map<pair<int, int>, vector<Monster *>> board;
    vector<Monster *> monster_vector;
    FileHandler obj;
    while (true)
    {
        cout<<"\n";
        cout<<"            Menu             \n";
        cout << "1. Initialise Monster Board\n";
        cout << "2. Display All Monsters\n";
        cout << "3. Find a Monster\n";
        cout << "4. Fight action(move with Fight functionality)\n";
        cout << "5. Display Life History of all Monsters\n";
        cout << "6. Display all Cells\n";
        cout << "7. Exit\n";
        cout << "Enter option: ";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            monster_vector = obj.load(monster_vector);
            updateBoard(&board, monster_vector);
            break;
        case 2:
            displayMonster(monster_vector);
            break;
        case 3:
            findMonster(monster_vector);
            break;
        case 4:
            moveMonster(monster_vector, &board);
            break;
        case 5:
            LifeHistory(monster_vector);
            break;
        case 6:
            displayAllCell(&board);
            break;
        case 7:
            obj.saveHistory(monster_vector);
            exit(0);
        default:
            exit(0);
            break;
        }
    }
}
