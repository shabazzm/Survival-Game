/*******************************************************************************
 * Author: Maryum Shabazz
 * Date:6/5/2019
 * Description:Game cpp file contains function to store items, print map, set
 * directions on map, provide prompts for user and control flow of Game
 * also excepts injury, cold, and rain codes from space functions to control
 * severity of each event. 
*******************************************************************************/

#include "Game.hpp"

/*******************************************************************************
 * constructor for game function, provides instructions on how game runs , 
 * also seeds random time for random events to be used in several functions in
 * game cpp 
*******************************************************************************/
Game::Game()
{
    //displays objectives and function of game 
    cout<<"-------------------WILDERNESS SURVIVAL----------------------"<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<<"In this game you are a passenger of a downed plane that has "<<endl;
    cout<<"crashed in the wilderness. You will start with health"<<endl;
    cout<<"points. To reach the end of the game you must carefully observe"<<endl;
    cout<<"and out wit the harsh enviroment you find yourself in"<<endl;
    
    cout<<endl;
    cout<<endl;
    
    cout<<"An old logging road, is the closest path to civilization you "<<endl;
    cout<<"have, but it is usually deserted this time of the year"<<endl;
    cout<<"without a way to signal for help, you may die before being"<<endl;
    cout<<"rescued. The crash site provides many useful tools, look around "<<endl;
    cout<<"carefully. A flare gun will greatly increase your chances of"<<endl;
    cout<<"rescue. "<<endl;
    cout<<"At each site you will have the chance to search for objects"<<endl;
    cout<<"There an unlimited number of objects in each location "<<endl;
    cout<<"but the type of objects available may be different"<<endl;
    cout<<"not all objects are useful. "<<endl;
    cout<<"You will be given a back pack which can hold 25 items"<<endl;
    cout<<"Your character has been clinically diagnosed with OCD"<<endl;
    cout<<"and will not get rid of any items if you chooe to "<<endl;
    cout<<"keep them"<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<<"Each round a day goes by and your health will decrease by one automatically"<<endl;
    cout<<"each day, you will have the chance to get injured, endure"<<endl;
    cout<<"cold, and the chance for rain"<<endl;
    cout<<"Various items you collect along the way can aid you "<<endl;
    cout<<"in maintaining health"<<endl;
    cout<<endl;
    cout<<endl;
    
    cout<<"if you reach the logging road without a flare gun, your chances"<<endl;
    cout<<"of rescue are slim"<<endl;
    cout<<"if you health decreases below zero you will die"<<endl;
    cout<<"May the odds be ever in your favor."<<endl;
    cout<<endl;
    cout<<endl;
    
    
    //seeds random time
    seed=time(0);
    std::srand(seed);
    
    
  
}
/*******************************************************************************
 * This function has no parameters or arguements and prints map for user.
 * Allowing user to see where they are in relationship to everything else. 
*******************************************************************************/
void Game::printMap()
{
    
    //displays map of locations to user 
   cout<<"Game Map:"<<endl;
   cout<<endl; 
   
   cout<<"            OLD LOGGING ROAD  "<<endl;
   cout<<"                          ^"<<endl;
   cout<<"          /               |    "<<endl;
   cout<<"         /                |       "<<endl;
   cout<<"        /                 v        "<<endl;
   cout<<"       BOAT  <--------> CABIN"<<endl;
   cout<<"        ^                  ^"<<endl;
   cout<<"        |                  |"<<endl;
   cout<<"        |                  |"<<endl;
   cout<<"        v                  v"<<endl;
   cout<<"      RIVER<--> CRASH<-->FOREST     "<<endl;
   cout<<endl;
   cout<<endl;
   
}

