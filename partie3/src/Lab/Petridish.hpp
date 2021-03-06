#pragma once
#include "Bacterium.hpp"
#include "Nutriment.hpp"
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
    Petridish(Vec2d position,double radius, double Temperature,double gradientExponent);
    /*!
     * Deletes = operator inherited from CircularBody:: to avoid unnecessary memory usage
     */
    Petridish& operator=(Petridish const &) = delete;
    /*!
     * @brief Gets the Nutriment:: colliding with a CircularBody::
     * @param The CircularBody::
     * @return A pointer of a Nutriment:: that is colldiing with the CircularBody::
     */
    Nutriment* getNutrimentColliding(CircularBody const& body)const;
    /*!
     * @brief Gets the Score of a position on the Petridish::
     * @param A position
     * @return The Score of the position
     */
    double getPositionScore(Vec2d const& position)const;
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
    void removeBacterium(size_t);
    /*!
     * @brief Adds a Nutriment:: to the Petridish::
     * @param Nutriment:: to be added
     * @return True if the Nutriment:: could be added, false if not
     */
    bool addNutriment(Nutriment* nutriment);
    /*!
     * @brief Updates Petridish:: after every fraction of time dt
     * @param Fraction of time dt after which the Petridish:: is updated
     */
    void update(sf::Time dt);
    /*!
     * @brief Computes score which controls the perception of Gradient
     * @param Position
     * @return Value of the score
     */
    double score(Vec2d position);
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
    std::vector<Nutriment*> nutriments;
    double temperature;
    double gradientExponent;
};

