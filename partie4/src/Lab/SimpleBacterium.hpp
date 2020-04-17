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
    /*!
     * @brief Constructs a SimpleBacterium:: from another
     * @param The Simplebacterium:: to be copied
     * @return A copy of the original SimpleBacterium::
     */
    SimpleBacterium(SimpleBacterium &);
    /*!
     * @brief Draws a SimpleBacterium::
     * @param TargetWindow where the SimpleBacterium:: will be drawn
     */
    void drawOn(sf::RenderTarget& targetWindow) const override;
    /*!
     * @brief Updates a SimpleBacterium::
     * @param Time delay between updates
     */
    void update(sf::Time) override;
    /*!
     * @brief Updates the Flagella of the SimpleBacterium::
     * @param Time delay between updates
     */
    void updateFlagella(sf::Time);
    /*!
     * @brief Updates the probability of the Flagella to Tumble
     * @param Time Delay between the tumbles
     */
    void updateProbability();
    /*!
     * @brief Changes the direction of tumble depending on the algorithm of SimpleBacterium:: and the probability of the tumble
     */
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
    /*!
     * @brief Returns the tumbling state of the SimpleBacterium::
     * @return Returns True if tumbling false if not
     */
    bool isTumbling();
    /*!
     * @brief Clones the SimpleBacterium::
     * @return A pointer to a mutated copy of the SimpleBacterium::
     */
    Bacterium* clone() override;
    /*!
     * @brief Getter for the "simple bacterium" config
     * @return The JSON configuration of the SimpleBacterium::
     */
    j::Value& getConfig()const override;
    /*!
     * @brief Getter for the speed vector of the SimpleBacterium::
     * @return The speed vector of the SimpleBacterium::
     */
    Vec2d getSpeedVector() ;
    /*!
     * @brief Draws the Flagella of the SimpleBacterium::
     */
    void drawFlagella()const;
    /*!
     * @brief Destructor of the SimpleBacterium::
     */
    virtual ~SimpleBacterium() override;
private:
    double t;
    double rotation;
    double oldScore;
    double tumblingProbability;
    sf::Time tLastTumble;
    std::string algo;
};


