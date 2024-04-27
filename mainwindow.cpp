#include <Python.h>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <map>
#include <cstdlib>
#include <random>
#include <vector>
#include <string>
#include <chrono>
#include "function_link.h"
#include "Libs/spline.h"
#include <QResizeEvent>
#include <QPixmap>

// #include "smoothing_function.cpp"

// --------------------!!!----------------------
// TODO: SMOOTH CURVE???      <-----------------------MARK
// TODO: parse lightnings
// FIXME: PSRS CRASH
// TODO: IMPLEMENT 4 LAST ALGS
// ----------------optionally-------------------
// TODO: PROGRESS BAR


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    // реклама бабло все дела
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> get_bool(0,1);

    QString pic_name = "";
    if (get_bool(rng)) {
        pic_name = ":/images/zhir";
    } else {
        pic_name = ":/images/azino";
    }
    ui->rofl->setPixmap(QPixmap(pic_name));

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
    int step = ui->StepSpin->value(); // FIXME: what if step > amount ???
    std::vector<int> initial_arr;

    ui->BeginBtn->setEnabled(false);
    ui->CancelBtn->setEnabled(true);

    int max_x_val = -1, max_y_val = -1, min_y_val=-1;

    int total_amount = ui->ChoiceTableButtons->rowCount();
    ui->ProgressBar->setValue(0);

    for (size_t i = 0; i < total_amount; ++i) {
        if (!button_activation_info[get_str_from_table(i, 0)]) { continue; }
        // too lazy to use threads...

        ui->ProgressStatus->setText((std::string("current status: calculating ") + get_str_from_table(i, 0)).c_str());
        qApp->processEvents();

        QLineSeries *series = new QLineSeries();
        series->setName(QString(get_str_from_table(i, 0).c_str()));
        std::function<void(std::vector<int>)> sort_func;

        std::vector<int> X, Y;

        for (size_t final_size=step, iteration=1; (final_size <= max_arr_size) && (!stop_called); ++iteration, final_size = step * iteration) {
            initial_arr.reserve(final_size);
            for (int x = 0; (x < final_size) && (!stop_called); x++){
                initial_arr[x] = rand() % final_size;
            }

            auto start = std::chrono::high_resolution_clock::now();

            function_link(initial_arr, get_str_from_table(i, 0));

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

            // series->append(final_size, duration.count());
            X.push_back(final_size);
            Y.push_back(duration.count());

            max_x_val = final_size > max_x_val ? final_size : max_x_val;
            max_y_val = duration.count() > max_y_val ? duration.count() : max_y_val;
            if (min_y_val == -1) {min_y_val = duration.count();}
            else {min_y_val = duration.count() < min_y_val ? duration.count() : min_y_val;}

            initial_arr.clear();
        }

        // tk::spline spl(X,Y);

        smooth_easy_(Y);
        for (size_t final_size=step, iteration=1; (final_size <= max_arr_size) && (!stop_called); ++iteration, final_size = step * iteration) {
            series->append(X[iteration - 1], Y[iteration - 1]);
        }

        series->setColor(QColor(colors_list[i].c_str()));
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

        ui->ProgressBar->setValue(int((i + 1) * 1.0 / (total_amount - disabled_count) * 100));
        qApp->processEvents();

    }

    ui->BeginBtn->setEnabled(true);
    ui->CancelBtn->setEnabled(false);

    if (stop_called) {
        stop_called = false;
        ui->ProgressBar->setValue(100);
        ui->ProgressStatus->setText("current status: stopped");
        chart->removeAllSeries();
        return;
    }

    ui->ProgressBar->setValue(100);
    ui->ProgressStatus->setText("current status: finished!");
    std::cout <<  "Finished!" << std::endl;
}


void MainWindow::on_CancelBtn_clicked()
{
    stop_called = true;
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    chartView->resize(ui->ChartFrame->width(), ui->ChartFrame->height());
}
//--------------------------
void smooth_easy_(std::vector<int>& arr){
    for(int i = 1; i<arr.size(); ++i)
        arr[i] = (arr[i-1] + arr[i]) / 2;
}

void smooth_(std::vector<int>& arr){
    std::vector<int> rhs = arr;
    int n = arr.size();
    for(int i = 0; i < n - 2; ++i){
        int j = (i == n - 1) ? 0 : i + 1;
        rhs[i] = 4 * arr[i] + 2 * arr[j];
    }
    arr = rhs;
}
