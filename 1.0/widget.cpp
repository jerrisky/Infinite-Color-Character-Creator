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
const int size_width=2048;
const int size_height=2048;
const int eyenumber=9;
const int brownumber=8;
const int nosenumber=4;
const int mouthnumber=10;
const int colornumber=4;
const int clonumber=3;
const int backgroundnumber=4;
const int cefanumber=6;
const int houfanumber=12;
const int liuhainumber=5;
const int faceDecnumber=4;
const int headDecnumber=6;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置页面关系
    QSound *sound=new QSound("D:\\QT\\bgm.wav",this);
    sound->play();
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
    connect(ui->commitNameButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
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

    //设置背景

    //图片保存功能

    //设置背景音乐

    //设置按钮音效

    //设置按钮图标

    //随机数模式

    //帮助文档

    //



}

Widget::~Widget()
{
    delete ui;
}


//开始函数定义
void Widget::on_eyeButton_clicked()
{
        ui->eyeLabel->setPixmap(QPixmap(":/res/eye1.png"));
        eyeTimer->start(speed);
        eyeFlag=abs(eyeFlag)+1;
}
void Widget::on_noseButton_clicked()
{
        ui->noseLabel->setPixmap(QPixmap(":/res/nose1.png"));
        noseTimer->start(speed);
        noseFlag=abs(noseFlag)+1;
}
void Widget::on_browButton_clicked()
{
        ui->browLabel->setPixmap(QPixmap(":/res/brow1.png"));
        browTimer->start(speed);
        browFlag=abs(browFlag)+1;
}
void Widget::on_mouthButton_clicked()
{
        ui->mouthLabel->setPixmap(QPixmap(":/res/mouth1.png"));
        mouthTimer->start(speed);
        mouthFlag=abs(mouthFlag)+1;
}
void Widget::on_faceDecButton_clicked()
{
        ui->faceDecLabel->setPixmap(QPixmap(":/res/faceDec1.png"));
        faceDecTimer->start(speed);
        faceDecFlag=abs(faceDecFlag)+1;
}
void Widget::on_headDecButton_clicked()
{
        ui->headDecLabel->setPixmap(QPixmap(":/res/headDec1.png"));
        headDecTimer->start(speed);
        headDecFlag=abs(headDecFlag)+1;
}
void Widget::on_colorButton_clicked()
{
        ui->colorLabel->setPixmap(QPixmap(":/res/color1.png"));
        colorTimer->start(speed);
        colorFlag=abs(colorFlag)+1;
}
void Widget::on_cloButton_clicked()
{
        ui->cloLabel->setPixmap(QPixmap(":/res/clo1.png"));
        cloTimer->start(speed);
        cloFlag=abs(cloFlag)+1;
}
void Widget::on_cefaButton_clicked()
{
        ui->cefaLabel->setPixmap(QPixmap(":/res/cefa1.png"));
        cefaTimer->start(speed);
        cefaFlag=abs(cefaFlag)+1;
}
void Widget::on_liuhaiButton_clicked()
{
        ui->liuhaiLabel->setPixmap(QPixmap(":/res/liuhai1.png"));
        liuhaiTimer->start(speed);
        liuhaiFlag=abs(liuhaiFlag)+1;
}
void Widget::on_houfaButton_clicked()
{
        ui->houfaLabel->setPixmap(QPixmap(":/res/houfa1.png"));
        houfaTimer->start(speed);
        houfaFlag=abs(houfaFlag)+1;
}
void Widget::on_backgroundButton_clicked()
{
        ui->backgroundLabel->setPixmap(QPixmap(":/res/background1.png"));
        backgroundTimer->start(speed);
        backgroundFlag=abs(backgroundFlag)+1;
}


