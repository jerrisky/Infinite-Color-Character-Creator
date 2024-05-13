#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QTimer>
#include<QPixmap>
#include<QImage>
#include<QDebug>
#include<QMouseEvent>
#include<QScreen>
#include<QColorDialog>
#include<QMessageBox>
#include<stdio.h>
#include<QMediaPlayer>
#include<QSound>
#include<stdlib.h>
#include<QPainter>
#include<QFile>
#include<QDialog>
const int size_width=2048;
const int size_height=2048;
const int eyenumber=12;
const int brownumber=8;
const int nosenumber=5;
const int mouthnumber=10;
const int colornumber=5;
const int clonumber=5;
const int backgroundnumber=7;
const int cefanumber=6;
const int houfanumber=12;
const int liuhainumber=5;
const int faceDecnumber=8;
const int headDecnumber=14;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //背景
    ui->page1Label->setPixmap(QPixmap(":/res/page1.png"));
    ui->page1Label->setScaledContents(true);
    ui->page2Label->setPixmap(QPixmap(":/res/page3.png"));
    ui->page2Label->setScaledContents(true);
    ui->page3Label->setPixmap(QPixmap(":/res/page3.png"));
    ui->page3Label->setScaledContents(true);
    ui->page4Label->setPixmap(QPixmap(":/res/page3.png"));
    ui->page4Label->setScaledContents(true);
    pushButtonSound=new QSound(":/res/pushButtonSound.wav",this);//文件名错了

    //设置页面关系
    ui->styleStackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->startButton,&QPushButton::clicked,ui->stackedWidget,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->easyButton,&QPushButton::clicked,[=](){
        speed=200;
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->normalButton,&QPushButton::clicked,[=](){
        speed=100;
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->hardButton,&QPushButton::clicked,[=](){
        speed=30;
        ui->stackedWidget->setCurrentIndex(3);
    });

    //设置计时器并自动释放
    eyeTimer=new QTimer(this);
    noseTimer=new QTimer(this);
    mouthTimer=new QTimer(this);
    colorTimer=new QTimer(this);
    headDecTimer=new QTimer(this);
    faceDecTimer=new QTimer(this);
    cefaTimer=new QTimer(this);
    liuhaiTimer=new QTimer(this);
    houfaTimer=new QTimer(this);
    browTimer=new QTimer(this);
    backgroundTimer=new QTimer(this);
    cloTimer=new QTimer(this);


    //连接按钮实现图片显示变化
    connect(eyeTimer,&QTimer::timeout,this,&Widget::eyetimeout);

    connect(browTimer,&QTimer::timeout,this,&Widget::browtimeout);

    connect(noseTimer,&QTimer::timeout,this,&Widget::nosetimeout);

    connect(mouthTimer,&QTimer::timeout,this,&Widget::mouthtimeout);

    connect(cefaTimer,&QTimer::timeout,this,&Widget::cefatimeout);

    connect(liuhaiTimer,&QTimer::timeout,this,&Widget::liuhaitimeout);

    connect(houfaTimer,&QTimer::timeout,this,&Widget::houfatimeout);

    connect(cloTimer,&QTimer::timeout,this,&Widget::clotimeout);

    connect(colorTimer,&QTimer::timeout,this,&Widget::colortimeout);

    connect(backgroundTimer,&QTimer::timeout,this,&Widget::backgroundtimeout);

    connect(headDecTimer,&QTimer::timeout,this,&Widget::headDectimeout);

    connect(faceDecTimer,&QTimer::timeout,this,&Widget::faceDectimeout);




    //设置图像大小自适应
    ui->houfaLabel->setScaledContents(true);
    ui->eyeLabel->setScaledContents(true);
    ui->faceDecLabel->setScaledContents(true);
    ui->noseLabel->setScaledContents(true);
    ui->headDecLabel->setScaledContents(true);
    ui->cefaLabel->setScaledContents(true);
    ui->browLabel->setScaledContents(true);
    ui->liuhaiLabel->setScaledContents(true);
    ui->cloLabel->setScaledContents(true);
    ui->colorLabel->setScaledContents(true);
    ui->mouthLabel->setScaledContents(true);
    ui->backgroundLabel->setScaledContents(true);

    //
    setWindowTitle("Character Creator");

}

