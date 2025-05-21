#ifndef LEVEL_H
#define LEVEL_H

#include <cstddef>

class LevelController;

class Level {
public:
    Level();
    Level(size_t row_count, size_t column_count, char* level_data);

    [[nodiscard]] size_t get_rows() const;
    void set_rows(size_t row_count);

    [[nodiscard]] size_t get_columns() const;
    void set_columns(size_t column_count);

    [[nodiscard]] const char* get_data() const;
    void set_data(char* level_data);

    static char& get_level_cell(size_t row_index, size_t column_index);

private:
    size_t rows;
    size_t columns;
    char* data;
};

// --- Inline Definitions ---

inline Level::Level()
    : rows(0), columns(0), data(nullptr) {}

inline Level::Level(size_t row_count, size_t column_count, char* level_data)
    : rows(row_count), columns(column_count), data(level_data) {}

inline size_t Level::get_rows() const {
    return rows;
}

inline void Level::set_rows(size_t row_count) {
    rows = row_count;
}

inline size_t Level::get_columns() const {
    return columns;
}

inline void Level::set_columns(size_t column_count) {
    columns = column_count;
}

inline const char* Level::get_data() const {
    return data;
}

inline void Level::set_data(char* level_data) {
    data = level_data;
}

#endif // LEVEL_H
