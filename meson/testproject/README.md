meson似乎没有自带包管理功能，仅能查找本地的pkgconfig、cmake和系统库等，不能从网络上下载

需要和vcpkg/conan等包管理器集成才可以

```bash
# 在当前目录下执行以下命令配置并构建meson项目
# 在本示例中需要在构建宿主环境先安装spdlog库，否则会构建失败
meson setup build && cd build
meson compile
```