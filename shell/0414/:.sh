####################################################################
# File Name: :.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年04月14日 星期二 09时57分08秒
####################################################################
#!/bin/bash

rm -f fred
if [ -f fred ]; then
	:
else
	echo file fred did not exist
fi

exit 0
