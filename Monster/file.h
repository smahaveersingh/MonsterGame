//
//  file.h
//  Monster
//
//  Created by Mahaveer Singh on 19/08/2020.
//  Copyright © 2020 Mahaveer Singh. All rights reserved.
//

#ifndef file_h
#define file_h
#endif /* file_h */
#include <iostream>

#include "monster.h"
#include "hillGaint.h"
#include "dragon.h"

#include <vector>
#include <string>
#include <fstream>

using namespace std;
class FileHandler
{
public:
    vector<Monster *> load(vector<Monster *> monster_vector)
    {
        monster_vector.clear();
        ifstream file("monster.txt");
        string line,temp;
        vector<string> monsterDetail;
        vector<int> purchaseNumber;
        
        while (getline(file, line))
               {
                   for (int i = 0; i < line.size(); i++)
                   {
                       if (line[i] != ';')
                       {
                           temp = temp + line[i];
                       }
                       else
                       {
                           monsterDetail.push_back(temp);
                           temp = "";
                       }
                   }
                   
                   if (monsterDetail[0] == "D")
                   {
                       Monster *obj = new Dragon(stoi(monsterDetail[1]), stoi(monsterDetail[2]), stoi(monsterDetail[3]), stoi(monsterDetail[4]), stoi(monsterDetail[5]), true, stoi(monsterDetail[6]));
                       monster_vector.push_back(obj);
                   }
                   else
                   {
                       Monster *obj = new HillGiant(stoi(monsterDetail[1]), stoi(monsterDetail[2]), stoi(monsterDetail[3]), stoi(monsterDetail[4]), stoi(monsterDetail[5]), true);
                       monster_vector.push_back(obj);
                   }
                   monsterDetail.clear();
                  
               }
               file.close();
               return monster_vector;
    }
    
    void saveHistory(vector<Monster *> monster_vector)
    {
        ofstream file("monsters_life.out.txt");
        for (auto i : monster_vector)
        {
            file << i->getId() << " " << ((i->getFlightDistance() == 1) ? "Hill Giant " : "Dragon ") << " path: ";
            for (auto j : i->getPath())
                file << "(" << j.first << "," << j.second << ")";
            if (i->getAlive())
            {
                file << ", Alive!\n";
            }
        }
        file.close();
    }
};

