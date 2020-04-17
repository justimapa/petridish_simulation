#pragma once
#include "Bacterium.hpp"
#include "Grip.hpp"


/*!
 * @class TwitchingBacterium
 * @brief class that represents bacteria
 * with tentacles within the Petridish::
 *
 * Subclass of Bacterium
 */
class TwitchingBacterium : public Bacterium
{
public:
    /*!
     * @brief Constructs a TwitchingBacterium:: fully set up
     * @param Position
     * @return A TwitchingBacterium:: with all parameters set
     */
    TwitchingBacterium(Vec2d const& position_);
    /*!
     * @brief Draws the TwitchingBacterium::
     * @param targetWindow where the TwitchingBacterium:: will be drawn
     */
    virtual void drawOn(sf::RenderTarget& targetWindow) const override;
    /*!
     * @brief Moves the Bacterium:: within the Petridish::
     * @param Time dt after which movement will take place
     */
    virtual void move(sf::Time dt) override;
    /*!
     * @brief Clones the TwitchingBacterium::
     * @return Copy of the initial TwitchingBacterium::
     */
    virtual Bacterium* clone() override;
    /*!
     * @brief Getter for the "twitching bacterium" config
     * @return The JSON configuration of the TwitchingBacterium::
     */
    virtual j::Value& getConfig() const override;
    /*!
     * @brief Getter for the movement "consumption factor" config
     * @return The JSON configuration of the movement "consumption factor"
     */
    j::Value& getMovementEnergy() const;
    /*!
     * @brief Getter for the tenatcle "consumption factor" config
     * @return The JSON configuration of the tentacle "consumption factor"
     */
    j::Value& getTentacleEnergy() const;
    /*!
     * @brief Moves the grip of the TwitchingBacterium::
     * @param delta
     */
    void moveGrip(const Vec2d& delta);
    /*!
     * @brief Destructor of the TwitchingBacterium::
     */
    virtual ~TwitchingBacterium() override;
private:
    Grip grip;
};

