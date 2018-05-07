#include "test.h"



test::test(char argv[])
{
	init();

	mat = cv::imread(argv);
	cv::imshow(windowName, mat);
}


test::~test()
{
}

bool test::run()
{
	return false;
}

bool test::init()
{
	cv::namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	cv::setMouseCallback(windowName, onMouse, this);
	return false;
}
void test::onMouse(int event, int x, int y, int flags, void * param)//ウィンドウクリック時の動作の登録
{
	test* pThis = (test*)param;
	pThis->onMouse(event, x, y, flags);
}

void test::onMouse(int event, int x, int y, int flags)//クリック座標の距離の表示
{
	/*if (select_object)
	{
		selection.x = CV_IMIN(x, origin.x);
		selection.y = CV_IMIN(y, origin.y);
		selection.width = selection.x + CV_IABS(x - origin.x);
		selection.height = selection.y + CV_IABS(y - origin.y);

		selection.x = CV_IMAX(selection.x, 0);
		selection.y = CV_IMAX(selection.y, 0);
		selection.width = CV_IMIN(selection.width, mat.cols);
		selection.height = CV_IMIN(selection.height, mat.rows);
		selection.width -= selection.x;
		selection.height -= selection.y;
	}*/

	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		/*point.x = x;
		point.y = y;
		origin = cv::Point(x, y);
		selection = cv::Rect(x, y, 0, 0);*/
		std::cout << "click" << std::endl;
		select_object = true;
		break;

	case CV_EVENT_LBUTTONUP:
		select_object = false;
		std::cout << "off" << std::endl;
		break;

	default:
		break;
	}
}