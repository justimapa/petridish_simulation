#pragma once
#include <string>
#include <vector>
#include "Graph.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"

class Stats:public Drawable,public Updatable
{
public:
    Stats();
    void drawOn(sf::RenderTarget&) const;
    void update(sf::Time dt);
    std::string getCurrentTitle();
    void setActive(int);
    void next();
    void previous();
    void reset();
    void addGraph(int id,std::string title,std::vector<std::string> const& names,double min,double max,Vec2d const& size);
    /*!
     * @brief Resets generator's stopwatch to 0
     */
    void resetStopwatch();
    ~Stats();
private:
    int currentid;
    sf::Time stopwatch;
    std::map<int,std::string> titles;
    std::map<std::string,std::unique_ptr<Graph>> graphs;
};
