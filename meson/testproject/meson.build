project('testproject', 'c', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'c_std=c17', 'cpp_std=c++17'])

spdlog = dependency('spdlog')

exe = executable('testproject', 'testproject.cpp', install : true, dependencies : [spdlog])

test('basic', exe)
