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

class test
{
public:
	test(char argv[]);
	~test();
	bool run();
private:
	cv::Mat mat;
	bool init();
	static void onMouse(int event, int x, int y, int flags, void * param);//�E�B���h�E�N���b�N���̓���̓o�^
	void onMouse(int event, int x, int y, int flags);


	cv::Rect selection;
	std::string windowName = "image";

	cv::Point point = { -1,-1 };
	cv::Point origin;
	bool select_object = false;
};

