#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int speed;
    QTimer* eyeTimer;
    QTimer* noseTimer;
    QTimer* mouthTimer;
    QTimer* colorTimer;
    QTimer* headDecTimer;
    QTimer* faceDecTimer;
    QTimer* cefaTimer;
    QTimer* liuhaiTimer;
    QTimer* houfaTimer;
    QTimer* browTimer;
    QTimer* backgroundTimer;
    QTimer* cloTimer;


    //
    QImage eyeImage;
    QImage browImage;
    QImage noseImage;
    QImage mouthImage;
    QImage colorImage;
    QImage cloImage;
    QImage backgroundImage;
    QImage cefaImage;
    QImage houfaImage;
    QImage liuhaiImage;
    QImage faceDecImage;
    QImage headDecImage;


    //
    QColor eyeColor;
    QColor eyeColor2;
    QColor cefaColor;
    QColor cefaColor2;
    QColor houfaColor;
    QColor houfaColor2;
    QColor liuhaiColor;
    QColor liuhaiColor2;
    QColor browColor;
    QColor browColor2;
    QColor noseColor;
    QColor noseColor2;
    QColor mouthColor;
    QColor mouthColor2;
    QColor cloColor;
    QColor cloColor2;
    QColor colorColor;
    QColor colorColor2;
    QColor backgroundColor;
    QColor backgroundColor2;
    QColor headDecColor;
    QColor headDecColor2;
    QColor faceDecColor;
    QColor faceDecColor2;
    //
    void mousePressEvent(QMouseEvent *event);
private slots:

    //时间到了按钮的槽函数
    void eyetimeout();
    void colortimeout();
    void headDectimeout();
    void nosetimeout();
    void liuhaitimeout();
    void mouthtimeout();
    void browtimeout();
    void cefatimeout();
    void faceDectimeout();
    void houfatimeout();
    void clotimeout();
    void backgroundtimeout();

    //启动按钮
    void on_eyeButton_clicked();
    void on_browButton_clicked();
    void on_cefaButton_clicked();
    void on_liuhaiButton_clicked();
    void on_houfaButton_clicked();
    void on_noseButton_clicked();
    void on_mouthButton_clicked();
    void on_colorButton_clicked();
    void on_cloButton_clicked();
    void on_backgroundButton_clicked();
    void on_faceDecButton_clicked();
    void on_headDecButton_clicked();

    //
    void on_eyeCommitButton_clicked();

    void on_colorCommitButton_clicked();

    void on_browCommitButton_clicked();

    void on_headDecCommitButton_clicked();

    void on_noseCommitButton_clicked();

    void on_liuhaiCommitButton_clicked();

    void on_mouthCommitButton_clicked();

    void on_cefaCommitButton_clicked();

    void on_faceDecCommitButton_clicked();

    void on_houfaCommitButton_clicked();

    void on_cloCommitButton_clicked();

    void on_backgroundCommitButton_clicked();

    void on_eyeColorButton_clicked();

    void on_eyeColorCommitButton_clicked();

    void on_colorColorButton_clicked();

    void on_colorColorCommitButton_clicked();

    void on_browColorButton_clicked();

    void on_browColorCommitButton_clicked();

    void on_noseColorButton_clicked();

    void on_noseColorCommitButton_clicked();

    void on_mouthColorButton_clicked();

    void on_mouthColorCommitButton_clicked();

    void on_faceDecColorButton_clicked();

    void on_faceDecColorCommitButton_clicked();

    void on_liuhaiColorButton_clicked();

    void on_liuhaiColorCommitButton_clicked();

    void on_cefaColorButton_clicked();

    void on_cefaColorCommitButton_clicked();

    void on_houfaColorButton_clicked();

    void on_houfaColorCommitButton_clicked();

    void on_headDecColorButton_clicked();

    void on_headDecColorCommitButton_clicked();

    void on_cloColorButton_clicked();

    void on_cloColorCommitButton_clicked();

    void on_backgroundColorButton_clicked();

    void on_backgroundColorCommitButton_clicked();

    void on_page3BackButton_clicked();
    void on_page2BackButton_clicked();
    void on_page2NextButton_clicked();
    void on_page1NextButton_clicked();

    void on_slowButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_commitNameButton_clicked();

    void on_commitButton_clicked();

    void on_clearButton_clicked();

private:
    int position[2]={0};
    Ui::Widget *ui;
    QString name;
    QImage oc;

    //id
//    int eyeID=1;
//    int browID=1;
//    int faceDecID=1;
//    int headDecID=1;
//    int noseID=1;
//    int mouthID=1;
//    int cefaID=1;
//    int houfaID=1;
//    int liuhaiID=1;
//    int cloID=1;
//    int colorID=1;
//    int backgroundID=1;

    //判断是否选择的flag
    int eyeFlag=0;//为正代表在变化，为负代表已选定，为0代表还未开始
    int browFlag=0;
    int faceDecFlag=0;
    int headDecFlag=0;
    int noseFlag=0;
    int mouthFlag=0;
    int cefaFlag=0;
    int houfaFlag=0;
    int liuhaiFlag=0;
    int cloFlag=0;
    int colorFlag=0;
    int backgroundFlag=0;

    //判断颜色按钮是否按下
    int eyeColorFlag=0;
    int browColorFlag=0;
    int faceDecColorFlag=0;
    int headDecColorFlag=0;
    int noseColorFlag=0;
    int mouthColorFlag=0;
    int cefaColorFlag=0;
    int houfaColorFlag=0;
    int liuhaiColorFlag=0;
    int cloColorFlag=0;
    int colorColorFlag=0;
    int backgroundColorFlag=0;

    //判断本次是否有合理颜色被选择
    int eyeChoose=0;
    int liuhaiChoose=0;
    int cefaChoose=0;
    int houfaChoose=0;
    int faceDecChoose=0;
    int headDecChoose=0;
    int browChoose=0;
    int noseChoose=0;
    int mouthChoose=0;
    int colorChoose=0;
    int cloChoose=0;
    int backgroundChoose=0;
};
#endif // WIDGET_H
