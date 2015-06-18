####################################################################
# File Name: if_elif.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月15日 星期日 09时28分39秒
####################################################################
#!/bin/bash

echo -n "It is morning? Please answer yes or no!	"
read timeofday

#下一句代码不能用模式匹配
#并且==或=两边要有空格
if [ "$timeofday" == "yes" ]
then
	echo "good morning"
#下一句==或=两端要有空格
elif [ "$timeofday" == "no" ]
then
	echo "good afternoon"
else
	echo "sorry,$timeofday not recognized.Enter yes or no"
	exit 1
fi
exit 0
