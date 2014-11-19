#include "ScanUploadFile.h"
#include "CBrowseDir.h"
extern "C" {
#include "qiniu/cJSON/cJSON.h"
#include "qiniu/b64/urlsafe_b64.h"
#include "qiniu/include/qiniu/io.h"
#include "qiniu/include/qiniu/resumable_io.h"
#include "qiniu/include/qiniu/emu_posix.h"
#include "qiniu/include/openssl/hmac.h"

#pragma comment(lib, "qiniu/lib/qiniu.lib")
}	
void ScanAllFile(char *Path, std::vector<FileInfo> &fi)
{
	//���������
	CStatDir statdir;

	//����Ҫ������Ŀ¼
	if (!statdir.SetInitDir(Path))
	{
		printf("%s, Not Be Found This Local",Path);
		return;
	}
	std::vector<std::string> file_vec = statdir.BeginBrowseFilenames("*");
	for(std::vector<std::string>::const_iterator it = file_vec.begin(); it < file_vec.end(); ++it)
		std::cout<<*it<<std::endl;
	printf("File Number: %d\n",file_vec.size());
	fi = statdir.AssemblyFileInfo(file_vec);
	file_vec.clear();
	
}
