#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <sstream>

class DataManager
{
private:
    std::map<std::string, std::shared_ptr<Multimedia>> data;
    std::map<std::string, std::shared_ptr<Group>> groups;

public:
    DataManager() = default;
    ~DataManager() = default;

    std::shared_ptr<Photo> createPhoto(std::string name, std::string path, double latitude, double longitude);
    std::shared_ptr<Video> createVideo(std::string name, std::string path, unsigned int length);
    std::shared_ptr<Film> createFilm(std::string name, std::string path, unsigned int length, unsigned int* chaptersLength, unsigned int numChapters);
    std::shared_ptr<Group> createGroup(std::string name);

    /*!
     * \brief showMediaInfo shows the info of the media object with the correct name
     * \param name the name of the media
     * \param o the ostream object
     */
    void showMediaInfo(std::string name, std::ostream& o) const;

    /*!
     * \brief playMedia plays the media object with the correct name
     * \param name the name of the media
     * \returns 1 if successful, -1 if not
     */
    int playMedia(std::string name) const;

    /*!
     * \brief showGroupInfo shows the info of the group with the correct name
     * \param name the name of the group
     * \param o the ostream object
     */
    void showGroupInfo(std::string name, std::ostream& o) const;

    /*!
     * \brief destroyMedia will destroy a Media object with the correct name
     * \param name the name of the media
     */
    int destroyMedia(std::string name);

    /*!
     * \brief destroyGroup will destroy a Group object with the correct name
     * \param name the name of the group
     */
    int destroyGroup(std::string name);

    /*!
     * \brief Returns the attributes of searched media
     * \param name the name of the group
     * \returns a string with the information inside it
     */
    std::string showMediaAttributes(std::string name) const; 

    /*!
     * \brief Returns the names of media with this substring in their name
     * \param substring the substring
     * \returns a string with the information inside it
     */
    std::string searchMediaWithSubstring(std::string substring) const;
};

#endif // DATAMANAGER_H