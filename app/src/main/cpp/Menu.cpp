#include "Menu.hpp"

Menu::Menu(Vector2 const& ScreenDims, std::string * ptst) : startButton(ScreenDims.x / 2, ScreenDims.y / 2, 150, 150, BLUE, "Start"),
                                                            ptstate(ptst)
{

}

void Menu::actualize(const float dt)
{
    if (startButton.isPressed())
    {
        *ptstate = "Ingame";
    }
}

void Menu::Draw()
{
    startButton.Draw(false);
}