//
// Created by cx on 2018-02-11.
//

#ifndef CXEDIT_EDITMEM_H
#define CXEDIT_EDITMEM_H


#include <string>
#include <ostream>

class editmem {
public:
    editmem(const std::string &filename, const std::string &last_edit);

    const std::string &getLast_edit() const;
    void setFilename(const std::string &filename);
    void setLast_edit(const std::string &last_edit);
    void setLast_edit();
    virtual ~editmem();

    friend std::ostream &operator<<(std::ostream &os, const editmem &editmem1);

private:
    std::string filename;
    std::string last_edit;
    struct {
        uint32_t x;
        uint32_t y;
    } CursorPosition;

};


#endif //CXEDIT_EDITMEM_H
