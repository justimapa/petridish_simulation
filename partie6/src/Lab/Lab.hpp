#pragma once
#include "Nutriment.hpp"
#include "Petridish.hpp"
#include "NutrimentGenerator.hpp"

/*!
 * @class Lab
 * @brief class representing the lab where the simulations
 * take place
 */
class Lab
{
public:
    /*!
     * @brief Default constructor for class Lab::
     */
    Lab();
    /*!
     * @brief Gets the Nutriment that is colliding with a CircularBody::
     * @return A pointer towards the Nutriments if collision a nullptr if no collision
     */
    Nutriment* getNutrimentColliding(CircularBody const&)const;
    Bacterium* getBacteriumColliding(CircularBody const& body)const;
    /*!
     * @brief Gets the score of a given position
     * @param Vec2d position who's score will be calculated
     * @return Calculatated position
     */
    double getPositionScore(Vec2d const&)const;
    double getBacteriaScore(Vec2d const&)const;
    /*!
     * @brief Getter for the Petridish::'s GradientExponent
     * @return GradientExponent of the Petridish::
     */
    double getGradientExponent() const;
    /*!
     * @brief Decreases GradientExponent
     */
    void decreaseGradientExponent();
    /*!
     * @brief Increases GradientExponent
     */
    void increaseGradientExponent();
    /*!
     * @brief Sets to config default
     */
    void refreshConfig();
    /*!
     * @brief Getter for the dish's temperature
     * @return Temperature of the dish::
     */
    double getTemperature() const;
    /*!
     * @brief Decreases temperature of the dish
     */
    void decreaseTemperature();
    /*!
     * @brief Increases temperature of the dish
     */
    void increaseTemperature();
    /*!
     * @brief Tests if a CircularBody:: is inside the Lab::'s dish
     * @param A CircularBody::
     * @return true if the other CircularBody:: has a smaller radius and the center is
     * within the dish, false if not
     */
    bool contains(const CircularBody&) const;
    /*!
     * @brief Adds a Nutriment:: to the Petridish::
     * @param Nutriment:: to be added
     */
    void addNutriment(Nutriment*);
    /*!
     * @brief Adds a Bacterium:: to the Petridish::
     * @param Bacterium:: to be added
     */
    void addBacterium(Bacterium*);
    void addPhage(Bacteriophage*);
    /*!
     * @brief Adds a Swarm:: to the Petridish::
     * @param Swarm:: to be added
     */
    void addSwarm(Swarm* swarm);
    /*!
      * @brief Gets the Swarm:: of the Petridish with the corresponding id
      * @param Id of the Swarm
      * @return Pointer to the Swarm::
      */
     Swarm* getSwarmWithId(const std::string& id)const;
    /*!
     * @brief Tests if a CircularBody:: is in collision with Petridish::
     * @return True if CircularBody is in collision false if not
     */
    bool doesCollideWithDish(const CircularBody &) const;
    /*!
     * @brief Draws dish on targetWindow
     * @param targetWindow where dish will be drawn
     */
    void drawOn(sf::RenderTarget& targetWindow) const;
    /*!
     * @brief Updates Lab:: after every fraction of time dt
     * @param Fraction of time dt after which the Lab:: is updated
     */
    void update(sf::Time dt);
    std::unordered_map<std::string, double> fetchData(const std::string &);
    /*!
     * @brief Erases all nutriments and bacteria within the dish
     */
    void reset();
    /*!
     * @brief Destructor for the Lab::
     */
    ~Lab();
    /* The following methods are for the multiple petridish extension*/
    void setActivePetridish(int);
    int getCurrentPetridishId()const;
    Petridish* getCurrentPetridish()const;
    void nextPetridish();
    void previousPetridish();
    void addPetridish(int);
private:
    int currentDishId;
    NutrimentGenerator generator;
    std::map<int,Petridish*> dishes;
};