Widget::~Widget()
{
    delete ui;
}


//开始函数定义
void Widget::on_eyeButton_clicked()
{
    pushButtonSound->play();
    ui->eyeLabel->setPixmap(QPixmap(":/res/eye1.png"));
        eyeTimer->start(speed);
        eyeFlag=abs(eyeFlag)+1;
}
void Widget::on_noseButton_clicked()
{
    pushButtonSound->play();
    ui->noseLabel->setPixmap(QPixmap(":/res/nose1.png"));
        noseTimer->start(speed);
        noseFlag=abs(noseFlag)+1;
}
void Widget::on_browButton_clicked()
{
    pushButtonSound->play();
    ui->browLabel->setPixmap(QPixmap(":/res/brow1.png"));
        browTimer->start(speed);
        browFlag=abs(browFlag)+1;
}
void Widget::on_mouthButton_clicked()
{
    pushButtonSound->play();
    ui->mouthLabel->setPixmap(QPixmap(":/res/mouth1.png"));
        mouthTimer->start(speed);
        mouthFlag=abs(mouthFlag)+1;
}
void Widget::on_faceDecButton_clicked()
{
    pushButtonSound->play();
    ui->faceDecLabel->setPixmap(QPixmap(":/res/faceDec1.png"));
        faceDecTimer->start(speed);
        faceDecFlag=abs(faceDecFlag)+1;
}
void Widget::on_headDecButton_clicked()
{
    pushButtonSound->play();
    ui->headDecLabel->setPixmap(QPixmap(":/res/headDec1.png"));
        headDecTimer->start(speed);
        headDecFlag=abs(headDecFlag)+1;
}
void Widget::on_colorButton_clicked()
{
    pushButtonSound->play();
        ui->colorLabel->setPixmap(QPixmap(":/res/color1.png"));
        colorTimer->start(speed);
        colorFlag=abs(colorFlag)+1;
}
void Widget::on_cloButton_clicked()
{
    pushButtonSound->play();
    ui->cloLabel->setPixmap(QPixmap(":/res/clo1.png"));
        cloTimer->start(speed);
        cloFlag=abs(cloFlag)+1;
}
void Widget::on_cefaButton_clicked()
{
    pushButtonSound->play();
    ui->cefaLabel->setPixmap(QPixmap(":/res/cefa1.png"));
        cefaTimer->start(speed);
        cefaFlag=abs(cefaFlag)+1;
}
void Widget::on_liuhaiButton_clicked()
{
    pushButtonSound->play();
    ui->liuhaiLabel->setPixmap(QPixmap(":/res/liuhai1.png"));
        liuhaiTimer->start(speed);
        liuhaiFlag=abs(liuhaiFlag)+1;
}
void Widget::on_houfaButton_clicked()
{
    pushButtonSound->play();
    ui->houfaLabel->setPixmap(QPixmap(":/res/houfa1.png"));
        houfaTimer->start(speed);
        houfaFlag=abs(houfaFlag)+1;
}
void Widget::on_backgroundButton_clicked()
{
    pushButtonSound->play();
    ui->backgroundLabel->setPixmap(QPixmap(":/res/background1.png"));
        backgroundTimer->start(speed);
        backgroundFlag=abs(backgroundFlag)+1;
}


