####################################################################
# File Name: and.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月15日 星期日 11时59分35秒
####################################################################
#!/bin/bash

touch file_one
rm -f file_two
if [ -f file_one ]&& echo "hello" && [ -f file_two ] && echo "there";then
	echo "in if"
else
	echo "in else"
fi

rm -f file_one
if [ -f file_one ] || echo "world" || echo "how are you";then
	echo "in if"
else
	echo "in else"
fi
exit 0
