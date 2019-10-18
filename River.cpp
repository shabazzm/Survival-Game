/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/19
 * Description: cpp file for river which holds functions to control 
 * injuries, cold,introduction to scene and what you can search.
*******************************************************************************/
#include "River.hpp"


/*******************************************************************************
 * void function, with no parameters or arguements used to describe space to 
 * user, if user has been to area before they are given a shorter description of
 * area. 
*******************************************************************************/
void River::intro()
{
    //determines which introduction will be displayed to user 
    if (hereBefore==false)
    {
        cout<<"You've made it to the bank of a river, the water looks clear"<<endl;
        cout<<"it might be safe for drinking."<<endl;
        cout<<"The map says from this river I should be able to reach a boat"<<endl;
        cout<<endl;
    }
    else if(hereBefore==true)
    {
        timesVisted++;
        cout<<"You have been to this river site times "<<timesVisted<< " before,"<<endl;
        
        
    }
    
    hereBefore=true;
    
}
/*******************************************************************************
 * int function with no parameters or arguements, used to randomly determine 
 * what items are found. A random number is generated and an if/else if branch
 * is used to determine which items are found if any. 
*******************************************************************************/
int River::search()
{
    string uoption;
    int option;
    
    //generates random numbers from 1 to 2.    
    const int MINVAL=1,DIESIDES=2;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else branch to determine what will be found 
    if(die1==1)
    {
        
        cout<<"except water this river is useless"<<endl;
        cout<<" I don't see anything around here but sticks and rocks "<<endl;
        cout<<endl;
        cout<<endl;
        searchTime++;
        return 0;
               
               
    }
    else if(die1==2)
    {
        cout<<"I can't find anything here. Wait, I think I see something!"<<endl;
        cout<<"...never mind, just another rock."<<endl;
        cout<<endl;
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
int River::injury()
{
    string uoption;
    int option;
        
    
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //if else if determines which injury will happen 
    if(die1==1) //no injury 
    {
        return 1;
    }
    else if (die1==2)   //mild injury 
    {
       
        return 2;
        
    }
    else if(die1==3)    // chance for severe injury or no injury 
    {
        //gives user prompt of what options are possible 
        cout<<"What would should I do?"<<endl;
        cout<<"I'm really thirsty and this water should be okay"<<endl;
        cout<<"Select 1 to drink water"<<endl;
        cout<<"Select 2 to not drink the water"<<endl;
        cout<<endl;
          
        //obtains and validates user input 
        getline(cin,uoption);
        option=inputValidation(uoption);
           
        while(option<1 ||option>2)
        {
            cout<<"select 1 for yes and 2 for no"<<endl;
            getline(cin,uoption);
            option=inputValidation(uoption);
        }
        
        //if users selects 1 (yes) random number are generated to determine if 
        //user will get sick or not. 66% chance of getting sick, 33% chance of not  
        if(option==1)
        {
            //random number generated 
            int die2=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
            
            //if else if branch determines what will happen based on random number 
            //generated 
            if(die2==1) //user does not become ill 
            {
                cout<<"This water isn't so bad, a little silty"<<endl;
                cout<<endl;
                return 1;
            }
            else if(die2==3 || die2==2)     //user becomes ill (moderate to severe )
            {
                cout<<"ughhh...I really shouldn't have drank this water"<<endl;
                cout<<"I feel like I'm going to die"<<endl;
                cout<<"my stomach is killing me"<<endl;
                cout<<endl;
                cout<<endl;
                return 3;
            }
        }
        else if(option==2)  //user chooses not to drink water is not ill 
        {
            cout<<"Yeah, this water probably isn't safe"<<endl;
            cout<<"I'll find something else"<<endl;
            cout<<endl;
            return 1;
        }
        
        
    }
    
    
}

/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by rain which is passed to 
 * severity function for rain in game cpp 
*******************************************************************************/
int River::rain()
{
     
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
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
int River::coldNight()
{
     
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1) //warm night 
    {
        return 1;
    }
    else if (die1==2)   // cool night 
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
string River::siteName()
{
    string site="RIVER";
    return site;
}
/*******************************************************************************
 *  int function, returns number site is designated at to be used in game cpp
 * for determine if user has reached logging road yet. 
*******************************************************************************/
int River::siteCode()
{
    int codeNum=2;
    return codeNum;
}