####################################################################
# File Name: first_shell.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年02月13日 星期五 10时25分05秒
####################################################################

#!/bin/bash

myvar="Hi there"

echo $myvar
echo "$myvar"
echo '$myvar'
echo \$myvar

echo ${myvar}
echo "${myvar}"

echo $val hello

echo -------------
echo Enter some text
read myvar

echo '$myvar' now equals $myvar

exit 0
