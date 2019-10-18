/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/19 
 * Description cpp file for cabin which holds functions to control 
 * injuries, cold,introduction to scene and what you can search.
*******************************************************************************/
#include "Cabin.hpp"


/*******************************************************************************
 * void function, with no parameters or arguements used to describe space to 
 * user, if user has been to area before they are given a shorter description of
 * area. 
*******************************************************************************/
void Cabin::intro()
{
    if (hereBefore==false)
    {
        cout<<"There's a deserted cabin in the woods just like the map."<<endl;
        cout<<"shows. I wonder what's inside?"<<endl;
        cout<<"Maybe it has some food or something I can use to signal for help."<<endl;
        cout<<"You walk inside the cabin to find it covered with cobwebs"<<endl;
        cout<<"and dust. It looks like no one has lived here for years"<<endl;
        cout<<"There's an old wooden table and chair and a bed"<<endl;
        cout<<"with moth eaten blankets."<<endl;
        cout<<endl;
        cout<<endl;
    }
    else if(hereBefore==true)
    {
        timesVisted++;
        cout<<"You have been to this cabin "<<timesVisted<< " times before,"<<endl;
        cout<<"It's still as dusty as ever. I don't know how much more "<<endl;
        cout<<"there is to find here."<<endl;
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
int Cabin::search()
{
    string uoption;
    int option;
    
    
    //generates random 2 random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1)
    {
        if(flareGunFound==false)
        {
            cout<<"There's an old safe recessed in one wall."<<endl;
            cout<<"Should I open the safe?"<<endl;
            
            cout<<"Select 1 to break apart chair and use pieces"<<endl;
            cout<<"to pry open safe"<<endl;
            cout<<"Select 2 to leave safe alone "<<endl;
            cout<<endl;
           
            getline(cin,uoption);
            option=inputValidation(uoption);
           
            while(option<1 ||option>2)
            {
                cout<<"select 1 for yes and 2 for no"<<endl;
                getline(cin,uoption);
                option=inputValidation(uoption);
            }
            
            if (option==1)
            {
                cout<<"Finally some luck! There's a flare gun in this old safe"<<endl;
                cout<<"I can use this to signal for help if I can ever reach that road"<<endl;
                
                cout<<"A warm place to rest, a flare gun and a moth eaten bed!"<<endl;
                cout<<"What more can I ask for?"<<endl;
                cout<<endl;
                
                searchTime++;
                return 7;
            }
            else if(option==2)
            {
                cout<<"Yeah, prying open an old safe is a fool's errand"<<endl;
                cout<<"I need food, water and shelter, not some old coins"<<endl;
                
                cout<<endl;
                searchTime++;
                
                return 0;
            }
        }
        else if(flareGunFound==true)
        {
            cout<<"This cabin is pretty barren not much to see here"<<endl;
            cout<<"It's probably a wasting of time searching more"<<endl;
            cout<<endl;
            searchTime++;
            
            return 0;
        }
        
    }
    else if (die1==2)
    {
       
        cout<<"I found some sealed homemade jerky and I think it's still edible"<<endl;
        cout<<"Whoever lived here must have been a great cook, this is pretty good"<<endl;
        cout<<endl;
        searchTime++;
        return 6;
        
    }
    else if(die1==3)
    {
       cout<<"Let me see what's under this bed."<<endl;
       cout<<"Looks like it's an old first aid kit."<<endl;
       cout<<"This could really come in handy!"<<endl;
       cout<<endl;
       searchTime++;
       
       return 4;
        
    }
    
    
}
/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by injury. Also gives brief 
 * description of injury.
*******************************************************************************/
int Cabin::injury()
{
    string uoption;
    int option;
        
    
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1) 
    {

            cout<<"I'm going to see what are in these cabinets near the bed."<<endl;
            cout<<"The top drawer is empty , I'll check the bottom too?"<<endl;
            
            cout<<"Select 1 to open bottom drawer"<<endl;
            cout<<"Select 2 to not open bottom drawer "<<endl;
            cout<<endl;
           
            getline(cin,uoption);
            option=inputValidation(uoption);
           
            while(option<1 ||option>2)
            {
                cout<<"select 1 for yes and 2 for no"<<endl;
                getline(cin,uoption);
                option=inputValidation(uoption);
            }
            
            if (option==1)
            {
                cout<<"Damn, a mouse just ran out and bit me...don't those things carry disease?"<<endl;
                cout<<"I have shitty luck."<<endl;
                cout<<endl;
                cout<<endl;
                
                return 2;
            }
            else if(option==2)
            {
                cout<<"Yeah, I'm not going to open some old drawer, besides I hear scurrying inside"<<endl;
                cout<<"Some animals are really dangerous"<<endl;
                cout<<endl;
                cout<<endl;
                
                return 1;
            }
        
        
        
    }
    else if (die1==2)   //mild injury
    {
       
        cout<<"This cabin is pretty nice, the mattress is comfy even without sheets"<<endl;
        cout<<endl;
        return 1;
        
    }
    else if(die1==3)    //moderate to severe injury
    {
       cout<<"Shit!, I just scracthed myself on a rusty nail hanging from the wall"<<endl;
       cout<<"I think my tetanus is up to date so I should be okay"<<endl;
       cout<<endl;
       cout<<endl;
       
       return 2;
        
    }
    
    
}

/*******************************************************************************
 * int function with no parameters or arguements, returns number 
 * to determine the severity of the damage done by rain which is passed to 
 * severity function for rain in game cpp 
*******************************************************************************/
int Cabin::rain()
{
     
    cout<<"Luckily this cabin looks old but the roof seems good"<<endl;
    cout<<"I shouldn't have to worry about rain"<<endl;
    cout<<endl;
    cout<<endl;
    
    return 1;
    
}
/*******************************************************************************
 *int function with no parameters or arguements, returns int, randomly generates
  random number which will be used in game cpp to determine how cold night will 
  be.  
*******************************************************************************/
int Cabin::coldNight()
{
     
    //generates  random numbers from 1 to 2.    
    const int MINVAL=1,DIESIDES=2;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else branch determines how warm cabin is.
    if(die1==1)	//warm night 
    {
        cout<<"I'm pretty cozy in this cabin I think I'll take a short nap"<<endl;
        cout<<endl;
        return 1;
    }
    else if (die1==2)	//cool night 
    {
        return 2;
        
    }
    
}

/*******************************************************************************
 * string function with no parameters or arguements, returns name of site. 
*******************************************************************************/
string Cabin::siteName()
{
    string site="CABIN";
    return site;
}
/*******************************************************************************
 *  int function, returns number site is designated at to be used in game cpp
 * for determine if user has reached logging road yet. 
*******************************************************************************/
int Cabin::siteCode()
{
    int codeNum=2;
    return codeNum;
}
