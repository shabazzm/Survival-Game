/*******************************************************************************
 * Author: Maryum Shabaz
 * Date: 6/5/19
 * Description: Header file for derived class for base abstract class of space 
*******************************************************************************/

#ifndef FOREST_HPP
#define FOREST_HPP

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

//class declaration of derived class of abstract base class 
class Forest:public Space
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
        Forest()
        {
            //seeds random number generator 
            seed=time(0);
            std::srand(seed);
            
            //sets bool flag as false 
            hereBefore=false;
        }
    
    protected:
        unsigned seed; 
       
    
};
#endif 
