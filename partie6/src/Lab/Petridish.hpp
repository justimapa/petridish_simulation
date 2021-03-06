#pragma once
#include "Bacterium.hpp"
#include "Nutriment.hpp"
#include "Bacteriophage.hpp"
#include "Swarm.hpp"
#include <vector>
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"

/*!
 * @class Petridish::
 * @brief class representing the Petri dish where the
 * simulation takes place
 *
 * Subclass of CircularBody::, Drawable:: and Updatable::
 */
class Petridish : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief Constructor for the Petridish::
     * @param Position of the Petridish::
     * @param Radius of the Petridish::
     * @param Temperature of the Petridish::
     */
    Petridish(Vec2d const& position,double const& radius, double const& Temperature,double const& gradientExponent);
    /*!
     * Deletes = operator inherited from CircularBody:: to avoid unnecessary memory usage
     */
    Petridish& operator=(Petridish const &) = delete;
    /*!
     * @brief Gets the Nutriment:: colliding with a CircularBody::
     * @param The CircularBody::
     * @return A pointer towards the Bacterium:: if collision a nullptr if no collision
     */
    Nutriment* getNutrimentColliding(CircularBody const& body)const;
    /*!
     * @brief Gets the Bacterium:: colliding with a CircularBody::
     * @param The CircularBody::
     * @return A pointer towards the Bacterium:: if collision a nullptr if no collision
     */
    Bacterium* getBacteriumColliding(CircularBody const& body)const;
    /*!
     * @brief Gets the score of a given position with respect to
     * a Nutriment:: source
     * @param Vec2d position who's score will be calculated
     * @return Calculatated score
     */
    double getPositionScore(Vec2d const& position)const;
    /*!
     * @brief Gets the score of a given position with respect to
     * a Bacterium::
     * @param Vec2d position who's score will be calculated
     * @return Calculatated score
     */
    double getBacteriaScore(Vec2d const& position)const;
    /*!
     * @brief Getter for the power
     * @return Power of the the Petridish::
     */
    double getPower()const;
    /*!
     * @brief Getter for the GradientExponent
     * @return GradientExponent of the Petridish::
     */
    double getGradientExponent() const;
    /*!
     * @brief Decreases GradientExponent of the Petridish::
     */
    void decreaseGradientExponent();
    /*!
     * @brief Increases GradientExponent of the Petridish::
     */
    void increaseGradientExponent();
    /*!
     * @brief Resets GradientExponent of the Petridish:: to config default
     */
    void resetGradientExponent();
    /*!
     * @brief Getter for the temperature
     * @return Temperature of the Petridish::
     */
    double getTemperature() const;
    /*!
     * @brief Decreases temperature of the Petridish::
     */
    void decreaseTemperature();
    /*!
     * @brief Increases temperature of the Petridish::
     */
    void increaseTemperature();
    /*!
     * @brief Resets temperature of the Petridish:: to config default
     */
    void resetTemperature();
    /*!
     * @brief Adds a Bacterium:: to the Petridish::
     * @param Bacterium:: to be added
     * @return True if the Bacterium:: could be added, false if not
     */
    bool addBacterium(Bacterium* bacterium);
    /*!
     * @brief Adds a Bacteriophage:: to the Petridish::
     * @param Bacteriophage:: to be added
     * @return True if the Bacteriophage:: could be added, false if not
     */
    bool addPhage(Bacteriophage* phage);
    /*!
     * @brief Adds a Nutriment:: to the Petridish::
     * @param Nutriment:: to be added
     * @return True if the Nutriment:: could be added, false if not
     */
    bool addNutriment(Nutriment* nutriment);
    /*!
     * @brief Adds a Swarm:: to the Petridish::
     * @param Swarm:: to be added:
     * @return True if the Swarm:: could be added, false if not
     */
    bool addSwarm(Swarm* swarm);
    /*!
     * @brief Gets the Swarm__ corresponding to an id
     * @param id of the Swarm
     * @return Pointer to the Swarm::
     */
    Swarm* getSwarmWithId(const std::string& id) const;
    /*!
     * @brief Updates Petridish:: after every fraction of time dt
     * @param Fraction of time dt after which the Petridish:: is updated
     */
    void update(sf::Time dt);
    /*!
     * @brief Draws Petridish:: on targetWindow
     * @param targetWindow where the Petridish:: will be drawn
     */
    void drawOn(sf::RenderTarget& targetWindow) const;
    /*!
     * @brief Erases all nutriments and bacteria within the Petridish::
     */
    void reset();
    /*!
     * @brief Destructor for the Petridish::
     */
    ~Petridish();


private:
    std::vector<Bacterium*> bacteria;
    std::vector<Bacterium*> buffer;
    std::vector<Nutriment*> nutriments;
    std::vector<Swarm*> swarms;
    std::vector<Bacteriophage*> phages;
    std::vector<Bacteriophage*> phagebuffer;
    double temperature;
    double gradientExponent;
};

