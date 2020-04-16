#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

/*!
 * @class SimpleBacterium
 * @brief class that represents the behavior and movement
 * of simple bacteria within a Petridish
 *
 * Subclass of Bacterium
 */
class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    /*!
     * @brief Constructs a SimpleBacterium:: fully set up
     * @param Position
     * @return A SimpleBacterium:: with all parameters set
     */
    SimpleBacterium(Vec2d const&);
    SimpleBacterium(SimpleBacterium &);
    /*!
     * @brief Draws a SimpleBacterium::
     * @param TargetWindow where the SimpleBacterium:: will be drawn
     */
    void drawOn(sf::RenderTarget& targetWindow) const override;
    void update(sf::Time) override;
    void updateFlagella(sf::Time);
    void updateProbability();
    void tumble();
    /*!
     * @brief Draws a flagella connected to the SimpleBacterium::
     * @param TargetWindow where the flagella will be drawn
     */
    void drawFlagella(sf::RenderTarget& target)const;
    /*!
     * @brief Moves the SimpleBacterium:: at every fraction of time dt
     * @param Time dt after which another movement occurs
     */
    void move(sf::Time dt) override;
    /*!
     * @brief Returns a zero force
     * @param Position
     * @param Direction
     * @return Returns the zero 2d vector
     */
    Vec2d f(Vec2d position, Vec2d direction) const override;
    bool isTumbling();
    Bacterium* clone() override;
    j::Value& getConfig()const override;
    Vec2d getSpeedVector() ;
    void drawFlagella()const;
    virtual ~SimpleBacterium() override;
private:
    double t;
    double rotation;
    double oldScore;
    double tumblingProbability;
    sf::Time tLastTumble;
    std::string algo;
};


