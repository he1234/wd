####################################################################
# File Name: test.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月13日 星期五 16时23分35秒
####################################################################

#!/bin/bash

#如果bash是普通文件
if [ -f /bin/bash ]
then
	echo "file/bin/bash exists"
fi

#如果bash是一个目录
if [ -d /bin/bash ]
then
	echo "/bin/bash is a directory"
else
	echo "/bin/bash is NOT a directory"
fi

exit 0
