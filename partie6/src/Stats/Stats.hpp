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
    /*!
     * @brief Draws the Stats::
     * @param targetWindow where the Stats:: will be drawn
     */
    virtual void drawOn(sf::RenderTarget&) const override;
    /*!
     * @brief Updates stats at every fraction
     * of time dt
     * @param Fraction of time dt
     */
    virtual void update(sf::Time dt) override;
    /*!
     * @brief Getter for the Title of the current Graph::
     * @return A string of the title
     */
    std::string getCurrentTitle() const;
    /*!
     * @brief Setter for the active Graph::
     */
    void setActive(int);
    /*!
     * @brief Increments the active graph Id
     */
    void next();
    /*!
     * @brief Decrements the active graph Id
     */
    void previous();
    /*!
     * @brief Reset all the graphs
     */
    void reset();
    /*!
     * @brief Adds a Graph:: to the map of Graphs
     * @param Integer Id of the Graphs
     * @param String Title of the Graphs
     * @param names series' titles
     * @param min    y-axis: min value expected
     * @param max    y-axis: max value expected
     * @param size   size on screen
     */
    void addGraph(int id,std::string title,std::vector<std::string> const& names,double min,double max,Vec2d const& size);
    /*!
     * @brief Resets generator's stopwatch to 0
     */
    void resetStopwatch();
    /*!
     * @brief Destructor for Stats
     */
    virtual ~Stats() override;
private:
    int currentid;
    sf::Time stopwatch;
    std::map<int,std::string> titles;
    std::map<std::string,std::unique_ptr<Graph>> graphs;
};

