####################################################################
# File Name: for.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月15日 星期日 10时04分10秒
####################################################################
#!/bin/bash

for foo in bar fud 43
do
	echo $foo
done

for file in $(ls ./*.sh);do
	echo $file
done
exit 0
