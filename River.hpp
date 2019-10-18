/*******************************************************************************
 * Author: Maryum Shabaz
 * Date: 6/5/19
 * Description: Header file for derived class for base abstract class of space 
*******************************************************************************/
#ifndef RIVER_HPP
#define RIVER_HPP

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

// class declaration for derived class of asbtract base class 
class River:public Space
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
        
        //constructor 
        River()
        {
            //seeds random number generator 
            seed=time(0);
            std::srand(seed);
            
            //flag used in intro function 
            hereBefore=false;
        }
    
    protected:
        unsigned seed; 
        
        
    
};
#endif 