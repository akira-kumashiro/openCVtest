#include "test.h"

Test::Test(char argv[])//�R���X�g���N�^
{
	init();//�E�C���h�E�̓o�^

	mat = cv::imread(argv);//�摜�̓ǂݍ���
	if (mat.data == NULL)//�摜�̓ǂݍ��݂Ɏ��s�����Ƃ��̏���
	{
		std::cout << "Cannot open this file!" << std::endl;
		return;
	}
	cv::imshow(windowName, mat);//�摜�̕\��
}

Test::~Test()//�f�R���X�g���N�^
{
	cv::destroyWindow(windowName);//�w�肵���E�C���h�E�����
	//�S����openCV�̃E�C���h�E�����������cv::destroyAllWindows();
}

bool Test::init()
{
	cv::namedWindow(windowName, CV_WINDOW_AUTOSIZE);//�E�C���h�E�̖��O�����Đ���
	cv::setMouseCallback(windowName, onMouse, this);
	return true;
}

void Test::onMouse(int event, int x, int y, int flags, void * param)//�E�B���h�E�N���b�N���̓���̓o�^
{
	Test* pThis = (Test*)param;
	pThis->onMouse(event, x, y, flags);
}

void Test::onMouse(int event, int x, int y, int flags)//�N���b�N���W�̋����̕\��
{
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN://���N���b�N���ꂽ��
		std::cout << "click at (x,y)=(" << std::to_string(x) << "," << std::to_string(y) << ")" << std::endl;
		select_object = true;
		break;

	case CV_EVENT_LBUTTONUP://���N���b�N����߂���
		select_object = false;
		std::cout << "off at (x,y)=(" << std::to_string(x) << "," << std::to_string(y) << ")" << std::endl;
		break;

	default:
		break;
	}
}