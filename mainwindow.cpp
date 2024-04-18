#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <vector>
#include <chrono>
#include "function_link.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    chart->setTitle(QStringLiteral("Sorting chart"));
    chart->createDefaultAxes();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->ChartFrame);
    chartView->resize(ui->ChartFrame->width(), ui->ChartFrame->height());

    chart->removeAllSeries(); // deletes pointers+objects too

    axisX->setRange(0, 1000);
    axisY->setRange(0, 1000);

    chart->setAxisX(axisX);
    chart->setAxisY(axisY);


    //-------------- init data map
    for (size_t i = 0; i < ui->ChoiceTableButtons->rowCount(); ++i) {
        auto item_txt = get_str_from_table(i, 0);
        button_activation_info[item_txt] = true;
        std::cout << item_txt << " " << i << std::endl;
    }
    my_brush.setColor(clr_white);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChoiceTableButtons_cellClicked(int row, int column)
{
    bool res = button_activation_info[get_str_from_table(row, column)];

    if (res) {
        my_brush = clr_gray;
        ++disabled_count;
    } else {
        my_brush = clr_white;
        --disabled_count;
    }

    button_activation_info[get_str_from_table(row, column)] = !res;
    ui->ChoiceTableButtons->item(row, column)->setBackground(my_brush);
}


void MainWindow::on_SelectBtn_clicked()
{
    bool turn_on = false;
    if (ui->ChoiceTableButtons->rowCount() == disabled_count) {  // turn everything on
        turn_on = true;
        my_brush = clr_white;
        disabled_count = 0;
    } else {  // turn everything off
        my_brush = clr_gray;
        disabled_count = ui->ChoiceTableButtons->rowCount();
    }

    for (size_t i = 0; i < ui->ChoiceTableButtons->rowCount(); ++i) {
        button_activation_info[get_str_from_table(i, 0)] = turn_on;
        ui->ChoiceTableButtons->item(i, 0)->setBackground(my_brush);
    }
}


void MainWindow::on_BeginBtn_clicked()
{
    chart->removeAllSeries();
    int max_arr_size = ui->AmountSpin->value();
    int step = ui->StepSpin->value(); // FIXME: step > amount
    std::vector<int> initial_arr;

    ui->BeginBtn->setEnabled(false);
    ui->CancelBtn->setEnabled(true);

    int max_x_val = -1, max_y_val = -1, min_y_val=-1;


    for (size_t i = 0; i < ui->ChoiceTableButtons->rowCount(); ++i) {
        if (!button_activation_info[get_str_from_table(i, 0)]) { continue; }
        // too lazy to use threads...

        QLineSeries *series = new QLineSeries();
        series->setName(QString(get_str_from_table(i, 0).c_str()));
        std::function<void(std::vector<int>)> sort_func;

        for (size_t final_size=step, iteration=1; final_size <= max_arr_size; ++iteration, final_size = step * iteration) {
            initial_arr.reserve(final_size);
            for (int x = 0; x < final_size; x++){
                initial_arr[x] = rand() % final_size;
            }

            auto start = std::chrono::high_resolution_clock::now();

            function_link(initial_arr, get_str_from_table(i, 0));

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            series->append(final_size, duration.count());

            max_x_val = final_size > max_x_val ? final_size : max_x_val;
            max_y_val = duration.count() > max_y_val ? duration.count() : max_y_val;
            if (min_y_val == -1) {min_y_val = duration.count();}
            else {min_y_val = duration.count() < min_y_val ? duration.count() : min_y_val;}

            std::cout << "\t" << final_size << " " << duration.count() << std::endl;
            initial_arr.clear();
        }
        chart->addSeries(series);

        axisX->setRange(0, max_x_val);
        axisY->setRange(0, max_y_val);

        axisX->setMin(0);
        axisX->setMax(max_x_val);
        //axisX->setTickCount(100);

        axisY->setMin(min_y_val);
        axisY->setMax(max_y_val);
        //axisY->setTickCount(100);

        series->attachAxis(axisX);
        series->attachAxis(axisY);

        std::cout <<  get_str_from_table(i, 0) << " done!" << std::endl;
        series->setUseOpenGL(true);
    }


    // QLineSeries *series = new QLineSeries();
    // series->setName("bebra");
    // series->append(0, 6);
    // series->append(2, 4);
    // series->append(3, 8);
    // series->append(7, 4);
    // series->append(10, 5);
    // *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3)
    //         << QPointF(20, 2);
    // //chart->legend()->hide();
    // chart->addSeries(series);
    // series->setUseOpenGL(true);

    //chart->zoomOut();
    ui->BeginBtn->setEnabled(true);
    ui->CancelBtn->setEnabled(false);
}


void MainWindow::on_CancelBtn_clicked()
{
    ui->CancelBtn->setEnabled(false);

    //TODO: emit cancelation

    ui->BeginBtn->setEnabled(true);
}

