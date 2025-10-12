#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

const int WinWidth = 1024;
const int WinHeight = 768;
const int roadWidth = 1800;
const int roadSegLength = 180;
const int roadCount = 1884;

struct Road {
    float x, y, z;
    float X, Y, W;
    float scale,curve;
    Road(int _x, int _y, int _z, float _c) : x(_x), y(_y), z(_z), curve(_c) {}
    void project(int camX, int camY, int camZ) {
        scale = 1.0f / (z - camZ);
        X = (1 + (x - camX) * scale) * WinWidth / 2;
        Y = (1 - (y - camY) * scale) * WinHeight / 2;
        W = scale * roadWidth * WinWidth / 2;
    }

};

void DrawTrape(RenderWindow& window, Color c, int x1, int y1, int w1, int x2, int y2, int w2) {
    ConvexShape polygon(4);
    polygon.setFillColor(c);
    polygon.setPoint(0, Vector2f(x1-w1, y1));
    polygon.setPoint(1, Vector2f(x2-w2, y2));
    polygon.setPoint(2, Vector2f(x2+w2, y2));
    polygon.setPoint(3, Vector2f(x1+w1, y1));
    window.draw(polygon);
}

int main()
{
    RenderWindow window(VideoMode(WinWidth, WinHeight), "Racing");
    window.setFramerateLimit(60);

    vector <Road>roads;
    for (int i = 0; i < roadCount; i++) {
        float curve = (i > 0 && i < 300) ? 0.5 : -0.5;
        Road r(0, 1600 * sin(i / 30.0), (i + 1) * roadSegLength, curve);
        roads.push_back(r);
    }
    int cameraX = 0;
    float cameraY = 1600;
    int cameraZ = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) cameraZ += roadSegLength;
        if (Keyboard::isKeyPressed(Keyboard::Down)) cameraZ -= roadSegLength;
        if (Keyboard::isKeyPressed(Keyboard::Left)) cameraX -= 100;
        if (Keyboard::isKeyPressed(Keyboard::Right)) cameraX += 100;
        int totalLength = roadCount * roadSegLength;
        if (cameraZ >= totalLength) cameraZ -= totalLength;
        if (cameraZ < 0) cameraZ += totalLength;
        window.clear();
        int roadIndex = cameraZ / roadSegLength;
        float x = 0, dx = 0;
        cameraY = 1600 + roads[roadIndex].y;
        int minY = WinHeight;
        for (int i = roadIndex; i < roadIndex + 300; ++i) {
            Road& now = roads[i % roadCount];
            now.project(cameraX - x, cameraY, cameraZ - (i >= roadCount ? totalLength : 0 ));
            dx += now.curve;
            x += dx;
            if (!i) {
                continue;
            }
            if (now.Y < minY) {
                minY = now.Y;
            }
            else {
                continue;
            }
            Road& pre = roads[(i - 1) % roadCount];
            Color grass = (i / 3) % 2 ? Color(16, 210, 16) : Color(0, 199, 0);
            Color edge = (i / 3) % 2 ? Color(0, 0, 0) : Color(255, 255, 255);
            Color road = (i / 3) % 2 ? Color(105, 105, 105) : Color(101, 101, 101);
            DrawTrape(window, grass, pre.X, pre.Y, WinWidth*10, now.X, now.Y, WinWidth*10);
            DrawTrape(window, edge, pre.X, pre.Y, pre.W * 1.3, now.X, now.Y, now.W * 1.3);
            DrawTrape(window, road, pre.X, pre.Y, pre.W, now.X, now.Y, now.W);
        }
        window.display();
    }
    return 0;
}