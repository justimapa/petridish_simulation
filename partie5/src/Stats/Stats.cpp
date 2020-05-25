#include <Stats/Stats.hpp>
#include <SFML/Graphics.hpp>
#include "Application.hpp"
#include <iostream>
using namespace std;

Stats::Stats():
    currentid(0)
{
}

void Stats::drawOn(sf::RenderTarget & target) const
{
    auto title_paire=titles.find(currentid);
    auto graph_paire=graphs.find(title_paire->second);
    (graph_paire->second)->drawOn(target);
}

void Stats::update(sf::Time dt)
{
    stopwatch+=dt;
    if(stopwatch>=sf::seconds(getShortConfig().stats_refresh_rate)) {
        auto title_paire=titles.find(currentid);
        auto graph_paire=graphs.find(title_paire->second);
        try {
            (graph_paire->second)->updateData(stopwatch,getAppEnv().fetchData(title_paire->second));
        } catch(std::out_of_range) {
            cerr<<"out of range"<<endl;
        }
        resetStopwatch();
    }
}

void Stats::setActive(int id)
{
    currentid=id;
}


string Stats::getCurrentTitle() const
{
    try {
        auto paire=titles.find(currentid);
        return  paire->second;
    } catch(std::out_of_range) {
        cerr<<"Out of range"<<endl;
    } catch(std::invalid_argument) {
        cerr<<"Invalid_argument"<<endl;
    }
}
void Stats::next()
{
    currentid=(++currentid)%titles.size();
}
void Stats::previous()
{
    currentid=(--currentid)%titles.size();
}

void Stats::reset()
{
    for(auto& graph:graphs) {
        (graph.second)->reset();
    }
}

void Stats::addGraph(int id, string title,  std::vector<string> const& names, double min, double max, Vec2d const& size)
{
    setActive(id);
    titles[id]=title;
    unique_ptr<Graph> pointer;
    pointer.reset(new Graph(names,size,min,max));
    graphs[title]=std::move(pointer);
}
void Stats::resetStopwatch()
{
    stopwatch = sf::Time::Zero;
}
Stats::~Stats()
{
    reset();
}

