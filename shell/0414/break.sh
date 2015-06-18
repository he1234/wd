####################################################################
# File Name: break.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年04月14日 星期二 09时40分13秒
####################################################################
#!/bin/bash

rm -rf fred*
echo > fred1
echo > fred2
mkdir fred3
echo > fred4

#fred*表示以开头含fred的文件
for file in fred*
do
	if [ -d "$file" ]; then
		break;
	fi
done

echo first directory starting fred was $file
rm -rf fred*
exit 0
