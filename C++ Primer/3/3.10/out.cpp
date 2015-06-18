
	 File Name maincpp
	 Author heCentOS
	 Mail1778195296qqcom 
	 Created Time 2015年03月06日 星期五 19时27分04秒
 

includeiostream
includevector
includefstream

int mainvoid

	stdifstream ifsinttxt
	ififsgood
	
		stdcout  open inttxt failure  stdendl
		return 1
	
	int num
	int index  0
	stdvectorint vec
	whileifs  num
	
		vecpushbacknum
		 index
		if0  index2
		
			stdcout  vecindex  1  vecindex  2  stdendl
		
	
	stdcout  vecindex 1  stdendl
	if1  index2
		
		stdcout  The last one is not been added  stdendl
	

	stdcout    stdendl
	int si  vecsize
	stdcout  si    si  stdendl
	forindex  0index  si2 index
	
		stdcout  index   and   si  index   is   vecindex  vecsi  1 index  stdendl
	
	if1  si2
	
		stdcout  The middle element is   vecindex  stdendl
	
	return 0

