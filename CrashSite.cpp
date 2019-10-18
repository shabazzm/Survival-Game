/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/19
 * Description: main file for crashite file which holds functions to control 
 * injuries, cold,introduction to scene and what you can search.
*******************************************************************************/
#include "CrashSite.hpp"

/*******************************************************************************
 * void function, with no parameters or arguements used to describe space to 
 * user, if user has been to area before they are given a shorter description of
 * area. 
*******************************************************************************/
void CrashSite::intro()
{
    //if else if statement dictates which output will be displayed to user 
    if (hereBefore==false)
    {
        cout<<"You were flying out to visit family across country"<<endl;
        cout<<"The plane you were in has crashed killing all 327 passengers"<<endl;
        cout<<"except you. You crawl from the burning wreckage of the  "<<endl;
        cout<<"plane over dead bodies and flaming sharp wreckage to "<<endl;
        cout<<"collapse in the undergrowth."<<endl;
        cout<<endl;
        cout<<endl;
        
        cout<<"In the distance you hear what could be rushing water to"<<endl;
        cout<<"your left. To your right you see a forest."<<endl;
        cout<<"Both are far away."<<endl;
        cout<<endl;
        cout<<endl;
        
        cout<<"All you have is the clothes on your back and a backpack"<<endl;
        cout<<"that was under your seat and filled with a computer and"<<endl;
        cout<<"a paperback"<<endl;
        cout<<endl;
        cout<<endl;
        
        cout<<"You notice a waterproof map lying a few feet from you"<<endl;
        cout<<"you pick it up"<<endl;
        cout<<endl;
        cout<<endl;
        
        cout<<"You rest for several minutes before deciding what to"<<endl;
        cout<<"do next."<<endl;
        cout<<endl;
        cout<<endl;
    }
    else if(hereBefore==true)
    {
        //counter used to keep track of how many times each area has been visted.
        timesVisted++;
        
        cout<<"You have been to this crash site "<<timesVisted<< " times before,"<<endl;
        cout<<" bodies lie rotting on the ground, the stench of decayed"<<endl;
        cout<<"flesh is heavy in the air, flies swarm the wreckage."<<endl;
        cout<<endl;
        cout<<endl;
        
    }
    
    //sets marker to let user know they have been there 
    hereBefore=true;
    
    
}
/*******************************************************************************
 * int function with no parameters or arguements, used to randomly determine 
 * what items are found. A random number is generated and an if/else if branch
 * is used to determine which items are found if any. 
*******************************************************************************/
int CrashSite::search()
{
    string uoption;
    int option;
    
    //generates random numbers from 1 to 6.    
    const int MINVAL=1,DIESIDES=8;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //used to determine which item is found 
    if(die1==1)
    {
        //if else branch used to determine what will happen if flaregun is 
        //found or not found. 
        if(flareGunFound==false)
        {
            //displays prompt for user 
           cout<<"You hear movement in the wreckage and what sound like a "<<endl;
           cout<<"calling for help"<<endl;
           cout<<endl;
           
           //gives user choice of what to do 
           cout<<"What would you like to do?"<<endl;
           cout<<"Select 1 to go towards the voice"<<endl;
           cout<<"Select 2 to ignore the voice and continue onwards"<<endl;
           cout<<endl;
           
           //collects input from user and validates input 
           getline(cin,uoption);
           option=inputValidation(uoption);
           
           while(option<1 ||option>2)
           {
               cout<<"select 1 for yes and 2 for no"<<endl;
               getline(cin,uoption);
               option=inputValidation(uoption);
           }
           
           //if users chooses to go toward voice 
           if(option==1)
           {
               cout<<"Let's search"<<endl;
               cout<<"There could be survivors"<<endl;
               cout<<"You pick your way through the crash site "<<endl;
               cout<<" and find the co-pilot alive a short way away"<<endl;
               cout<<"from the ruined cockpit"<<endl;
               
               cout<<"He's streaked with blood and can barely talk"<<endl;
               cout<<endl;
               
               cout<<endl;
               cout<<"He tells you 'You're the only survivor."<<endl;
               cout<<"It's miles away until you'll reach any civilization"<<endl;
               cout<<"Search the wreckage, there's supplies you can take' "<<endl;
               cout<<"he passes you a flare gun and then dies"<<endl;
               
              //flare gun is found 
              flareGunFound=true;
              
              //time spent searching is incremented 
              searchTime++;
              return 7;
               
               
           }
           else if(option==2)   //users chooses not to go towards the voice 
           {
               cout<<"Good choice, searching for survivors will slow "<<endl;
               cout<<"you down. "<<endl;
               return 0;
           }
            
        }
        else if(flareGunFound==true)
        {
            cout<<"There doesn't seem to be much in the area"<<endl;
            cout<<"I should probably move on"<<endl;
            cout<<endl;
            
            //time spent searching is incremented.
            searchTime++;
            return 0;
        }
    }
    else if(die1==2)    // dried food is found 
    {
        cout<<"I found a package of food freeze dried food from one of"<<endl;
        cout<<"the plane's emergency kit, everything else is ruined"<<endl;
        cout<<endl;
        cout<<endl;
        
        searchTime++;
        return 2;
    }
    else if(die1==3)    //cigarette lighter is found 
    {
        cout<<"A dead man lies in my path, I searched his pockets"<<endl;
        cout<<"He has a cigarette lighter, good for starting fires"<<endl;
        cout<<endl;
        cout<<endl;
        
        searchTime++;
        return 5;
    }
    else if(die1==4 || die1==5 || die1==6)  //empty water bottle is found 
    {
        cout<<"There's an empty pint water bottle"<<endl;
        cout<<"Every little bit helps"<<endl;
        
        cout<<endl;
        cout<<endl;
        
        searchTime++;
        return 8;
    }
    else if(die1==7 || die1==8)     //twine is found 
    {
        cout<<"I find some pieces of plastic cord. These should come in"<<endl;
        cout<<"handy"<<endl;
        
        cout<<endl;
        cout<<endl;
        
        searchTime++;  
        return 1;
    }
    
    
    
    
    
    
}
/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by injury. Also gives brief 
 * description of injury. 
