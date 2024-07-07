#include <string>

int main() {
    char utf8c = u8'a';
    // char utf8c = '好'; // Error: multi-character character constant
    char16_t utf16c = u'好';
    char32_t utf32c = U'好';
    char utf8s[] = "你好世界";  // 取决于编译器的默认字符编码和文件编码
    char utf8s2[] = u8"你好世界";   // UTF-8字符编码
    char16_t utf16s[] = u"你好世界"; // UTF-16字符编码
    char32_t utf32s[] = U"你好世界"; // UTF-32字符编码

    return 0;
}