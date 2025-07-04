#include <iostream>

// Дополнительный отладочный оъект для класса дерева и перегрузка функций преобразования в текст.

class DebugTreeObject {
public:
    DebugTreeObject() {
        obj = '.';
    }
    DebugTreeObject(char init) {
        obj = init;
    }
    ~DebugTreeObject() {}
    friend bool operator>(const DebugTreeObject& lv, const DebugTreeObject& rv) {
        return (lv.obj > rv.obj);
    }
    friend bool operator<(const DebugTreeObject& lv, const DebugTreeObject& rv) {
        return (lv.obj < rv.obj);
    }
    friend bool operator==(const DebugTreeObject& lv, const DebugTreeObject& rv) {
        return (lv.obj == rv.obj);
    }
    friend char operator-(DebugTreeObject& lv, DebugTreeObject& rv) {
        return (lv.obj - rv.obj);
    }
    friend std::ostream& operator<<(std::ostream& os, const DebugTreeObject& rv) {
        std::cout << "'" << rv.obj << "'";                      // Простой вывод одного символа в кавычках.
        return os;
    }
    char obj;
};

namespace DTO {                                                 // Или лучше придумать другой метод.

std::string to_string(short rv) {
    return std::to_string(rv);
}

std::string to_string(float rv) {
    return std::to_string(rv);
}

std::string to_string(const DebugTreeObject& rv) {
    std::string t;
    t += rv.obj;
    return t;
}

}
