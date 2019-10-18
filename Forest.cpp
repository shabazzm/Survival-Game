/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/19
 * Description: cpp file for forest which holds functions to control 
 * injuries, cold,introduction to scene and what you can search.
*******************************************************************************/
#include "Forest.hpp"


/*******************************************************************************
 * void function, with no parameters or arguements used to describe space to 
 * user, if user has been to area before they are given a shorter description of
 * area.  
*******************************************************************************/
void Forest::intro()
{
    if (hereBefore==false)
    {
        cout<<"It's a forest thick with trees and bugs. I don't see anything"<<endl;
        cout<<"we can eat. The mosquitos are killing me. We should "<<endl;
        cout<<"move on quickly."<<endl;
        
        cout<<"The map says ahead there should be a cabin, maybe I can"<<endl;
        cout<<"find shelter there"<<endl;
        cout<<endl;
        cout<<endl;
    }
    else if(hereBefore==true)
    {
        timesVisted++;
        cout<<"You have been to this forest "<<timesVisted<< "  times "<<endl;
        cout<<"before."<<endl;
        cout<<"Visiting this place again is not helping"<<endl;
        cout<<"we need to get to safety"<<endl;
        cout<<endl;
        cout<<endl;
        
        
    }
    
    
    hereBefore=true;
    
}
/*******************************************************************************
 * int function with no parameters or arguements, used to randomly determine 
 * what items are found. A random number is generated and an if/else if branch
 * is used to determine which items are found if any. 
*******************************************************************************/
int Forest::search()
{
    int option;
    string uoption;
    
    //generates andom numbers from 1 to 3  
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else if branch used to determine what is found 
    if(die1==1)
    {
         cout<<"This time of year there's not much to be found in the"<<endl;
         cout<<"forest."<<endl;
         
         searchTime++;
         return 0;
    }
    else if(die1==2)
    {
        cout<<"I see something shiny out the corner of my eye"<<endl;
        cout<<endl;
        cout<<endl;
        
        //prompt for user    
        cout<<"What would you like to do?"<<endl;
        cout<<"Select 1 to check out the shiny object"<<endl;
        cout<<"Select 2 to continue onwards"<<endl;
        cout<<endl;
        
        //obtains input from user and validates it  
        getline(cin,uoption);
        option=inputValidation(uoption);
           
        while(option<1 ||option>2)
        {
            cout<<"select 1 for yes and 2 for no"<<endl;
            getline(cin,uoption);
            option=inputValidation(uoption);
        }
        
        //if else branch to control what happens based on players choice 
        if(option==1)   //pocket knife found 
        {
            cout<<"I move aside the undergrowth. There's a slightly rusted "<<endl;
            cout<<"pocket knife lying there"<<endl;
            cout<<"This could come in handy"<<endl;
            cout<<endl;
            cout<<endl;
            
            searchTime++;
            return 3;
        }
        else if(option==2)  //nothing found 
        {
            cout<<"I don't want to waste time I need to keep moving"<<endl;
            cout<<endl;
            cout<<endl;
            
            return 0;
        }
        
        
       
    }
    else if(die1==3)
    {
        cout<<"This forest seems neverending. I may never make it out of here alive"<<endl;
        cout<<endl;
        searchTime++;
        return 0;
        
    }
  
    
    
}
/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by injury. Also gives brief 
 * description of injury.
*******************************************************************************/
int Forest::injury()
{
        
    
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else if branch to determine what injury happens 
    if(die1==1)
    {
        return 1;
    }
    else if (die1==2)   //mild injury 
    {
        cout<<"There's thorn's and brambles everywhere"<<endl;
        cout<<"it would be easy to get hurt"<<endl;
        cout<<"Damn, I just tripped on a root and skinned my knee"<<endl;
        
        return 2;
        
    }
    else if(die1==3)    //moderate to severe injury 
    {
        cout<<"FUCK! I didn't even realise that ravine was there"<<endl;
        cout<<"Pretty sure my ankle is sprained"<<endl;
        cout<<endl;
        cout<<endl;
        
        return 3;
    }
    
    
}

/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by rain which is passed to 
 * severity function for rain in game cpp 
*******************************************************************************/
int Forest::rain()
{
     
    //generatesrandom numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1) //no rain 
    {
        return 1;
    }
    else if (die1==2)   //mild rain 
    {
        cout<<"Some of these tree's block the rain pretty well. "<<endl;
        cout<<endl;
        return 2;
        
    }
    else if(die1==3)    //moderate rain 
    {
        cout<<"The forest doesn't provide great shelter."<<endl;
        cout<<endl;
 
        cout<<endl;
        
        return 3;
    }
    
}
/*******************************************************************************
 * int function, has no parameters or arguement. Random number is generated 
 * which is used to determine how cold the night will be. 
*******************************************************************************/
int Forest::coldNight()
{
     
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else if branch to determine how cold night will be
    if(die1==1) //warm night 
    {
        return 1;
    }
    else if (die1==2)   //cool night 
    {
        return 2;
        
    }
    else if(die1==3)    //cold night 
    {
        return 3;
    }
    
    
}

/*******************************************************************************
 * string function with no parameters or arguements, returns name of site. 
*******************************************************************************/
string Forest::siteName()
{
    string site="FOREST";
    return site;
}
/*******************************************************************************
 *  int function, returns number site is designated at to be used in game cpp
 * for determine if user has reached logging road yet. 
*******************************************************************************/
int Forest::siteCode()
{
    int codeNum=2;
    return codeNum;
}
