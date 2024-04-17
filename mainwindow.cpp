#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "algorithms/Stalin.h"
#include <functional>
#include <chrono>


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
    int max_arr_size = ui->AmountSpin->value();
    int step = ui->StepSpin->value(); // FIXME: step > amount

    ui->BeginBtn->setEnabled(false);
    ui->CancelBtn->setEnabled(true);

    std::vector<double> initial_arr;

    for (size_t i = 0; i < ui->ChoiceTableButtons->rowCount(); ++i) {
        if (!button_activation_info[get_str_from_table(i, 0)]) { continue; }
        // too lazy to use threads...

        QLineSeries *series = new QLineSeries();

        std::function<void(std::vector<double>)> sort_func;

        for (size_t final_size=step, iteration=1; final_size <= max_arr_size; ++iteration, final_size = step * iteration) {
            initial_arr.reserve(final_size);
            for (int x = 0; x < final_size; x++){
                initial_arr[x] = rand() % final_size;
            }

            auto start = std::chrono::high_resolution_clock::now();



            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = duration_cast<std::chrono::microseconds>(stop - start);
            series->append(step, duration.count());
            initial_arr.clear();
        }
        chart->addSeries(series);
        series->setUseOpenGL(true);
    }



    ui->BeginBtn->setEnabled(true);
    ui->CancelBtn->setEnabled(false);
}


void MainWindow::on_CancelBtn_clicked()
{
    ui->CancelBtn->setEnabled(false);

    //TODO: emit cancelation

    ui->BeginBtn->setEnabled(true);
}

