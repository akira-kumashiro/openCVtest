#include "test.h"

Test::Test(char argv[])//コンストラクタ
{
	init();//ウインドウの登録

	mat = cv::imread(argv);//画像の読み込み
	if (mat.data == NULL)//画像の読み込みに失敗したときの処理
	{
		std::cout << "Cannot open this file!" << std::endl;
		return;
	}
	cv::imshow(windowName, mat);//画像の表示
}

Test::~Test()//デコンストラクタ
{
	cv::destroyWindow(windowName);//指定したウインドウを閉じる
	//全部のopenCVのウインドウを閉じたい時はcv::destroyAllWindows();
}

bool Test::init()
{
	cv::namedWindow(windowName, CV_WINDOW_AUTOSIZE);//ウインドウの名前をつけて生成
	cv::setMouseCallback(windowName, onMouse, this);
	return true;
}

void Test::onMouse(int event, int x, int y, int flags, void * param)//ウィンドウクリック時の動作の登録
{
	Test* pThis = (Test*)param;
	pThis->onMouse(event, x, y, flags);
}

void Test::onMouse(int event, int x, int y, int flags)//クリック座標の距離の表示
{
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN://左クリックされた時
		std::cout << "click at (x,y)=(" << std::to_string(x) << "," << std::to_string(y) << ")" << std::endl;
		select_object = true;
		break;

	case CV_EVENT_LBUTTONUP://左クリックをやめた時
		select_object = false;
		std::cout << "off at (x,y)=(" << std::to_string(x) << "," << std::to_string(y) << ")" << std::endl;
		break;

	default:
		break;
	}
}