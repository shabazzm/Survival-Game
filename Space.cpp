/*******************************************************************************
 * Author: Maryum Shabazz
 * Date: 6/5/2019
 * Description: Contains getters and setters for space pointers, also function 
 * to return search time and set searchTime 
*******************************************************************************/

#include "Space.hpp"

/*******************************************************************************
 * Void function with space pointers as parameters and arguements. sets pointer
 * to address of space pointer that is passed into function. 
*******************************************************************************/

void Space::setRight(Space*rightSpace)
{
    right=rightSpace;
}
/*******************************************************************************
 *  Void function with space pointers as parameters and arguements. sets pointer
 * to address of space pointer that is passed into function. 
*******************************************************************************/

void Space::setLeft(Space* leftSpace)
{
    left=leftSpace;
}
/*******************************************************************************
 *  Void function with space pointers as parameters and arguements. sets pointer
 * to address of space pointer that is passed into function. 
*******************************************************************************/
void Space::setTop(Space*topSpace)
{
    top=topSpace;
}
/*******************************************************************************
 *  Void function with space pointers as parameters and arguements. sets pointer
 * to address of space pointer that is passed into function. 
*******************************************************************************/
void Space::setBottom(Space*bottomSpace)
{
    bottom=bottomSpace;
}
/*******************************************************************************
 * returns space pointer, has no parameters or arguements, used to get address
 * of space pointer in that direction. 
*******************************************************************************/

Space* Space::getRight()
{
    return right;
}
/*******************************************************************************
 * returns space pointer, has no parameters or arguements, used to get address
 * of space pointer in that direction. 
*******************************************************************************/

Space* Space::getLeft()
{
    return left;
}
/*******************************************************************************
 * returns space pointer, has no parameters or arguements, used to get address
 * of space pointer in that direction. 
*******************************************************************************/

Space* Space::getTop()
{
    return top;
}
/*******************************************************************************
 * returns space pointer, has no parameters or arguements, used to get address
 * of space pointer in that direction. 
*******************************************************************************/

Space* Space::getBottom()
{
    return bottom;
}
/*******************************************************************************
 * Void function has no parameters or arguements, sets time searched as zero. 
*******************************************************************************/
void Space::resetSearchTime()
{
    searchTime=0;
}
/*******************************************************************************
 * returns int, has no parameters or arguements, returns time searched. 
*******************************************************************************/
int Space::returnSearchTime()
{
    return searchTime;
    
}