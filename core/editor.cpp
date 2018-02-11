#include "editor.h"
#include <unistd.h>
#include <sys/ioctl.h>
using namespace editor;

Editor::Editor() {
    this->terminal_restore = termios{};
    tcgetattr(0, &this->terminal_restore);
    this->Cursor.x = 0;
    this->Cursor.y = 0;
}

editor::Editor::~Editor() {
    callAtExit();
}

Editor::Editor(const char* fname) : Editor::Editor() {

}

Editor::Editor(const std::string& fname) : editor::Editor::Editor() {

}

Editor::Editor(std::experimental::string_view fname) : editor::Editor::Editor(){

}

void Editor::open_file(const std::string& filename) {

}

void Editor::open_file(const char* filename) {

}

void Editor::open_file(std::experimental::string_view filename) {

}

Editor::usize Editor::get_height() {
    return 0;
}

Editor::usize Editor::get_width() {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    std::cout << "Current terminal width setting: " << ws.ws_col << "\n";
    return 0;
}

void Editor::callAtExit() {
    tcsetattr(STDIN_FILENO, TCSANOW, &this->terminal_restore);
}

void Editor::run() {
    std::cout << "Starting editor... \n";
}

bool Editor::setup_rawmode() {
    struct termios raw;
    tcgetattr(0, &this->terminal_restore);
    if(raw_mode) {
        return raw_mode;
    }
    if(tcgetattr(STDIN_FILENO, &this->terminal_restore) == -1) {
        callAtExit();
        exit(1);
    }
    if (!isatty(STDIN_FILENO)) {
        callAtExit();
        exit(1);
    }

    raw = terminal_restore;
    /* modify the original mode */
    /* input modes: no break, no CR to NL, no parity check, no strip char,
     * no start/stop output control. */
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    /* output modes - disable post processing */
    raw.c_oflag &= ~(OPOST);
    /* control modes - set 8 bit chars */
    raw.c_cflag |= (CS8);
    /* local modes - choing off, canonical off, no extended functions,
     * no signal chars (^Z,^C) */
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    /* control chars - set return condition: min number of bytes and timer. */
    raw.c_cc[VMIN] = 0; /* Return each byte, or zero for timeout. */
    raw.c_cc[VTIME] = 1; /* 100 ms timeout (unit is tens of second). */

    /* put terminal in raw mode after flushing */
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) < 0) {
        callAtExit();
    }
    return (raw_mode = true);
}
