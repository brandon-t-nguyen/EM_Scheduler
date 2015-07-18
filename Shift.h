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

    Shift();
    ~Shift();
    void init(int shiftID,std::string shiftName, Date* datePtr,unsigned int start, unsigned int end);
    //Sets the name of the shift
    //In:: input: the visible name of this shift
    void setName(std::string input);

    //Assigns a student this shift
    //In:: taker:pointer to student who takes the shift
    bool assign(Student* taker);

    //Unassigns this shift
    void unassign();

    //Blocks off this shift
    //In:: Reason: string to show why it's blocked off
    void block(std::string reason = "");

    //Unblocks this shift
    void unblock(void);

    //getter for manual
    bool isManual(void);
    bool isBlocked(void);

    //Manual setter
    void setManual(bool input);

    Student* student(void);
    Date* date(void);

    int getID(void);

    std::string startTimeString(bool hour24 = false);
    std::string endTimeString(bool hour24 = false);
    std::string shiftTimeString(bool hour24 = false);

    //Set the shift's time. Will return true if it works. Will return false if it fails
    bool setTime(unsigned int start, unsigned int end);
    unsigned int getStart(void);
    unsigned int getEnd(void);


    //Everyone love's a toString!
    std::string toString(void);

    //Static methods

    //This method checks if two shifts have overlapping times
    static bool shiftsOverlap(Shift& shift1, Shift& shift2);
protected:
private:
    int id;                     //Numerical id for numberkeeping
    std::string name;           //The shift's name
    std::string blockReason;    //Visible reason for the block
    bool blocked;               //Determines if the shift is blocked
    bool manual;                //Determines if it's a manual change.
    Student* assocStudent;      //Pointer to the student who has this shift. Equals nullptr if not taken
    Date* assocDate;            //Pointer to the date that it is attached to

    unsigned int startTime;     //The beginning time 0 is 12AM
    unsigned int endTime;       //The end time. Can extend to the next day if at least 24
};


#endif //EM_SCHEDULER_SHIFT_H
