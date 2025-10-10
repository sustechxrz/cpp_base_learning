#include <SFML/Graphics.hpp>
using namespace sf;

const int WinWidth = 1024;
const int WinHeight = 768;

int main()
{
    RenderWindow window(VideoMode(WinWidth, WinHeight), "Racing");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    }
    return 0;
}