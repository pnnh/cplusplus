#include <iostream>
#include <sstream>

int main()
{
    std::cout << "ostringstream produces strings with str" << std::endl;
    std::ostringstream oss;
    oss << "By Grabthar's hammer, ";
    oss << "by the suns of Worvan, ";
    oss << "You shall be avenged!";
    const auto lazarus = oss.str();
    std::cout << lazarus << std::endl;

    oss.str("I'm a new string!");
    const auto groot = oss.str();
    std::cout << groot << std::endl;

    std::cout << "istringstream consumes strings with str" << std::endl;
    std::string numbers("1 2.23606 2");
    std::istringstream iss{numbers};
    int a;
    float b, c, d;
    iss >> a >> b >> c >> d;
    std::cout << a << " " << b << " " << c << " " << d << std::endl;

    std::cout << "stringstream supports all string stream operations" << std::endl;
    std::stringstream ss;
    ss << "Zed's DEAD, baby! ";
    std::string who;
    ss >> who;
    int what;
    ss >> std::hex >> what;
    std::cout << who << " " << what << std::endl;
}