*******************************************************************************/
int CrashSite::injury()
{
        
    
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1) 
    {
        return 1;
    }
    else if (die1==2)   //mild injury 
    {
        cout<<"I tripped and scraped off some skin"<<endl;
        cout<<"The abrasion isn't deep but now I have to worry about infection"<<endl;
        
        cout<<endl;
        cout<<endl;
        return 2;
        
    }
    else if(die1==3)    //moderate to severe injury 
    {
        cout<<"The wreckage is dangerous and I sliced my skin on a shard of metal"<<endl;
        cout<<"The bleeding stopped after a few minute of pressure but keeping it clean"<<endl;
        cout<<"will be difficult"<<endl;
        cout<<endl;
        
        return 3;
    }
    
    
}

/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by rain which is passed to 
 * severity function for rain in game cpp 
*******************************************************************************/
int CrashSite::rain()
{
     
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else branch determines severity of rain 
    if(die1==1) //no rain 
    {
        return 1;
    }
    else if (die1==2)   //mild rain
    {
        return 2;
        
    }
    else if(die1==3)    //moderate to severe rain 
    {
 
        cout<<endl;
        
        return 3;
    }
    
}
/*******************************************************************************
 * int function, has no parameters or arguement. Random number is generated 
 * which is used to determine how cold the night will be. 
*******************************************************************************/
int CrashSite::coldNight()
{
     
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
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
 
        cout<<endl;
        
        return 3;
    }
    
    
}
/*******************************************************************************
 * string function with no parameters or arguements, returns name of site. 
*******************************************************************************/
string CrashSite::siteName()
{
    string site="CRASH SITE";
    return site;
}
/*******************************************************************************
 * int function, returns number site is designated at to be used in game cpp
 * for determine if user has reached logging road yet. 
*******************************************************************************/
int CrashSite::siteCode()
{
    int codeNum=2;
    return codeNum;
}