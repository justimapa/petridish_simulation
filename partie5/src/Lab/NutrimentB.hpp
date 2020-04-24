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
    virtual Quantity eatenBy(Bacterium& bact) const override;
    virtual Quantity eatenBy(SimpleBacterium& bact) const override;
    virtual Quantity eatenBy(TwitchingBacterium& bact) const override;
    virtual Quantity eatenBy(SwarmBacterium& bact) const override;
    /*!
     * @brief Shortcut for access to config parameters
     * @return The config parameters of NurtimentB::
     */
    virtual j::Value const& getConfig() const override;
    /*!
     * @brief Destructor for the class NutrimentA::
     */
    virtual ~NutrimentB() override;
};
