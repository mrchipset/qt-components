#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AppWindow; }
QT_END_NAMESPACE

class AppWindow : public QMainWindow
{
    Q_OBJECT

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

private:
    Ui::AppWindow *ui;
};
#endif // APPWINDOW_H
