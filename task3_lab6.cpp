#include <iostream>
#include <string>
using namespace std;

class Position
{
private:
    int x;
    int y;
    int z;

public:
    Position(int i_x, int i_y, int i_z) : x(i_x), y(i_y), z(i_z) {}

    void display() const
    {
        cout << "Position:" << endl;
        cout << "X:" << x << endl;
        cout << "Y:" << y << endl;
        cout << "Z:" << z << endl;
    }
};

class Health
{
private:
    int health;

public:
    Health(int i_health) : health(i_health) {}

    void setplayerHealth(int i_health)
    {
        health = i_health;
    }

    void damage(int i_damage)
    {
        health -= i_damage;
    }

    void display() const
    {
        cout << "Health:" << health << endl;
    }
};

class Character : public Position, public Health
{
private:
    string name;

public:
    Character(const string &i_name, int i_x, int i_y, int i_z, int i_health) : name(i_name), Position(i_x, i_y, i_z), Health(i_health) {}

    void display() const
    {
        cout << "Player Name:" << name << endl;
        Position::display();
        Health::display();
    }
};

int main()
{
    Character player("Hero", 10, 10, 10, 100);
    player.display();

    cout << "\nAfter damage" << endl;
    player.damage(30);

    player.display();
    return 0;
}