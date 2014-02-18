#!/bin/sh

echo "Hello World!!"

# 变量，等号两边不能有空格
string="A"
number=23
echo "string = ${string}, number = ${number}"

# 常用命令
ls # 列出当前目录的文件
wc -l test.sh # 计算文件的行数
wc -w test.sh # 计算文件的单词数
wc -c test.sh # 计算文件的字符数
grep '我是关键字，并高亮显示' test.sh # 在文件中查找字符串
file test.sh # 查看文件类型
read input && echo "input = ${input}" # 获取用户输入并打印出来
