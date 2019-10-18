/*******************************************************************************
 *Author: Maryum Shabazz
  Date: 6/5/19
  Description: Boat file holds, injury, search, site name, site code, rain, and
  cold weather functions for boat.  
*******************************************************************************/
#include "Boat.hpp"


/*******************************************************************************
 * void function, with no parameters or arguements used to describe space to 
 * user, if user has been to area before they are given a shorter description of
 * area. 
*******************************************************************************/
void Boat::intro()
{
    if (hereBefore==false)
    {
        cout<<"There is a boat near the shore of a river. It looks to be"<<endl;
        cout<<"okay to row. The map shows taking the boat to near the"<<endl;
        cout<<"logging road then walking to the road would be shorter"<<endl;
        cout<<"but I'm not sure the boat will survive a trip on the river"<<endl;
        cout<<"Maybe I should go to the cabin and take the road"<<endl;
        cout<<"from there."<<endl;
        cout<<endl;
        cout<<endl;
    }
    else if(hereBefore==true)
    {
        timesVisted++;
        cout<<"I have been to this boat "<<timesVisted<< " time(s) before,"<<endl;
        cout<<"It isn't very big, I don't think it has anything more "<<endl;
        cout<<"than I found in it before"<<endl;
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
int Boat::search()
{
    string uoption;
    int option;
    
    
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    //used to determine what can be found 
    if(die1==1)
    {
        //gives user option to  find flare gun if not found
        if(flareGunFound==false)	//if flaregun has not been found 
        {
            cout<<"There's is fisherman's tool chest under the"<<endl;
            cout<<"row boat seat."<<endl;
            cout<<"Should I open the chest?"<<endl;
            
            cout<<"Select 1 to open chest"<<endl;
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
            
	    //used to determine if user searches chest 
            if (option==1)
            {
                cout<<"There's a flare gun in this old tool chest"<<endl;
                
                cout<<"I can use this when I get to the road to signal for"<<endl;
                cout<<"safety."<<endl;
                cout<<endl;
                cout<<endl;
                
		//flaregun found 
                searchTime++;
                return 7;
            }
            else if(option==2)	//users chooses not to search chest 
            {
                cout<<"I'm not wasting my time searching every nook and cranny"<<endl;
                cout<<"I'm so close to being rescued I need to focus on that"<<endl;
                cout<<endl;
                searchTime++;
                
                return 0;
            }
        }
        else if(flareGunFound==true)	//if user has found flaregun nothing found
        {
            cout<<"This boat doesn't have much more"<<endl;
            cout<<endl;
            searchTime++;
            
            return 0;
        }
        
    }
    else if (die1==2)	//user finds twine
    {
       
        cout<<"I found some twine, maybe I can use this"<<endl;
        cout<<endl;
        searchTime++;
        return 1;
        
    }
    else if(die1==3)	//user finds first aid kit 
    {
       cout<<"Let me see what else is in this boat."<<endl;
       cout<<"I found a first aid kit, tucked in a corner of the boat."<<endl;
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
int Boat::injury()
{
             
   
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1)
    {

        return 1;
        
        
    }
    else if (die1==2)
    {
       
        cout<<"This boat has a lot of splinters, I just got a big one in my palm."<<endl;
        cout<<endl;
        cout<<endl;
        
        return 2;
        
    }
    else if(die1==3)
    {
       cout<<"Ouch, there's some leeches in the water in the boat's bottom"<<endl;
       cout<<"Those blood suckers hurt"<<endl;
       cout<<endl;
       cout<<endl;
       
       return 2;
        
    }
    
    
}

/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
 * to determine the severity of the damage done by rain which is passed to 
 * severity function for rain in game cpp 
*******************************************************************************/
int Boat::rain()
{
     
   //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
    if(die1==1)
    {
        return 1;
    }
    else if (die1==2)
    {
        cout<<"There's no protection from the rain in this boat"<<endl;
        cout<<endl;
        cout<<endl;
        
        return 2;
        
    }
    else if(die1==3)
    {
        cout<<"The boat fills with water when it rains. I'm freezing"<<endl;
        cout<<"Maybe I can find some sort of shelter temporarily."<<endl;
        cout<<endl;
        cout<<endl;
        
        return 3;
    }
    return 1;
    
}
/*******************************************************************************
 * int function with no parameters or arguements, generates random number 
   which is returned and will be passed to function in game cpp. Uses if else if 
   branch to determine how cold it will be 
*******************************************************************************/
int Boat::coldNight()
{
     
   
    //generates random numbers from 1 to 3.    
    const int MINVAL=1,DIESIDES=3;
    int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
    
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
string Boat::siteName()
{
    string site="BOAT";
    return site;
}
/*******************************************************************************
 *  int function, returns number site is designated at to be used in game cpp
 * for determine if user has reached logging road yet. 
*******************************************************************************/
int Boat::siteCode()
{
    int codeNum=2;
    return codeNum;
}
