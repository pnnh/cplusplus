---
cls: MTNote
uid: 1841cbf1-da63-47f5-bcbc-a71dbf69f242
title: 演示使用LunaSVG库进行svg到png图片转换
---

## 演示使用LunaSVG库进行svg到png图片转换

本示例在Windows 11环境下测试通过，需注意前置条件，其它平台操作步骤类似。

### 前置条件

需要安装CMake和Ninja，以便进行构建编译。

因为使用了vcpkg来进行依赖管理，避免手动下载编译lunasvg库。所以需要本机部署并配置好vcpkg，详情可参考[官方教程](https://learn.microsoft.com/zh-cn/vcpkg/get_started/overview)。 

配置好后可以将VCPKG_ROOT环境变量配置为vcpkg的安装目录，或者直接修改CMakePresets.json中toolchainFile字段，指定vcpkg的安装目录。

### 构建

```bash
cmake --preset windows
cmake --build --preset windows
```

### 运行

代码中写死了输入和输出文件的路径，可以根据需要自行修改，注意工作目录。

```bash
.\build\windows\LunaSVGExamples.exe
```

### 核心代码

```c++
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
```
更多用法可以参考[官方文档](https://github.com/sammycage/lunasvg)。
