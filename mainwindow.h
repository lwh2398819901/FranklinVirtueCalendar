#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSqlDatabase>

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
    bool initDataBase();
private:
    Ui::MainWindow *ui;
    QVector<QString>virtueList;
    QLabel statusLable;
    QSqlDatabase sqliteDatabase;
    int now = 0;
};

#endif // MAINWINDOW_H
