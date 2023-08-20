#include "Program.hpp"
#include <libretirement/core/Calculator.hpp>
#include <libretirement/core/Presenter.hpp>
#include <libretirement/core/System.hpp>

using namespace retirement::core;

Program::Program()
{

}

void Program::execute(Date &retirement)
{
    auto presenter = Presenter::getInstance();
    auto calculator = Calculator::getInstance();
    auto system = System::getInstance();

    presenter->display(
            calculator->compute(retirement, 
                                system->getDate()));
}
