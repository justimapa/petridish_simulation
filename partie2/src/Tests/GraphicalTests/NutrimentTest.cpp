/*
 * prjsv
 * 2020
 * Marco Antognini & Jamila Sam
 * NutrimentTest FOR STEP2
 */

#include <Application.hpp>
#include <Lab/Nutriment.hpp>

class NutrimentTest : public Application
{
public:
    NutrimentTest(int argc, char const** argv)
        : Application(argc, argv)
    {
    }

    virtual ~NutrimentTest() = default;

    virtual void onRun() override final;

    virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
    std::string getHelpTextFile() const override final;
private:
    Nutriment* lastCreated = nullptr;
};

IMPLEMENT_MAIN(NutrimentTest);

void NutrimentTest::onRun()
{
    // Basic setup
    Application::onRun();
    setStats(false);
}

void NutrimentTest::onEvent(sf::Event event, sf::RenderWindow&)
{
    constexpr int NUT_QTY(50);
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        default:
            break;

        case sf::Keyboard::N:

            lastCreated = new Nutriment(NUT_QTY, getCursorPositionInView());
            getEnv().addNutriment(lastCreated);

            break;

        // to test takeQuantity
        case sf::Keyboard::T:

            if (lastCreated != nullptr) {
                lastCreated->takeQuantity(15);
            }

            break;
        }
    }
}

std::string NutrimentTest::getHelpTextFile() const
{
    return RES_LOCATION + "nutriment_help_step2.txt";
}
