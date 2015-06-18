####################################################################
# File Name: try_var.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月13日 星期五 11时23分11秒
####################################################################


#!/bin/bash

salutation="hello"
IFS='------'	#输入域替换符,只有第一个字符起作用

echo $slutation
echo "The program $0 is now running"
echo "The parameter was $2"
echo "The parameter was $1"

echo "the parameter list was $*"	#各参数之间用IFS的第一个字符替换
echo "the parameter list was $@"	#参数间隔不受输入域替换符影响
echo ------------------------------------
unset IFS
echo "the parameter list was $*"	#删除IFS后的$*
echo "the parameter number is $#"	#参数个数
echo "the script process ID is $$"	#shell 脚本进程ID
echo "The user's home directory is $HOME"	#环境变量$HOME家目录

echo "The script is now complete"

exit 0
