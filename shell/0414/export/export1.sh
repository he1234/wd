####################################################################
# File Name: export1.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年04月14日 星期二 11时45分27秒
####################################################################
#!/bin/bash

foo="The first meta-syntactic variable"
#export表示将变量bar导入到所有该脚本调用的子shell进程中
export bar="The second meta-syntactic variable"
./export2.sh

echo "export1.sh : $bar"
exit 0
