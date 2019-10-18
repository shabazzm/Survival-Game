/*******************************************************************************
 *Author: Maryum Shabazz
  Date: 6/5/19
  Description: file for safety site, has search, injury, cold weather and rain
  functionality.  
*******************************************************************************/
#include "Safety.hpp"


/*******************************************************************************
 * void function, with no parameters or arguements used to describe space to 
 * user.
*******************************************************************************/
void Safety::intro()
{
        cout<<"I finally made it! The old logging road is still here."<<endl;
        cout<<"Now I just need something to signal for help. "<<endl;
        cout<<endl;
        cout<<endl;
   
    hereBefore=true;
    
}
/*******************************************************************************
 * int function with no parameters or arguements, used to randomly determine 
 * what items are found. A random number is generated and an if/else if branch
 * is used to determine which items are found if any. 
*******************************************************************************/
int Safety::search()
{
           
    
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else if branch to determine which objects will be found 
    if(die1==1)
    {
        cout<<"I don't think there is much to find on this road"<<endl;
        cout<<"I take that back, I just found some twine"<<endl;
        cout<<endl;
        searchTime++;
        return 1;
        
    }
    else if (die1==2)
    {
       
        cout<<"Well that was a waste of time I found rocks."<<endl;
        cout<<endl;
        searchTime++;
        return 0;
        
    }
    else if(die1==3)
    {
       cout<<"I'd be better off trying to get blood from a turnip. THis road has NOTHING."<<endl;
       cout<<endl;
       searchTime++;
       
       return 0;
        
    }
    
    
}
/*******************************************************************************
 * int function generates injury that will be produced. Logging road is safe
   and no injury will happen. Has no parameters or arguements. 
*******************************************************************************/
int Safety::injury()
{
         
    
    cout<<"This old logging road is pretty safe, level and flat"<<endl;
    cout<<"At least there is nothing to injure myself on here"<<endl;
    return 1;
    
}

/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by rain which is passed to 
 * severity function for rain in game cpp 
*******************************************************************************/
int Safety::rain()
{
     
   //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
     //if else if branch to determine whether it will rain
    if(die1==1)	//no rain 
    {
        return 1;
    }
    else if (die1==2)	//mild rain 
    {
        cout<<"There's no protection from the rain on this road"<<endl;
        cout<<endl;
        cout<<endl;
        
        return 2;
        
    }
    else if(die1==3)	//moderate to severe rain
    {
        cout<<"The road is muddy and slippery when it rains."<<endl;
        cout<<"Maybe I can find some sort of shelter temporarily."<<endl;
        cout<<endl;
        cout<<endl;
        
        return 3;
    }
    return 1;
    
}
/*******************************************************************************
 * int function returns randomly generated number to determine weather 
   conditions. Has no arguements or parameters. 
*******************************************************************************/
int Safety::coldNight()
{
     
   
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else if branch to determine what weather will be like 
    if(die1==1)	//warm night
    {
        return 1;
    }
    else if (die1==2)	//cool night
    {
        return 2;
        
    }
    else if(die1==3)	//cold night
    {
     
        return 3;
    }
    
}

/*******************************************************************************
 * string function with no parameters or arguements, returns name of site. 
*******************************************************************************/
string Safety::siteName()
{
    string site="SAFETY";
    return site;
}
/*******************************************************************************
 *  int function, returns number site is designated at to be used in game cpp
 * for determine if user has reached logging road yet. 
*******************************************************************************/
int Safety::siteCode()
{
    int codeNum=7;
    return codeNum;
}
