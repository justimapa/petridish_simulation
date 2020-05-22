#pragma once
#include <array>
#include "MutableNumber.hpp"
#include "Utility/Utility.hpp"

/*!
 * @class MutableColor
 * @brief Class representing a color which can mutate
 */
class MutableColor
{
public:
    /*!
     * @brief Constructor for the class
     * @param Values taken from config file
     * @return Constructed MutableColor::
     */
    MutableColor(j::Value const& config);
    /*!
     * @brief Mutates each component of RGBA
     */
    void mutate();
    /*!
     * @brief Getter which returns a color
     * @return Color recognized by SFML
     */
    sf::Color get() const;
    ~MutableColor();
private:
    std::array<MutableNumber, 4> RGBA;
};