//时间到了函数的定义
void Widget::eyetimeout()
{
    QString path=":/res/";
    path+="eye";
    path+=QString::number(rand()%eyenumber+1);
    path+=".png";
    eyeImage.load(path);
    ui->eyeLabel->setPixmap(QPixmap::fromImage(eyeImage));
}
void Widget::browtimeout()
{
    QString path=":/res/";
    path+="brow";
    path+=QString::number(rand()%brownumber+1);
    path+=".png";
    browImage.load(path);
    ui->browLabel->setPixmap(QPixmap::fromImage(browImage));
}
void Widget::faceDectimeout()
{
    QString path=":/res/";
    path+="faceDec";
    path+=QString::number(rand()%faceDecnumber+1);
    path+=".png";
    faceDecImage.load(path);
    ui->faceDecLabel->setPixmap(QPixmap::fromImage(faceDecImage));
}
void Widget::headDectimeout()
{
    QString path=":/res/";
    path+="headDec";
    path+=QString::number(rand()%headDecnumber+1);
    path+=".png";
    headDecImage.load(path);
    ui->headDecLabel->setPixmap(QPixmap::fromImage(headDecImage));
}
void Widget::nosetimeout()
{
    QString path=":/res/";
    path+="nose";
    path+=QString::number(rand()%nosenumber+1);
    path+=".png";
    noseImage.load(path);
    ui->noseLabel->setPixmap(QPixmap::fromImage(noseImage));

}
void Widget::mouthtimeout()
{
    QString path=":/res/";
    path+="mouth";
    path+=QString::number(rand()%mouthnumber+1);
    path+=".png";
    mouthImage.load(path);
    ui->mouthLabel->setPixmap(QPixmap::fromImage(mouthImage));
}
void Widget::cefatimeout()
{
    QString path=":/res/";
    path+="cefa";
    path+=QString::number(rand()%cefanumber+1);
    path+=".png";
    cefaImage.load(path);
    ui->cefaLabel->setPixmap(QPixmap::fromImage(cefaImage));
}
void Widget::houfatimeout()
{
    QString path=":/res/";
    path+="houfa";
    path+=QString::number(rand()%houfanumber+1);
    path+=".png";
    houfaImage.load(path);
    ui->houfaLabel->setPixmap(QPixmap::fromImage(houfaImage));
}
void Widget::liuhaitimeout()
{
    QString path=":/res/";
    path+="liuhai";
    path+=QString::number(rand()%liuhainumber+1);
    path+=".png";
    liuhaiImage.load(path);
    ui->liuhaiLabel->setPixmap(QPixmap::fromImage(liuhaiImage));
}
void Widget::colortimeout()
{
    QString path=":/res/";
    path+="color";
    path+=QString::number(rand()%colornumber+1);
    path+=".png";
    colorImage.load(path);
    ui->colorLabel->setPixmap(QPixmap::fromImage(colorImage));
}
void Widget::clotimeout()
{
    QString path=":/res/";
    path+="clo";
    path+=QString::number(rand()%clonumber+1);
    path+=".png";
    cloImage.load(path);
    ui->cloLabel->setPixmap(QPixmap::fromImage(cloImage));
}
void Widget::backgroundtimeout()
{
    QString path=":/res/";
    path+="background";
    path+=QString::number(rand()%backgroundnumber+1);
    path+=".png";
    backgroundImage.load(path);
    ui->backgroundLabel->setPixmap(QPixmap::fromImage(backgroundImage));
}


//确定函数定义
void Widget::on_eyeCommitButton_clicked()
{
    pushButtonSound->play();
    eyeTimer->stop();
    eyeFlag=-abs(eyeFlag);
}

void Widget::on_colorCommitButton_clicked()
{
    pushButtonSound->play();
    colorTimer->stop();
    colorFlag=-abs(colorFlag);
}

void Widget::on_browCommitButton_clicked()
{
    pushButtonSound->play();
    browTimer->stop();
    browFlag=-abs(browFlag);
}

void Widget::on_headDecCommitButton_clicked()
{
    pushButtonSound->play();
    headDecTimer->stop();
    headDecFlag=-abs(headDecFlag);
}

void Widget::on_noseCommitButton_clicked()
{
    pushButtonSound->play();
    noseTimer->stop();
    noseFlag=-abs(noseFlag);
}

void Widget::on_liuhaiCommitButton_clicked()
{
    pushButtonSound->play();
    liuhaiTimer->stop();
    liuhaiFlag=-abs(liuhaiFlag);
}

void Widget::on_mouthCommitButton_clicked()
{
    pushButtonSound->play();
    mouthTimer->stop();
    mouthFlag=-abs(mouthFlag);
}

