#pragma once
#include "Utility/Utility.hpp"

/*!
 * @class MutableNumber
 * @brief class representing a number which can change its value
 * i.e. mutate
 */
class MutableNumber
{
public:
    /*!
     * @brief Constructor for the class
     * @param value of the number
     * @param mutation probability
     * @param standard deviation
     * @param boolean checking for lower bound
     * @param lower bound value
     * @param boolean checking for upper bound
     * @param upper bound value
     * @return A constructed MutableNumber::
     */
    MutableNumber(double value_, double prob_mutation_, double StdDev_, bool hasLowerBound_=false, double LowerBound_=0.0, bool hasUpperBound_=false, double UpperBound_=0.0);
    /*!
     * @brief Constructor
     * @param Values taken from config file
     * @return A constructed MutableNumber::
     */
    MutableNumber(j::Value const& config);
    MutableNumber();
    /*!
     * @brief Getter which returns the MutableNumber::'s value
     * @return MutableNumber::'s value
     */
    double get() const;
    /*!
     * @brief Setter for the MutableNumber::'s value (under certain conditions)
     * @param Value that will be set
     */
    void set(double value_);
    /*!
     * @brief Modifies the value of the MutableNumber::
     */
    void mutate();
    /*!
     * @brief Creates a MutableNumber:: with values between 0 and 1
     * @param Same params as a usual MutableNumber::
     * @return MutableNumber:: between 0 and 1
     *
     * static method which can be used without creating an instance of a MutableNumber::
     */
    static MutableNumber probability(double initialValue, double prob_mutation_, double StdDev_);
    /*!
     * @brief Creates a MutableNumber:: with values between 0 and 1
     * @param Values taken from config file
     * @return MutableNumber:: between 0 and 1
     *
     * static method which can be used without creating an instance of a MutableNumber::
     */
    static MutableNumber probability(j::Value const& config);
    /*!
     * @brief Creates a positive MutableNumber::
     * @param Same params as a usual MutableNumber::
     * @return Positive MutableNumber::
     *
     * static method which can be used without creating an instance of a MutableNumber::
     */
    static MutableNumber positive(double initialValue, double prob_mutation_, double StdDev_, bool hasMax=false, double max=0.0);
    /*!
     * @brief Creates a positive MutableNumber::
     * @param Values taken from config file
     * @return Positive MutableNumber::
     *
     * static method which can be used without creating an instance of a MutableNumber::
     */
    static MutableNumber positive(j::Value const& config, bool hasMax=false, double max=0.0);

private:
    double value;
    double prob_mutation;
    double StdDev;
    bool hasLowerBound;
    double LowerBound;
    bool hasUpperBound;
    double UpperBound;

};
