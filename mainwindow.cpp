#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <map>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QChart *chart = new QChart();

    /*
    QLineSeries *series = new QLineSeries();
    series->setName("bebra");
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3)
            << QPointF(20, 2);
    //chart->legend()->hide();
    chart->addSeries(series);
    series->setUseOpenGL(true);
    */

    // создаю чтоб отрисовалась сетка
    QLineSeries *series = new QLineSeries();
    chart->addSeries(series);
    series->setUseOpenGL(true);

    chart->setTitle(QStringLiteral("Qt line chart example"));
    chart->createDefaultAxes();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->ChartFrame);
    chartView->resize(ui->ChartFrame->width(), ui->ChartFrame->height());

    chart->removeAllSeries();

    //--------------
    std::map<std::string, bool> button_activation_info{};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    std::cout << row << " " << column << std::endl;
}

