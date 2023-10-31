#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_backButton_released();
    void on_lineURL_returnPressed();
    void on_lineSearch_returnPressed();
    void updateURLText();

private:
    Ui::MainWindow *ui;

    QWebEngineView* webView;

    QUrl currentPage = QUrl("https://www.google.com");
};
#endif // MAINWINDOW_H
