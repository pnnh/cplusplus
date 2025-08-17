#include <lunasvg.h>
#include <iostream>

int main(int argc, char** argv) {
    auto document = lunasvg::Document::loadFromFile("./data/input.svg");
    if (document == nullptr) {
        std::cerr << "Failed to load SVG" << std::endl;
        return 1;
    }
    auto bitmap = document->renderToBitmap(256, 256);
    if (bitmap.isNull()) {
        std::cerr << "Failed to render SVG to bitmap" << std::endl;
        return 1;
    }
    // bitmap.convertToRGBA();
    auto result = bitmap.writeToPng("./output/output.png");
    if (!result) {
        std::cerr << "Failed to write bitmap to PNG" << std::endl;
        return 1;
    }
    return 0;
}