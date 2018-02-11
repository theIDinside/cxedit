//
// Created by cx on 2018-02-11.
//

#ifndef CXEDIT_ACTIONS_H
#define CXEDIT_ACTIONS_H


enum editor_actions {
    CURSOR_INCX,
    CURSOR_INCY,
    CURSOR_DECX,
    CURSOR_DECY,
    SEARCH,
    GOTO,
    SAVE,
    OPEN,
    CLOSE,
    EXIT,
    SELECT,
    INSERT,
    DELETE,
    APPEND,
    COPY,
    PASTE,
    UNDO,
    REDO
};

// Design this with the command pattern, current state is shite
class action {
public:
    virtual bool perform()= 0;
};

template <typename T=char>
class insert : public action {
public:
    bool perform() override {

    }
};

#endif //CXEDIT_ACTIONS_H