/*******************************************************************************
 * this function has no parameters or arguements, it is used to link each 
 * pointer for each space to the correct space or set it to null if there is 
 * nothing in that direction. 
*******************************************************************************/
void Game::setMap()
{
    //assigns space pointers to the 6 object addresses. 
    Space*sitePtr1=&crash;
    Space*sitePtr2=&forest1;
    Space*sitePtr3=&river1;
    Space*sitePtr4=&cabin1;
    Space*sitePtr5=&boat1;
    Space*sitePtr6=&safety1;
    
    
    //sets crash site pointers 
    crash.setRight(sitePtr2);
    crash.setLeft(sitePtr3);
    crash.setTop(NULL);
    crash.setBottom(NULL);
    
    
    //sets forest site pointers 
    forest1.setRight(NULL);
    forest1.setLeft(sitePtr1);
    forest1.setTop(sitePtr4);
    forest1.setBottom(NULL);
    
    //sets river site pointers
    river1.setRight(sitePtr1);
    river1.setLeft(NULL);
    river1.setTop(sitePtr5);
    river1.setBottom(NULL);
    
    //sets cabin site pointers
    cabin1.setRight(NULL);
    cabin1.setLeft(sitePtr5);
    cabin1.setTop(sitePtr6);
    cabin1.setBottom(sitePtr2);
    
    //sets boat site pointers 
    boat1.setRight(sitePtr4);
    boat1.setLeft(NULL);
    boat1.setTop(sitePtr6);
    boat1.setBottom(sitePtr3);
    
    //sets safety pointers 
    safety1.setRight(sitePtr4);
    safety1.setLeft(sitePtr5);
    safety1.setTop(NULL);
    safety1.setBottom(NULL);
    
    //calls function that will control flow of the game 
    gameFlow();
    
    
    
}
/*******************************************************************************
 * this function has no parameters or arguements. This function will control 
 * the flow of the game and has a while loop that will stop if the bool value
 * to indicate player is Saved is true or health decreases below zero 
*******************************************************************************/
void Game::gameFlow()
{
    int savedOption=0;
    bool searchAgain=true;
    int searchOption=0;
    
    //while loop to continue game while user is not saved and has health 
    while(playerSaved!=true && health>=0)
    {  
        cout<<"You are at :"<<(playerPtr->siteName())<<endl;
        //calls function to describe space
        playerPtr->intro();
        
        //allows user to search
        searchAgain=true;
        while(searchAgain==true)
        {
            //asks user for input 
            cout<<"Would you like to search this area?"<<endl;
            cout<<"Select 1 for yes, 2 for no"<<endl;
            cout<<endl;
        
        
            string usearchOption;
            
            //validates input 
            getline(cin,usearchOption);
            searchOption=inputValidation(usearchOption);
            
            while(searchOption<1 ||searchOption>2)
            {
                cout<<"enter 1 for yes 2 for no"<<endl;
                getline(cin,usearchOption);
                searchOption=inputValidation(usearchOption);
            }
            
            //if else if branch controls what will happen
            if(searchOption==1)
            {
                //search function is called 
                int searchNum=playerPtr->search();
                
                //number of item found is stored in backpack 
                itemStorage(searchNum);
            }
            else if(searchOption==2) 
            {
                searchAgain=false;
            }
            
        }
        
        //calls function to determine if rained
        int rainNum=playerPtr->rain();
        
        //calls function to determine severity of rain 
        rainSeverity(rainNum);
        
        //calls function to determine if injured
        int injuryNum=playerPtr->injury();
        
        //calls function to determine severity of injury
        injurySeverity(injuryNum);
        
        //calls function to determine if will be a cold night
        int coldNum=playerPtr->coldNight();
        
        //function to determine how cold night will be 
        coldSeverity(coldNum);
        
        //function is called which determines if the user is 
        //at the place they can be rescued yet
        int localeNum=playerPtr->siteCode();
        
        //if /else if branch to determine what will happen
        //based on which site user is at. 7 is the code for safety1
        //all other areas are coded 2
        if(localeNum==7)
        {
            //calls the saved function in game to determine what will 
            //happen based on random chance, if a flare gun is found
            //and if the health is above zero 
            savedOption=saved();
            
            //if else if branch to determine what happens
            //if zero is selected the user has enough points to continue 
            //but has not gotten rescued 
            if(savedOption==0)
            {
               //prints map 
               printMap();
               
	       //prints out where user is 
	       cout<<"You are at the :"<<(playerPtr->siteName())<<endl;
	       cout<<endl;
    
               //decreases health 
               health--;
               
               //displays remaining health points 
               cout<<"You have  "<<health<<" health pts remaining"<<endl;
               
               //calls function that will allow player to move 
               movePlayer();
            }
            else if(savedOption==1) //user is rescued or has died 
            {
               cout<<endl;
               cout<<"thanks for playing"<<endl;
               cout<<endl;
            }
            
        }
        else if(localeNum==2)   //user is not where they can be rescued
        {
            
            //prints map 
             printMap();
             
             //prints out where user is 
             cout<<"You are at the  :"<<(playerPtr->siteName())<<endl;
             
             //decreases health 
             health--;
             
             //displays remaining health 
             cout<<"You have  "<<health<<" health pts remaining"<<endl;
             cout<<endl;
             
	     if(health>0)
	     {
            
            	 //allows player to move
             	movePlayer();
	     }
             
        }
        
        
    }
    
    //displays if user dies without reaching safety 
    if(health<0 &&savedOption==0)
    {
        cout<<"You were too late, you died."<<endl;
        cout<<endl;
    }
    
}
/*******************************************************************************
 * void function with no parameters or arguements,  Allows user to move 
 * character from one location to next 
*******************************************************************************/
void Game::movePlayer()
{
      
    int direction;
    string udirection;
    
    //asks user for input
    cout<<"enter 1 for left 2 for right, 3 for up, 4 for down"<<endl;
    cout<<endl;
    getline(cin,udirection);
    
    //validates user input 
    direction=inputValidation(udirection);
    while(direction<1 ||direction>4)
    {
        cout<<"enter 1 for left 2 for right, 3 for up, 4 for down"<<endl;
        cout<<endl;
        getline(cin,udirection);
        direction=inputValidation(udirection);
    }
    
    //based on direction user selects checks to see if 
    //direction is available to travel or not
    //if cannot travel in that direction user is prompted 
    //to select new direction and recursively calls movePlayer function 
    if(direction==1)
    {
        tempPtr=playerPtr->getLeft();
        if(tempPtr==NULL)   //if/else branch controls if user can move 
        {
            cout<<"You cannot move in that direction"<<endl;
            cout<<"please enter another direction "<<endl;
            cout<<endl;
            
            //calls move player so user can move in another direction 
            movePlayer();
            
        }
        else
        {
            playerPtr=tempPtr;  //user is allowed to move in that direction
        }
        
    }
    else if(direction==2)
    {
        tempPtr=playerPtr->getRight();
        if(tempPtr==NULL)
        {
            cout<<"You cannot move in that direction"<<endl;
            cout<<"please enter another direction "<<endl;
            cout<<endl;
            movePlayer();
            
        }
        else
        {
            playerPtr=tempPtr;
        }
        
    }
    else if(direction==3)
    {
        tempPtr=playerPtr->getTop();
        if(tempPtr==NULL)
        {
            cout<<"You cannot move in that direction"<<endl;
            cout<<"please enter another direction "<<endl;
            cout<<endl;
            movePlayer();
            
        }
        else
        {
            playerPtr=tempPtr;
        }
        
    }
    else if(direction==4)
    {
        tempPtr=playerPtr->getBottom();
        if(tempPtr==NULL)
        {
            cout<<"You cannot move in that direction"<<endl;
            cout<<"please enter another direction "<<endl;
            cout<<endl;
            movePlayer();
            
        }
        else
        {
            playerPtr=tempPtr;
        }
        
    }
}
/*******************************************************************************
 * void function that has an int parameter and arguement, takes in item 
 * number for item which controls which item goes into back pack
 * item is represented as a string which is pushed back into a vector 
 * if no item was found the user is told so and if/else branch is used to 
 * check of there is room still in the back pack or not 
*******************************************************************************/
void Game::itemStorage(int inventoryNumber)
{
    string uselection;
    int selection;
    
    if(inventoryNumber!=0)
    {

    	//gives player the option to discard or keep the item they have found 
    	cout<<"Would you like to keep the item you have found?"<<endl;
    	cout<<"Select 1 for yes, 2 for no"<<endl;

    	//collects input from user and validates input 
    	getline(cin,uselection);
    	selection=inputValidation(uselection);
         
    	while(selection<1 ||selection>2)
    	{
        	cout<<"select 1 for yes and 2 for no"<<endl;
        	getline(cin,uselection);
        	selection=inputValidation(uselection);
     	}
     }
    
    //checks to see if there is room in back pack
    //if not tells user thsere is no more room in back pack
    //if yes pushes item into back pack 
    if(itemsInBackPack==25 ||itemsInBackPack>25)
    {
        cout<<"no more room in back pack"<<endl;
    }
    else
    {
        if(inventoryNumber==0)
        {
            cout<<"Nothing useful found"<<endl;
            cout<<"items in back pack are "<<itemsInBackPack<<endl;
            cout<<endl;
        }
        else if(inventoryNumber==1)
        {
            
	    if(selection==2)
            {
                cout<<"Yeah, I don't need twine"<<endl;
            }
            else if(selection==1)
            {
            
            	string itemOne="Twine";
            
            	twine=true;
            	backpack.push_back(itemOne);
            	itemsInBackPack++;
	    }
        }
        else if(inventoryNumber==2)
        {
	    if(selection==2)
            {
                cout<<"This packaged food is too heavy to carry"<<endl;
            }
            else if(selection==1)
 	    {

            	string itemTwo="Packaged Food";
            
            	packagedFood=true;
            
            
            	backpack.push_back(itemTwo);
            	health=health+10;

		cout<<"Health increased by 10"<<endl;
            	itemsInBackPack++;
	    }
            
        }
        else if(inventoryNumber==3)
        {
  	    if(selection==2)
            {
 		cout<<"I don't think this pocket knife will be useful"<<endl;
            }
            else if(selection==1)
            {

	        string itemThree="Pocket Knife";
            
                pocketKnife=true;
            
            	backpack.push_back(itemThree);
            	itemsInBackPack++;
            }
            
        }
        else if(inventoryNumber==4)
        {
	    if(selection==2)
            {
		cout<<"This first aid kit is too heavy to carry"<<endl;
	    }
	    else if(selection==1)
	    {

                string itemFour="First Aid Kit";
            
                firstAidKit=true;
            
                backpack.push_back(itemFour);
            
                health=health+10;
	        cout<<"Health increased by 10"<<endl;
            
                itemsInBackPack++;
            }
            
        }
        else if(inventoryNumber==5)
        {
            if(selection==2)
	    {
    		cout<<"This cigarette lighter is not much use"<<endl;
            }
            else if(selection==1)
            {
      
      	        string itemFive="Cigarette Lighter";
            
           	fireStarter=true;
            
            	backpack.push_back(itemFive);
            			          
            	itemsInBackPack++;
             }
        }
        else if(inventoryNumber==6)
        {
	     if(selection==2)
	     {
                 cout<<"This dried jerky is going bad, tossing it"<<endl;
	     }
 	     else if(selection==1)
             {
             
           	string itemSix="Dried Jerky";
           
           	driedJerky=true;
           	health=health+10;
           
                cout<<"Health increased by 10"<<endl;
           	backpack.push_back(itemSix);
           
           	itemsInBackPack++;
	      }
        }
        else if(inventoryNumber==7)
        {
   	      if(selection==2)
	      {
      		 cout<<"I probably could use this flare gun, but what if"<<endl;
		 cout<<"it explodes better be safe and toss it?"<<endl;
              }
	      else if(selection==1)
              {
           	 string itemSeven="Flare Gun";
            
            	 flareGun=true;
            
            	 backpack.push_back(itemSeven);
            
                 itemsInBackPack++;
               }
        }
        else if(inventoryNumber==8)
        {
            if(selection==2)
	    {
            	 cout<<"An empty water bottle is hardly useful. Tossing it"<<endl;
	    }
	    else if(selection==1)
            {
            	 string itemEight="Water Bottle";
            
            	 waterBottle=true;
            
                 backpack.push_back(itemEight);
            	 
    
             	 itemsInBackPack++;
	    }
        }
    }
    
    
    //prints items in back pack 
    cout<<endl;
    cout<<"--------BACKPACK INVENTORY----------"<<endl;
    
    if(itemsInBackPack>0)
    {
        //prints items in backPack
        for(int i=0; i<itemsInBackPack; i++)
        {
            cout<<(i+1)<<". "<<(backpack[i])<<endl;
        }
    }
    
    
    cout<<endl;
    
}
/*******************************************************************************
 * void function, takes int parameter and has int arguement of randomly 
 * generated number to determine if it will rain today.
*******************************************************************************/
void Game::rainSeverity(int wetness)
{
    if(wetness==1)
    {
        cout<<"Today will be dry, no need to worry about rain."<<endl;
        cout<<endl;
    }
    else if(wetness==2)
    {
        //if user has waterBottle rain increases their health 
        //else rain decreases their health 
        
        if(waterBottle==true)
        {
            cout<<"The rain's not too bad and I can get some water at least "<<endl;
            cout<<"I am well hydrated, health increased by 1"<<endl;
            cout<<endl;
            health++;
            
        }
        else
        {
            cout<<"The rain sucks, I hope it stops soon"<<endl;
            cout<<"I'm kinda cold, health decreased by 2"<<endl;
            cout<<endl;
            health=health-2;
        }
    }
    else if(wetness==3)
    {
        cout<<"It's soaking wet, I'm shivering and fucking miserable."<<endl;
        cout<<"I'm going to get hypothermic or sick"<<endl;
        cout<<endl;
        
        //user has water bottle rain only decreases health slightly 
        //if user does not have water bottle health decreases more 
        if(waterBottle==true)
        {
            cout<<"At least I can collect some water with my bottle"<<endl;
            cout<<"I'm still not happy though, health decreases by 1"<<endl;
            cout<<endl;
            health--;
            
        }
        else
        {
            cout<<"I'm in a down pour and I don't even have a "<<endl;
            cout<<"bottle to collect water, not really seeing the "<<endl;
            cout<<"upside of this, health decreases by 3"<<endl;
            cout<<endl;
            health=health-3;
        }
    }
}
/*******************************************************************************
 * void function with int parameter and int arguement, to determine severity 
 * of how cold the day will be 
*******************************************************************************/
void Game::coldSeverity(int hypothermia )
{
    //if else statement determines whether user will gain or lose health 
    //by using the int value passed in 
    if(hypothermia==1)
    {
        cout<<"It's warm now need to worry about being cold"<<endl;
        cout<<endl;
        cout<<"health increases by 2"<<endl;
        cout<<endl;
        health=health+2;
    }
    else if(hypothermia==2)
    {
        cout<<"It's cold, I should probably keep moving to stay warm"<<endl;
        cout<<"I don't think I should stop and rest"<<endl;
        cout<<endl;
        
        //if users has a fire starter health increases, else health decreases 
        if(fireStarter==true)
        {
            cout<<"I have a fire starter, I should be able to make a small fire"<<endl;
            cout<<"Cool that worked, finally I'm warm again"<<endl;
            cout<<endl;
            cout<<"health increases by 3"<<endl;
            health=health+3;
        }
        else if(fireStarter==false)
        {
            cout<<"If I had something to start a fire with I would be so much "<<endl;
            cout<<"Warmer."<<endl;
            cout<<"health decreases by 3"<<endl;
            cout<<endl;
            health=health-3;
        }
        
    }
    else if(hypothermia==3)
    {
        cout<<"It's really cold, I might not make it much longer"<<endl;
        cout<<"To die after surviving all this would really be shitty luck"<<endl;
        cout<<"health decreases by 5";
        cout<<endl;
        
        health=health-5;
    }
}
/*******************************************************************************
 * void function with int parameter and arguement, uses passed in number to 
 * determine the severity of the injury. using if else if branch 
*******************************************************************************/
void Game::injurySeverity(int needFirstAid)
{
    //if else if branch used to determine severity of injury 
    if(needFirstAid==1) //no injury 
    {
        cout<<"I need to be careful so I don't hurt myself"<<endl;
        cout<<"An injury out here could kill me quickly"<<endl;
        cout<<endl;
        health=health+5;
        cout<<"You have avoided injury for one day"<<endl;
        cout<<"Health increases by 5"<<endl;
        cout<<endl;
    }
    else if(needFirstAid==2)    //mild injury 
    {
        //if user has first aid kit injury only slightly decreases health 
        if(firstAidKit==true)
        {
            cout<<"I have a first aid kit I can bandage myself with"<<endl;
            cout<<"health decreases by only 1"<<endl;
            cout<<endl;
            
            health=health-1;
        }
        else
        {
            cout<<"It would be useful if you had a first aid kit"<<endl;
            cout<<"It's going to be hard taking care of myself without one"<<endl;
            cout<<"Don't airplanes carry them? Maybe the boat or cabin"<<endl;
            cout<<"has one?"<<endl;
            cout<<"health decreased by 5"<<endl;
            cout<<endl;
            
            health=health-5;
        }
    }
    else if(needFirstAid==3)    //moderate to severe injury 
    {
         if(firstAidKit==true)
        {
            cout<<"You have a first aid kit you can use to treat yourself with"<<endl;
            cout<<endl;
            cout<<"health only decreaed by 3"<<endl;
            cout<<endl;
            health=health-3;
        }
        else
        {
            cout<<"It would be useful if I had a first aid kit"<<endl;
            cout<<"It's going to be hard taking care of this  without one"<<endl;
            cout<<"Don't airplanes carry them? Maybe the boat or cabin"<<endl;
            cout<<"has one?"<<endl;
            cout<<"health decreased by 10"<<endl;
            cout<<endl;
            
            health=health-10;
        }
    }
    
}
/*******************************************************************************
 * void function is called when user reaches safety to check if they will be 
 * saved or not. This function has no arguements or parameters and uses and 
 * if/else if branch to check if there are is a flare gun. 
*******************************************************************************/
int Game::saved()
{
    int option;
    string uoption;
    
    //used to determine if user is saved or not 
    if(flareGun==true && health>=0)
    {
        cout<<"You have survived a grueling ordeal"<<endl;
        cout<<"a passing logger and his son drive you to a local hospital"<<endl;
        cout<<"Your family soon calls and is overjoyed to find out you are alive"<<endl;
        cout<<"You have survived the plane crash and the wilderness"<<endl;
        cout<<"But what you have seen stays with you forever"<<endl;
        cout<<endl;
        cout<<endl;
        playerSaved=true;
        return 1;
    }
    else if(flareGun==true && health<0)
    {
        cout<<"You are saved by a passing logger and his son"<<endl;
        cout<<"They take you to a local hospital after you have spent"<<endl;
        cout<<"days out in the wilderness"<<endl;
        cout<<"You make one phone call to your family who is overjoyed "<<endl;
        cout<<"find out you are alive"<<endl;
        cout<<"over the next few days your wounds and exposure prove"<<endl;
        cout<<"to be too much, you die in a hospital"<<endl;
        cout<<"the final victim of the plane crash"<<endl;
        cout<<endl;
        cout<<endl;
        playerSaved=true;
        
        return 1;
    }
    else if(flareGun==false&&health<0)
    {
        cout<<"You have no way of signalling for help, you die of exposure"<<endl;
        cout<<"health points are :"<<health<<" "<<endl;
        playerSaved=true;
        
        return 1;
        
    }
    else if(flareGun==false && health>=0)
    {
        cout<<"You fruitlessly walk along the logging road hoping for help"<<endl;
        cout<<"No one is coming you need a way of signalling for help"<<endl;
        
        cout<<"What would you like to do?"<<endl;
        cout<<"Select 1 to go back and search for something "<<endl;
        cout<<"to signal for help with"<<endl;
        cout<<"Select 2 to continue walking the road"<<endl;
        cout<<endl;
           
           getline(cin,uoption);
           option=inputValidation(uoption);
           
           while(option<1 ||option>2)
           {
               cout<<"select 1 for yes and 2 for no"<<endl;
               getline(cin,uoption);
               option=inputValidation(uoption);
           }
           
           if(option==1)
           {
               return 0;
           }
           else if(option==2)
           {
                //generates random numbers from 1 to 5.    
                const int MINVAL=1,DIESIDES=5;
                int die1=(rand() % (DIESIDES-MINVAL +1))+ MINVAL;
                
                //there is a random chance that even if the player does not have a 
                //flare gun they can still be saved 
                
                if(die1==1)
                {
                    cout<<"Against all odds you are saved"<<endl;
                    cout<<"by a passing logger and his son"<<endl;
                    cout<<"They take you to a local hospital after you have spent"<<endl;
                    cout<<"days out in the wilderness"<<endl;
                    cout<<"You make one phone call to your family who is overjoyed "<<endl;
                    cout<<"find out you are alive"<<endl;
                    cout<<"over the next few days your wounds and exposure prove"<<endl;
                    cout<<"to be too much, you die in a hospital"<<endl;
                    cout<<"the final victim of the plane crash"<<endl;
                    cout<<endl;
                    cout<<endl;
                    
                    playerSaved=true;
                    return 1;
                    
                }
                else if(die1==2 || die1==3 || die1==4 || die1==5)   //player dies
                {
                    cout<<"You have no way of signalling for help, you die of exposure"<<endl;
                    
                    playerSaved=true;
                    return 1;
                }
           }
           
    }
}
