####################################################################
# File Name: one.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年04月14日 星期二 12时17分07秒
####################################################################
#!/bin/bash

#exec表示把当前shell替换为其它程序（设为program）
#program执行完毕后不会返回父shell
exec "/home/he/Desktop/CODE/C++ Primer/2/2.5节const/main"

echo "in exec.sh"

exit 0
