//
// Created by Qibin Chen on 20/05/2017.
//

#ifndef FACEMASH2_MAINWINDOW_H
#define FACEMASH2_MAINWINDOW_H

#include <QtWidgets>

namespace clientnetwork
{
class MyClient;
}

namespace client
{

class PhotoSetsController;

class MainWindow : public QMainWindow
{
Q_OBJECT

private:
//	View
	QWidget *centralWidget;
	QHBoxLayout *mainLayout;
	QScrollArea *controlArea, *photoArea;
	QGroupBox *photoSetsBox;
	QPushButton *addPhotoButton, *manualRefreshButton, *enablePhotoStreamButton;
//  Controller
	clientnetwork::MyClient *clientNetwork;
	PhotoSetsController *photoSetsController;
	QThread *photostream;
	QObject *streamdisplay;
	QTimer *streamtimer;
	bool streamOn;

//	Initialize
	void InitMainScene();

	void InitMainControl();

	void InitShortCuts();

	void InitButtons();

signals:
	void RefreshRequired();

private slots:
	void SwitchPhotoStream();

	void LogIn();

public slots:
	void RefreshPhotos();

	void RefreshComplete(QGroupBox *newPhotoSetsBox);

public:
	explicit MainWindow(QWidget *parent = nullptr);

	virtual ~MainWindow();

};
}
#endif //FACEMASH2_WIDGET_H
