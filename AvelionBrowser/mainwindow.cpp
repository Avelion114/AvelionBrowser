#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webView = new QWebEngineView(this);
    webView->setGeometry(0 ,100, 1000,1000);
    QObject::connect(webView, &QWebEngineView::urlChanged, this, &MainWindow::updateURLText);
    webView->load(currentPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_backButton_released()
{
    webView->back();
    currentPage = webView->url();
}

void MainWindow::on_lineURL_returnPressed()
{
    currentPage = QUrl(ui->lineURL->text());
    webView->load(currentPage);
}

void MainWindow::on_lineSearch_returnPressed()
{
    QString Search = ui->lineSearch->text();
    for (auto i : Search) {
        if(i == ' ')
        {
            i = '+';
        }
    }
    currentPage = QUrl("https://www.google.com/search?q=" + Search);
    webView->load(currentPage);
    webView->setUrl(currentPage);
}

void MainWindow::updateURLText()
{
    ui->lineURL->setText(webView->url().toString());
}
