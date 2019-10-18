/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 4/18/19
 * Description: This is the cpp file for inputValidation
 ******************************************************************************/

#include <iostream>
#include "inputValidation.hpp"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;



/*******************************************************************************
 * This function will take a string, make sure it is a integer and return it
 * as an integer. The parameter is a string, the arguement is a string
*******************************************************************************/
int inputValidation(string entry)
{
    // catches if user press enter
    while (entry.size()==0)
    {
        cout<<"Please enter an integer"<<endl;
                getline(cin,entry);
                
            
    }
    
        for ( int i=0;i<entry.size();i++)  //see quora link below for reference
        {   
            //if statement checks if each character is a digit or not
            //see quora link below for citation
            if (entry[i] <= '9' && entry[i] >= '0')
            { int temp=0;
                   }
            else //if character is not a digit user is prompted to enter integer
            {   
                cout<<"Please enter a non negative integer"<<endl;
                getline(cin,entry);
                i=-1;
                
            }
            while (entry.size()==0)
            {
                cout<<"Please enter an integer"<<endl;
                        getline(cin,entry);
                        
                    
            }
        }
       
        int val=stoi(entry);
        return val;
        
// used below for reference  for input validation function.
//https://www.quora.com/How-can-I-extract-each-character-from-a-string-in-C++
}

/*******************************************************************************
 * Input validation function for strings, brings in string input checks to 
 * ensure string is only letters or spaces and then sends string back, if string
 * contains characters other then letters or spaces user is promted to enter new
 * string and that string is checked.
*******************************************************************************/
string stringInputValidation(string sEntry)
{
    
    // catches if user presses enter
    while (sEntry.size()==0)
    {
        cout<<"Please enter an entry consisting only of letters or spaces"<<endl;
                getline(cin,sEntry);
                
            
    }
    
        for ( int i=0;i<sEntry.size();i++)  //see link below for reference
        {   
            //if statement checks if each character is a letter or space or not
            //see learn cplusplus link below for citation
            if (isalpha(sEntry[i]) || isspace(sEntry[i]))
            { 
                int temp=0;
            }
            else //if character is not a space or letteruser enters new data
            {   
                cout<<"Please enter a entry consisting of letters"<<endl;
                cout<<"and/or spaces"<<endl;
                getline(cin,sEntry);
                i=-1;
                
            }
            while (sEntry.size()==0)
            {
                cout<<"Please enter a entry consisting of letters"<<endl;
                cout<<"and/or spaces"<<endl;
                getline(cin,sEntry);
                        
                    
            }
        }
       
        
        return sEntry;
        
// used below for reference 
//http://www.cplusplus.com/reference/cctype/isspace/
//http://www.cplusplus.com/reference/cctype/isalpha/
}
/*******************************************************************************
 * This function will take a string, check to make sure it has a period but only
 * one and a number and return the double number. 
*******************************************************************************/
double doubleInputValidation(string dEntry)
{
   int periodCount=0;
    // catches if user press enter
    while (dEntry.size()==0)
    {
        cout<<"Please enter a non negative double number"<<endl;
                getline(cin,dEntry);
                
            
    }

        for ( int i=0;i<dEntry.size();i++)  //see quora link below for reference
        {   
            //if statement checks if each character is a digit or period
            //see quora link below for citation
            if ((dEntry[i] <= '9' && dEntry[i] >= '0') ||dEntry[i]=='.')
            { 
                int temp=0;
                if(dEntry[i]=='.')
                {
                    periodCount++;
                }
                if(periodCount>1)
                {
                    i=-1;
                    periodCount=0;
                    cout<<"Please enter a non negative double number"<<endl;
                    getline(cin,dEntry);
                    
                }
                if (dEntry.size()==1) //checks to ensure user can't enter just .
                {
                  cout<<"Please enter a non negative double"<<endl; 
                  getline(cin,dEntry);
                  i=-1;
                  periodCount=0;
                }
             }
            else //if entry is not a digit or period user renters
            {   
                cout<<"Please enter a non negative double"<<endl;
                getline(cin,dEntry);
                i=-1;
                periodCount=0;
            }
            while (dEntry.size()==0) //checks for enter
            {
                cout<<"Please enter a non negative double"<<endl;
                getline(cin,dEntry);
            }
        }
        
       
        double val=std::stod(dEntry);
        return val;
}