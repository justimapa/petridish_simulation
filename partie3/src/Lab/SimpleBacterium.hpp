#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    SimpleBacterium(Vec2d const&);
    SimpleBacterium(SimpleBacterium &);

    void drawOn(sf::RenderTarget& target) const override;
    void update(sf::Time) override;
    void updateFlagella(sf::Time);
    void updateProbability();
    void tumble();
    void drawFlagella(sf::RenderTarget& target)const;
    void move(sf::Time) override;
    bool isTumbling();
    Bacterium* clone() override;
    j::Value& getConfig()const override;
    Vec2d getSpeedVector() ;
    void drawFlagella()const;
    Vec2d f(Vec2d position, Vec2d direction) const override;
    ~SimpleBacterium() override;
private:
    double t;
    double rotation;
    double oldScore;
    double tumblingProbability;
    sf::Time tLastTumble;
    std::string algo;
};


