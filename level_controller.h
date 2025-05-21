#ifndef LEVEL_CONTROLLER_H
#define LEVEL_CONTROLLER_H

#include "level.h"
#include "raylib.h"
#include <vector>
#include <string>

class LevelController {
public:
    // Singleton access
    static LevelController& getInstanceLevel();

    // Deleted copy/move operations
    LevelController(const LevelController&) = delete;
    LevelController& operator=(const LevelController&) = delete;
    LevelController(LevelController&&) = delete;
    LevelController& operator=(LevelController&&) = delete;

    // Accessors and modifiers
    [[nodiscard]] std::vector<Level> get_levels() const;
    void set_levels(const std::vector<Level>& level_list);

    [[nodiscard]] Level& get_current_level();
    [[nodiscard]] char* get_current_level_data() const;

    void set_current_level(const Level& level);
    void set_level_cell(size_t row_index, size_t column_index, char new_value);

    // Core game logic
    bool is_inside_level(int row_index, int column_index);
    bool is_colliding(Vector2 position, char target);
    char& get_collider(Vector2 position, char target);

    void draw_level();
    void load_level(int level_offset = 0);
    static void unload_level();
    static void reset_level_index();

    // Level parsing
    Level parseLevelRLE(const std::string& encoded_data);
    std::vector<Level> loadLevelsFromFile(const std::string& filepath);

private:
    LevelController() = default;
    ~LevelController() = default;

    Level current_level;
    char* current_level_data = nullptr;
    std::vector<Level> LEVELS;
};

#endif // LEVEL_CONTROLLER_H
