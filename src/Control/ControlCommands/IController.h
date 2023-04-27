#ifndef LABS_ICONTROLLER_H
#define LABS_ICONTROLLER_H



class IController {
public:
    virtual char get_step() = 0;
    virtual char get_char() = 0;
    virtual int get_width() = 0;
    virtual int get_height() = 0;
    virtual char get_cfg() = 0;
    virtual std::string get_file_name() = 0;
    virtual char get_logs() = 0;

    virtual char get_game_log() = 0;
    virtual char get_error_log() = 0;
    virtual char get_status_log() = 0;

    virtual char get_num_level() = 0;

    virtual ~IController() = default;
protected:
    char ch;
    int num;
};

#endif