#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#define X0 0
#define Y0 1
#define STEP 0.1
#define BORDER_X 12.5


/*
#define X0 1
#define Y0 1
#define STEP 0.5
#define BORDER_X 10.2
*/

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