void Widget::on_cefaCommitButton_clicked()
{
    pushButtonSound->play();
    cefaTimer->stop();
    cefaFlag=-abs(cefaFlag);
}

void Widget::on_faceDecCommitButton_clicked()
{
    pushButtonSound->play();
    faceDecTimer->stop();
    faceDecFlag=-abs(faceDecFlag);
}

void Widget::on_houfaCommitButton_clicked()
{
    pushButtonSound->play();
    houfaTimer->stop();
    houfaFlag=-abs(houfaFlag);
}

void Widget::on_cloCommitButton_clicked()
{
    pushButtonSound->play();
    cloTimer->stop();
    cloFlag=-abs(cloFlag);
}

void Widget::on_backgroundCommitButton_clicked()
{
    pushButtonSound->play();
    backgroundTimer->stop();
    backgroundFlag=-abs(backgroundFlag);
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    position[0]=event->x();
    position[1]=event->y();
    int x=(position[0]-24)*size_width/500;
    int y=(position[1]-24)*size_height/500;
    if(eyeColorFlag==1)//开始选颜色了
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }//不能写出去，因为在什么颜色都没选的时候不该
        eyeColor=eyeImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(eyeColor.red()==0&&eyeColor.blue()==0&&eyeColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        eyeColor2=QColorDialog::getColor(eyeColor);
        if(eyeColor2.isValid())
        {
        eyeChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(browColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        browColor=browImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(browColor.red()==0&&browColor.blue()==0&&browColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        browColor2=QColorDialog::getColor(browColor);
        if(browColor2.isValid())
        {
        browChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(noseColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        noseColor=noseImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(noseColor.red()==0&&noseColor.blue()==0&&noseColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        noseColor2=QColorDialog::getColor(noseColor);
        if(noseColor2.isValid())
        {
        noseChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(mouthColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        mouthColor=mouthImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(mouthColor.red()==0&&mouthColor.blue()==0&&mouthColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        mouthColor2=QColorDialog::getColor(mouthColor);
        if(mouthColor2.isValid())
        {
        mouthChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(liuhaiColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        liuhaiColor=liuhaiImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(liuhaiColor.red()==0&&liuhaiColor.blue()==0&&liuhaiColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        liuhaiColor2=QColorDialog::getColor(liuhaiColor);
        if(liuhaiColor2.isValid())
        {
        liuhaiChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(cefaColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        cefaColor=cefaImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(cefaColor.red()==0&&cefaColor.blue()==0&&cefaColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        cefaColor2=QColorDialog::getColor(cefaColor);
        if(cefaColor2.isValid())
        {
        cefaChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(houfaColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        houfaColor=houfaImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(houfaColor.red()==0&&houfaColor.blue()==0&&houfaColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        houfaColor2=QColorDialog::getColor(houfaColor);
        if(houfaColor2.isValid())
        {
        houfaChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(headDecColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        headDecColor=headDecImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(headDecColor.red()==0&&headDecColor.blue()==0&&headDecColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        headDecColor2=QColorDialog::getColor(headDecColor);
        if(headDecColor2.isValid())
        {
        headDecChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(faceDecColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        faceDecColor=faceDecImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(faceDecColor.red()==0&&faceDecColor.blue()==0&&faceDecColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        faceDecColor2=QColorDialog::getColor(faceDecColor);
        if(faceDecColor2.isValid())
        {
        faceDecChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(colorColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        colorColor=colorImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(colorColor.red()==0&&colorColor.blue()==0&&colorColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        colorColor2=QColorDialog::getColor(colorColor);
        if(colorColor2.isValid())
        {
        colorChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(cloColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        cloColor=cloImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(cloColor.red()==0&&cloColor.blue()==0&&cloColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        cloColor2=QColorDialog::getColor(cloColor);
        if(cloColor2.isValid())
        {
        cloChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
    else if(backgroundColorFlag==1)
    {
        if(x<0||x>=size_width||y<0||y>=size_height)
        {
            QMessageBox::information(this,"温馨提示","你点出可供选择的范围了TT");
            return;
        }
        backgroundColor=backgroundImage.pixel(x,y);//指的是眼睛图层你正点到的颜色;
        if(backgroundColor.red()==0&&backgroundColor.blue()==0&&backgroundColor.red()==0)
        {
            QMessageBox::information(this,"温馨提示","你点到其他图层or点出范围了TT");//前提是我不使用黑色作为模板的颜色，因为未填充区域默认为纯黑（0，0，0）
            return;
        }
        backgroundColor2=QColorDialog::getColor(backgroundColor);
        if(backgroundColor2.isValid())
        {
        backgroundChoose=1;//这个变量有必要，排除第二、三次选择时没有选择颜色的可能性
        }
    }
}

void Widget::on_eyeColorButton_clicked()
{
    pushButtonSound->play();
    //单次只允许选一个的颜色
    if(browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(eyeColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(eyeFlag<0)//选定了样式
    {
        eyeColorFlag=1;//开始选颜色
        setWindowTitle("正在选择眼睛颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}


void Widget::on_eyeColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( eyeChoose==1)
    {
    for(int i=0;i<eyeImage.width();i++)
    {
        for(int j=0;j<eyeImage.height();j++)
        {
            color=eyeImage.pixel(i,j);
            if(color.red()==eyeColor.red()&&color.green()==eyeColor.green()&&color.blue()==eyeColor.blue())
            {
                eyeImage.setPixelColor(i,j,eyeColor2);
            }
        }
        ui->eyeLabel->setPixmap(QPixmap::fromImage(eyeImage));
    }
     eyeColorFlag=0;
     eyeChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_colorColorButton_clicked()
{

    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(colorColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(colorFlag<0)
    {
        colorColorFlag=1;
        setWindowTitle("正在选择肤色颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_colorColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( colorChoose==1)
    {
    for(int i=0;i<colorImage.width();i++)
    {
        for(int j=0;j<colorImage.height();j++)
        {
            color=colorImage.pixel(i,j);
            if(color.red()==colorColor.red()&&color.green()==colorColor.green()&&color.blue()==colorColor.blue())
            {
                colorImage.setPixelColor(i,j,colorColor2);
            }
        }
        ui->colorLabel->setPixmap(QPixmap::fromImage(colorImage));
    }
     colorColorFlag=0;
     colorChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_browColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(browColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(browFlag<0)
    {
        browColorFlag=1;
        setWindowTitle("正在选择眉毛颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_browColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( browChoose==1)
    {
    for(int i=0;i<browImage.width();i++)
    {
        for(int j=0;j<browImage.height();j++)
        {
            color=browImage.pixel(i,j);
            if(color.red()==browColor.red()&&color.green()==browColor.green()&&color.blue()==browColor.blue())
            {
                browImage.setPixelColor(i,j,browColor2);
            }
        }
        ui->browLabel->setPixmap(QPixmap::fromImage(browImage));
    }
     browColorFlag=0;
     browChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_noseColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(noseColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(noseFlag<0)
    {
        noseColorFlag=1;
        setWindowTitle("正在选择鼻子颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_noseColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( noseChoose==1)
    {
    for(int i=0;i<noseImage.width();i++)
    {
        for(int j=0;j<noseImage.height();j++)
        {
            color=noseImage.pixel(i,j);
            if(color.red()==noseColor.red()&&color.green()==noseColor.green()&&color.blue()==noseColor.blue())
            {
                noseImage.setPixelColor(i,j,noseColor2);
            }
        }
        ui->noseLabel->setPixmap(QPixmap::fromImage(noseImage));
    }
     noseColorFlag=0;
     noseChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_mouthColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(mouthColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(mouthFlag<0)
    {
        mouthColorFlag=1;
        setWindowTitle("正在选择嘴巴颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_mouthColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( mouthChoose==1)
    {
    for(int i=0;i<mouthImage.width();i++)
    {
        for(int j=0;j<mouthImage.height();j++)
        {
            color=mouthImage.pixel(i,j);
            if(color.red()==mouthColor.red()&&color.green()==mouthColor.green()&&color.blue()==mouthColor.blue())
            {
                mouthImage.setPixelColor(i,j,mouthColor2);
            }
        }
        ui->mouthLabel->setPixmap(QPixmap::fromImage(mouthImage));
    }
     mouthColorFlag=0;
     mouthChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_faceDecColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(faceDecColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(faceDecFlag<0)
    {
        faceDecColorFlag=1;
        setWindowTitle("正在选择面饰颜色");//搞一个清空图层？
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_faceDecColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( faceDecChoose==1)
    {
    for(int i=0;i<faceDecImage.width();i++)
    {
        for(int j=0;j<faceDecImage.height();j++)
        {
            color=faceDecImage.pixel(i,j);
            if(color.red()==faceDecColor.red()&&color.green()==faceDecColor.green()&&color.blue()==faceDecColor.blue())
            {
                faceDecImage.setPixelColor(i,j,faceDecColor2);
            }
        }
        ui->faceDecLabel->setPixmap(QPixmap::fromImage(faceDecImage));
    }
     faceDecColorFlag=0;
     faceDecChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_liuhaiColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(liuhaiColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(liuhaiFlag<0)
    {
        liuhaiColorFlag=1;
        setWindowTitle("正在选择刘海颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_liuhaiColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( liuhaiChoose==1)
    {
    for(int i=0;i<liuhaiImage.width();i++)
    {
        for(int j=0;j<liuhaiImage.height();j++)
        {
            color=liuhaiImage.pixel(i,j);
            if(color.red()==liuhaiColor.red()&&color.green()==liuhaiColor.green()&&color.blue()==liuhaiColor.blue())
            {
                liuhaiImage.setPixelColor(i,j,liuhaiColor2);
            }
        }
        ui->liuhaiLabel->setPixmap(QPixmap::fromImage(liuhaiImage));
    }
     liuhaiColorFlag=0;
     liuhaiChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_cefaColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(cefaColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(cefaFlag<0)
    {
        cefaColorFlag=1;
        setWindowTitle("正在选择侧发颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_cefaColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( cefaChoose==1)
    {
    for(int i=0;i<cefaImage.width();i++)
    {
        for(int j=0;j<cefaImage.height();j++)
        {
            color=cefaImage.pixel(i,j);
            if(color.red()==cefaColor.red()&&color.green()==cefaColor.green()&&color.blue()==cefaColor.blue())
            {
                cefaImage.setPixelColor(i,j,cefaColor2);
            }
        }
        ui->cefaLabel->setPixmap(QPixmap::fromImage(cefaImage));
    }
     cefaColorFlag=0;
     cefaChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_houfaColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(houfaColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(houfaFlag<0)
    {
        houfaColorFlag=1;
        setWindowTitle("正在选择后发颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_houfaColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( houfaChoose==1)
    {
    for(int i=0;i<houfaImage.width();i++)
    {
        for(int j=0;j<houfaImage.height();j++)
        {
            color=houfaImage.pixel(i,j);
            if(color.red()==houfaColor.red()&&color.green()==houfaColor.green()&&color.blue()==houfaColor.blue())
            {
                houfaImage.setPixelColor(i,j,houfaColor2);
            }
        }
        ui->houfaLabel->setPixmap(QPixmap::fromImage(houfaImage));
    }
     houfaColorFlag=0;
     houfaChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_headDecColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(headDecColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(headDecFlag<0)
    {
        headDecColorFlag=1;
        setWindowTitle("正在选择头饰颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_headDecColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( headDecChoose==1)
    {
    for(int i=0;i<headDecImage.width();i++)
    {
        for(int j=0;j<headDecImage.height();j++)
        {
            color=headDecImage.pixel(i,j);
            if(color.red()==headDecColor.red()&&color.green()==headDecColor.green()&&color.blue()==headDecColor.blue())
            {
                headDecImage.setPixelColor(i,j,headDecColor2);
            }
        }
        ui->headDecLabel->setPixmap(QPixmap::fromImage(headDecImage));
    }
     headDecColorFlag=0;
     headDecChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_cloColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(cloFlag<0)
    {
        cloColorFlag=1;
        setWindowTitle("正在选择服饰颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_cloColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( cloChoose==1)
    {
    for(int i=0;i<cloImage.width();i++)
    {
        for(int j=0;j<cloImage.height();j++)
        {
            color=cloImage.pixel(i,j);
            if(color.red()==cloColor.red()&&color.green()==cloColor.green()&&color.blue()==cloColor.blue())
            {
                cloImage.setPixelColor(i,j,cloColor2);
            }
        }
        ui->cloLabel->setPixmap(QPixmap::fromImage(cloImage));
    }
     cloColorFlag=0;
     cloChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_backgroundColorButton_clicked()
{
    pushButtonSound->play();
    if(eyeColorFlag==1||browColorFlag==1||noseColorFlag==1||mouthColorFlag==1||cefaColorFlag==1||liuhaiColorFlag==1||houfaColorFlag==1||headDecColorFlag==1||faceDecColorFlag==1||colorColorFlag==1||backgroundColorFlag==1||cloColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","当前尚有其他部分正在选颜色，请先处理再继续O");
        return;
    }
    else if(backgroundColorFlag==1)
    {
        QMessageBox::information(this,"温馨提示","重复点击了TT");
        return;
    }
    if(backgroundFlag<0)
    {
        backgroundColorFlag=1;
        setWindowTitle("正在选择背景颜色中……");
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_backgroundColorCommitButton_clicked()
{
    pushButtonSound->play();
    setWindowTitle("Character Creator");
    QColor color;
    if( backgroundChoose==1)
    {
    for(int i=0;i<backgroundImage.width();i++)
    {
        for(int j=0;j<backgroundImage.height();j++)
        {
            color=backgroundImage.pixel(i,j);
            if(color.red()==backgroundColor.red()&&color.green()==backgroundColor.green()&&color.blue()==backgroundColor.blue())
            {
                backgroundImage.setPixelColor(i,j,backgroundColor2);
            }
        }
        ui->backgroundLabel->setPixmap(QPixmap::fromImage(backgroundImage));
    }
     backgroundColorFlag=0;
     backgroundChoose=0;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还没有选择颜色O");
    }
}

void Widget::on_page1NextButton_clicked()
{
    pushButtonSound->play();
    ui->styleStackedWidget->setCurrentIndex(1);
}

void Widget::on_page2BackButton_clicked()
{
    pushButtonSound->play();
    ui->styleStackedWidget->setCurrentIndex(0);
}

void Widget::on_page2NextButton_clicked()
{
    pushButtonSound->play();
    ui->styleStackedWidget->setCurrentIndex(2);
}

void Widget::on_page3BackButton_clicked()
{
    pushButtonSound->play();
    ui->styleStackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_3_clicked()
{
    qDebug()<<"haha";
}

void Widget::on_pushButton_4_clicked()
{
    qDebug()<<"qiaIQI";
}

void Widget::on_slowButton_clicked()
{
    speed=600;
    pushButtonSound->play();
    ui->stackedWidget->setCurrentIndex(3);
}

void Widget::on_commitNameButton_clicked()
{
    pushButtonSound->play();
    name=ui->nameLineEdit->text();//读取位置有讲究，不能写在前面
    if(name.isEmpty())
    {
        QMessageBox::information(this,"温馨提示","名字不能为空");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(2);
        QMessageBox::information(this,"帮助文档","首先感谢你游玩本游戏!\n\n预警：本游戏拥有并不高的选型自由度和奇怪的绘制比例，且部分部件之间存在着强不适配性，系本人时间不充裕与画工不成熟所致，纯属个人自嗨产物，还请见谅TT\n\n以“后发”为例说明使用方法:\n首先点击“后发”按钮进入选择模式；\n再点击其右侧的“确定”按钮来确定后发的基本样式；\n然后点击“颜色”按钮，进入颜色选择模式，在此模式下，你可以通过在最左边的显示框中点击对应部分上所需要修改的颜色，并选择你所需要的的颜色；\n选定颜色后，点击“颜色”按钮右侧的“确定”按钮，等待一段时间，即可完成该部分对应颜色的更改；\n最后点击“确认生成”按钮，即可完成对象的生成。\n\nTips:\n(1)你可以不选择某部分的样式，或者多次生成同一角色，但是新生成的角色形象会覆盖旧的，还请注意！(2)无论你是否进入颜色选择模式，你都可以先不修改本部分颜色而去选择其他部分的样式；你可以通过窗口标题来回忆你是否进入或进入了哪个颜色模式。\n(3)尽管你可以在任何时候进入任何部分的颜色选择模式，但需要注意不同部分之间的叠加关系，以防无法点入某一已被覆盖的部分。\n");
    }
}

void Widget::on_commitButton_clicked()
{
    pushButtonSound->play();
    oc.load(":/res/background1");
    QPainter painter;
    if(backgroundFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,backgroundImage);
        painter.end();
    }
    if(colorFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,colorImage);
        painter.end();
    }
    if(browFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,browImage);
        painter.end();
    }
    if(eyeFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,eyeImage);
        painter.end();
    }
    if(noseFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,noseImage);
        painter.end();
    }
    if(mouthFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,mouthImage);
        painter.end();
    }
    if(faceDecFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,faceDecImage);
        painter.end();
    }
    if(houfaFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,houfaImage);
        painter.end();
    }
    if(cloFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,cloImage);
        painter.end();
    }
    if(cefaFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,cefaImage);
        painter.end();
    }
    if(liuhaiFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,liuhaiImage);
        painter.end();
    }
    if(headDecFlag<0)
    {
        painter.begin(&oc);
        painter.drawImage(0,0,headDecImage);
        painter.end();
    }
    if(oc.save(name+".png"))
    {
        QMessageBox::information(this,"好消息","你的角色"+name+"已生成并保存在当前目录下，请注意查收^_^");
    }
    else
    {
        QMessageBox::warning(this,"坏消息","，生成失败,请再次尝试TT");
    }
}

void Widget::on_clearButton_clicked()
{
    pushButtonSound->play();
    name.clear();
    ui->nameLineEdit->clear();
    pushButtonSound->play();
}

void Widget::on_startButton_clicked()
{
    pushButtonSound->play();
}

void Widget::on_hardButton_clicked()
{
    pushButtonSound->play();
}

void Widget::on_normalButton_clicked()
{
    pushButtonSound->play();
}

void Widget::on_easyButton_clicked()
{
    pushButtonSound->play();
}

void Widget::on_helpButton_clicked()
{
    pushButtonSound->play();
    QMessageBox::information(this,"帮助文档","首先感谢你游玩本游戏!\n\n预警：本游戏拥有并不高的选型自由度和奇怪的绘制比例，且部分部件之间存在着强不适配性，系本人时间不充裕与画工不成熟所致，纯属个人自嗨产物，还请见谅TT\n\n以“后发”为例说明使用方法:\n首先点击“后发”按钮进入选择模式；\n再点击其右侧的“确定”按钮来确定后发的基本样式；\n然后点击“颜色”按钮，进入颜色选择模式，在此模式下，你可以通过在最左边的显示框中点击对应部分上所需要修改的颜色，并选择你所需要的的颜色；\n选定颜色后，点击“颜色”按钮右侧的“确定”按钮，等待一段时间，即可完成该部分对应颜色的更改；\n最后点击“确认生成”按钮，即可完成对象的生成。\n\nTips:\n(1)你可以不选择某部分的样式，或者多次生成同一角色，但是新生成的角色形象会覆盖旧的，还请注意！(2)无论你是否进入颜色选择模式，你都可以先不修改本部分颜色而去选择其他部分的样式；你可以通过窗口标题来回忆你是否进入或进入了哪个颜色模式。\n(3)尽管你可以在任何时候进入任何部分的颜色选择模式，但需要注意不同部分之间的叠加关系，以防无法点入某一已被覆盖的部分。\n");
}

void Widget::on_widget_3_customContextMenuRequested(const QPoint &pos)
{
    ;
}
