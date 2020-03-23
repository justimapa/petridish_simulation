#pragma once
#include "Utility/Utility.hpp"

class MutableNumber
{
public:
    MutableNumber(double value_, double prob_mutation_, double StdDev_, bool hasLowerBound_=false, double LowerBound_=0.0, bool hasUpperBound_=false, double UpperBound_=0.0);
    MutableNumber(j::Value const& config);
    MutableNumber();
    double get() const;
    void set(double value_);
    void mutate();
    static MutableNumber probability(double initialValue, double prob_mutation_, double StdDev_);
    static MutableNumber probability(j::Value const& config);
    static MutableNumber positive(double initialValue, double prob_mutation_, double StdDev_, bool hasMax=false, double max=0.0);
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
