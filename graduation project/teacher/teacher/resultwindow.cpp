#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "votepage.h"
#include "loginwindow.h"
#include <QSqlQuery>
#include <QtWidgets>
#include <QtCharts>
#include <QTableWidget>
using namespace QtCharts;

ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
   ,icon_window(":/shangluo.png")
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    this->setWindowIcon(icon_window);
    //界面美化
    ui->returnButton->setStyleSheet("QPushButton{color: rgb(255,255,255);background-color: rgb(0, 170, 127);"
                                    "border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed
    ui->returnloginButton->setStyleSheet("QPushButton{color: rgb(255,255,255);background-color: rgb(0, 170, 127);"
                                    "border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");//pressed

    //初始化选项
    for(int i = 0; i < 9; i++)
    {
        options << QString("option%1").arg(i + 1);
    }

    //将已有的投票主题显示在控件上
    QSqlQuery query("select * from tablename;");
    while(query.next())
    {
        ui->votelistWidget->addItem(query.value("themename").toString());
    }
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_votelistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QTextBrowser* votetextbrowser = new QTextBrowser(this);
    votetextbrowser->setGeometry(230,0,970,801);
    QString tmptable; //存放投票结果表的名字
    QString themetablename;
    QSqlQuery query("select * from tablename;");
    while(query.next())
    {
        if(query.value("themename").toString() == item->text())
        {
            themetablename = query.value("number").toString();
            tmptable = themetablename + "_Votedata"; //获取投票数据结果的表名
            break;
        }
    }

    //统计投票人数
    int sum = 0; //记录当前主题投票人数
    QString tmpsql = "select * from userdata;";
    query.exec(tmpsql);
    while(query.next())
    {
        if(query.value(themetablename).toInt() == 1)
        {
            sum++;
        }
    }

    tmpsql = QString("select * from '%0';").arg(tmptable);
    query.exec(tmpsql);
    //统计当前主题得分，并将每个问题用饼状图显示
    int score[9] = {0}; //初始化为0
    QComboBox *pageComboBox = new QComboBox; //创建页面盒子，存放问题的题目
    QStackedWidget *stackedWidget = new QStackedWidget; //创建栈页面控件，存放投票结果
    while(query.next())
    {
        //获取当前问题
        QString questionName = query.value("question").toString();

        //查看当前问题是单选还是多选
        QString sigOrMul = "单选";
        QSqlQuery tmpquery(QString("select * from '%0';").arg(themetablename));
        while(tmpquery.next())
        {
            if(tmpquery.value("question").toString() == questionName)
            {
                if(tmpquery.value("state").toInt() == 1)
                {
                    sigOrMul.clear();
                    sigOrMul = "多选";
                }
                break;
            }
        }

        pageComboBox->addItem(QString("问题%1").arg(query.at() + 1));

        int option_count = 0; //记录问题的选项个数
        int tmp = 0;
        //统计当前问题得分
        for(int i = 0; i < 9 && ((tmp = query.value(options[i]).toInt()) >= 0); i++)
        {
            score[i] = tmp;
            option_count++;
        }

        if(option_count != 9)  //如果option_count == 9说明当前问题没有投票结果
        {
            QPieSeries *series = new QPieSeries(); //创建饼状图
            series->setHoleSize(0.25);
            for(int i = 0; i < option_count; i++) //设置每个选项的数据
            {
               series->append(QString("选项%1:%2/%3").arg(i+1).arg(score[i]).arg(sum), score[i]); //设置分数
            }
            series->setLabelsVisible();

            //新建 QChart 类指针，并将series 添加到chart中，然后设置标题和隐藏图例；
            QChart *chart = new QChart;
            chart->addSeries(series);
            chart->setTitle(QString("(%1)题目: ").arg(sigOrMul)+questionName);
            chart->setAnimationOptions(QChart::AllAnimations); //设置动画
            //chart->legend()->hide();

            //新建 QChartView 类指针，然后将 chart 添加到 chartview 中，设置其渲染属性为 “抗混叠” (QPainter::Antialiasing)；
            QChartView *chartview = new QChartView(chart);
            chartview->setRenderHint(QPainter::Antialiasing);
            //chartview->setChart(chart);

            //将饼状图压入栈控件中
            stackedWidget->addWidget(chartview);
        }
        else
        {
            QLabel *label = new QLabel("当前问题结果投票结果为0");
            label->setStyleSheet("font: 36pt '微软雅黑';"
                                 "color: rgb(85, 170, 127);"); //设置字体样式
            label->setAlignment(Qt::AlignCenter); //设置字体水平和垂直居中

            //将饼状图压入栈控件中
            stackedWidget->addWidget(label);
        }
    }

    //将栈控件和页面盒子放入到布局，并连接
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(pageComboBox);
    gridLayout->addWidget(stackedWidget);
    votetextbrowser->setLayout(gridLayout);
    votetextbrowser->show();

    connect(pageComboBox, QOverload<int>::of(&QComboBox::activated),
            stackedWidget, &QStackedWidget::setCurrentIndex);
}


void ResultWindow::on_returnButton_clicked()
{
    VotePage* vw = new VotePage;
    vw->show();
    this->close();
}

void ResultWindow::on_returnloginButton_clicked()
{
    LoginWindow* lw = new LoginWindow;
    lw->show();
    this->close();
}
