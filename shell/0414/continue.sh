####################################################################
# File Name: continue.sh
# Author: he_CentOS
# mail: 1778195296@qq.com
# Created Time: 2015年04月14日 星期二 09时52分41秒
####################################################################
#!/bin/bash

rm -rf fred*
echo > fred1
echo > fred2
mkdir fred3
echo > fred4

for file in fred*
do
	if [ -d "$file" ]; then
		echo "skipping directory $file"
		continue
	fi
	echo file is $file
done

rm -rf fred*
exit 0
