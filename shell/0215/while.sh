####################################################################
# File Name: while.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月15日 星期日 10时11分57秒
####################################################################
#!/bin/bash

echo "Enter password"
read trythis

while [ "$trythis" != "secret" ]
do
	echo "sorry,try again"
	read trythis
done
exit 0
