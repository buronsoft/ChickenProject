#include <SFML/Graphics.hpp>
#include "Chicken.h"

using namespace sf;

void drawChicken(Chicken, RenderWindow*);
Chicken updateChicken(Chicken, RenderWindow*);

int main()
{
    RenderWindow window(VideoMode(500.f, 500.f), "Chicken Project");
    Chicken chicken(100.f, 110.f, 75.f, 0.3f, 0.3f, Color::Yellow);
    Chicken pepe(40.f, 50.f, 50.f, 0.3f, 0.3f, Color::Blue);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        chicken = updateChicken(chicken, &window);
        pepe = updateChicken(pepe, &window);
        drawChicken(chicken, &window);
        drawChicken(pepe, &window);
        window.display();
    }

    return 0;
}

Chicken updateChicken(Chicken chicken, RenderWindow* window)
{
    chicken.posX += chicken.velX;
    chicken.posY += chicken.velY;
    if (chicken.posX >= (*window).getSize().x - (2 * chicken.dim) || chicken.posX <= 0.f)
    {
        chicken.velX *= -1;
    }
    if (chicken.posY >= (*window).getSize().y - (3 * chicken.dim) || chicken.posY <= 0.f)
    {
        chicken.velY *= -1;
    }
    return chicken;
}

void drawChicken(Chicken chicken, RenderWindow* window)
{
    CircleShape body(chicken.dim);
    body.setFillColor(chicken.color);
    body.setPosition(Vector2f{ chicken.posX, chicken.posY + chicken.dim });
    (*window).draw(body);

    CircleShape head(chicken.dim / 2);
    head.setFillColor(chicken.color);
    head.setPosition(Vector2f{ chicken.posX + chicken.dim / 2, chicken.posY });
    (*window).draw(head);

    CircleShape rightEye(chicken.dim / 12);
    rightEye.setFillColor(Color::Black);
    rightEye.setPosition(chicken.posX + 5*chicken.dim/8, chicken.posY + chicken.dim / 3);
    (*window).draw(rightEye);

    CircleShape leftEye(chicken.dim / 12);
    leftEye.setFillColor(Color::Black);
    leftEye.setPosition(chicken.posX + 10*chicken.dim/8, chicken.posY + chicken.dim / 3);
    (*window).draw(leftEye);

    CircleShape beack(chicken.dim / 6, 3);
    beack.setFillColor(Color::Color(250, 150, 10));
    beack.setPosition(chicken.posX + 19*chicken.dim/16, chicken.posY + 7*chicken.dim / 8);
    beack.setRotation(180.f);
    (*window).draw(beack);
    
    RectangleShape leftFoot(Vector2f{ 2 * chicken.dim / 3, chicken.dim / 6 });
    leftFoot.setFillColor(Color::Color(250, 150, 10));
    leftFoot.setPosition(chicken.posX, chicken.posY + 3 * chicken.dim - chicken.dim / 6);
    (*window).draw(leftFoot);

    RectangleShape rightFoot(Vector2f{ 2 * chicken.dim / 3, chicken.dim / 6 });
    rightFoot.setFillColor(Color::Color(250, 150, 10));
    rightFoot.setPosition(chicken.posX + 2 * chicken.dim - 2 * chicken.dim / 3, chicken.posY + 3 * chicken.dim - chicken.dim / 6);
    (*window).draw(rightFoot);
}