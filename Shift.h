//
// Created by Brandon on 7/1/2015.
//

#ifndef EM_SCHEDULER_SHIFT_H
#define EM_SCHEDULER_SHIFT_H

#include "Student.h"
#include "Date.h"
#include <string>

class Shift
{
public:

    Shift(Date* date,std::string shiftName);
    ~Shift();

    //Sets the name of the shift
    //In:: input: the visible name of this shift
    void setName(std::string input);

    //Assigns a student this shift
    //In:: taker:pointer to student who takes the shift
    void assign(Student* taker);

    //Unassigns this shift
    void unassign(void);

    //Blocks off this shift
    //In:: Reason: string to show why it's blocked off
    void block(std::string reason = "");

    //Unblocks this shift
    void unblock(void);

    //Everyone love's a toString!
    std::string toString(void);
protected:
private:
    int id;                     //Numerical id for numberkeeping
    std::string name;           //The shift's name
    std::string blockReason;    //Visible reason for the block
    bool blocked;               //Determines if the shift is blocked
    Student* assocStudent;      //Pointer to the student who has this shift. Equals nullptr if not taken
    Date* assocDate;            //Pointer to the date that it is attached to
};


#endif //EM_SCHEDULER_SHIFT_H
