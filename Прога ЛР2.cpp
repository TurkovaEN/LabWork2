#include <stdio.h>
#include <stdlib.h>


// Структура уровня
typedef struct Level {
    int width;   // Ширина уровня
    int height;  // Высота уровня
} Level;

// Структура позиции
typedef struct Position {
    int x;      // Координата x
    int y;      // Координата y
} Position;

// Структура объекта
typedef struct Object {
    Position pos;  // Позиция объекта
    char type;    // Тип объекта ('P' - игрок, 'E' - враг)
} Object;

// Структура игрока
typedef struct Player {
    Object obj; // Объект игрока
    int health; // Здоровье игрока
} Player;

// Структура врага
typedef struct Enemy {
    Object obj; // Объект врага
    int damage; // Урон врага
} Enemy;

// Функция инициализации уровня
Level initLevel(int width, int height) {
    Level level;
    level.width = width;
    level.height = height;
    return level;
}

// Функция инициализации объекта
Object initObject(int x, int y, char type) {
    Object obj;
    obj.pos.x = x;
    obj.pos.y = y;
    obj.type = type;
    return obj;
}

// Функция инициализации игрока
Player initPlayer(int x, int y, int health) {
    Player player;
    player.obj = initObject(x, y, 'P');
    player.health = health;
    return player;
}

// Функция инициализации врага
Enemy initEnemy(int x, int y, int damage) {
    Enemy enemy;
    enemy.obj = initObject(x, y, 'E');
    enemy.damage = damage;
    return enemy;
}

// Функция вывода уровня на консоль
void printLevel(Level level) {
    for (int i = 0; i < level.height; i++) {
        for (int j = 0; j < level.width; j++) {
            printf("%c", ' ');
        }
        printf("\n");
    }
}

// Функция вывода игрока на консоль
void printPlayer(Player player) {
    printf("Игрок: (x: %d, y: %d, здоровье: %d)\n", player.obj.pos.x, player.obj.pos.y, player.health);
}

// Функция вывода врага на консоль
void printEnemy(Enemy enemy) {
    printf("Враг: (x: %d, y: %d, урон: %d)\n", enemy.obj.pos.x, enemy.obj.pos.y, enemy.damage);
}


int main() {
    // Статические переменные
    Level level = initLevel(10, 10);
    Player player = initPlayer(2, 2, 100);
    Enemy enemy = initEnemy(5, 5, 20);

    // Вывод на консоль
    printf("Уровень:\n");
    printLevel(level);
    printPlayer(player);
    printEnemy(enemy);

    // Динамические переменные
    Player* dynamicPlayer = (Player*)malloc(sizeof(Player));
    *dynamicPlayer = initPlayer(7, 7, 50);

    Enemy* dynamicEnemy = (Enemy*)malloc(sizeof(Enemy));
    *dynamicEnemy = initEnemy(3, 3, 15);

    // Вывод на консоль
    printf("\nДинамический игрок:\n");
    printPlayer(*dynamicPlayer);
    printf("\nДинамический враг:\n");
    printEnemy(*dynamicEnemy);

    // Освобождение памяти
    free(dynamicPlayer);
    free(dynamicEnemy);

    return 0;
}
