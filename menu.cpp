#include "menu.h"

Menu::Menu()
{
    this->chosen_mode = 0;
}

Menu::~Menu()
{
}

void Menu::render()
{
    int mode;

    std::cout << "CHOOSE A MODE TO PLAY" << std::endl
              << std::endl;

    std::cout << "1 - "
              << "SINGLEPLAYER" << std::endl;

    std::cout << "2 - "
              << "MULTIPLAYER" << std::endl;

    std::cout << "3 - "
              << "QUIT" << '\n';

    while (!this->chosen_mode)
    {
        try
        {   
            std::cout << std::endl << "Choice: ";

            std::string input;
            getline(std::cin, input);

            if (input.length() != 1)
            {
                throw "INPUT::Please, choose a valid mode between 1 to 3";
            }

            mode = (int)input[0] - 48; // 49 is '1' ASCII value

            if (mode < 1 || mode > 3)
            {
                throw "INPUT::Please, choose a valid mode between 1 to 3";
            }

            if (mode == 3)
            {
                std::cout << "Quitting..." << std::endl;
                exit(0);
            }

            this->chosen_mode = mode;
        }
        catch (const char *const error)
        {
            std::cout << "ERROR::" << error << '\n';
        }
    }
}

int Menu::get_chosen_mode()
{
    return this->chosen_mode;
}