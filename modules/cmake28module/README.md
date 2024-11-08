在mac下验证，执行以下命令

需要先通过brew安装新版的llvm

```shell
mkdir build
cmake --preset macos
cmake --build --preset macos
```