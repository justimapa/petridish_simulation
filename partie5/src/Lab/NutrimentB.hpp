#pragma once
#include "Nutriment.hpp"

/*!
 * @class NutrimentB
 * @brief Class representing nutrients of type B
 *
 * Subclass of Nutriment::
 */
class NutrimentB : public Nutriment
{
public:
    /*!
     * @brief Constructs a NutrimentB:: fully set up
     * @param Quantity of the NutrimentB::
     * @param Position of the NutrimentB::
     * @return A NutrimentB:: with all parameters set
     */
    NutrimentB(Quantity const& quantity,Vec2d const& position);
    /*!
     * @brief Looks at how much NutrimentB:: is eaten by the different types
     * of Bacterium::
     * @param Bacterium:: that is eating
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(Bacterium& bact) override;
    virtual Quantity eatenBy(SimpleBacterium& bact) override;
    virtual Quantity eatenBy(TwitchingBacterium& bact) override;
    virtual Quantity eatenBy(SwarmBacterium& bact) override;
    /*!
     * @brief Shortcut for access to config parameters
     * @return The config parameters of NurtimentB::
     */
    virtual j::Value const& getConfig() const override;
    /*!
     * @brief Getter for the config value of the resistance factor
     * @return The config value of the resistance factor
     */
    j::Value const& getResistanceFactor() const;
    /*!
     * @brief Getter for the config value of the nutritive factor
     * @return The config value of the nutritive factor
     */
    j::Value const& getNutritiveFactor() const;
    /*!
     * @brief Getter for the config value of the poison factor
     * @return The config value of the poison factor
     */
    j::Value const& getPoisonFactor() const;
    /*!
     * @brief Destructor for the class NutrimentA::
     */
    virtual ~NutrimentB() override;
};
