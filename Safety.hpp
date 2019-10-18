/*******************************************************************************
 * Author: Maryum Shabaz
 * Date: 6/5/19
 * Description: Header file for derived class for base abstract class of space 
*******************************************************************************/
#ifndef SAFETY_HPP
#define SAFETY_HPP

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

// class declaration of derived class of abstract base class space 
class Safety:public Space
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
        Safety()
        {
            //seeds random number generator 
            seed=time(0);
            std::srand(seed);
            
            //sets flag to be used in intro  function as false 
            hereBefore=false;
        }
    
    protected:
        unsigned seed; 
        bool flareGunFound=false;
        
        
    
};
#endif 