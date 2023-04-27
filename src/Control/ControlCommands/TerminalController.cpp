#include "TerminalController.h"

char TerminalController::get_step() {
    std::cout << "Введите символ, отвечающий за управление игрой: ";
    return read_char();
}

char TerminalController::get_char() {
    std::cout << "Введите 'y', если хотите оставить у поля стандартное значение(10, 10): ";
    return read_char();
}

int TerminalController::get_width() {
    std::cout << "Введите ширине: ";
    return read_num();
}

int TerminalController::get_height() {
    std::cout << "Введите высоту: ";
    return read_num();
}

char TerminalController::get_cfg() {
    std::cout << "Введите 'y', если хотите поставить стандартное управление (w, a, s, d, e): ";
    return read_char();
}

std::string TerminalController::get_file_name() {
    std::cout << "Введите имя файла: ";
    std::string file_name;
    std::cin >> file_name;
    return file_name;
}

char TerminalController::get_logs() {
    std::cout << "Введите, куда будут выводиться логи (1 - в консоль, 2 - в файл, 3 - в консоль и в файл): ";
    return read_char();
}

char TerminalController::get_game_log() {
    std::cout << "Хотите ли вы отслеживать изменения в игре? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    return read_char();
}

char TerminalController::get_error_log() {
    std::cout << "Хотите ли вы отслеживать ошибки? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    return read_char();
}

char TerminalController::get_status_log() {
    std::cout << "Хотите ли вы отслеживать статус игры? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    return read_char();
}

char TerminalController::read_char() {
    std::cin >> ch;
    return ch;
}

int TerminalController::read_num() {
    std::cin >> num;
    return num;
}

char TerminalController::get_num_level() {
    std::cout << "Выберите уровень игры. Для того, чтобы выбрать первый уровень напишите цифры 1. "
                 "Остальные введенные символы поставят уровень 2. ";
    return read_char();
}
