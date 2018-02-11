#include "./core/editor.h"

using namespace editor;
int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: cxeditor <filename>" << std::endl;
    }
    else {
        Editor editor("somefile");
        editor.run();
        editor.get_width();
    }
}
