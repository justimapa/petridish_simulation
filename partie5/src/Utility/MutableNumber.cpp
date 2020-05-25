#include "MutableNumber.hpp"
#include "Random/Random.hpp"

MutableNumber::MutableNumber(double value_, double prob_mutation_,
                             double StdDev_, bool hasLowerBound_, double LowerBound_,
                             bool hasUpperBound_, double UpperBound_)
    : value(value_),
      prob_mutation(prob_mutation_),
      StdDev(StdDev_),
      hasLowerBound(hasLowerBound_),
      LowerBound(LowerBound_),
      hasUpperBound(hasUpperBound_),
      UpperBound(UpperBound_)
{ }

MutableNumber::MutableNumber(j::Value const& config)
    : value(config["initial"].toDouble()),
      prob_mutation(config["rate"].toDouble()),
      StdDev(config["sigma"].toDouble()),
      hasLowerBound(config["clamp min"].toBool()),
      LowerBound(config["min"].toDouble()),
      hasUpperBound(config["clamp max"].toBool()),
      UpperBound(config["max"].toDouble())
{ }

MutableNumber::MutableNumber()
{

}

void MutableNumber::set(double value_)
{
    if(value_ > UpperBound and hasUpperBound) {
        value = UpperBound;
    } else if(value_ < LowerBound and hasLowerBound) {
        value = LowerBound;
    } else {
        value = value_;
    }
}

double MutableNumber::get() const
{
    return value;
}

void MutableNumber::mutate()
{
    if(bernoulli(prob_mutation)) {
        set(value+=normal(0, StdDev*StdDev));
    }
}

MutableNumber MutableNumber::probability(double initialValue, double prob_mutation_, double StdDev_)
{
    return MutableNumber(initialValue, prob_mutation_, StdDev_, true, 0.0, true, 1.0);
}

MutableNumber MutableNumber::probability(j::Value const& config)
{
    return MutableNumber(config["initial"].toDouble(), config["rate"].toDouble(), config["sigma"].toDouble(), true, 0.0, true, 1.0);
}

MutableNumber MutableNumber::positive(double initialValue, double prob_mutation_, double StdDev_, bool hasMax, double max)
{
    return MutableNumber(initialValue, prob_mutation_, StdDev_, true, 0.0, hasMax, max);
}

MutableNumber MutableNumber::positive(j::Value const& config, bool hasMax, double max)
{
    return MutableNumber(config["initial"].toDouble(), config["rate"].toDouble(), config["sigma"].toDouble(), true, 0.0, hasMax, max);
}

MutableNumber::~MutableNumber()
{

}
