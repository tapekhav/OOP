#ifndef LABS_MESSAGE_H
#define LABS_MESSAGE_H

#include <string>
#include <map>


class Message {
public:
    enum Prefix {
        Game,
        GameStatus,
        Error
    };

    explicit Message(Prefix, const std::string&, int num = -1);
    std::string get_msg();
    Prefix get_prefix() const;
    friend std::ostream& operator<<(std::ostream&, Message&);

    void update();

private:
    const std::map<Prefix, std::string> prefix_map = {
            {Game, "[Game] "},
            {GameStatus, "[GameStatus] "},
            {Error, "[Error] "}
    };
    Prefix prefix;
    std::string info;
    int num;
};


#endif
