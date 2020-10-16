//
//  dragon.h
//  Monster
//
//  Created by Mahaveer Singh on 19/08/2020.
//  Copyright © 2020 Mahaveer Singh. All rights reserved.
//

#ifndef dragon_h
#define dragon_h
#endif /* dragon_h */


class Dragon : public Monster
{
public:
    Dragon(int id, int i, int j, int direction, int size, bool alive, int flightDistance)
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
        this->flightDistance = flightDistance;
        path.push_back(position);
        killerMonster=-1;
    }
    bool isWayBlocked()
    {
        bool boo;
        switch (direction)
        {
        case north:
            boo = ((position.first - flightDistance) < 0) ? true : false;
            break;
        case east:
            boo = ((position.second + flightDistance) > 9) ? true : false;
            break;
        case south:
            boo = ((position.first + flightDistance) > 9) ? true : false;
            break;
        case west:
            boo = ((position.second - flightDistance) < 0) ? true : false;
            break;
        default:
            break;
        }
        return boo;
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
                    position.first -= flightDistance;
                    path.push_back(position);
                    check = 1;
                    break;
                case east:
                    position.second += flightDistance;
                    path.push_back(position);
                    check = 1;
                    break;
                case south:
                    position.first += flightDistance;
                    path.push_back(position);
                    check = 1;
                    break;
                case west:
                    position.second -= flightDistance;
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
};
