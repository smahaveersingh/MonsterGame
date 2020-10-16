//
//  hillGaint.h
//  Monster
//
//  Created by Mahaveer Singh on 19/08/2020.
//  Copyright © 2020 Mahaveer Singh. All rights reserved.
//

#ifndef hillGaint_h
#define hillGaint_h
#endif /* hillGaint_h */

class HillGiant : public Monster
{
 public:
    HillGiant(int id, int i, int j, int direction, int size, bool alive)
    {
        this->id = id;
        position.first = i;
        position.second = j;
        switch (direction)
        {
        case 1:
            this->direction = north;
            break;
        case 2:
            this->direction = east;
            break;
        case 3:
            this->direction = south;
            break;
        case 4:
            this->direction = west;
            break;
        default:
            break;
        }
        this->size = size;
        this->alive = alive;
        this->flightDistance=1;
        path.push_back(position);
        killerMonster=-1;
    }
    
    void move()
    {
        int check = 0;
        while (check == 0)
        {
            if (!isWayBlocked())
            {
                switch (direction)
                {
                case north:
                    position.first -= 1;
                    path.push_back(position);
                    check = 1;
                    break;
                case east:
                    position.second += 1;
                    path.push_back(position);
                    check = 1;
                    break;
                case south:
                    position.first += 1;
                    path.push_back(position);
                    check = 1;
                    break;
                case west:
                    position.second -= 1;
                    path.push_back(position);
                    check = 1;
                    break;
                default:
                    break;
                }
            }
            else
            {
                direction = direc(rand() % 4);
            }
        }
    }
    bool isWayBlocked()
       {
           bool boo;
           switch (direction)
           {
           case north:
               boo = ((position.first - 1) < 0) ? true : false;
               break;
           case east:
               boo = ((position.second + 1) > 9) ? true : false;
               break;
           case south:
               boo = ((position.first + 1) > 9) ? true : false;
               break;
           case west:
               boo = ((position.second - 1) < 0) ? true : false;
               break;
           default:
               break;
           }
           return boo;
       }
    
    
};
 
