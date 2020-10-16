//
//  monster.h
//  Monster
//
//  Created by Mahaveer Singh on 19/08/2020.
//  Copyright © 2020 Mahaveer Singh. All rights reserved.
//

#ifndef monster_h
#define monster_h
#endif /* monster_h */

using namespace std;
enum direc
{
    north = 1,
    east,
    south,
    west
};
class Monster
{
protected:
    int id;
    pair<int, int> position;
    direc direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    int flightDistance;
    int killerMonster;
public:
    void setKillerMonster(int killerMonster){
        this->killerMonster=killerMonster;
    }
    
    virtual void move() = 0;
    
    virtual bool isWayBlocked() = 0;
    
    void setId(int id)
    {
        this->id = id;
    }
    void setPosition(int i, int j)
    {
        position.first = i;
        position.second = j;
        path.push_back(position);
    }
    void setDirection(direc direction)
    {
        this->direction = direction;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    void setAlive(bool alive)
    {
        this->alive = alive;
    }
    void setFlightDistance(int flightDistance)
    {
        this->flightDistance = flightDistance;
    }
    int getId()
    {
        return id;
    }
    pair<int, int> getPosition()
    {
        return position;
    }
    direc getDirection()
    {
        return direction;
    }
    int getSize()
    {
        return size;
    }
    bool getAlive()
    {
        return alive;
    }
    list<pair<int, int>> getPath()
    {
        return path;
    }
    int getFlightDistance()
    {
        return flightDistance;
    }
    int getKillerMonster(){
        return killerMonster;
    }
    friend ostream &operator<<(ostream &output, const Monster &v)
    {
     output << v.id << " " << ((v.flightDistance == 1) ? "Hill Giant" : "Dragon");
        output << " (" << v.position.first << "," << v.position.second << ") " << v.size << " ";
        if (v.direction == north)
            output << "north ";
        else if (v.direction == east)
            output << "east ";
        else if (v.direction == south)
            output << "south ";
        else
            output << "west ";
        if (v.flightDistance > 1)
            output << v.flightDistance << " ";
        output << " " << ((v.alive) ? "alive" : "dead");
        output << "\n";
        return output;
    }
    
};
