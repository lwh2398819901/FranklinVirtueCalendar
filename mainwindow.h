#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

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
    void changedText();
    void changedTextForDate(const QDate&date);
private:
    Ui::MainWindow *ui;
    QVector<QString>virtueList;
    QLabel statusLable;
};

#endif // MAINWINDOW_H
