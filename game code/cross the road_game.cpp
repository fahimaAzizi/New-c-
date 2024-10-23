#include <SFML/Graphics.hpp>
#include <deque>
#include <vector>
#include <cstdlib>
using namespace std;

class cPlayer {
public:
    int x, y;
    sf::Sprite sprite;  // Sprite for player

    cPlayer(int width, sf::Texture& texture) {
        x = width / 2;
        y = 0;
        sprite.setTexture(texture);
    }

    void updatePosition() {
        sprite.setPosition(x * 50, y * 50);  // Update sprite position based on player coordinates
    }
};

class cLane {
private:
    deque<bool> cars;
    int width;

public:
    cLane(int width) : width(width) {
        for (int i = 0; i < width; i++)
            cars.push_front(false);
    }

    void Move() {
        if (rand() % 10 == 1)
            cars.push_front(true);  // A car appears
        else
            cars.push_front(false);  // No car

        cars.pop_back();  // Remove the last car to maintain lane size
    }

    bool CheckPos(int pos) {
        return cars[pos];
    }

    // Draws cars at their respective positions using carTexture
    void drawLane(sf::RenderWindow& window, sf::Texture& carTexture, int laneY) {
        sf::Sprite carSprite;
        carSprite.setTexture(carTexture);

        for (int i = 0; i < width; i++) {
            if (cars[i]) {
                carSprite.setPosition(i * 50, laneY * 50);  // Position the car
                window.draw(carSprite);
            }
        }
    }
};

class cGame {
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    cPlayer* player;
    vector<cLane*> map;
    sf::RenderWindow window;
    sf::Texture carTexture;
    sf::Texture playerTexture;

public:
    cGame(int w = 20, int h = 10) : window(sf::VideoMode(1000, 500), "Car Game") {
        numberOfLanes = h;
        width = w;
        quit = false;
        score = 0;

       
       carTexture.loadFromFile("path_to_image/car1.png");
       playerTexture.loadFromFile("path_to_image/player.png");

    
        for (int i = 0; i < numberOfLanes; i++)
            map.push_back(new cLane(width));

        player = new cPlayer(width, playerTexture);
    }

    ~cGame() {
        delete player;
        for (auto lane : map)
            delete lane;
    }

    void Input() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player->x > 0)
            player->x--;  // Move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->x < width - 1)
            player->x++;  // Move right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player->y > 0)
            player->y--;  // Move up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player->y < numberOfLanes - 1)
            player->y++;  // Move down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            quit = true;  // Quit the game
    }

    void Logic() {
        for (int i = 0; i < numberOfLanes; i++) {
            map[i]->Move();

            // Check if player is hit by a car
            if (map[i]->CheckPos(player->x) && player->y == i) {
                quit = true;
                cout << "Game Over!" << endl;
            }
        }

        // Increase score as player survives
        if (!quit) {
            score++;
        }
    }

    void Draw() {
        window.clear();

        // Draw lanes and cars
        for (int i = 0; i < numberOfLanes; i++) {
            map[i]->drawLane(window, carTexture, i);
        }

        // Update player position and draw the player
        player->updatePosition();
        window.draw(player->sprite);

        window.display();
    }

    void Run() {
        while (window.isOpen() && !quit) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            Input();
            Logic();
            Draw();
        }
    }
};

int main() {
    cGame game(20, 10);
    game.Run();
    return 0;
}
