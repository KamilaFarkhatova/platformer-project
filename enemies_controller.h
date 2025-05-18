#ifndef ENEMIES_CONTROLLER_H
#define ENEMIES_CONTROLLER_H
#include <vector>
#include <raylib.h>
#include "enemy.h"
#include "level.h"

class EnemiesController {
public:
    [[nodiscard]] std::vector<Enemy> get_enemies() const {
        return enemies;
    }

    static EnemiesController &getInstance() {
        static EnemiesController instance;
        return instance;
    };
    EnemiesController(const EnemiesController&) = delete;
    EnemiesController operator=(const EnemiesController&) = delete;
    EnemiesController(EnemiesController&&) = delete;
    EnemiesController operator=(EnemiesController&&) = delete;
    void spawn_enemies();
    void update_enemies();
    bool is_colliding_with_enemies(Vector2 pos) const;
    void remove_colliding_enemy(Vector2 pos);

    static void draw_enemies();

private:
    EnemiesController() = default;
    ~EnemiesController() = default;
    std::vector<Enemy> enemies{};
    };

#endif //ENEMIES_CONTROLLER_H
