本项目用以学习C++语言而编写的示例代码

一般不依赖第三方库，但是为了方便，可能会使用一些第三方库，比如Boost等

所以采用了vcpkg来进行第三方库的管理，使用方式参考官方文档

### 构建执行

```bash
cmake --preset windows
cmake --build --preset windows --target xxx
```
