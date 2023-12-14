#include "DataManager.h"

std::shared_ptr<Photo> DataManager::createPhoto(std::string name, std::string path, double latitude, double longitude){
    if(data.find(name) != data.end()){
        std::cerr << "The name already exists\n";
        return nullptr;
    }
    std::shared_ptr<Photo> photo = std::shared_ptr<Photo>(new Photo(name, path, latitude, longitude));
    data[name] = photo;
    return photo;
}

std::shared_ptr<Video> DataManager::createVideo(std::string name, std::string path, unsigned int length){
    if(data.find(name) != data.end()){
        std::cerr << "The name already exists\n";
        return nullptr;
    }
    std::shared_ptr<Video> video = std::shared_ptr<Video>(new Video(name, path, length));
    data[name] = video;
    return video;
}

std::shared_ptr<Film> DataManager::createFilm(std::string name, std::string path, unsigned int length, unsigned int* chaptersLength, unsigned int numChapters){
    if(data.find(name) != data.end()){
        std::cerr << "The name already exists\n";
        return nullptr;
    }
    std::shared_ptr<Film> film = std::shared_ptr<Film>(new Film(name, path, length, chaptersLength, numChapters));
    data[name] = film;
    return film;
}

std::shared_ptr<Group> DataManager::createGroup(std::string name){
    if(groups.find(name) != groups.end()){
        std::cerr << "The group name already exists\n";
        return nullptr;
    }
    std::shared_ptr<Group> group = std::shared_ptr<Group>(new Group(name));
    groups[name] = group;
    return group;
}

void DataManager::showMediaInfo(std::string name, std::ostream& o) const{
    if(data.find(name) == data.end()){
        std::cerr << "The name doesn't exist\n";
        return;
    }
    data.at(name)->showNames(o);
}

void DataManager::showGroupInfo(std::string name, std::ostream &o) const{
    if(groups.find(name) == groups.end()){
        std::cerr << "The group name doesn't exist\n";
        return;
    }
    groups.at(name)->showGroupInfo(o);
}

void DataManager::playMedia(std::string name) const{
    if(data.find(name) == data.end()){
        std::cerr << "The name doesn't exist\n";
        return;
    }
    data.at(name)->streamObject();
}

void DataManager::destroyMedia(std::string name){
    if(data.find(name) == data.end()){
        std::cerr << "The name doesn't exist no nee to destroy it\n";
        return;
    }
    std::shared_ptr<Multimedia> mediaToDelete = data.at(name);
    //We first need to take the media out of all the groups he is in. We iterate through each group and delete the media if it is in it
    for(auto i = groups.begin(); i != groups.end(); i++){
        //We check if the media is in the Group that is a std::list<std::shared_ptr<MultiMedia>>
        for(auto j = i->second->begin(); j != i->second->end(); j++){
            if((*j)->getName() == name){
                i->second->erase(j);
                break;
            }
        }
    }
    data.erase(name);
    mediaToDelete.reset(); //Destroys the object
}

void DataManager::destroyGroup(std::string name){
    if(groups.find(name) == groups.end()){
        std::cerr << "The group name doesn't exist no need to destroy it\n";
        return;
    }
    std::shared_ptr<Group> groupToDelete = groups.at(name);
    groups.erase(name);
    groupToDelete.reset(); //Destroys the object
}
