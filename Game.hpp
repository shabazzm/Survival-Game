/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/9/2019
 * Description: Game cpp header file that holds functions, and variables that
 * will be used to control flow of game
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "inputValidation.hpp"
#include <vector>
#include "Space.hpp"
#include "Forest.hpp"
#include "River.hpp"
#include "CrashSite.hpp"
#include "Cabin.hpp"
#include "Boat.hpp"
#include "Safety.hpp"


using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::vector;

//class declaration of game class 
class Game 
{
    private:
        
    
    public:
        
        Boat boat1;
        CrashSite crash;
        River river1;
        Forest forest1;
        Cabin cabin1;
        Safety safety1;
        Game();
        void setMap();
        
        
    protected:
        void printMap();
        void movePlayer();
        void gameFlow();
        Space *playerPtr=&crash;
        Space*tempPtr=&crash;
        
        void itemStorage(int);
        void rainSeverity(int);
        void coldSeverity(int);
        void injurySeverity(int);
        int saved();
        
        
        int health=25;
        
        //used to hold items 
        vector<string>backpack;
        int backPackMax=25;
        int itemsInBackPack=0;
        bool twine=false, packagedFood=false;
        bool pocketKnife=false, firstAidKit=false;
        bool fireStarter=false, driedJerky=false;
        bool flareGun=false;
        bool waterBottle=false;
        bool playerSaved=false;
        unsigned seed;
        
        
    
    
};
#endif
