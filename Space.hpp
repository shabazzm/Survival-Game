/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/2019
 * Description: header file for abstract class , holds several pure virtual 
 * functions and several variables that will be used in derived classes 
 * this space class cannot be instantiated 
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>

using std::endl;
using std::string;
using std::cin;
using std::cout;

//class declaration of space 
class Space 
{
   private:
   
        //REQUIRED POINTERS
        Space* top=NULL;
        Space* bottom=NULL;
        Space* left=NULL;
        Space* right=NULL;
   
   public:
   
        //setters and getters for space pointers 
        Space* getRight();
        Space* getLeft();
        Space* getBottom();
        Space* getTop();
        void setRight(Space*);
        void setLeft(Space*);
        void setBottom(Space*);
        void setTop(Space*);
        virtual void resetSearchTime();
        virtual int returnSearchTime();
        
        //pure virtial function 
        virtual void intro()=0;
        virtual int search()=0;
        virtual int rain()=0;
        virtual int injury()=0;
        virtual int coldNight()=0;
        virtual string siteName()=0;
        virtual int siteCode()=0;
        
	
   protected:
        string name, token;
        bool hereBefore=false;
        int timesVisted=0, searchTime=0;

};
#endif 
