#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/ActualVectorCalculator_autogen/include/ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include<variant>
#include <QDoubleValidator>
#include "vector.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setValidators();
    QWidget::setWindowTitle("Simple Vector Calculator");
   // QWidget::setWindowFlags(windowFlags() &(~Qt::WindowMaximizeButtonHint)); // disable fullscreen only
    MainWindow::setFixedSize(QSize(800,600)); //Disable resize & fullscreen
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setValidators(){
    QDoubleValidator *validator = new QDoubleValidator();
    ui->v11->setValidator(validator);
    ui->v12->setValidator(validator);
    ui->v13->setValidator(validator);
    ui->v21->setValidator(validator);
    ui->v22->setValidator(validator);
    ui->v23->setValidator(validator);
}

void MainWindow::on_addBtn_clicked()
{
    QString printresult;

    auto [v1,v2] = readVectors();


    std::variant<Vector2D,Vector3D> resultant = std::visit(
        [](auto&& a, auto&& b) -> std::variant<Vector2D,Vector3D>{
            using T1 = std::decay_t<decltype(a)>;
            using T2 = std::decay_t<decltype(b)>;

            if constexpr(std::is_same_v<T1,T2>){
                return a + b;
            }else{
                return{};
            }
        },v1,v2
        );

    std::visit([&](auto&& resultant){
        using T = std::decay_t<decltype(resultant)>;

        if constexpr (std::is_same_v<T,Vector2D>){
            printresult = QString("Resultant: {%1, %2}").arg(resultant.x).arg(resultant.y);
        }else if constexpr (std::is_same_v<T,Vector3D>){
            printresult = QString("Resultant: {%1, %2, %3}").arg(resultant.x).arg(resultant.y).arg(resultant.z);
        }

    },resultant);

   ui->resultantField->setText(printresult);
   ui->resultantField->setAlignment(Qt::AlignHCenter);
}


