add_requires("spdlog")

target("xmakehello")
    set_kind("binary")
    add_files("*.cpp")
    add_packages("spdlog")