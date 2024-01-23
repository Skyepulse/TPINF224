#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <string>
#include <iostream>
#include <memory>
#include "Multimedia.h"
class Group: public std::list<std::shared_ptr<Multimedia>>
{
private:
    std::string groupname;


protected:
    Group() = default;
    Group(std::string name):groupname{name}{}
    friend class DataManager;


public:
    ~Group(){
        std::cout << "Group Destroyed, not its content!\n";
    }

    std::string getGroupName() const {return groupname;}
    void setGroupName(std::string name){groupname = name;}

    /*!
     * \brief showGroupInfo shows the name of the group and the info of all the objects it contains
     */
    void showGroupInfo(std::ostream& o) const {
        o << "Group name: " << groupname << std::endl;
        if(this->empty())
            o << "Group is empty\n";
        else
            for(auto i = this->begin(); i != this->end(); i++)
                (*i)->showNames(o);
    }
};

#endif // GROUP_H