void MainWindow::on_multBtn_clicked()
{
    QString printresult;
    auto v1 = readVectors().first;

    std::variant<Vector2D,Vector3D> resultant = std::visit(
        [&](auto&& a) -> std::variant<Vector2D,Vector3D>{
            using T1 = std::decay_t<decltype(a)>;
            double scalar = ui->v22->text().toDouble();

            if constexpr (std::is_same_v<T1,Vector2D>){
                return Vector2D(a) * scalar;
            }
            else if constexpr (std::is_same_v<T1,Vector3D>){
                return Vector3D(a) * scalar;
            }
        },v1
        );

    std::visit([&](auto&& resultant){
        using T = std::decay_t<decltype(resultant)>;

        if constexpr (std::is_same_v<T,Vector2D>){
            printresult = QString("Resultant: {%1, %2}").arg(resultant.x).arg(resultant.y);
        }else if constexpr (std::is_same_v<T,Vector3D>){
            printresult = QString("Resultant: {%1, %2, %3}").arg(resultant.x).arg(resultant.y).arg(resultant.z);
        }

    },resultant);

    ui->resultantField->setText(printresult);
    ui->resultantField->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_dotBtn_clicked()
{
    QString printresult;
    auto v1 = readVectors().first;
    auto v2 = readVectors().second;

    double resultant = std::visit(
        [&](auto&& a, auto&& b) -> double {
            using T1 = std::decay_t<decltype(a)>;
            using T2 = std::decay_t<decltype(b)>;

            if constexpr (std::is_same_v<T1,T2>){
                return a.dotProduct(b);
            }
            else{
                return {};
            }
        },v1,v2
        );

    printresult = QString("Resultant: {%1}").arg(resultant);

    ui->resultantField->setText(printresult);
    ui->resultantField->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_subBtn_clicked()
{
    QString printresult;

    auto [v1,v2] = readVectors();


    std::variant<Vector2D,Vector3D> resultant = std::visit(
        [](auto&& a, auto&& b) -> std::variant<Vector2D,Vector3D>{
            using T1 = std::decay_t<decltype(a)>;
            using T2 = std::decay_t<decltype(b)>;

            if constexpr(std::is_same_v<T1,T2>){
                return a - b;
            }else{
                return{};
            }
        },v1,v2
        );

    std::visit([&](auto&& resultant){
        using T = std::decay_t<decltype(resultant)>;

        if constexpr (std::is_same_v<T,Vector2D>){
            printresult = QString("Resultant: {%1, %2}").arg(resultant.x).arg(resultant.y);
        }else if constexpr (std::is_same_v<T,Vector3D>){
            printresult = QString("Resultant: {%1, %2, %3}").arg(resultant.x).arg(resultant.y).arg(resultant.z);
        }

    },resultant);

    ui->resultantField->setText(printresult);
    ui->resultantField->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_crossBtn_clicked()
{
    QString printresult;
    auto v1 = readVectors().first;
    auto v2 = readVectors().second;

    Vector3D resultant = std::visit(
        [&](auto&& a, auto&& b) -> Vector3D {
            using T1 = std::decay_t<decltype(a)>;
            using T2 = std::decay_t<decltype(b)>;

            if constexpr (std::is_same_v<T1,Vector3D> && std::is_same_v<T2,Vector3D>){
                return a.crossProduct(b);
            }else{
                return{};
            }
        },v1,v2
        );

    printresult = QString("Resultant: {%1, %2, %3}").arg(resultant.x).arg(resultant.y).arg(resultant.z);

    ui->resultantField->setText(printresult);
    ui->resultantField->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_angleBtn_clicked(){
    QString printresult;
    auto v1 = readVectors().first;
    auto v2 = readVectors().second;

    double resultant = std::visit(
        [&](auto&& a, auto&& b) -> double {
            using T1 = std::decay_t<decltype(a)>;
            using T2 = std::decay_t<decltype(b)>;

            if constexpr (std::is_same_v<T1,T2>){
                return a.angleBetween(b);
            }
            else{
                return {};
            }
        },v1,v2
        );

    printresult = QString("Resultant: {%1}").arg(resultant);

    ui->resultantField->setText(printresult);
    ui->resultantField->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_magBtn_clicked(){
    QString printresult;
    auto v1 = readVectors().first;
    auto v2 = readVectors().second;

    double resultant = std::visit(
        [&](auto&& a, auto&& b) -> double {
            using T1 = std::decay_t<decltype(a)>;
            using T2 = std::decay_t<decltype(b)>;

            if constexpr (std::is_same_v<T1,T2>){
                return a.magnitude();
            }
            else{
                return {};
            }
        },v1,v2
        );

    printresult = QString("Resultant: {%1}").arg(resultant);

    ui->resultantField->setText(printresult);
    ui->resultantField->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_pltBtn_clicked()
{

}


void MainWindow::on_scalarMultCheckBox_checkStateChanged(const Qt::CheckState &arg1)
{
    if(arg1){
        ui->multBtn->setEnabled(true);
        ui->v21->setEnabled(false);
        ui->v21->clear();
        ui->v23->setEnabled(false);
        ui->v23->clear();
        ui->addBtn->setEnabled(false);
        ui->subBtn->setEnabled(false);
        ui->dotBtn->setEnabled(false);
        ui->crossBtn->setEnabled(false);
        ui->angleBtn->setEnabled(false);
        ui->magBtn->setEnabled(false);
        ui->pltBtn->setEnabled(false);
        ui->magCheckBox->setEnabled(false);
    }else{
        if(ui->checkBox3D->isChecked()){
            ui->v23->setEnabled(true);
            ui->crossBtn->setEnabled(true);
        }
        ui->multBtn->setEnabled(false);
        ui->magBtn->setEnabled(false);
        ui->v21->setEnabled(true);
        ui->addBtn->setEnabled(true);
        ui->subBtn->setEnabled(true);
        ui->dotBtn->setEnabled(true);
        ui->angleBtn->setEnabled(true);
        ui->pltBtn->setEnabled(true);
        ui->magCheckBox->setEnabled(true);
    }
}

void MainWindow::on_checkBox3D_stateChanged(int arg1)
{
    if(arg1){
        if(ui->scalarMultCheckBox->isChecked() || ui->magCheckBox->isChecked()){
            ui->v13->setEnabled(true);
        }else{
            ui->crossBtn->setEnabled(true);
            ui->v13->setEnabled(true);
            ui->v23->setEnabled(true);
        }
    }
    else{
        ui->v13->clear();
        ui->v23->clear();
        ui->v13->setEnabled(false);
        ui->v23->setEnabled(false);
        ui->crossBtn->setEnabled(false);
    }
}

void MainWindow::on_magCheckBox_stateChanged(int arg1)
{
    if(arg1){
        ui->magBtn->setEnabled(true);
        ui->v21->setEnabled(false);
        ui->v21->clear();
        ui->v22->setEnabled(false);
        ui->v22->clear();
        ui->v23->setEnabled(false);
        ui->v23->clear();
        ui->addBtn->setEnabled(false);
        ui->subBtn->setEnabled(false);
        ui->dotBtn->setEnabled(false);
        ui->crossBtn->setEnabled(false);
        ui->angleBtn->setEnabled(false);
        ui->pltBtn->setEnabled(false);
        ui->multBtn->setEnabled(false);
        ui->scalarMultCheckBox->setEnabled(false);
    }
    else{
        if(ui->checkBox3D->isChecked()){
            ui->crossBtn->setEnabled(true);
            ui->v23->setEnabled(true);
        }
        ui->magBtn->setEnabled(false);
        ui->v21->setEnabled(true);
        ui->v22->setEnabled(true);
        ui->addBtn->setEnabled(true);
        ui->subBtn->setEnabled(true);
        ui->dotBtn->setEnabled(true);
        ui->angleBtn->setEnabled(true);
        ui->pltBtn->setEnabled(true);
        ui->scalarMultCheckBox->setEnabled(true);
    }
}

std::pair<std::variant<Vector2D,Vector3D>,std::variant<Vector2D,Vector3D>> MainWindow::readVectors(){
    std::pair<std::variant<Vector2D,Vector3D>,std::variant<Vector2D,Vector3D>> resultant;

    bool hasZ = !(ui->v13->text().isEmpty()) || !(ui->v23->text().isEmpty());

    if(hasZ){
        double v11 = ui->v11->text().toDouble();
        double v12 = ui->v12->text().toDouble();
        double v13 = ui->v13->text().toDouble();

        double v21 = ui->v21->text().toDouble();
        double v22 = ui->v22->text().toDouble();
        double v23 = ui->v23->text().toDouble();


        Vector3D v1(v11,v12,v13);
        Vector3D v2(v21,v22,v23);

        resultant = {v1,v2};
    }else{
        double v11 = ui->v11->text().toDouble();
        double v12 = ui->v12->text().toDouble();

        double v21 = ui->v21->text().toDouble();
        double v22 = ui->v22->text().toDouble();


        Vector2D v1(v11,v12);
        Vector2D v2(v21,v22);

        resultant = {v1,v2};
    }

    return resultant;
}
