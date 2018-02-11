#pragma once
#include <string>
#include <memory>
#include <experimental/filesystem>
#include <experimental/string_view>
#include <iostream>
#include <termios.h>
#include <term.h>

namespace editor {
    class Editor {
        using usize = std::size_t;
    private:
        const char* filename;
        usize height, width;
        struct termios terminal_restore;
        bool raw_mode;
    public:
        Editor();
        Editor(const char* filename);
        Editor(const std::string& filename);
        Editor(std::experimental::string_view filename);
        ~Editor();

        bool setup_rawmode();
        void run();
        void open_file(const std::string& filename);
        void open_file(const char* filename);
        void open_file(std::experimental::string_view filename);

        void close_file(std::size_t fileid);

        usize get_height();
        usize get_width();

        void move_cursor_y(std::size_t y);
        void move_cursor_x(std::size_t x);
        void callAtExit();

        struct {
            std::size_t x;
            std::size_t y;
        } Cursor;
    };

    enum Parens {
        LBRACKET,
        RBRACKET,
        LCURLY,
        RCURLY,
        LPARENS,
        RPARENS
    };
}
