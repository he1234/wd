####################################################################
# File Name: case.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月15日 星期日 11时39分45秒
####################################################################
#!/bin/bash

echo "Is it morning? Please answer yes or no"
read timeofday

case "$timeofday" in
	[Yy]|[Yy][Ee][Ss]) echo "good morning";;
	[Nn]|[Nn][Oo]) echo "good afternoon";;
	*) echo "Sorry,answer not recongnized";;
esac
exit 0
