#include <iostream>

using namespace std;

// Класс Level
class Level {
private:
    int width;   // Ширина уровня
    int height;  // Высота уровня

public:
    Level(int width, int height) : width(width), height(height) {}

    void print() const {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << ' ';
            }
            cout << endl;
        }
    }
};

// Класс Position
class Position {
private:
    int x;      // Координата x
    int y;      // Координата y

public:
    Position(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

// Класс Object
class Object {
private:
    Position pos;  // Позиция объекта
    char type;    // Тип объекта ('P' - игрок, 'E' - враг)

public:
    Object(int x, int y, char type) : pos(x, y), type(type) {}

    int getX() const { return pos.getX(); }
    int getY() const { return pos.getY(); }
    char getType() const { return type; }
};

// Класс Player
class Player {
private:
    Object obj; // Объект игрока
    int health; // Здоровье игрока

public:
    Player(int x, int y, int health) : obj(x, y, 'P'), health(health) {}

    int getX() const { return obj.getX(); }
    int getY() const { return obj.getY(); }
    int getHealth() const { return health; }

    void print() const {
        cout << "Игрок: (x: " << getX() << ", y: " << getY() << ", здоровье: " << getHealth() << ")" << endl;
    }
};

// Класс Enemy
class Enemy {
private:
    Object obj; // Объект врага
    int damage; // Урон врага

public:
   
    Enemy() : obj(0, 0, 'E'), damage(0) {}
    Enemy(int x, int y, int damage) : obj(x, y, 'E'), damage(damage) {}

    int getX() const { return obj.getX(); }
    int getY() const { return obj.getY(); }
    int getDamage() const { return damage; }

    void print() const {
        cout << "Враг: (x: " << getX() << ", y: " << getY() << ", урон: " << getDamage() << ")" << endl;
    }
};


int main() {
    // Статические объекты
    Level level(10, 10);
    Player player(2, 2, 100);
    Enemy enemy(5, 5, 20);

    // Вывод на консоль
    cout << "Уровень:" << endl;
    level.print();
    player.print();
    enemy.print();


    // Динамический массив объектов
    Player dynamicPlayers[2] = { Player(7, 7, 50), Player(3, 3, 60) };

    // Вывод на консоль
    cout << "\nДинамические игроки:" << endl;
    for (int i = 0; i < 2; i++) {
        dynamicPlayers[i].print();
    }

    // Массив динамических объектов
    Enemy* dynamicEnemies = new Enemy[2];
    dynamicEnemies[0] = Enemy(8, 8, 15);
    dynamicEnemies[1] = Enemy(1, 1, 25);

    // Вывод на консоль
    cout << "\nДинамические враги:" << endl;
    for (int i = 0; i < 2; i++) {
        dynamicEnemies[i].print();
    }

    // Освобождение памяти
    delete[] dynamicEnemies;

    // Динамический объект класса
    Level* dynamicLevel = new Level(15, 15);

    // Вывод на консоль
    cout << "\nДинамический уровень:" << endl;
    dynamicLevel->print();

    // Освобождение памяти
    delete dynamicLevel;

    return 0;
}
