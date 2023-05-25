#include "mainmenu.h"

Texture cross1;
Texture zero1;
int menu_init() {
    cross1.loadFromFile("./images/cross.png");
    cross1.setSmooth(true);
    zero1.loadFromFile("./images/zero.png");
    zero1.setSmooth(true);
    return 0;
}
int menu_draw(RenderWindow &window) {
    window.clear(Color::White);
    Sprite temp;
    temp.setTexture(cross1);
    temp.setPosition(90, 175);
    window.draw(temp);
    temp.setTexture(zero1);
    temp.setPosition(310, 175);
    window.draw(temp);
    return 0;
}
int menu(RenderWindow &window, int width, int height)
{
    menu_init();
    while (true) {
        Event event;

        while (window.pollEvent(event))
        {  
            if (event.type == Event::Closed)
            {
                return 5;
            }
            if (event.mouseButton.button == Mouse::Left) {
                if (event.mouseButton.x >= 90 && event.mouseButton.x <= 290 && event.mouseButton.y >= 175 && event.mouseButton.y <= 375) {
                    return 1;
                    
                }
                if (event.mouseButton.x >= 310 && event.mouseButton.x <= 510 && event.mouseButton.y >= 175 && event.mouseButton.y <= 375) {
                    return 2;
                }
            }
        }
        menu_draw(window);
        window.display();
    }
    return 0;
}
