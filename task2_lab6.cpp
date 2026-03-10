#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
    int health;
    int damage;

public:
    Character(int i_health, int i_damage) : health(i_health), damage(i_damage) {}

    void display() const
    {
        cout << "Health:" << health << endl;
        cout << "Damage:" << damage << endl;
    }
};

class Player : public Character
{
private:
    string name;

public:
    Player(const string &i_name, int i_health, int i_damage) : name(i_name), Character(i_health, i_damage) {}

    void display() const
    {
        cout << "Player name:" << name << endl;
        Character::display();
    }
};

class Enemy : public Character
{
public:
    Enemy(int i_health, int i_damage) : Character(i_health, i_damage) {}

    void display() const
    {
        cout << "Enemy" << endl;
        Character::display();
    }
};

class Wizard : public Player
{
private:
    int magicPower;
    int spell;

public:
    Wizard(const string &i_name, int i_health, int i_damage, int i_magicPower, int i_spell) : magicPower(i_magicPower), spell(i_spell), Player(i_name, i_health, i_damage) {}

    void display() const
    {
        Player::display();
        cout << "Magic Power:" << magicPower << endl;
        cout << "Spell:" << spell << endl;
    }
};

int main()
{
    Wizard W1("Elden", 100, 0, 20, 40);
    W1.display();
    return 0;
}