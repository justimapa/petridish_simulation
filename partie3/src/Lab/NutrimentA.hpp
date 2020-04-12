#pragma once
#include "Nutriment.hpp"

/*!
 * @class NutrimentA
 * @brief Class representing nutrients of type A
 *
 * Subclass of Nutriment::
 */
class NutrimentA:public Nutriment
{
public:
    /*!
     * @brief Constructs a NutrimentA:: fully set up
     * @param Quantity of the NutrimentA::
     * @param Position of the NutrimentA::
     * @return A NutrimentA:: with all parameters set
     */
    NutrimentA(Quantity const& quantity,Vec2d const& position);
    /*!
     * @brief Shortcut for access to config parameters
     * @return The config parameters of NurtimentA::
     */
    virtual j::Value const& getConfig() const override;
    /*!
     * @brief Destructor for the class NutrimentA::
     */
    virtual ~NutrimentA() override;
};