//时间到了函数的定义
void Widget::eyetimeout()
{
    QString path=":/res/";
    path+="eye";
    path+=QString::number(eyeID%eyenumber+1);
    path+=".png";
    eyeImage.load(path);
    ui->eyeLabel->setPixmap(QPixmap::fromImage(eyeImage));
    eyeID++;
}
void Widget::browtimeout()
{
    QString path=":/res/";
    path+="brow";
    path+=QString::number(browID%brownumber+1);
    path+=".png";
    browImage.load(path);
    ui->browLabel->setPixmap(QPixmap::fromImage(browImage));
    browID++;
}
void Widget::faceDectimeout()
{
    QString path=":/res/";
    path+="faceDec";
    path+=QString::number(faceDecID%faceDecnumber+1);
    path+=".png";
    faceDecImage.load(path);
    ui->faceDecLabel->setPixmap(QPixmap::fromImage(faceDecImage));
    faceDecID++;
}
void Widget::headDectimeout()
{
    QString path=":/res/";
    path+="headDec";
    path+=QString::number(headDecID%headDecnumber+1);
    path+=".png";
    headDecImage.load(path);
    ui->headDecLabel->setPixmap(QPixmap::fromImage(headDecImage));
    headDecID++;
}
void Widget::nosetimeout()
{
    QString path=":/res/";
    path+="nose";
    path+=QString::number(noseID%nosenumber+1);
    path+=".png";
    noseImage.load(path);
    ui->noseLabel->setPixmap(QPixmap::fromImage(noseImage));
    noseID++;
}
void Widget::mouthtimeout()
{
    QString path=":/res/";
    path+="mouth";
    path+=QString::number(mouthID%mouthnumber+1);
    path+=".png";
    mouthImage.load(path);
    ui->mouthLabel->setPixmap(QPixmap::fromImage(mouthImage));
    mouthID++;
}
void Widget::cefatimeout()
{
    QString path=":/res/";
    path+="cefa";
    path+=QString::number(cefaID%cefanumber+1);
    path+=".png";
    cefaImage.load(path);
    ui->cefaLabel->setPixmap(QPixmap::fromImage(cefaImage));
    cefaID++;
}
void Widget::houfatimeout()
{
    QString path=":/res/";
    path+="houfa";
    path+=QString::number(houfaID%houfanumber+1);
    path+=".png";
    houfaImage.load(path);
    ui->houfaLabel->setPixmap(QPixmap::fromImage(houfaImage));
    houfaID++;
}
void Widget::liuhaitimeout()
{
    QString path=":/res/";
    path+="liuhai";
    path+=QString::number(liuhaiID%liuhainumber+1);
    path+=".png";
    liuhaiImage.load(path);
    ui->liuhaiLabel->setPixmap(QPixmap::fromImage(liuhaiImage));
    liuhaiID++;
}
void Widget::colortimeout()
{
    QString path=":/res/";
    path+="color";
    path+=QString::number(colorID%colornumber+1);
    path+=".png";
    colorImage.load(path);
    ui->colorLabel->setPixmap(QPixmap::fromImage(colorImage));
    colorID++;
}
void Widget::clotimeout()
{
    QString path=":/res/";
    path+="clo";
    path+=QString::number(cloID%clonumber+1);
    path+=".png";
    cloImage.load(path);
    ui->cloLabel->setPixmap(QPixmap::fromImage(cloImage));
    cloID++;
}
void Widget::backgroundtimeout()
{
    QString path=":/res/";
    path+="background";
    path+=QString::number(backgroundID%backgroundnumber+1);
    path+=".png";
    backgroundImage.load(path);
    ui->backgroundLabel->setPixmap(QPixmap::fromImage(backgroundImage));
    backgroundID++;
}


//确定函数定义
void Widget::on_eyeCommitButton_clicked()
{
    eyeTimer->stop();
    eyeFlag=-abs(eyeFlag);
}

void Widget::on_colorCommitButton_clicked()
{
    colorTimer->stop();
    colorFlag=-abs(colorFlag);
}

void Widget::on_browCommitButton_clicked()
{
    browTimer->stop();
    browFlag=-abs(browFlag);
}

void Widget::on_headDecCommitButton_clicked()
{
    headDecTimer->stop();
    headDecFlag=-abs(headDecFlag);
}

void Widget::on_noseCommitButton_clicked()
{
    noseTimer->stop();
    noseFlag=-abs(noseFlag);
}

void Widget::on_liuhaiCommitButton_clicked()
{
    liuhaiTimer->stop();
    liuhaiFlag=-abs(liuhaiFlag);
}

void Widget::on_mouthCommitButton_clicked()
{
    mouthTimer->stop();
    mouthFlag=-abs(mouthFlag);
}

void Widget::on_cefaCommitButton_clicked()
{
    cefaTimer->stop();
    cefaFlag=-abs(cefaFlag);
}

void Widget::on_faceDecCommitButton_clicked()
{
    faceDecTimer->stop();
    faceDecFlag=-abs(faceDecFlag);
}

void Widget::on_houfaCommitButton_clicked()
{
    houfaTimer->stop();
    houfaFlag=-abs(houfaFlag);
}

void Widget::on_cloCommitButton_clicked()
{
    cloTimer->stop();
    cloFlag=-abs(cloFlag);
}

void Widget::on_backgroundCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}


void Widget::on_eyeColorCommitButton_clicked()
{
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
    if(eyeFlag<0)
    {
        colorColorFlag=1;
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_colorColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_browColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_noseColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_mouthColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_faceDecColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_liuhaiColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_cefaColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_houfaColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_headDecColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_cloColorCommitButton_clicked()
{
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
    }
    else
    {
        QMessageBox::information(this,"温馨提示","你还未选定该样式O");
    }
}

void Widget::on_backgroundColorCommitButton_clicked()
{
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
