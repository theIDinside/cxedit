//
// Created by cx on 2018-02-11.
//

#include "editmem.h"
#include <ctime>
#include <sstream>

editmem::editmem(const std::string &filename, const std::string &last_edit) : filename(filename),
                                                                              last_edit(last_edit) {}

editmem::~editmem() {

}

void editmem::setLast_edit(const std::string &last_edit) {
    editmem::last_edit = last_edit;
}

void editmem::setFilename(const std::string &filename) {
    editmem::filename = filename;
}

const std::string &editmem::getLast_edit() const {
    return last_edit;
}

void editmem::setLast_edit() {
    // current date/time based on current system
    std::time_t now = time(0);
    // convert now to string form
    char* dt = std::ctime(&now);
}

std::ostream &operator<<(std::ostream &os, const editmem &editmem1) {
    os << "{\n\tfilename: " << editmem1.filename
       << "\n\tlast_edit: " << editmem1.last_edit
       << "\n\tcursor_pos: (" << editmem1.CursorPosition.x << "," << editmem1.CursorPosition.y << ")"
       << "\n}";
    return os;
}
