/******************************************************************************
Author: Maryum Shabazz
Date: 6/5/2019
Description: menu header file, holds functions and variables for menu cpp
*******************************************************************************/
#include <iostream>
#include <string>
#ifndef MENU_HPP
#define MENU_HPP
#include "inputValidation.hpp"
#include "Game.hpp"

using std::endl;
using std::string;
using std::cin;
using std::cout;


//menu class declared
class Menu 
{
    private:
        void menuSelectionFunction();
        string umenuSelect;
        int menuSelect;
    
    public:
        void menuFunction();
       
    protected:
    
    
};
#endif