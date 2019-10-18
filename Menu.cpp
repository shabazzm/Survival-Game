/******************************************************************************
Author: Maryum Shabazz
Date: 6/5/2019
Description: Menu cpp holds menu function to display menu options, and 
holds function so user can select menu option wanted. After each 
instance of the game the menu is returned too 
*******************************************************************************/
#include "Menu.hpp"

/****************************************************************************
 * This is a void function with no arguements or parameters and displays 
 * options to play or quit to the user and calls calls menuSelectionFunction.
****************************************************************************/
void Menu::menuFunction()
{
    //prompts displayed to user
    cout<<"Follow the Menu Prompts"<<endl;
    cout<<"1. Select 1 to PLAY"<<endl;
    cout<<"2. Select 2 to QUIT"<<endl;
    
    //calls function so user can select menu option 
    menuSelectionFunction();
}
/*******************************************************************************
 * This is a void function with  no parameter or arguements. This function 
 * allows the user to select the menu option they would like 
*******************************************************************************/
void Menu::menuSelectionFunction()
{
    
    //obtains menu selection from user and validates input
    getline(cin, umenuSelect);
    menuSelect=inputValidation(umenuSelect);
    while(menuSelect<1 || menuSelect>2)
    {
       cout<<"Enter number between 1 and 2."<<endl;
       getline(cin, umenuSelect);
       menuSelect=inputValidation(umenuSelect); 
    }
    
    //if else if  branch to control what action is executed. 
    if(menuSelect==1)
    {
        //creates game object 
        Game program1;
        
        //calls the function that will begin the game. 
        program1.setMap();
        
        //sends user back to menu function 
        menuFunction();
    }
    else if(menuSelect==2)
    {
        //prompt for user
        cout<<"EXITED..."<<endl;
    }
    
}

