#pragma once

#ifdef _DEBUG
//Debug���[�h�̏ꍇ
#pragma comment(lib,"C:\\opencv\\opencv-2.4.11\\build\\x64\\vc12\\lib\\opencv_core2411d.lib")
#pragma comment(lib,"C:\\opencv\\opencv-2.4.11\\build\\x64\\vc12\\lib\\opencv_imgproc2411d.lib")
#pragma comment(lib,"C:\\opencv\\opencv-2.4.11\\build\\x64\\vc12\\lib\\opencv_highgui2411d.lib")
#else
//Release���[�h�̏ꍇ
#pragma comment(lib,"C:\\opencv\\opencv-2.4.11\\build\\x64\\vc12\\lib\\opencv_core2411.lib")
#pragma comment(lib,"C:\\opencv\\opencv-2.4.11\\build\\x64\\vc12\\lib\\opencv_imgproc2411.lib")
#pragma comment(lib,"C:\\opencv\\opencv-2.4.11\\build\\x64\\vc12\\lib\\opencv_highgui2411.lib")
#endif

#include <opencv2\opencv.hpp>
#include<opencv2\core\core_c.h>
#include <opencv\highgui.h>
#include <opencv2\highgui\highgui.hpp>

class Test
{
public:
	Test(char argv[]);//�R���X�g���N�^
	~Test();//�f�R���X�g���N�^
private:
	cv::Mat mat;//�ǂݍ��񂾉摜
	bool init();//�N���b�N�֌W�̐ݒ�
	static void onMouse(int event, int x, int y, int flags, void * param);//�E�B���h�E�N���b�N���̓���̓o�^
	void onMouse(int event, int x, int y, int flags);

	std::string windowName = "image";//�E�C���h�E�̖��O

	bool select_object = false;
};

