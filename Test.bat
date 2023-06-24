@echo off

REM 编译 shudu.cpp 文件
g++ -fprofile-arcs -ftest-coverage -o shudu shudu.cpp Arg.cpp CreateSD.cpp CreateZJ.cpp header.cpp DLX.cpp

REM 执行 shudu.exe，并传入参数 -n 100
shudu.exe -c 10000
shudu.exe -n 100
shudu.exe -s shudu.txt
shudu.exe -n 100 -u
shudu.exe -n 100 -m 1
shudu.exe -n 100 -m 2
shudu.exe -n 100 -m 3
shudu.exe -n 100 -r 30-45
shudu.exe -n 0 
shudu.exe -u
shudu.exe -c 0
shudu.exe -s "xxxxx.txt"
shudu.exe -n


REM 生成代码覆盖率报告
gcovr -r . --html --html-details -o coverage.html

REM 暂停命令行窗口，以便查看输出
pause