#include "Menu.hpp"

Menu::Menu(Vector2 const& ScreenDims, string * ptst, Ingame *_Ingame_ptr_) : startInfiniButton(ScreenDims.x / 2, ScreenDims.y / 2 - 100, 150, 150, BLUE, "Start"),
                                                                             selectNiveauButton(ScreenDims.x / 2, ScreenDims.y / 2 + 100, 150, 150, BLUE, "Select\n\n\nLevel"),
                                                                             ptstate(ptst),
                                                                             Ingame_ptr(_Ingame_ptr_),
                                                                             selecteur(ptst, _Ingame_ptr_)
{

}

void Menu::actualize(const float dt)
{
    if (*ptstate == "Menu")
    {
        if (startInfiniButton.isPressed())
        {
            *ptstate = "Ingame";
            (*Ingame_ptr).numLevel = 0;
            (*Ingame_ptr).Start();
        }
        else if (selectNiveauButton.isPressed())
        {
            *ptstate = "choixLevel";
        }
    }
    if (*ptstate == "choixLevel")
    {
        selecteur.actualize();
    }
}

void Menu::Draw()
{
    startInfiniButton.Draw(false);
    selectNiveauButton.Draw(false);
    if (*ptstate == "choixLevel")
        selecteur.Draw();
}