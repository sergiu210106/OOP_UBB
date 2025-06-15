#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

int main(int argc, char * argv[]) {
    QApplication a(argc, argv);
    QWidget * wnd = new QWidget{};
    QVBoxLayout *vLay = new QVBoxLayout{};
    QPushButton * btn1 = new QPushButton{"Button 1", wnd};
    QPushButton * btn2 = new QPushButton{"Button 2", wnd};
    QPushButton * btn3 = new QPushButton{"Button 3", wnd};

    vLay->addWidget(btn1);
    vLay->addWidget(btn2);
    vLay->addWidget(btn3);

    wnd->setLayout(vLay);
    wnd->show();
    wnd->setWindowTitle("Vertical layout");

    return a.exec();
}
