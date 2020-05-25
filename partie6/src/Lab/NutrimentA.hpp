#pragma once
#include "Nutriment.hpp"

/*!
 * @class NutrimentA
 * @brief class representing nutrients of type A
 *
 * Subclass of Nutriment::
 */

class NutrimentA: public Nutriment
{
public:
    /*!
     * @brief Constructs a NutrimentA:: fully set up
     * @param Quantity of the NutrimentA::
     * @param Position of the NutrimentA::
     * @param id of the Petridish the NutrimentA:: belongs to, set to 0 to be compatible with the other tests
     * @return A NutrimentA:: with all parameters set
     */
    NutrimentA(Quantity const& quantity, Vec2d const& position, const int &id=0);
    /*!
     * @brief Looks at how much NutrimentA:: is eaten by the different types
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
     * @return The config parameters of NutrimentA::
     */
    virtual j::Value const& getConfig() const override;
    /*!
     * @brief Destructor for the class NutrimentA::
     */
    virtual ~NutrimentA() override;
};


