#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(QApplication::clipboard(), &QClipboard::dataChanged, this, &MainWindow::clipboardChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clipboardChanged()
{
    const QClipboard* clipboard = QApplication::clipboard();
    const QMimeData* data = clipboard->mimeData();
    if(data->hasText()) {
        ui->clipboardHistory->insertItem(0, data->text());
    } else {
        ui->clipboardHistory->insertItem(0, "Unsupported type");
    }
}


void MainWindow::on_clipboardHistory_itemDoubleClicked(QListWidgetItem *item)
{
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(item->text());
}

