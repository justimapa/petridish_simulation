#pragma once
#include <SFML/Graphics.hpp>
#include "Interface/Updatable.hpp"

/*!
 * @class NutrimentGenerator
 * @brief class representing an automatic generator for
 * for nutrient sources within the Petridish::
 *
 * Subclass of Updatable::
 */
class NutrimentGenerator : public Updatable
{
public:
    /*!
     * @brief Constructs a NutrimentGenerator::
     * @param PetridishId associated to this NutrimentGenerator
     * @return NutrimentGenerator:: constructed by default
     * with its stopwatch set to 0
     */
    NutrimentGenerator(int const& id);
    /*!
     * @brief Updates the creation and evolution of nutrients within
     * the Petridish::
     * @param Time dt after which update will occur
     */
    virtual void update(sf::Time dt) override;
    /*!
     * @brief Resets generator's stopwatch to 0
     */
    void resetStopwatch();
    /*!
     * @brief Destructor for the class NutrimentGenerator::
     */
    virtual ~NutrimentGenerator() override;
private:
    sf::Time stopwatch;
    //Id of the Petridish the Generator belongs to
    int id;
};

