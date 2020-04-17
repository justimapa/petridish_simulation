#include "Swarm.hpp"
#include "SwarmBacterium.hpp"
#include "Application.hpp"

using namespace std;

Swarm::Swarm(const string& id):
    id(id),
    leader(nullptr)
{

}

void Swarm::addSwarmBacterium(SwarmBacterium* bacterium){
    if(bacterium!=nullptr){
        group.push_back(bacterium);
    }
}
void Swarm::removeSwarmBacterium(SwarmBacterium* bacterium){
    if(bacterium!=nullptr){
        for(SwarmBacterium* bact:group){
            if(bact==bacterium){
                bact=nullptr;
            }
        }
    }
    group.erase(remove(group.begin(),group.end(),nullptr),group.end());
}
const Vec2d& Swarm::getLeaderPosition()const{
    return leader->getPosition();
}
j::Value& Swarm::getInitialColor()const{
    return getAppConfig()["swarms"][id]["color"];
}
void Swarm::update(sf::Time dt){
    group.erase(remove(group.begin(),group.end(),nullptr),group.end());

    leader=nullptr;
    double leaderScore(0);
    double temp(0);
    for (SwarmBacterium* swarmbacterium: group){
        temp=getAppEnv().getPositionScore(swarmbacterium->getPosition());
        if (temp> leaderScore){
                leaderScore = temp;
                cerr<<leaderScore<<endl;
                leader = swarmbacterium;
            }
        }
   }
bool Swarm::isLeader(const SwarmBacterium* bacterium)const {
    return leader==bacterium;
}
bool Swarm::hasLeader()const{
    return leader!=nullptr;
}
string Swarm::getId()const{
    return id;
}
Swarm::~Swarm(){
    for(SwarmBacterium* bacterium:group){
        bacterium=nullptr;
    }
    group.erase(remove(group.begin(),group.end(),nullptr),group.end());
}
