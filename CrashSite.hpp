/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/19
 * Descriptiom: header file for derived class CrashSite a derived class of 
 * abstract base class Space 
*******************************************************************************/

#ifndef CRASHSITE_HPP
#define CRASHSITE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Space.hpp"
#include "inputValidation.hpp"
using std::endl;
using std::string;
using std::cin;
using std::cout;

//class declaration of derived class of space 
class CrashSite:public Space
{
    private:
    
    public:
        virtual void intro();
        virtual int search();
        virtual int rain();
        virtual int injury();
        virtual int coldNight();
        virtual string siteName();
        virtual int siteCode();
        
        CrashSite()
        {
            //seeds random number generator 
            seed=time(0);
            std::srand(seed);
            
            //sets bool value as false 
            hereBefore=false;
        }
    
    protected:
        unsigned seed; 
        bool flareGunFound=false;
        
    
};
#endif 